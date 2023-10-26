#include "Game.h"


void Game::initVariable()
{
	//Leaderboard
	this->playerNames.clear();
	this->playerNames2.clear();
	this->playerNames3.clear();
	//Game Status
	this->endGame = false;
	this->beatmap1 = false;
	this->beatmap2 = false;
	this->beatmap3 = false;
	this->selectBeatmap = false;
	this->pause = false;
	this->escHeld = false;
	this->entername = false;
	this->entername2 = false;
	this->entername3 = false;
	this->leaderboard = false;
	


	//Game Logic
	this->runtime = 0.f;
	this->lastBallUpdate = 0;
	this->lastLostHealth = 0;
	this->lastEsc = 0;
	this->lastClick = 0;
	this->lastDashTime = 0;
	this->biglineSpawnTime = 0;
	this->cooldownButton = 0;
	this->preparingRecSpawnTime = 5;
	this->spaceKeyPressed = false;
	this->point = 0;
	this->spawnTimerMax = 10.f;
	this->iframeCooldownMax = 80;
	this->readyToHit = true;
	this->ifrrameCooldown = iframeCooldownMax;
	this->spawnTimer = this->spawnTimerMax;
	this->music1 = false;
	this->playButtonSelected = false;
	this->beatmapButtonSelected1 = false;
	this->beatmapButtonSelected2 = false;
	this->beatmapButtonSelected3 = false;
	this->gameOverSound = true;
	this->youWonSound = true;

	this->resumeButtonSelected = false;
	this->leaveButtonSelected = false;
	this->mainmenuButtonSelected = false;
	this->restartButtonSelected = false;
	this->entergameButtonSelected = false;
	this->wave = false;
	this->cloudBackground = false;

	this->leaderboardButtonSelected = false;
	this->exitButtonSelected = false;
	this->nameUpdate = false;
	this->pollingClock.restart();
	this->updateTimeClock.restart();


}

