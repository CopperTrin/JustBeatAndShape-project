#pragma once

#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
enum SquareTypes { DEFAULTSQUARE = 0, SQUARE2,SQUARE3,TRACKING,MISSILE,MISSLECLEAR};
	class Square
	{
	private:
		sf::Sprite square;
		sf::Texture textureSquare;
		sf::Texture missleTex;
		sf::Texture bombTex;
		sf::Texture boomTex;
		sf::Texture clearTex;
		sf::IntRect currentFrame;
		sf::Clock animationTimer;
		
		
		

		//Functions
		void initVariable();
		void initTexture();
		void initSquare();
		void initAnimations();
		int type;
		SquareTypes types;
		bool isBoom;

	public:

		Square(float pos_x, float pos_y, int type);
		virtual~Square();
		//Accessor
		const sf::FloatRect getBound() const;
		const sf::Vector2f& getPos() const;
		const int& getType() const;

		//Functions
		void move(const sf::Vector2f& playerPosition);
		
		void updateAnimations();
		void update();
		void render(sf::RenderTarget* target);
	};

