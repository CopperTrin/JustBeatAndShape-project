#include "Ball.h"

void Ball::initShape(const sf::RenderWindow& window)
{
	this->shape.setRadius(static_cast<float>(rand() % 30 + 120));
	sf::Color color;
	switch (this->type)
	{
	case DEFAULT:
		color = sf::Color(254, 31, 112, 100);
		this->shape.setFillColor(color);
		this->shape.setOutlineColor(sf::Color(254, 31, 112, 200));
		this->shape.setOutlineThickness(2.f);
		break;
	case DAMAGING:
		color = sf::Color(254, 31, 112, 255);
		this->shape.setFillColor(color);
		this->shape.setOutlineColor(sf::Color(254, 31, 112, 200));
		this->shape.setOutlineThickness(2.f);
	}
	

	int pos = static_cast<float>(rand() % 4 + 1);
	if (pos == 1)
		this->shape.setPosition(sf::Vector2f(300, 50));
	if (pos == 2)
		this->shape.setPosition(sf::Vector2f(300, 450));
	if (pos == 3)
		this->shape.setPosition(sf::Vector2f(900, 50));
	if (pos == 4)
		this->shape.setPosition(sf::Vector2f(900, 450));
	
}


//Con /Decon
Ball::Ball(const sf::RenderWindow& window, int type)
	:type(type)
{
	this->initShape(window);
}

Ball::~Ball()
{
}

//Accessor
const sf::CircleShape Ball::getShape() const
{
	return this->shape;
}

const int& Ball::getType() const
{
	return this->type;
}


void Ball::setType(int type)
{
	this->type = type;

	switch (this->type)
	{
	case DEFAULT:
		this->shape.setFillColor(sf::Color(254, 31, 112, 100));
		this->shape.setOutlineColor(sf::Color(254, 31, 112, 200));
		break;
	case DAMAGING:
		this->shape.setFillColor(sf::Color(254, 31, 112, 255));
		this->shape.setOutlineColor(sf::Color(254, 31, 112, 200));
		break;
	}

}

//Function
void Ball::update()
{
}

void Ball::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
