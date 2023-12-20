#include "Square.h"

void Square::initVariable()
{
	this->isBoom = false;
}

void Square::initTexture()
{
	if (!this->textureSquare.loadFromFile("Texture/smallSquareSheet.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->bombTex.loadFromFile("Texture/bomb.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->missleTex.loadFromFile("Texture/missile.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->clearTex.loadFromFile("Texture/squareClear.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->boomTex.loadFromFile("Texture/smallBall.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void Square::initSquare()
{
	if (this->type == TRACKING) {
		this->square.setTexture(this->bombTex);
	}
	else if (this->type == MISSILE) {
		this->square.setTexture(this->missleTex);
	}
	else if (this->type == MISSLECLEAR) {
		this->square.setTexture(this->clearTex);
	}
	else {
		this->square.setTexture(this->textureSquare);
		this->currentFrame = ::sf::IntRect(0, 0, 150, 150);
		this->square.setTextureRect(this->currentFrame);
	}

	if (this->type == SQUARE2) {
		this->square.setScale(0.75f, 0.1f);
	}
	else if (this->type == SQUARE3) {
		this->square.setScale(0.1f, 1.f);
	}
	else if (this->type == MISSLECLEAR) {
		this->square.setScale(0.05f, 0.5f);
	}
	else if (this->type == TRACKING) {
		this->square.setScale(0.15f, 0.15f);
	}
	else if (this->type == MISSILE) {
		this->square.setScale(0.15f, 0.2f);
	}
	else {
		this->square.setScale(0.2f, 0.2f);
	}
}


void Square::initAnimations()
{
	this->animationTimer.restart();
}

Square::Square(float pos_x, float pos_y, int type)
	:type(type)
{
	this->initVariable();
	this->initTexture();
	this->initSquare();
	this->initAnimations();
	this->square.setPosition(pos_x, pos_y);
}

Square::~Square()
{
}
const sf::FloatRect Square::Square::getBound() const
{
	return this->square.getGlobalBounds();
}

const sf::Vector2f& Square::Square::getPos() const
{
	return this->square.getPosition();
}

const int& Square::getType() const
{
	return this->type;
}

void Square::move(const sf::Vector2f& playerPosition)
{
	if (this->type == DEFAULTSQUARE)
	{
		this->square.move(7, 0);
	}
	else if (this->type == SQUARE2)
	{
		this->square.move(-7, 0);
	}
	else if (this->type == SQUARE3)
	{
		this->square.move(0, 7);
	}
	else if (this->type == MISSLECLEAR)
	{
		this->square.move(0, 8);
	}
	else if (this->type == TRACKING )
	{
		// Calculate the direction from the square to the player
		sf::Vector2f direction = playerPosition - this->square.getPosition();

		// Normalize the direction vector (make it a unit vector)
		float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
		if (length > 0)
		{
			direction.x /= length;
			direction.y /= length;
		}

		if (this->square.getPosition().y+50 < playerPosition.y && length > 50)
		{
			// Continue tracking the player along both X and Y axes
			float speed = 2.0f;
			this->square.move(speed * direction.x, speed + 5 * direction.y + 3.f);

			// Rotate the square to face the player
			if (this->square.getPosition().y < 200)
			{
				float angle = atan2(direction.y, direction.x);
				float degrees = angle * 180.0f / 3.14159265f;
				this->square.setRotation(degrees);
			}
			
		}
		else
		{
			// Continue tracking the player along both X and Y axes
			float speed = 2.0f;
			float speedX = 2.0f;
			if (this->square.getPosition().x < playerPosition.x) speedX = 2;
			else if (this->square.getPosition().x > playerPosition.x) speedX = -2;
			this->square.move(speedX , speed * direction.y + 10.f);
		}
		
	}
	else if (this->type == MISSILE && this->isBoom == false)
	{
		// Calculate the direction from the square to the player
		sf::Vector2f direction = playerPosition - this->square.getPosition();

		// Normalize the direction vector (make it a unit vector)
		float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
		if (length > 0)
		{
			direction.x /= length;
			direction.y /= length;
		}
		// Continue tracking the player along both X and Y axes
		float speed = 2.5f;
		this->square.move(speed * direction.x, speed * direction.y);

		// Rotate the square to face the player
			float angle = atan2(direction.y, direction.x);
				float degrees = angle * 180.0f / 3.14159265f;
				this->square.setRotation(degrees);
		
	}
}



void Square::updateAnimations()
{
	if (this->animationTimer.getElapsedTime().asSeconds() > 0.02f)
	{
		this->currentFrame.left += 150.f;
		if (this->currentFrame.left >= 1500.f)
			this->currentFrame.left = 0.f;

		this->square.setTextureRect(this->currentFrame);

		this->animationTimer.restart();
	}
}

void Square::update()
{
	if(this->type == DEFAULTSQUARE )this->updateAnimations();
}

void Square::render(sf::RenderTarget* target)
{
	target->draw(this->square);
}
