#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
class Spike
{
private:
	sf::Sprite spike;
	sf::Texture texture;
	sf::IntRect currentFrame;
	sf::Clock animationTimer;
	

	//Functions
	void initVariable();
	void initTexture();
	void initSpike();
	void initAnimations();

public:

	Spike(float pos_x, float pos_y);
	virtual~Spike();
	//Accessor
	const sf::FloatRect getBound() const;
	const sf::Vector2f& getPos() const;

	//Functions
	void updateAnimations();
	void update();
	void render(sf::RenderTarget* target);
};

