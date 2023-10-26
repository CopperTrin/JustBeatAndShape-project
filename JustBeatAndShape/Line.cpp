#include "Line.h"

void Line::initShape(const sf::RenderWindow& window)
{
	this->shape.setSize(sf::Vector2f(10.f, 900.f));
	sf::Color color;
	int pos = static_cast<float>(rand() % 4 + 1);
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
	case BIGLINE1:
		this->shape.setSize(sf::Vector2f(5.f, 900.f));
		color = sf::Color(254, 31, 112, 155);
		this->shape.setFillColor(color);
		if (pos == 1)
			this->shape.setPosition(sf::Vector2f(200, 0));
		if (pos == 2)
			this->shape.setPosition(sf::Vector2f(600, 0));
		if (pos == 3)
			this->shape.setPosition(sf::Vector2f(1000, 0));
		if (pos == 4)
			this->shape.setPosition(sf::Vector2f(1400, 0));
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

const sf::Vector2f& Line::getSize() const
{
	return this->shape.getSize();
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
	if (this->type == BIGLINE1 && this->shape.getSize().x <= 395)
	{
		sf::Vector2f currentSize = this->shape.getSize();
		currentSize.x += 5;
		this->shape.setSize(currentSize);
		sf::Vector2f currentPos = this->shape.getPosition();
		currentPos.x -= 2.5f;
		this->shape.setPosition(currentPos);
		if (this->shape.getSize().x >= 400)
		{
			this->shape.setFillColor(sf::Color(254, 31, 112, 255));
		}
			
	}
}

void Line::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
