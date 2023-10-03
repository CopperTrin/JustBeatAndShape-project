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
	if (!this->textureCircle2.loadFromFile("Texture/smallBall2.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	
}

void Small::initSmall()
{
	this->small.setTexture(this->textureCircle);
	if (this->type == SmallTypes::CLEAR) this->small.setTexture(this->textureCircle2);;
	this->small.setScale(0.2f, 0.2f);
}



Small::Small(float pos_x, float pos_y, int type)
	:type(type)
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

const int& Small::getType() const
{
	return this->type;
}



void Small::randomColor()
{
	small.setColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1));
}

void Small::setPosition(const sf::Vector2f pos)
{
	this->small.setPosition(pos);
}

void Small::update()
{
	switch (this->type)
	{
	case DEFAULTSMALL:
		this->small.move(-7.f, 0.f);
		break;
	case SMALLANGLE1:
		this->small.move(-6.f, -1.5f);
		break;
	case SMALLANGLE2:
		this->small.move(-5.f, -3.f);
		break;
	case SMALLANGLE3:
		this->small.move(-6.f, 1.5f);
		break;
	case SMALLANGLE4:
		this->small.move(-5.f, 3.f);
		break;
	case SMALLANGLE5:
		this->small.move(-7.f, 0.f);
		break;
	case CLEAR:
		this->small.move(-7.f, 0.f);
		break;
	}
}

void Small::render(sf::RenderTarget* target)
{
	target->draw(this->small);
}
