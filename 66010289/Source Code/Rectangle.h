#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum RectangleTypes { DEFAULTRECTANGLE = 0, PREPARINGRECTANGLE, DEFAULTRECTANGLE2, PREPARINGRECTANGLE2
, DEFAULTRECTANGLE3};

class Rectangle
{
private:
	sf::RectangleShape shape;
	int type;
	RectangleTypes types;
	void initShape();
public:
	//Con / Decon
	Rectangle(float pos_x, float pos_y, int type);

	virtual ~Rectangle();

	//Accessor
	const sf::RectangleShape getShape() const;
	const sf::FloatRect getBound() const;
	const int& getType() const;

	//Function
	void move();
	void setPosition(const sf::Vector2f& newPosition);
	void update();
	void render(sf::RenderTarget& target);

};

