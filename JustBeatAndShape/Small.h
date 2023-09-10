#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Small
{
private:
	sf::Sprite small;
	sf::Texture textureCircle;


	//Functions
	void initVariable();
	void initTexture();
	void initSmall();
	

public:

	Small(float pos_x, float pos_y);
	virtual~Small();
	//Accessor
	const sf::FloatRect getBound() const;
	const sf::Vector2f& getPos() const;

	//Functions
	void update();
	void render(sf::RenderTarget* target);
};

