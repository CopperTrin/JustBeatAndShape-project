#pragma once

#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
	class Square
	{
	private:
		sf::Sprite square;
		sf::Texture textureSquare;
		sf::IntRect currentFrame;
		sf::Clock animationTimer;
		

		//Functions
		void initVariable();
		void initTexture();
		void initSquare();
		void initAnimations();

	public:

		Square(float pos_x, float pos_y);
		virtual~Square();
		//Accessor
		const sf::FloatRect getBound() const;
		const sf::Vector2f& getPos() const;

		//Functions
		void move(const float dirX);
		void updateAnimations();
		void update();
		void render(sf::RenderTarget* target);
	};

