#include "Line.h"

void Line::initShape(const sf::RenderWindow& window)
{
	this->shape.setSize(sf::Vector2f(10.f, 900.f));
	sf::Color color;
	switch (this->type)
	{
	case DEFAULTLINE:
		color = sf::Color(254, 31, 112, 255);
		this->shape.setFillColor(color);
		this->shape.setPosition(sf::Vector2f(1500, 0));
		break;
	case HEALING:
		color = sf::Color(0,255,0,255);
		this->shape.setFillColor(color);
		this->shape.setPosition(sf::Vector2f(1500, 0));
		break;
	case PREPARING:
		this->shape.setSize(sf::Vector2f(20.f, 900.f));
		color = sf::Color(254, 31, 112, 155);
		this->shape.setFillColor(color);
		this->shape.setPosition(sf::Vector2f(rand()%1000 + 200, 0));
		break;
	case DAMAGINGLINE:
		this->shape.setSize(sf::Vector2f(20.f, 900.f));
		color = sf::Color(254, 31, 112, 255);
		this->shape.setFillColor(color);
		this->shape.setPosition(sf::Vector2f(1500, 0));
		break;
	}
	
}

Line::Line(const sf::RenderWindow& window, int type)
	:type(type)
{
	this->initShape(window);
}

Line::~Line()
{
}

const sf::RectangleShape Line::getShape() const
{
	return this->shape;
}

const sf::FloatRect Line::getBound() const
{
	return this->shape.getGlobalBounds();
}

const int& Line::getType() const
{
	return this->type;
}



void Line::move()
{
	this->shape.move(-9.f, 0.f);
}

void Line::setPosition(const sf::Vector2f& newPosition)
{
	this->shape.setPosition(newPosition);
}

void Line::setType(int type)
{
	this->type = type;

	switch (this->type)
	{
	case DEFAULTLINE:
		this->shape.setFillColor(sf::Color(254, 31, 112, 255));
		break;
	case HEALING:
		this->shape.setFillColor(sf::Color(0, 255, 0, 255));
		break;
	case PREPARING:
		this->shape.setFillColor(sf::Color(254, 31, 112, 155));
		break;
	case DAMAGINGLINE:
		this->shape.setFillColor(sf::Color(254, 31, 112, 255));
		break;
	}
}

void Line::update()
{
}

void Line::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