void Game::initWorld()
{
	//Load a texture from file (WorldBG)
	if (!this->worldBackgroudTex.loadFromFile("Texture/world2.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->worldBackgroudTex2.loadFromFile("Texture/world2_1.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->enterWorldBackgroudTex.loadFromFile("Texture/enterworld2.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->enterWorldBackgroudTex2.loadFromFile("Texture/enterworld2_1.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->leaderboardBackgroudTex.loadFromFile("Texture/leaderboard.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->gameOverScreenTex1.loadFromFile("Texture/gameOverScreen1.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->gameOverScreenTex2.loadFromFile("Texture/gameOverScreen2.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->gameOverScreenTex3.loadFromFile("Texture/gameOverScreen3.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->youWonScreenTex1.loadFromFile("Texture/youWonScreen1.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->youWonScreenTex2.loadFromFile("Texture/youWonScreen2.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->youWonScreenTex3.loadFromFile("Texture/youWonScreen3.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	if (!this->tutorialScreenTex.loadFromFile("Texture/Tutorial.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}



	this->worldBackgroud.setTexture(this->worldBackgroudTex);
	this->worldBackgroud2.setTexture(this->worldBackgroudTex2);
	this->enterWorldBackgroud.setTexture(this->enterWorldBackgroudTex);
	this->enterWorldBackgroud2.setTexture(this->enterWorldBackgroudTex2);
	this->leaderboardBackgroud.setTexture(this->leaderboardBackgroudTex);
	this->gameOverScreen1.setTexture(this->gameOverScreenTex1);
	this->gameOverScreen2.setTexture(this->gameOverScreenTex2);
	this->gameOverScreen3.setTexture(this->gameOverScreenTex3);
	this->youWonScreen1.setTexture(this->youWonScreenTex1);
	this->youWonScreen2.setTexture(this->youWonScreenTex2);
	this->youWonScreen3.setTexture(this->youWonScreenTex3);
	this->tutorialSceen.setTexture(this->tutorialScreenTex);
}

void Game::initMenu()
{
	//Load a texture from file (Menu)
	if (!this->menuTex.loadFromFile("Texture/Menu.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	this->menu.setTexture(this->menuTex);
}

void Game::initLeaderboard()
{

	std::ifstream inputFile3("player_names3.txt");
	if (inputFile3.is_open())
	{
		std::string playerName3;
		int lineCount = 0;

		while (std::getline(inputFile3, playerName3) && lineCount < 10) {
			playerNames3.push_back(playerName3);
			lineCount++;
		}
		inputFile3.close();
	}
	std::string playerListStr3 = "BEATMAP 3 :\n";
	for (const std::string& playerName : playerNames3)
	{
		playerListStr3 += playerName + "\n";
	}
	playerListText3.setString(playerListStr3);

	///////////////////////////////////////
	std::ifstream inputFile2("player_names2.txt");
	if (inputFile2.is_open())
	{
		std::string playerName2;
		int lineCount = 0;

		while (std::getline(inputFile2, playerName2) && lineCount < 10) {
			playerNames2.push_back(playerName2);
			lineCount++;
		}
		inputFile2.close();
	}
	std::string playerListStr2 = "BEATMAP 2 :\n";
	for (const std::string& playerName : playerNames2)
	{
		playerListStr2 += playerName + "\n";
	}
	playerListText2.setString(playerListStr2);

	///////////////////////////////////////

	std::ifstream inputFile("player_names.txt");
	if (inputFile.is_open())
	{
		std::string playerName;
		int lineCount = 0;

		while (std::getline(inputFile, playerName) && lineCount < 10) {
			playerNames.push_back(playerName);
			lineCount++;
		}
		inputFile.close();
	}
	std::string playerListStr = "BEATMAP 1 :\n";
	for (const std::string& playerName : playerNames)
	{
		playerListStr += playerName + "\n";
	}
	playerListText.setString(playerListStr);

}


void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initWindow()
{
	//Window
	this->videoMode = sf::VideoMode(1600, 900);
	this->window = new sf::RenderWindow(this->videoMode, "Just Beat and Shape!",  sf::Style::Fullscreen | sf::Style::Close | sf::Style::Titlebar );
	this->window->setFramerateLimit(60);
}

void Game::initGUI()
{
	//Load font
	if (!this->font.loadFromFile("Font/Nexa-ExtraLight.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	if (!this->font2.loadFromFile("Font/Nexa-Heavy.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	//Init point text
	this->timeText.setFont(this->font);
	this->timeText.setCharacterSize(24);
	this->timeText.setFillColor(sf::Color::White);
	this->timeText.setString("test");
	this->timeText.setPosition(5, 5);



	//title Text
	this->titleText.setFont(this->font);
	this->titleText.setCharacterSize(72);
	this->titleText.setFillColor(sf::Color::White);
	this->titleText.setString("Bossfight - Milky Ways");
	this->titleText.setPosition(
		this->window->getSize().x / 2.f - this->titleText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->titleText.getGlobalBounds().height / 2.f);

	//title Text2
	this->titleText2.setFont(this->font);
	this->titleText2.setCharacterSize(72);
	this->titleText2.setFillColor(sf::Color::White);
	this->titleText2.setString("Nitro Fun - Final Boss");
	this->titleText2.setPosition(
		this->window->getSize().x / 2.f - this->titleText2.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->titleText2.getGlobalBounds().height / 2.f);

	//title Text3
	this->titleText3.setFont(this->font);
	this->titleText3.setCharacterSize(72);
	this->titleText3.setFillColor(sf::Color::White);
	this->titleText3.setString("Pegboard Nerds - Try This");
	this->titleText3.setPosition(
		this->window->getSize().x / 2.f - this->titleText3.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->titleText3.getGlobalBounds().height / 2.f);

	//Init Process Bar
	this->gameProcessBar.setSize(sf::Vector2f(600.f, 10.f));
	this->gameProcessBar.setFillColor(sf::Color::White);
	this->gameProcessBar.setPosition(500.f, 40.f);

	this->gameProcessBarBack.setSize(sf::Vector2f(600.f, 10.f));
	this->gameProcessBarBack.setFillColor(sf::Color(25, 25, 25, 200));
	this->gameProcessBarBack.setPosition(500.f, 40.f);

	//Leaderboard
	this->playerNameText.setFont(font2);
	this->playerNameText.setCharacterSize(44);
	this->playerNameText.setFillColor(sf::Color::White);
	this->playerNameText.setPosition(530, 418);

	this->playerListText.setFont(font);
	this->playerListText.setCharacterSize(30);
	this->playerListText.setFillColor(sf::Color::White);
	this->playerListText.setPosition(80, 150);

	this->playerListText2.setFont(font);
	this->playerListText2.setCharacterSize(30);
	this->playerListText2.setFillColor(sf::Color::White);
	this->playerListText2.setPosition(580, 150);

	this->playerListText3.setFont(font);
	this->playerListText3.setCharacterSize(30);
	this->playerListText3.setFillColor(sf::Color::White);
	this->playerListText3.setPosition(1080, 150);

}

void Game::initMusic()
{
	//Init Beatmap Music
	if (beatmap1 == true)
	{
		if (!this->music.openFromFile("Music/beatmap1.ogg"))
		{
			std::cout << "ERROR::GAME::INITMUSIC::COULD NOT LOAD beatmap1.ogg" << "\n";
		}
	}

	if (beatmap2 == true)
	{
		if (!this->music.openFromFile("Music/beatmap2.ogg"))
		{
			std::cout << "ERROR::GAME::INITMUSIC::COULD NOT LOAD beatmap2.ogg" << "\n";
		}
	}

	if (beatmap3 == true)
	{
		if (!this->music.openFromFile("Music/beatmap3.ogg"))
		{
			std::cout << "ERROR::GAME::INITMUSIC::COULD NOT LOAD beatmap3.ogg" << "\n";
		}
	}


	music.setVolume(10);
	music.play();
}

void Game::initGameOverMusic()
{
	this->gameOverMusic.openFromFile("Music/gameOverMusic.ogg");
	this->gameOverMusic.setVolume(10);
}

void Game::initYouWonMusic()
{
	this->youWonMusic.openFromFile("Music/youWonMusic.ogg");
	this->youWonMusic.setVolume(10);
}

void Game::initMenuMusic()
{
	//Init Menu Music
	if (!this->menuMusic.openFromFile("Music/menu.ogg"))
	{
		std::cout << "ERROR::GAME::INITMUSIC::COULD NOT LOAD a.ogg" << "\n";
	}
	menuMusic.setVolume(10);
	menuMusic.play();
}

void Game::initButton()
{
	if (!playButtonTex.loadFromFile("Texture/play_button2.png")) // Load your play button texture
	{
		std::cout << "ERROR::GAME::INITTEXTURE::Could not load play button texture file." << "\n";
	}
	playButton.setTexture(playButtonTex);
	playButton.setPosition(1000.f, 400.f);

	if (!leaderboardButtonTex.loadFromFile("Texture/leaderboard_button.png")) // Load your play button texture
	{
		std::cout << "ERROR::GAME::INITTEXTURE::Could not load play button texture file." << "\n";
	}
	leaderboardButton.setTexture(leaderboardButtonTex);
	leaderboardButton.setScale(0.8f, 0.8f);
	leaderboardButton.setPosition(1120.f, 540.f);

	if (!exitButtonTex.loadFromFile("Texture/exit_button.png")) // Load your play button texture
	{
		std::cout << "ERROR::GAME::INITTEXTURE::Could not load play button texture file." << "\n";
	}
	exitButton.setTexture(exitButtonTex);
	exitButton.setScale(0.8f, 0.8f);
	exitButton.setPosition(1120.f, 660.f);

	if (!beatmapButtonTex1.loadFromFile("Texture/beatmapProfile1.png")) // Load your play button texture
	{
		std::cout << "ERROR::GAME::INITTEXTURE::Could not load play button texture file." << "\n";
	}
	beatmapButton1.setTexture(beatmapButtonTex1);
	beatmapButton1.setPosition(0.f, 0.f);

	if (!beatmapButtonTex2.loadFromFile("Texture/beatmapProfile2.png")) // Load your play button texture
	{
		std::cout << "ERROR::GAME::INITTEXTURE::Could not load play button texture file." << "\n";
	}
	beatmapButton2.setTexture(beatmapButtonTex2);
	beatmapButton2.setPosition(534.f, 0.f);

	if (!beatmapButtonTex3.loadFromFile("Texture/beatmapProfile3.png")) // Load your play button texture
	{
		std::cout << "ERROR::GAME::INITTEXTURE::Could not load play button texture file." << "\n";
	}
	beatmapButton3.setTexture(beatmapButtonTex3);
	beatmapButton3.setPosition(1068.f, 0.f);

	if (!resumeButtonTex.loadFromFile("Texture/resumeButton.png")) // Load your play button texture
	{
		std::cout << "ERROR::GAME::INITTEXTURE::Could not load play button texture file." << "\n";
	}
	resumeButton.setTexture(resumeButtonTex);
	resumeButton.setScale(0.5f, 0.5f);
	resumeButton.setPosition(
		this->window->getSize().x / 2.f - this->resumeButton.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->resumeButton.getGlobalBounds().height / 2.f - 200
	);

	if (!leaveButtonTex.loadFromFile("Texture/leaveButton.png")) // Load your play button texture
	{
		std::cout << "ERROR::GAME::INITTEXTURE::Could not load play button texture file." << "\n";
	}
	leaveButton.setTexture(leaveButtonTex);
	leaveButton.setScale(0.5f, 0.5f);
	leaveButton.setPosition(
		this->window->getSize().x / 2.f - this->leaveButton.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->leaveButton.getGlobalBounds().height / 2.f + 200
	);

	if (!mainmenuButtonTex.loadFromFile("Texture/mainmenuButton.png")) // Load your play button texture
	{
		std::cout << "ERROR::GAME::INITTEXTURE::Could not load play button texture file." << "\n";
	}
	mainmenuButton.setTexture(mainmenuButtonTex);
	mainmenuButton.setScale(0.5f, 0.5f);
	mainmenuButton.setPosition(
		this->window->getSize().x / 2.f - this->mainmenuButton.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->mainmenuButton.getGlobalBounds().height / 2.f + 350);

	if (!restartButtonTex.loadFromFile("Texture/RestartButton.png")) // Load your play button texture
	{
		std::cout << "ERROR::GAME::INITTEXTURE::Could not load play button texture file." << "\n";
	}
	restartButton.setTexture(restartButtonTex);
	restartButton.setScale(0.5f, 0.5f);
	restartButton.setPosition(
		this->window->getSize().x / 2.f - this->restartButton.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->restartButton.getGlobalBounds().height / 2.f + 0);
	restartButton.setColor(sf::Color(188, 188, 188));

	if (!entergameButtonTex.loadFromFile("Texture/entergameButton.png")) // Load your play button texture
	{
		std::cout << "ERROR::GAME::INITTEXTURE::Could not load play button texture file." << "\n";
	}
	entergameButton.setTexture(entergameButtonTex);
	entergameButton.setScale(0.35f, 0.35f);
	entergameButton.setPosition(
		this->window->getSize().x / 2.f - this->entergameButton.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->entergameButton.getGlobalBounds().height / 2.f + 400);

}

void Game::initPausedMenu()
{
	//Load a texture from file (WorldBG)
	if (!this->pausedMenuTex.loadFromFile("Texture/pauseMenu.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	this->pausedMenu.setTexture(this->pausedMenuTex);
}

void Game::resetGame()
{
	this->initVariable();
	this->initGUI();
	this->initButton();
	this->initPlayer();
	this->initLeaderboard();
	this->player->initVariable();
	this->player->initShape();
	this->balls.clear();
	this->lines.clear();
	this->spikes.clear();
	this->smalls.clear();
	this->squares.clear();
	this->rectangles.clear();
}

void Game::iframe()
{
	if (ifrrameCooldown == iframeCooldownMax)
	{
		this->readyToHit = true;
	}
	else
	{
		if (ifrrameCooldown <= iframeCooldownMax)ifrrameCooldown++;
	}
}

//Con / Decon
Game::Game()
{
	this->initVariable();
	this->initWorld();
	this->initMenu();
	this->initLeaderboard();
	this->initMenuMusic();
	this->initGameOverMusic();
	this->initYouWonMusic();
	this->initWindow();
	this->initPlayer();
	this->initGUI();
	this->initButton();
	this->initPausedMenu();
}

Game::~Game()
{
}

//Run
void Game::run()
{
	//While Game run do this
	while (this->window->isOpen())
	{
		this->updatePollEvents();
		

		if (entername == false && entername2 == false && entername3 == false && beatmap1 == false && selectBeatmap == false && beatmap2 == false && beatmap3 == false && leaderboard == false)
		{
			this->updateMenu();
			this->renderMenu();
			
			
			
		}

		if (selectBeatmap == true)
		{
			this->updateSelectBeatmap();
			this->renderSelectBeatmap();
		}
		//Play
		if (beatmap1 == true || beatmap2 == true || beatmap3 == true)
		{
			this->render();
			if (pause == false) this->update();
			this->updateButtonMain();
		}
		if (entername == true || entername2 == true || entername3 && beatmap1 == false && selectBeatmap == false && beatmap2 == false && beatmap3 == false && leaderboard == false)
		{
			this->window->clear();
			this->renderWorld();
			this->window->draw(playerNameText);
			this->window->display();
		}
		if (entername == false && entername2 == false && entername3 == false && beatmap1 == false && selectBeatmap == false && beatmap2 == false && beatmap3 == false && leaderboard == true)
		{
			this->window->clear();
			this->renderWorld();
			this->updateButtonMain();
			this->window->draw(playerListText);
			this->window->draw(playerListText2);
			this->window->draw(playerListText3);
			this->window->draw(mainmenuButton);
			this->window->display();
		}
		
	}
}



void Game::playMusic()
{
	//Play music
	if (music1)
		music.play();
}

void Game::updatePollEvents()
{
	while (this->window->pollEvent(sfmlEvent))
	{
		if (sfmlEvent.type == sf::Event::Closed)
		{
			this->window->close();
		}
		else if (sfmlEvent.type == sf::Event::TextEntered &&
			(this->entername == true || this->entername2 == true || this->entername3 == true))
		{
			if (sfmlEvent.text.unicode == 13) // 13 คือปุ่ม Enter
			{
				if (!playerNameText.getString().isEmpty())
				{
					if (entername == true)
					{
						entername = false;
						beatmap1 = true;
						menuMusic.stop();
						initMusic();
					}

					if (entername2 == true)
					{
						entername2 = false;
						beatmap2 = true;
						menuMusic.stop();
						initMusic();
					}

					if (entername3 == true)
					{
						entername3 = false;
						beatmap3 = true;
						menuMusic.stop();
						initMusic();
					}


				}
			}
			else if (sfmlEvent.text.unicode == 8 && !playerNameText.getString().isEmpty())
			{
				playerNameText.setString(playerNameText.getString().substring(0, playerNameText.getString().getSize() - 1));
			}
			else if (sfmlEvent.text.unicode >= 32 && sfmlEvent.text.unicode < 128)
			{
				if (playerNameText.getString().getSize() < 20)
				{
					playerNameText.setString(playerNameText.getString() + static_cast<char>(sfmlEvent.text.unicode));
				}
			}
		}
		else if (sfmlEvent.type == sf::Event::KeyPressed)
		{
			if (sfmlEvent.key.code == sf::Keyboard::Escape)
			{
				this->elaspedPollingTime = pollingClock.getElapsedTime();
				if (elaspedPollingTime.asMilliseconds() > lastEsc && (beatmap1 || beatmap2 || beatmap3))
				{
					this->pause = !this->pause;
					if (this->pause == true)
					{
						this->music.pause();
					}
					if (this->pause == false)
					{
						this->music.play();
					}
					lastEsc = elaspedPollingTime.asMilliseconds() + 200;
				}
			}
			else if(sfmlEvent.key.code == sf::Keyboard::O)
			{
				if(beatmap1 || beatmap2 || beatmap3)this->runtime = 188;
				
			}
		}
	}
}

void Game::updateInput()
{
	// Move Player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f, 0.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);

	// Dash System
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (!spaceKeyPressed && runtime >= lastDashTime + 1)
		{
			spaceKeyPressed = true;
			lastDashTime = runtime;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				sf::Vector2f dashDirection(-1.f, 0.f);
				this->player->dash(dashDirection, 70.f, 18.f);
				this->ifrrameCooldown = 45;
				this->readyToHit = false;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				sf::Vector2f dashDirection(1.f, 0.f);
				this->player->dash(dashDirection, 70.f, 18.f);
				this->ifrrameCooldown = 45;
				this->readyToHit = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				sf::Vector2f dashDirection(0.f, -1.f);
				this->player->dash(dashDirection, 70.f, 18.f);
				this->ifrrameCooldown = 45;
				this->readyToHit = false;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				sf::Vector2f dashDirection(0.f, 1.f);
				this->player->dash(dashDirection, 70.f, 18.f);
				this->ifrrameCooldown = 45;
				this->readyToHit = false;
			}
		}
	}
	else
	{
		spaceKeyPressed = false;
	}
}

void Game::updatePlayerCollision()
{
	//Check If player at corner.
	if (this->player->getBound().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBound().top);
	}
	else if (this->player->getBound().left + this->player->getBound().width > this->window->getSize().x)
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBound().width, this->player->getBound().top);
	}

	if (this->player->getBound().top < 0.f)
	{
		this->player->setPosition(this->player->getBound().left, 0.f);
	}
	else if (this->player->getBound().top + this->player->getBound().height > this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBound().left, this->window->getSize().y - this->player->getBound().height);
	}
}

void Game::updateName()
{
	if (this->nameUpdate == false)
	{
		this->nameUpdate = true;
		std::string playerName = playerNameText.getString() + " - " + std::to_string(static_cast<int>(point));

		if (this->beatmap1 == true)
		{
			playerNames.insert(playerNames.begin(), playerName);
			playerNameText.setString("");
			std::sort(playerNames.begin(), playerNames.end(), [](const std::string& a, const std::string& b) {
				// เปรียบเทียบค่า point แบบมากไปน้อย
				return std::stoi(a.substr(a.find_last_of("-") + 2)) > std::stoi(b.substr(b.find_last_of("-") + 2));
				});
			if (playerNames.size() > 10) {
				playerNames.resize(10); // จำกัดจำนวนรายชื่อเฉพาะ 10 รายการ
			}
			std::ofstream outputFile("player_names.txt");
			if (outputFile.is_open())
			{
				for (const std::string& playerName : playerNames)
				{
					outputFile << playerName << "\n";
				}
				outputFile.close();
			}
		}
		else if (this->beatmap2 == true)
		{
			playerNames2.insert(playerNames2.begin(), playerName);
			playerNameText.setString("");
			std::sort(playerNames2.begin(), playerNames2.end(), [](const std::string& a, const std::string& b) {
				// เปรียบเทียบค่า point แบบมากไปน้อย
				return std::stoi(a.substr(a.find_last_of("-") + 2)) > std::stoi(b.substr(b.find_last_of("-") + 2));
				});
			if (playerNames2.size() > 10) {
				playerNames2.resize(10); // จำกัดจำนวนรายชื่อเฉพาะ 10 รายการ
			}
			std::ofstream outputFile("player_names2.txt");
			if (outputFile.is_open())
			{
				for (const std::string& playerName : playerNames2)
				{
					outputFile << playerName << "\n";
				}
				outputFile.close();
			}
		}
		else if (this->beatmap3 == true)
		{
			playerNames3.insert(playerNames3.begin(), playerName);
			playerNameText.setString("");
			std::sort(playerNames3.begin(), playerNames3.end(), [](const std::string& a, const std::string& b) {
				// เปรียบเทียบค่า point แบบมากไปน้อย
				return std::stoi(a.substr(a.find_last_of("-") + 2)) > std::stoi(b.substr(b.find_last_of("-") + 2));
				});
			if (playerNames3.size() > 10) {
				playerNames3.resize(10); // จำกัดจำนวนรายชื่อเฉพาะ 10 รายการ
			}
			std::ofstream outputFile("player_names3.txt");
			if (outputFile.is_open())
			{
				for (const std::string& playerName : playerNames3)
				{
					outputFile << playerName << "\n";
				}
				outputFile.close();
			}
		}
	}
}





void Game::spawnBall()
{
	//Spawn ball every 5 seconds and ball deal damage after spawn.
	float ballSpawnTime = 0;

	if (runtime != 0 && static_cast<int>(runtime) % 5 == 0)
	{
		this->balls.clear();
		for (size_t i = 0; i < 2; i++)
		{
			this->balls.push_back(Ball(*this->window, BallTypes::DEFAULT));
		}
		if (runtime == 10 || runtime == 20 || runtime == 30)
		{
			for (size_t i = 0; i < 2; i++)
			{
				this->balls.push_back(Ball(*this->window, BallTypes::DEFAULT));
			}
		}
		ballSpawnTime = runtime;
	}
	if (runtime - ballSpawnTime > 4)
	{
		for (Ball& ball : balls)
		{
			ball.setType(BallTypes::DAMAGING);
		}

	}



}
void Game::spawnLine()
{
	static int lineSpawnTime = 0;

	if ((runtime != 0 && static_cast<int>(runtime) % 6 == 0) || (static_cast<int>(runtime) != 0 && static_cast<int>(runtime) % 7 == 0))
	{
		this->lines.push_back(Line(*this->window, LineTypes::DEFAULTLINE));
	}

	if (runtime >= 50 && static_cast<int>(runtime) % 4 == 0)
	{
		this->lines.push_back(Line(*this->window, LineTypes::DEFAULTLINE));
	}
	

	if (runtime != 0 && static_cast<int>(runtime) % 10 == 0)
	{
		for (size_t i = 0; i < 6; i++)
		{
			this->lines.push_back(Line(*this->window, LineTypes::PREPARING));
			lineSpawnTime = runtime;
		}
	}

	for (auto it = this->lines.begin(); it != this->lines.end(); /* ไม่มีการเพิ่ม iterator ในลูป */)
	{
		if (it->getType() == LineTypes::PREPARING)
		{
			if (runtime - lineSpawnTime > 1)
			{
				it->setType(LineTypes::DAMAGINGLINE);
			}
		}
		else if (it->getType() == LineTypes::DAMAGINGLINE)
		{
			if (runtime - lineSpawnTime > 2)
			{
				it = this->lines.erase(it);
				continue;
			}
		}

		++it;
	}
}


void Game::spawnSpike()
{
	//Spawn spike every 3 second.
	if (runtime != 0 && static_cast<int>(runtime) % 3 == 0)
	{
		for (size_t i = 0; i < 4; i++)
		{
			float yPosition = rand() % static_cast<int>(1200);

			// Check for overlapping spikes in y-axis
			bool overlap = false;
			for (const auto& spike : this->spikes)
			{
				if (abs(yPosition - spike->getPos().y) < 150.f) // Adjust the overlap threshold as needed
				{
					overlap = true;
					break;
				}
			}

			if (!overlap)
			{
				this->spikes.push_back(new Spike(1600, yPosition, this->randSpikeType()));

			}


		}
	}
	if (runtime != 0 && runtime >= 5 && static_cast<int>(runtime) % 3 == 0)
	{
		for (size_t i = 0; i < 2; i++)
		{
			float yPosition = rand() % static_cast<int>(900);

			// Check for overlapping spikes in y-axis
			bool overlap = false;
			for (const auto& spike : this->spikes)
			{
				if (abs(yPosition - spike->getPos().y) < 150.f) // Adjust the overlap threshold as needed
				{
					overlap = true;
					break;
				}
			}

			if (!overlap)
			{
				this->spikes.push_back(new Spike(1600, yPosition, this->randSpikeType()));

			}


		}
	}
}

void Game::spawnSmall()
{
	//Spawn small circle.
	if (static_cast<int>(runtime) % 1 == 0)
	{
		int randomY = rand() % this->window->getSize().y;
		this->smalls.push_back(new Small(1700, randomY, SmallTypes::DEFAULTSMALL));
	}
	if (static_cast<int>(runtime) % 2 == 0)
	{
		int randomY = rand() % this->window->getSize().y;
		this->smalls.push_back(new Small(1700, randomY, SmallTypes::DEFAULTSMALL));
	}
	if (runtime >= 60 && static_cast<int>(runtime) % 3 == 0)
	{
		int randomY = rand() % this->window->getSize().y;
		this->smalls.push_back(new Small(1700, randomY, SmallTypes::DEFAULTSMALL));
	}
}

void Game::spawnSquare()
{
	//Spawn small square.
	if (static_cast<int>(runtime) % 1 == 0)
	{
		int randomY = rand() % this->window->getSize().y;

		this->squares.push_back(new Square(-10, randomY, SquareTypes::DEFAULTSQUARE));
	}
	if (static_cast<int>(runtime) % 2 == 0)
	{
		int randomY = rand() % this->window->getSize().y;

		this->squares.push_back(new Square(-10, randomY, SquareTypes::DEFAULTSQUARE));
	}
	if (runtime >= 60 && static_cast<int>(runtime) % 3 == 0)
	{
		int randomY = rand() % this->window->getSize().y;

		this->squares.push_back(new Square(-10, randomY, SquareTypes::DEFAULTSQUARE));
	}
}



void Game::updateSpike()
{
	//Keep spike update.
	unsigned counter = 0;
	for (auto* spike : this->spikes)
	{
		spike->update();
		if (spike->getBound().left < 0 - spike->getBound().width)
		{
			//Delete enemies
			delete this->spikes.at(counter);
			this->spikes.erase(this->spikes.begin() + counter);
		}
		++counter;
	}
}

void Game::updateSmall()
{
	//Keep small ball updaate.
	unsigned counter = 0;
	for (auto* small : this->smalls)
	{
		small->update();
		if (small->getBound().left < 0 - small->getBound().width)
		{
			//Delete enemies
			delete this->smalls.at(counter);
			this->smalls.erase(this->smalls.begin() + counter);
		}
		++counter;
	}
}

void Game::updateSquare()
{
	//Keep small square update.
	unsigned counter = 0;
	for (auto* square : this->squares)
	{
		square->update();
		square->move(this->player->getPos());

		if (square->getType() == SquareTypes::DEFAULTSQUARE && square->getBound().left > this->window->getSize().x + square->getBound().width)
		{
			//Delete enemies 
			delete this->squares.at(counter);
			this->squares.erase(this->squares.begin() + counter);
		}
		else if (square->getType() == SquareTypes::SQUARE2 && square->getBound().left < 0 - square->getBound().width)
		{
			//Delete enemies 
			delete this->squares.at(counter);
			this->squares.erase(this->squares.begin() + counter);
		}
		else if (square->getType() == SquareTypes::SQUARE3 && square->getBound().top > window->getSize().y + square->getBound().height)
		{
			//Delete enemies 
			delete this->squares.at(counter);
			this->squares.erase(this->squares.begin() + counter);
		}
		++counter;
	}
}

void Game::updateRectangle()
{
	//Keep small square update.
	unsigned counter = 0;
	for (auto* rectangle : this->rectangles)
	{
		rectangle->update();

		if (rectangle->getBound().left > this->window->getSize().x + rectangle->getBound().width)
		{
			//Delete enemies 
			delete this->rectangles.at(counter);
			this->rectangles.erase(this->rectangles.begin() + counter);
		}
		else if (rectangle->getType() == RectangleTypes::DEFAULTRECTANGLE2 && rectangle->getBound().top > this->window->getSize().y + rectangle->getBound().height)
		{
			//Delete enemies
			delete this->rectangles.at(counter);
			this->rectangles.erase(this->rectangles.begin() + counter);
		}
		else if (rectangle->getType() == RectangleTypes::DEFAULTRECTANGLE3 && rectangle->getBound().top < -100)
		{
			//Delete enemies
			delete this->rectangles.at(counter);
			this->rectangles.erase(this->rectangles.begin() + counter);
		}
		else
			++counter;
	}
}

void Game::spawnSquare3()
{
	//Spawn small square.
	
	if (static_cast<int>(runtime) % 1 == 0)
	{
		for (int  i = 0; i < 3; i++)
		{
			int randomX = rand() % this->window->getSize().x;

			this->squares.push_back(new Square(randomX, -20, this->randSquareType()));
		}
		int randomX = rand() % this->window->getSize().x;
		this->squares.push_back(new Square(randomX, -20, SquareTypes::TRACKING));
	}
	if (runtime >= 45 && static_cast<int>(runtime) % 2 == 0)
	{
		for (int i = 0; i < 2; i++)
		{
			int randomX = rand() % this->window->getSize().x;

			this->squares.push_back(new Square(randomX, -20, this->randSquareType()));
		}
	}
	if (static_cast<int>(runtime) % 20 == 0 || static_cast<int>(runtime) == 3)
	{
		this->squares.push_back(new Square(700, -20, SquareTypes::MISSILE));
	}
}

void Game::spawnSpike3()
{
	//Spawn small square.
	if (static_cast<int>(runtime) % 4 == 0 && beatmap3)
	{
		int randomY = rand() % 500 + 200;
		this->spikes.push_back(new Spike(1700, randomY, SpikeTypes::CLOUD));
	}
	else if (static_cast<int>(runtime) % 4 == 0 && beatmap2)
	{
		this->spikes.push_back(new Spike(1700, 20, SpikeTypes::CLOUD));
	}
}

void Game::spawnLine3()
{
	if (static_cast<int>(runtime) % 5 == 0)
	{
		this->lines.push_back(Line(*this->window, LineTypes::BIGLINE1));
		biglineSpawnTime = runtime + 4;
	}
	if (biglineSpawnTime - 3 == runtime)
	{
		this->lines.push_back(Line(*this->window, LineTypes::BIGLINE1));
	}
	if (biglineSpawnTime == runtime) this->lines.clear();
}

void Game::spawnLineHeal()
{
	if (runtime != 0 && static_cast<int>(runtime) % 30 == 0)
	{
		this->lines.push_back(Line(*this->window, LineTypes::HEALING));
	}
}

void Game::updateButtonMain()
{
	if (this->pause == true)
	{
		//Resume Button
		if (resumeButton.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		{
			resumeButtonSelected = true;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				this->pause = false;
				this->music.play();
			}
		}
		else
		{
			resumeButtonSelected = false;
		}
		// Draw the exit button with a different color if selected
		if (resumeButtonSelected)
		{
			resumeButton.setColor(sf::Color(255, 255, 255)); // White when selected
		}
		else
		{
			resumeButton.setColor(sf::Color(188, 188, 188)); // Gray when not selected
		}

		//Leave Button
		if (leaveButton.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		{
			leaveButtonSelected = true;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				this->window->clear();
				playerNameText.setString("");
				this->resetGame();
				menuMusic.play();
			}

		}
		else
		{
			leaveButtonSelected = false;
		}
		// Draw the exit button with a different color if selected
		if (leaveButtonSelected)
		{
			leaveButton.setColor(sf::Color(255, 255, 255)); // White when selected
		}
		else
		{
			leaveButton.setColor(sf::Color(188, 188, 188)); // Gray when not selected
		}

		//Restart Button
		if (restartButton.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		{
			restartButtonSelected = true;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (this->beatmap1 == true)
				{
					this->window->clear();
					this->resetGame();
					selectBeatmap = false;
					beatmap1 = true;
					menuMusic.stop();
					initMusic();
				}
				else if (this->beatmap2 == true)
				{
					this->window->clear();
					this->resetGame();
					selectBeatmap = false;
					beatmap2 = true;
					menuMusic.stop();
					initMusic();
				}
				else if (this->beatmap3 == true)
				{
					this->window->clear();
					this->resetGame();
					selectBeatmap = false;
					beatmap3 = true;
					menuMusic.stop();
					initMusic();
				}
			}

		}
		else
		{
			restartButtonSelected = false;
		}
		// Draw the exit button with a different color if selected
		if (restartButtonSelected)
		{
			restartButton.setColor(sf::Color(255, 255, 255)); // White when selected
		}
		else
		{
			restartButton.setColor(sf::Color(188, 188, 188)); // Gray when not selected
		}
	}
	if (this->player->getHp() <= 0 || this->player->getIsWon() == true || this->leaderboard == true)
	{
		//Main menu Button
		if (mainmenuButton.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		{
			mainmenuButtonSelected = true;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				this->window->clear();
				if (!this->leaderboard)menuMusic.play();
				this->resetGame();
				this->gameOverMusic.stop();
				this->youWonMusic.stop();
			}
		}
		else
		{
			mainmenuButtonSelected = false;
		}
		// Draw the exit button with a different color if selected
		if (mainmenuButtonSelected)
		{
			mainmenuButton.setColor(sf::Color(255, 255, 255)); // White when selected
		}
		else
		{
			mainmenuButton.setColor(sf::Color(188, 188, 188)); // Gray when not selected
		}
	}
}

void Game::updateBall()
{

	for (size_t i = 0; i < this->balls.size(); i++)
	{
		// ตรวจสอบประเภทของลูกบอล
		if (this->balls[i].getType() == BallTypes::DAMAGING)
		{
			this->balls[i].move();
			//this->balls[i].resize();
			//this->balls[i].setPosition(sf::Vector2f(window->getSize().x / 2.f, window->getSize().y / 2.f));
		}
	}

}

void Game::updateLine()
{
	auto it = this->lines.begin();
	while (it != this->lines.end())
	{
		if (it->getType() == LineTypes::DEFAULTLINE || it->getType() == LineTypes::HEALING)
		{
			it->move();
			
		}
		if (it->getType() == LineTypes::BIGLINE1)
		{
			it->update();
		}
		if (it->getBound().left < 0)
		{
			it = this->lines.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void Game::spawnSmall2()
{
	//Spawn small square.
	if (static_cast<int>(runtime) % 1 == 0)
	{
		int randomY = rand() % 600 + 150;
		this->smalls.push_back(new Small(1600, randomY, this->randSmallType()));
		this->smalls.push_back(new Small(1600, randomY, SmallTypes::SMALLANGLE1));
		this->smalls.push_back(new Small(1600, randomY, SmallTypes::SMALLANGLE2));
		this->smalls.push_back(new Small(1600, randomY, SmallTypes::SMALLANGLE3));
		this->smalls.push_back(new Small(1600, randomY, SmallTypes::SMALLANGLE4));
	}

	if (runtime >= 30 && static_cast<int>(runtime) % 3 == 0)
	{
		int randomY = rand() % 600 + 150;
		this->smalls.push_back(new Small(1600, randomY, this->randSmallType()));
		this->smalls.push_back(new Small(1600, randomY, SmallTypes::SMALLANGLE1));
		this->smalls.push_back(new Small(1600, randomY, SmallTypes::SMALLANGLE2));
		this->smalls.push_back(new Small(1600, randomY, SmallTypes::SMALLANGLE3));
		this->smalls.push_back(new Small(1600, randomY, SmallTypes::SMALLANGLE4));
	}
}



void Game::spawnRectangle2()
{
	float yPosition = rand() % 1400 + 100.f;

	if (runtime != 0 && static_cast<int>(runtime) % 8 == 0 || runtime == 3)
	{
		this->rectangles.push_back(new Rectangle(0, 400, RectangleTypes::PREPARINGRECTANGLE));
		this->rectangles.push_back(new Rectangle(400, 0, RectangleTypes::PREPARINGRECTANGLE2));
		this->rectangles.push_back(new Rectangle(1200, 0, RectangleTypes::PREPARINGRECTANGLE2));
		this->preparingRecSpawnTime = runtime;
	}
	if (runtime == preparingRecSpawnTime + 1)
	{
		this->rectangles.push_back(new Rectangle(1180, 1000, RectangleTypes::DEFAULTRECTANGLE3));
		this->rectangles.push_back(new Rectangle(380, -100, RectangleTypes::DEFAULTRECTANGLE2));
		this->rectangles.push_back(new Rectangle(1700, 380, RectangleTypes::DEFAULTRECTANGLE));
	}

	if (runtime == preparingRecSpawnTime + 2)
	{
		this->rectangles.clear();
	}

	if (runtime == preparingRecSpawnTime + 3)
	{
		this->rectangles.push_back(new Rectangle(0, 150, RectangleTypes::PREPARINGRECTANGLE));
		this->rectangles.push_back(new Rectangle(0, 550, RectangleTypes::PREPARINGRECTANGLE));
	}

	if (runtime == preparingRecSpawnTime + 4)
	{
		this->rectangles.push_back(new Rectangle(1700, 130, RectangleTypes::DEFAULTRECTANGLE));
		this->rectangles.push_back(new Rectangle(1700, 530, RectangleTypes::DEFAULTRECTANGLE));
	}

	if (runtime == preparingRecSpawnTime + 5)
	{
		this->rectangles.clear();
	}
}

void Game::spawnSquare2()
{
	if (static_cast<int>(runtime) % 1 == 0)
	{
		for (size_t i = 0; i < 3; i++)
		{
			int randomY = rand() % this->window->getSize().y;
			this->squares.push_back(new Square(1610, randomY, SquareTypes::SQUARE2));
		}
	}
	if (runtime >= 45 && static_cast<int>(runtime) % 2 == 0)
	{
		for (size_t i = 0; i < 2; i++)
		{
			int randomY = rand() % this->window->getSize().y;
			this->squares.push_back(new Square(1610, randomY, SquareTypes::SQUARE2));
		}
	}
}






void Game::updateCollision()
{
	//Check the collision with ball
	for (size_t i = 0; i < this->balls.size(); i++)
	{
		if (this->player->getBound().intersects(this->balls[i].getShape().getGlobalBounds()))
		{
			switch (this->balls[i].getType())
			{
			case BallTypes::DAMAGING:
				if (this->readyToHit)
				{
					this->player->loseHp(1);
					
					this->ifrrameCooldown = 0;
					this->readyToHit = false;
				}
				break;
			}
		}
	}

	//Check the collision with spike.
	for (size_t i = 0; i < this->spikes.size(); i++)
	{
		if (this->player->getBound().intersects(this->spikes[i]->getBound()))
		{
			if (this->readyToHit)
			{
				this->player->loseHp(1);
				this->ifrrameCooldown = 0;
				this->readyToHit = false;
			}
		}
	}

	//Check the collision with small ball.
	for (size_t i = 0; i < this->smalls.size(); i++)
	{
		if (this->player->getBound().intersects(this->smalls[i]->getBound()))
		{
			if (this->smalls[i]->getType() == SmallTypes::CLEAR)
			{
				this->lines.clear();
				this->smalls.clear();
				this->squares.clear();
				this->rectangles.clear();
			}
			else if (this->readyToHit)
			{
				this->player->loseHp(1);
				this->ifrrameCooldown = 0;
				this->readyToHit = false;
			}
		}
	}

	//Check the collision with small square.
	for (size_t i = 0; i < this->squares.size(); i++)
	{
		if (this->player->getBound().intersects(this->squares[i]->getBound()))
		{
			if (this->squares[i]->getType() == SquareTypes::MISSLECLEAR)
			{
				this->squares.clear();
			}
			else if (this->readyToHit)
			{
				this->player->loseHp(1);
				this->ifrrameCooldown = 0;
				this->readyToHit = false;
				if (this->squares[i]->getType() == SquareTypes::MISSILE) std::cout << "Boom\n";
			}
		}
	}

	//Check the collision with Line;
	for (size_t i = 0; i < this->lines.size(); i++)
	{
		if (this->player->getBound().intersects(this->lines[i].getShape().getGlobalBounds()))
		{
			switch (this->lines[i].getType())
			{
			case LineTypes::DEFAULTLINE:
				if (this->readyToHit)
				{
					this->player->loseHp(1);
					this->ifrrameCooldown = 0;
					this->readyToHit = false;
				}
				break;
			case LineTypes::HEALING:
				this->player->music.stop();
				this->player->knockbackDistance = 0;
				this->player->healHp();
				if(beatmap1 || beatmap2) this->player->healHp();
				this->ifrrameCooldown = 0;
				this->readyToHit = false;
				this->lines.clear();
				break;
			case LineTypes::BIGLINE1:
				if (this->lines[i].getSize().x >= 400 && this->readyToHit)
				{
					this->player->loseHp(1); 
					this->ifrrameCooldown = 0;
					this->readyToHit = false;
				}
				break;
			}
		}
	}

	//Check the collision with rectangle
	for (size_t i = 0; i < this->rectangles.size(); i++)
	{
		if (this->player->getBound().intersects(this->rectangles[i]->getBound()))
		{
			switch (this->rectangles[i]->getType())
			{
			case RectangleTypes::DEFAULTRECTANGLE:
				if (this->readyToHit)
				{
					this->player->loseHp(1);
					this->ifrrameCooldown = 0;
					this->readyToHit = false;
				}
				break;
			}
		}
	}

}



void Game::updateGUI()
{
	std::stringstream ss;


	ss << "Time : " << std::fixed << std::setprecision(0) << this->runtime << "\n"
		<< "Point : " << this->point;

	this->timeText.setString(ss.str());

	float GamePercent = runtime / 187.0f;
	this->gameProcessBar.setSize(sf::Vector2f(600.0f * GamePercent, this->gameProcessBar.getSize().y));
}

//Update / Render
void Game::update()
{

	//Update only 1 time in each second.
	this->elapsedUpdateTime = updateTimeClock.getElapsedTime();
	if (std::floor(elapsedUpdateTime.asSeconds()) >= 1.0f)
	{
		if (this->player->getHp() > 0 && this->player->getIsWon() == false)this->runtime += 1.f;
		if (runtime > 2.f)
		{
			if (beatmap1)
			{
				this->spawnBall();
				this->spawnLine();
				this->spawnLineHeal();
				this->spawnSpike();
				this->spawnSmall();
				this->spawnSquare();

			}
			else if (beatmap2)
			{
				this->spawnSmall2();
				this->spawnRectangle2();
				this->spawnSquare2();
				this->spawnLine();
				this->spawnLineHeal();
				this->spawnSpike3();
			}
			else if (beatmap3)
			{
				this->spawnSquare3();
				this->spawnSpike3();
				this->spawnLine3();
				this->spawnLineHeal();
			}
		}
		if (beatmap2)
		{
			if (!wave)this->spikes.push_back(new Spike(0, 704, SpikeTypes::WAVE));
			this->wave = true;
		}
		if (beatmap3)
		{
			if (!cloudBackground)this->spikes.push_back(new Spike(0, -50, SpikeTypes::CLOUDBACKGROUND));
			this->cloudBackground = true;
		}
		this->point += this->player->getHp();

		updateTimeClock.restart();
	}

	//Update Game
	this->updateInput();
	this->updatePlayerCollision();
	this->player->update();
	if (!this->readyToHit) this->player->blinking();
	else this->player->setColor();
	this->updateCollision();
	this->iframe();
	if (this->beatmap2) this->player->move(-0.3f, 0.f);
	if (this->beatmap3) this->player->move(0.f, 0.4f);
	if (beatmap1)
	{
		this->updateBall();
		this->updateLine();
		this->updateSpike();
		this->updateSmall();
		this->updateSquare();
	}
	else if (beatmap2)
	{
		this->updateSmall();
		this->updateRectangle();
		this->updateSquare();
		this->updateSpike();
		this->updateLine();
	}
	else if (beatmap3)
	{
		this->updateSquare();
		this->updateSpike();
		this->updateLine();
	}
	if (this->player->getHp() > 0 && this->player->getIsWon() == false) this->updateGUI();
}

void Game::renderWorld()
{
	if (this->beatmap1)this->window->draw(this->worldBackgroud);
	else if (this->beatmap2)this->window->draw(this->worldBackgroud2);
	else if(this->entername) this->window->draw(this->enterWorldBackgroud);
	else if (this->entername2) this->window->draw(this->enterWorldBackgroud2);
	else if (this->entername3) this->window->draw(this->enterWorldBackgroud);
	else if (this->leaderboard) this->window->draw(this->leaderboardBackgroud);
	else this->window->draw(this->worldBackgroud);
}

void Game::renderBall()
{
	for (auto ball : this->balls)
	{
		ball.render(*this->window);
	}
}

void Game::renderLine()
{
	for (auto line : this->lines)
	{
		line.render(*this->window);
	}
}

void Game::renderSpike()
{
	for (auto* spike : this->spikes)
	{
		spike->render(this->window);
	}
}

const int Game::randSpikeType() const
{
	int type = SpikeTypes::DEFAULTSPIKE;
	int randValue = rand() % 100 + 1;
	if (randValue > 0 && randValue <= 30)
		type = SpikeTypes::SPIKE2;
	return type;
}

const int Game::randSmallType() const
{
	int type = SmallTypes::DEFAULTSMALL;
	int randValue = rand() % 100 + 1;
	if (randValue > 0 && randValue <= 20)
		type = SmallTypes::CLEAR;
	return type;
}

const int Game::randSquareType() const
{
	int type = SquareTypes::SQUARE3;
	int randValue = rand() % 100 + 1;
	if (randValue > 0 && randValue <= 10)
		type = SquareTypes::MISSLECLEAR;
	return type;
}

void Game::renderSmall()
{
	for (auto* small : this->smalls)
	{
		small->render(this->window);
	}
}

void Game::renderRectangle()
{
	for (auto* rectangle : this->rectangles)
	{
		rectangle->render(*this->window);
	}
}

void Game::renderSquare()
{
	for (auto* square : this->squares)
	{
		square->render(this->window);
	}
}

void Game::renderGUI()
{
	this->window->draw(this->timeText);
	this->window->draw(this->gameProcessBarBack);
	this->window->draw(this->gameProcessBar);
}

void Game::render()
{
	this->window->clear();

	this->renderWorld();

	this->player->render(*this->window);

	if (beatmap1)
	{
		this->renderBall();

		this->renderLine();

		this->renderSpike();

		this->renderSmall();

		this->renderSquare();
	}
	else if (beatmap2)
	{
		this->renderSmall();

		this->renderRectangle();

		this->renderSquare();

		this->renderSpike();

		this->renderSpike();

		this->renderLine();
	}
	else if (beatmap3)
	{
		this->renderSquare();

		this->renderSpike();

		this->renderLine();

	}
	//Title Start
	if (runtime < 2.f)
	{
		if (this->beatmap1) this->window->draw(this->titleText);
		if (this->beatmap2) this->window->draw(this->titleText2);
		if (this->beatmap3) this->window->draw(this->titleText3);
	}


	else if (runtime >= 2.f && this->player->getHp() > 0)
	{
		if (this->beatmap1)
		{
			this->titleText.setCharacterSize(25);
			this->titleText.setPosition(
				this->window->getSize().x / 2.f - this->titleText.getGlobalBounds().width / 2.f, 5);
			this->window->draw(this->titleText);
		}

		if (this->beatmap2)
		{
			this->titleText2.setCharacterSize(25);
			this->titleText2.setPosition(
				this->window->getSize().x / 2.f - this->titleText2.getGlobalBounds().width / 2.f, 5);
			this->window->draw(this->titleText2);
		}

		if (this->beatmap3)
		{
			this->titleText3.setCharacterSize(25);
			this->titleText3.setPosition(
				this->window->getSize().x / 2.f - this->titleText3.getGlobalBounds().width / 2.f, 5);
			this->window->draw(this->titleText3);
		}
	}



	this->renderGUI();

	if (pause == true)
	{
		this->window->draw(pausedMenu);
		this->window->draw(leaveButton);
		this->window->draw(resumeButton);
		this->window->draw(restartButton);

	}



	//Game over screen
	if (this->player->getHp() <= 0)
	{
		if (gameOverSound)
		{
			this->gameOverMusic.play();
			this->gameOverSound = false;
		}
		this->window->clear();
		if(this->beatmap1)this->window->draw(this->gameOverScreen1);
		if (this->beatmap2)this->window->draw(this->gameOverScreen2);
		if (this->beatmap3)this->window->draw(this->gameOverScreen3);
		this->timeText.setCharacterSize(60);
		this->timeText.setPosition(
			this->window->getSize().x / 2.f - this->timeText.getGlobalBounds().width / 2.f - 420,
			this->window->getSize().y / 2.f - this->timeText.getGlobalBounds().height / 2.f + 140);
		this->window->draw(this->timeText);
		this->window->draw(this->mainmenuButton);
		mainmenuButton.setPosition(
			this->window->getSize().x / 2.f - this->mainmenuButton.getGlobalBounds().width / 2.f - 410,
			this->window->getSize().y / 2.f - this->mainmenuButton.getGlobalBounds().height / 2.f + 350);
		this->window->draw(mainmenuButton);
		music.stop();

		this->updateName();
		

	}

	//Game Finish
	if (runtime >= 180)
	{
		this->window->clear();
		if (youWonSound)
		{
			this->youWonMusic.play();
			this->youWonSound = false;
		}
		this->player->isWonFunc();
		if (this->beatmap1)this->window->draw(this->youWonScreen1);
		if (this->beatmap2)this->window->draw(this->youWonScreen2);
		if (this->beatmap3)this->window->draw(this->youWonScreen3);
		this->timeText.setCharacterSize(60);
		this->timeText.setPosition(
			this->window->getSize().x / 2.f - this->timeText.getGlobalBounds().width / 2.f - 420,
			this->window->getSize().y / 2.f - this->timeText.getGlobalBounds().height / 2.f + 140);
		this->window->draw(this->timeText);
		this->window->draw(this->mainmenuButton);
		mainmenuButton.setPosition(
			this->window->getSize().x / 2.f - this->mainmenuButton.getGlobalBounds().width / 2.f - 410,
			this->window->getSize().y / 2.f - this->mainmenuButton.getGlobalBounds().height / 2.f + 350);
		this->window->draw(mainmenuButton);
		music.stop();

		this->updateName();
	}






	this->window->display();
}


/// Menu
void Game::renderMenuBackground()
{
	this->window->draw(this->menu);
}

void Game::updateButton()
{
	if (selectBeatmap == false)
	{
		//Play Button
		if (playButton.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		{
			playButtonSelected = true;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				this->selectBeatmap = true;
			}
		}
		else
		{
			playButtonSelected = false;
		}
		// Draw the play button with a different color if selected
		if (playButtonSelected)
		{
			playButton.setColor(sf::Color(255, 255, 255)); // White when selected
		}
		else
		{
			playButton.setColor(sf::Color(188, 188, 188)); // Gray when not selected
		}

		//Leaderboard Button
		if (leaderboardButton.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		{
			leaderboardButtonSelected = true;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				this->leaderboard = true;
			}
		}
		else
		{
			leaderboardButtonSelected = false;
		}
		// Draw the leaderboard button with a different color if selected
		if (leaderboardButtonSelected)
		{
			leaderboardButton.setColor(sf::Color(255, 255, 255)); // White when selected
		}
		else
		{
			leaderboardButton.setColor(sf::Color(188, 188, 188)); // Gray when not selected
		}

		//Exit Button
		if (exitButton.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		{
			exitButtonSelected = true;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				this->window->close();
			}
		}
		else
		{
			exitButtonSelected = false;
		}
		// Draw the exit button with a different color if selected
		if (exitButtonSelected)
		{
			exitButton.setColor(sf::Color(255, 255, 255)); // White when selected
		}
		else
		{
			exitButton.setColor(sf::Color(188, 188, 188)); // Gray when not selected
		}

	}
	if (this->tutorialMenu)
	{
		//Main menu Button
			if (entergameButton.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
			{
				entergameButtonSelected = true;

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					this->window->clear();
					this->tutorialMenu = false;
				}
			}
			else
			{
				entergameButtonSelected = false;
			}
			// Draw the exit button with a different color if selected
			if (entergameButtonSelected)
			{
				entergameButton.setColor(sf::Color(255, 255, 255)); // White when selected
			}
			else
			{
				entergameButton.setColor(sf::Color(188, 188, 188)); // Gray when not selected
			}
	}


}

void Game::updateMenu()
{
	this->updateButton();
	
}

void Game::renderMenu()
{
	this->window->clear();
	this->renderMenuBackground();
	this->window->draw(playButton);
	this->window->draw(leaderboardButton);
	this->window->draw(exitButton);
	if (tutorialMenu) 
	{
		this->window->draw(tutorialSceen);
		this->window->draw(entergameButton);
	}
	this->window->display();
}

void Game::updateSelectBeatmap()
{
	if (this->cooldownButton == 100)this->updateButton2();
	else if (this->cooldownButton <= 100)this->cooldownButton += 10;
}

void Game::updateButton2()
{
	if (selectBeatmap == true)
	{
		// BeatmapButton1 Button
		if (beatmapButton1.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		{
			beatmapButtonSelected1 = true;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				
				entername = true;
				selectBeatmap = false;
				
			}
		}
		else
		{
			beatmapButtonSelected1 = false;
		}
		if (beatmapButtonSelected1)
		{
			beatmapButton1.setColor(sf::Color(255, 255, 255)); // White when selected
		}
		else
		{
			beatmapButton1.setColor(sf::Color(188, 188, 188)); // Gray when not selected
		}

		// BeatmapButton2 Button
		if (beatmapButton2.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		{
			beatmapButtonSelected2 = true;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				
				selectBeatmap = false;
				entername2 = true;
				
			}
		}
		else
		{
			beatmapButtonSelected2 = false;
		}
		if (beatmapButtonSelected2)
		{
			beatmapButton2.setColor(sf::Color(255, 255, 255)); // White when selected
		}
		else
		{
			beatmapButton2.setColor(sf::Color(188, 188, 188)); // Gray when not selected
		}

		// BeatmapButton3 Button
		if (beatmapButton3.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		{
			beatmapButtonSelected3 = true;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				
				entername3 = true;
				selectBeatmap = false;
				
			}
		}
		else
		{
			beatmapButtonSelected3 = false;
		}
		if (beatmapButtonSelected3)
		{
			beatmapButton3.setColor(sf::Color(255, 255, 255)); // White when selected
		}
		else
		{
			beatmapButton3.setColor(sf::Color(188, 188, 188)); // Gray when not selected
		}
	}
}

void Game::renderSelectBeatmap()
{
	this->window->clear();
	this->window->draw(beatmapButton1);
	this->window->draw(beatmapButton2);
	this->window->draw(beatmapButton3);
	this->window->display();
}