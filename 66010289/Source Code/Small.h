#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum SmallTypes { DEFAULTSMALL = 0, SMALLANGLE1, SMALLANGLE2, SMALLANGLE3, SMALLANGLE4,SMALLANGLE5, CLEAR
};

class Small
{
private:
	sf::Sprite small;
	sf::Texture textureCircle;
	sf::Texture textureCircle2;


	//Functions
	void initVariable();
	void initTexture();
	void initSmall();
	int type;
	SmallTypes types;
	

public:

	Small(float pos_x, float pos_y, int type);
	virtual~Small();

	//Accessor
	const sf::FloatRect getBound() const;
	const sf::Vector2f& getPos() const;
	const int& getType() const;

	//Functions
	void randomColor();
	void setPosition(const sf::Vector2f pos);
	void update();
	void render(sf::RenderTarget* target);
};

