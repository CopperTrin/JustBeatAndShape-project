#include "Rectangle.h"

void Rectangle::initShape()
{
	
	sf::Color color;
	switch (this->type)
	{
	case DEFAULTRECTANGLE:
		this->shape.setSize(sf::Vector2f(180.0f, 160.0f));
		color = sf::Color(254, 0, 127, 255);
		this->shape.setFillColor(color);
		break;
	case PREPARINGRECTANGLE :
		this->shape.setSize(sf::Vector2f(1600.0f, 120.0f));
		color = sf::Color(254, 31, 112, 100);
		this->shape.setFillColor(color);
		break;
	case PREPARINGRECTANGLE2:
		this->shape.setSize(sf::Vector2f(120.0f, 900.0f));
		color = sf::Color(254, 31, 112, 100);
		this->shape.setFillColor(color);
		break;
	case DEFAULTRECTANGLE2:
		this->shape.setSize(sf::Vector2f(160.0f, 180.0f));
		color = sf::Color(254, 0, 127, 255);
		this->shape.setFillColor(color);
		break;
	case DEFAULTRECTANGLE3:
		this->shape.setSize(sf::Vector2f(160.0f, 180.0f));
		color = sf::Color(254, 0, 127, 255);
		this->shape.setFillColor(color);
		break;
	}
}

Rectangle::Rectangle(float pos_x, float pos_y, int type)
	:type(type)
{
	this->initShape();
	this->shape.setPosition(pos_x, pos_y);
}

Rectangle::~Rectangle()
{
}

const sf::RectangleShape Rectangle::getShape() const
{
	return this->shape;
}

const sf::FloatRect Rectangle::getBound() const
{
	return this->shape.getGlobalBounds();
}

const int& Rectangle::getType() const
{
	return this->type;
}

void Rectangle::move()
{
	switch (this->type)
	{
	case DEFAULTRECTANGLE:
		this->shape.move(-30, 0);
		break;

	case DEFAULTRECTANGLE2:
		this->shape.move(0, 30);
		break;
	case DEFAULTRECTANGLE3:
		this->shape.move(0, -30);
		break;
	}
	
}

void Rectangle::setPosition(const sf::Vector2f& newPosition)
{
	this->shape.setPosition(newPosition);
}

void Rectangle::update()
{
	if (this->type == DEFAULTRECTANGLE || this->type == DEFAULTRECTANGLE2 || this->type == DEFAULTRECTANGLE3)this->move();
}

void Rectangle::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
