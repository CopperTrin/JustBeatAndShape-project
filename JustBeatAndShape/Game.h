#pragma once

#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <sstream>
#include <iomanip>

#include"Player.h"
#include"Ball.h"
#include"Spike.h"
#include"Small.h"
#include"Square.h"

class Game
{
private:

	//Variables
	float spawnTimerMax;
	float spawnTimer;
	float point;
	bool endGame;
	bool spaceKeyPressed;
	int lastBallUpdate;
	int lastLostHealth;
	bool beatmap1;
	bool music1;
	int elapsedSeconds;
	
	

	//Window
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event sfmlEvent;

	//Sound
	sf::Music music;
	sf::Music menuMusic;

	//GUI
	sf::Font font;
	sf::Text gameOverText;
	sf::Text timeText;

	//ProgessGUI
	sf::RectangleShape gameProcessBar;
	sf::RectangleShape gameProcessBarBack;
	

	//Time
	sf::Clock clock;
	sf::Clock updateTimeClock;
	sf::Time elapsed;
	sf::Time elapsedUpdateTime;

	
	//Menu
	sf::Texture menuTex;
	sf::Sprite menu;

	//World
	sf::Texture worldBackgroudTex;
	sf::Sprite worldBackgroud;

	

	//Objects
	Player *player;
	std::vector<Ball> balls;
	std::vector<Spike*> spikes;
	std::vector<Small*> smalls;
	std::vector<Square*> squares;


	//Private Functions
	void initVariable();
	void initWorld();
	void initMenu();
	void initPlayer();
	void initWindow();
	void initGUI();
	void initMusic();
	void initMenuMusic();

public:
	

	//Con / decon
	Game();
	virtual ~Game();

	//Public Functions
	void run();



	//Update / Render
	void playMusic();
	void updatePollEvents();
	void updateInput();
	void updatePlayerCollision();
	void spawnBall();
	void spawnSpike();
	void spawnSmall();
	void spawnSquare();
	void updateSpike();
	void updateSmall();
	void updateSquare();
	void updateCollision();
	void updateGUI();
	void update();

	void renderWorld();
	void renderBall();
	void renderSpike();
	void renderSmall();
	void renderSquare();
	void renderGUI();
	void render();

	//Menu();
	void renderMenuBackground();

	void updateMenu();
	void renderMenu();

};

