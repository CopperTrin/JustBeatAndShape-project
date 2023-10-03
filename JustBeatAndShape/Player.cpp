#include "Player.h"


void Player::applyKnockback()
{
	if (knockbackDistance > 0.f)
	{
		shape.move(knockbackDirection * movementSpeed);
		knockbackDistance -= movementSpeed;
		if (knockbackDistance <= 0.f)
		{
			knockbackDistance = 0.f;
			knockbackDirection = sf::Vector2f(0.f, 0.f);
		}
	}
}

//Private Functions
void Player::initVariable()
{
	this->movementSpeed = 6.f;
	this->spaceKeyPressed = false;
	this->hpMax = 3;
	this->hp = hpMax;
	this->shape.setPosition(60, 450);
}

void Player::initTexture()
{
	//Load a texture from file
	if (!this->texture1.loadFromFile("Texture/Player1.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}

	if (!this->texture2.loadFromFile("Texture/Player2.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}

	if (!this->texture3.loadFromFile("Texture/Player3.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
}

void Player::initShape()
{
	this->shape.setTexture(this->texture1);

	//Resize
	this->shape.setScale(0.15f, 0.15f);
}


//Con /Decon
Player::Player()
{
	this->isDashing = false;
	this->initVariable();
	this->initTexture();
	this->initShape();
}

Player::~Player()
{
}


//Accessor
const sf::Vector2f& Player::getPos() const
{
	return this->shape.getPosition();
}


const sf::FloatRect Player::getBound() const
{
	return this->shape.getGlobalBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}





void Player::dash(const sf::Vector2f& direction, float distance, float speed)
{
	if (!isDashing)
	{
		this->dashDirection = direction;

		// Normalize the dash direction vector
		float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
		if (length != 0)
		{
			this->dashDirection.x /= length;
			this->dashDirection.y /= length;
		}

		this->dashDistance = distance;
		this->dashSpeed = speed;

		this->isDashing = true;
	}
}

void Player::move(const float dirX, const float dirY)
{
	this->shape.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

//Modifiers
void Player::setPosition(const sf::Vector2f pos)
{
	this->shape.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->shape.setPosition(x, y);
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	// Update the texture based on current hp
	if (this->hp == 3)
		this->shape.setTexture(this->texture1);
	else if (this->hp == 2)
		this->shape.setTexture(this->texture2);
	else if (this->hp == 1)
		this->shape.setTexture(this->texture3);
	if (this->hp < 0)
		this->hp = 0;

	knockbackDirection = sf::Vector2f((rand() % 3 - 1), (rand() % 3 - 1)); 
	knockbackDistance = 100.f; 
}

void Player::healHp()
{
	if(this->hp < this->hpMax)
	this->hp += 1;

	if (this->hp == 3)
		this->shape.setTexture(this->texture1);
	else if (this->hp == 2)
		this->shape.setTexture(this->texture2);
	else if (this->hp == 1)
		this->shape.setTexture(this->texture3);
	if (this->hp < 0)
		this->hp = 0;
}


void Player::updateDash()
{
	if (isDashing)
	{
		// Calculate the dash displacement
		sf::Vector2f dashDisplacement = this->dashDirection * this->dashSpeed;

		// Move the player by the dash displacement
		shape.move(dashDisplacement);

		// Decrease the remaining dash distance
		this->dashDistance -= this->dashSpeed;

		// Check if the dash is completed
		if (this->dashDistance <= 0.f)
		{
			this->isDashing = false;
		}
	}
}

void Player::updateHp()
{

}

void Player::update()
{
	applyKnockback();
	this->updateHp();
	this->updateDash();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
