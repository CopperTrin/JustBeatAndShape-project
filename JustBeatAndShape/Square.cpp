#include "Square.h"

void Square::initVariable()
{
	
}

void Square::initTexture()
{
	if (!this->textureSquare.loadFromFile("Texture/smallSquareSheet.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void Square::initSquare()
{
	this->square.setTexture(this->textureSquare);
	this->currentFrame = ::sf::IntRect(0, 0, 150, 150);
	this->square.setTextureRect(this->currentFrame);
	this->square.setScale(0.2f, 0.2f);

}

void Square::initAnimations()
{
	this->animationTimer.restart();
}

Square::Square(float pos_x, float pos_y)
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

void Square::move(const float dirX)
{
	this->square.move(7 * dirX, 0);
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
	this->updateAnimations();
}

void Square::render(sf::RenderTarget* target)
{
	target->draw(this->square);
}
