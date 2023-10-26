#pragma once

#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

#include"Player.h"
#include"Ball.h"
#include"Spike.h"
#include"Small.h"
#include"Square.h"
#include"Line.h"
#include"Rectangle.h"



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
	int lastEsc;
	int lastClick;
	int lastDashTime;
	int biglineSpawnTime;
	int preparingRecSpawnTime;
	int cooldownButton;
	bool selectBeatmap;
	bool entername;
	bool entername2;
	bool entername3;
	bool leaderboard;
	bool beatmap1;
	bool beatmap2;
	bool beatmap3;
	bool pause;
	bool pauseMenu;
	bool tutorialMenu = true;
	bool music1;
	float runtime;
	bool wave;
	bool cloudBackground;
	bool nameUpdate;
	int iframeCooldownMax;
	int ifrrameCooldown;
	bool readyToHit;
	bool gameOverSound;
	bool youWonSound;
	
	bool escHeld;
	bool playButtonSelected;
	bool leaderboardButtonSelected;
	bool exitButtonSelected;
	bool beatmapButtonSelected1;
	bool beatmapButtonSelected2;
	bool beatmapButtonSelected3;
	bool resumeButtonSelected;
	bool leaveButtonSelected;
	bool mainmenuButtonSelected;
	bool restartButtonSelected;
	bool entergameButtonSelected;
	
	
	//Window
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event sfmlEvent;

	//Sound
	sf::Music music;
	sf::Music menuMusic;
	sf::Music gameOverMusic;
	sf::Music youWonMusic;

	//GUI
	sf::Font font;
	sf::Font font2;
	sf::Text gameOverText;
	sf::Text winText;
	sf::Text timeText;
	sf::Text titleText;
	sf::Text titleText2;
	sf::Text titleText3;
	

	//LeaderBoard
	std::vector<std::string> playerNames;
	std::map<std::string, int> playerPoints;
	std::vector<std::string> playerNames2;
	std::map<std::string, int> playerPoints2;
	std::vector<std::string> playerNames3;
	std::map<std::string, int> playerPoints3;

	sf::Text playerNameText;
	sf::Text playerListText;
	sf::Text playerListText2;
	sf::Text playerListText3;

	
	

	//ProgessGUI
	sf::RectangleShape gameProcessBar;
	sf::RectangleShape gameProcessBarBack;
	

	//Time
	sf::Clock updateTimeClock;
	sf::Time elapsedUpdateTime;
	sf::Clock pollingClock;
	sf::Time elaspedPollingTime;
	

	
	//Menu
	sf::Texture menuTex;
	sf::Sprite menu;

	//World
	sf::Texture worldBackgroudTex;
	sf::Sprite worldBackgroud;
	sf::Texture worldBackgroudTex2;
	sf::Sprite worldBackgroud2;
	sf::Texture enterWorldBackgroudTex;
	sf::Sprite enterWorldBackgroud;
	sf::Texture enterWorldBackgroudTex2;
	sf::Sprite enterWorldBackgroud2;
	sf::Texture leaderboardBackgroudTex;
	sf::Sprite leaderboardBackgroud;
	sf::Texture gameOverScreenTex1;
	sf::Sprite gameOverScreen1;
	sf::Texture gameOverScreenTex2;
	sf::Sprite gameOverScreen2;
	sf::Texture gameOverScreenTex3;
	sf::Sprite gameOverScreen3;
	sf::Texture youWonScreenTex1;
	sf::Sprite youWonScreen1;
	sf::Texture youWonScreenTex2;
	sf::Sprite youWonScreen2;
	sf::Texture youWonScreenTex3;
	sf::Sprite youWonScreen3;
	sf::Texture tutorialScreenTex;
	sf::Sprite tutorialSceen;

	//PausedMenu
	sf::Texture pausedMenuTex;
	sf::Sprite pausedMenu;

	//Button
	sf::Sprite playButton;
	sf::Texture playButtonTex;
	sf::Sprite leaderboardButton;
	sf::Texture leaderboardButtonTex;
	sf::Sprite exitButton;
	sf::Texture exitButtonTex;
	sf::Sprite beatmapButton1;
	sf::Texture beatmapButtonTex1;
	sf::Sprite beatmapButton2;
	sf::Texture beatmapButtonTex2;
	sf::Sprite beatmapButton3;
	sf::Texture beatmapButtonTex3;
	sf::Sprite resumeButton;
	sf::Texture resumeButtonTex;
	sf::Sprite leaveButton;
	sf::Texture leaveButtonTex;
	sf::Sprite mainmenuButton;
	sf::Texture mainmenuButtonTex;
	sf::Sprite restartButton;
	sf::Texture restartButtonTex;
	sf::Sprite entergameButton;
	sf::Texture entergameButtonTex;



	//Objects
	Player *player;
	std::vector<Ball> balls;
	std::vector<Line> lines;
	std::vector<Spike*> spikes;
	std::vector<Small*> smalls;
	std::vector<Square*> squares;
	std::vector<Rectangle*> rectangles;


	//Private Functions
	
	void initVariable();
	void initWorld();
	void initMenu();
	void initLeaderboard();
	void initPlayer();
	void initWindow();
	void initGUI();
	void initMusic();
	void initGameOverMusic();
	void initYouWonMusic();
	void initButton();
	void initMenuMusic();
	void initPausedMenu();
	void resetGame();
	void iframe();
	
public:
	

	//Con / decon
	Game();
	virtual ~Game();

	//Public Functions
	void run();

	
	//Update / Render
	const int randSpikeType() const;
	const int randSmallType() const;
	const int randSquareType() const;
	void playMusic();
	void updatePollEvents();
	void updateInput();
	void updatePlayerCollision();
	void updateName();
	//Beatmap1
	void spawnBall();
	void spawnLine();
	void spawnSpike();
	void spawnSmall();
	void spawnSquare();
	

	//Beatmap2
	void spawnSmall2();
	void spawnRectangle2();
	void spawnSquare2();

	//Beatmap3
	void spawnSquare3();
	void spawnSpike3();
	void spawnLine3();
	void spawnLineHeal();

	void updateButtonMain();
	void updateBall();
	void updateLine();
	void updateSpike();
	void updateSmall();
	void updateSquare();
	void updateRectangle();
	void updateCollision();
	void updateGUI();
	void update();

	void renderWorld();
	void renderBall();
	void renderLine();
	void renderSpike();
	void renderSmall();
	void renderRectangle();
	void renderSquare();
	void renderGUI();
	void render();

	//Menu();
	void renderMenuBackground();
	void updateButton();

	void updateMenu();
	void renderMenu();

	//Select Beatmap Menu
	void updateButton2();
	void renderSelectBeatmap();
	void updateSelectBeatmap();


};

