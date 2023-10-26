#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Player
{
private:
	sf::Sprite shape;
	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture3;
	float movementSpeed;
	bool spaceKeyPressed;
	int hp;
	int hpMax;
	
	sf::Vector2f dashDirection;
	float dashDistance;
	float dashSpeed;
	bool isDashing;
	
	int blinkCooldown;
	bool isWon;
	//Private Funtions
	void applyKnockback();
	void initTexture();
	

public:
	sf::Vector2f knockbackDirection;
	float knockbackDistance;
	sf::Music music;
	void initVariable();
	void initShape();
	void initSound();
	void blinking();
	
	//Con /Decon
	Player();
	virtual ~Player();

	//Accessor
	const sf::FloatRect getBound() const;
	const sf::Vector2f& getPos() const;
	const int& getHp() const;
	const bool& getIsWon() const;

	//Modifiers
	void dash(const sf::Vector2f& direction, float distance, float speed);
	void move(const float dirX, const float dirY);
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setColor();
	void loseHp(const int value);
	void healHp();
	void isWonFunc();
	

	//Update / Render
	void updateDash();
	void updateHp();
	void update();
	void render(sf::RenderTarget& target);

};

