#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum SpikeTypes { DEFAULTSPIKE = 0, SPIKE2 ,WAVE,CLOUDBACKGROUND,CLOUD };

class Spike
{
private:
	sf::Sprite spike;
	sf::Texture texture;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4;
	sf::Texture texture5;
	sf::Texture texture6;
	sf::IntRect currentFrame;
	sf::Clock animationTimer;

	
	
	sf::IntRect currentFrame2;
	sf::Clock animationTimer2;
	

	//Functions
	void initVariable();
	void initTexture();
	void initSpike();
	void initAnimations();
	int type;
	SpikeTypes types;
public:

	Spike(float pos_x, float pos_y, int type);
	virtual~Spike();
	//Accessor
	const sf::FloatRect getBound() const;
	const sf::Vector2f& getPos() const;

	//Functions
	void updateAnimations();
	void update();
	void render(sf::RenderTarget* target);
};

