#include "Small.h"

void Small::initVariable()
{
}

void Small::initTexture()
{
	if (!this->textureCircle.loadFromFile("Texture/smallBall.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	
}

void Small::initSmall()
{
	this->small.setTexture(this->textureCircle);
	this->small.setScale(0.2f, 0.2f);
}



Small::Small(float pos_x, float pos_y)
{
	this->initTexture();
	this->initSmall();
	this->small.setPosition(pos_x, pos_y);
}

Small::~Small ()
{
}

const sf::FloatRect Small::getBound() const
{
	return this->small.getGlobalBounds();
}

const sf::Vector2f& Small::getPos() const
{
	return this->small.getPosition();
}



void Small::update()
{
	this->small.move(-7.f, 0.f);
}

void Small::render(sf::RenderTarget* target)
{
	target->draw(this->small);
}
