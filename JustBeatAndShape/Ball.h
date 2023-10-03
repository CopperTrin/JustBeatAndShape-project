#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum BallTypes { DEFAULT = 0, DAMAGING};

class Ball
{
private:
	sf::CircleShape shape;
	int type;
	BallTypes types;
	void initShape(const sf::RenderWindow& window);

public:
	//Con / Decon
	Ball(const sf::RenderWindow& window, int type);

	virtual ~Ball();

	//Accessor
	const sf::CircleShape getShape() const;
	const sf::FloatRect getBound() const;
	const int& getType() const;

	//Functions
	void move();
	void resize();
	void setPosition(const sf::Vector2f& newPosition);
	void setType(int type);
	void update();
	void render(sf::RenderTarget& target);

};

