#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum LineTypes { DEFAULTLINE = 0, HEALING ,PREPARING,DAMAGINGLINE,BIGLINE1,BIGLINE2};

class Line
{
private:
	sf::RectangleShape shape;
	int type;
	LineTypes types;
	void initShape(const sf::RenderWindow& window);

public:
	//Con / Decon
	Line(const sf::RenderWindow& window, int type);

	virtual ~Line();
	
	const sf::RectangleShape getShape() const;
	const sf::FloatRect getBound() const;
	const int& getType() const;
	const sf::Vector2f& getSize() const;

	//Functions
	void move();
	void setPosition(const sf::Vector2f& newPosition);
	void setType(int type);
	void update();
	void render(sf::RenderTarget& target);
};

