#include "Game.h"


void Game::initVariable()
{
	//Game Status
	this->endGame = false;
	this->beatmap1 = false;
	this->beatmap2 = false;
	this->beatmap3 = false;
	this->selectBeatmap = false;
	this->pause = false;
	this->escHeld = false;

	//Game Logic
	this->runtime = 0.f;
	this->lastBallUpdate = 0;
	this->lastLostHealth = 0;
	this->lastEsc = 0;
	this->lastClick = 0;
	this->lastDashTime = 0;
	this->cooldownButton = 0;
	this->preparingRecSpawnTime = 5;
	this->spaceKeyPressed = false;
	this->point = 0;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->music1 = false;
	this->playButtonSelected = false;
	this->beatmapButtonSelected1 = false;
	this->beatmapButtonSelected2 = false;
	this->beatmapButtonSelected3 = false;
	this->resumeButtonSelected = false;
	this->leaveButtonSelected = false;
	this->mainmenuButtonSelected = false;
	this->restartButtonSelected = false;
	this->wave = false;

	this->leaderboardButtonSelected = false;
	this->exitButtonSelected = false;
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
	
		
	
	this->worldBackgroud.setTexture(this->worldBackgroudTex);
	this->worldBackgroud2.setTexture(this->worldBackgroudTex2);
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

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initWindow()
{
	//Window
	this->videoMode = sf::VideoMode(1600, 900);
	this->window = new sf::RenderWindow(this->videoMode, "Just Beat and Shape!", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	this->window->setFramerateLimit(60);
}

void Game::initGUI()
{
	//Load font
	if (!this->font.loadFromFile("Font/Nexa-ExtraLight.ttf"))
		std::cout << "ERROR::GAME::Failed to load font" << "\n";
	//Init point text
	this->timeText.setFont(this->font);
	this->timeText.setCharacterSize(24);
	this->timeText.setFillColor(sf::Color::White);
	this->timeText.setString("test");
	this->timeText.setPosition(5,5);


	//Game over Text
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(84);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("GAME OVER");
	this->gameOverText.setPosition(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f);

	//Win Text
	this->winText.setFont(this->font);
	this->winText.setCharacterSize(84);
	this->winText.setFillColor(sf::Color::Green);
	this->winText.setString("YOU WIN");
	this->winText.setPosition(
		this->window->getSize().x / 2.f - this->winText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->winText.getGlobalBounds().height / 2.f);

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
		this->window->getSize().x / 2.f - this->leaveButton.getGlobalBounds().width / 2.f ,
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
	this->player->initVariable();
	this->player->initShape();
	this->balls.clear();
	this->lines.clear();
	this->spikes.clear();
	this->smalls.clear();
	this->squares.clear();
	this->rectangles.clear();
}

//Con / Decon
Game::Game()
{
	this->initVariable();
	this->initWorld();
	this->initMenu();
	this->initMenuMusic();
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
			if (beatmap1 == false && selectBeatmap == false && beatmap2 == false && beatmap3 == false)
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
				if(pause == false) this->update();
				this->updateButtonMain();
			}			
		}
}



void Game::playMusic()
{
	//Play music
	if(music1)
		music.play();
}

void Game::updatePollEvents()
{
	
	while (this->window->pollEvent(sfmlEvent))
	{
		if (sfmlEvent.Event::type == sf::Event::Closed)
			this->window->close();
		// Pause Game
		if (sfmlEvent.Event::KeyPressed && sfmlEvent.Event::key.code == sf::Keyboard::Escape)
		{
			this->elaspedPollingTime = pollingClock.getElapsedTime();
			if (elaspedPollingTime.asMilliseconds() > lastEsc) // Compare elapsed time in seconds
			{
				this->pause = !this->pause;
				if (this->pause == true)
				{
					this->music.pause();
				}
				if (this->pause == false)
					this->music.play();
				lastEsc = elaspedPollingTime.asMilliseconds() + 200;
			}
		}
		if (sfmlEvent.Event::KeyPressed && sfmlEvent.Event::key.code == sf::Keyboard::O) 
		{
			this->selectBeatmap = true;
			if (this->player->getHp() <= 0) 
			{
				this->window->clear();
				this->resetGame();
				menuMusic.play();
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
				lastLostHealth = runtime + 0.3f;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				sf::Vector2f dashDirection(1.f, 0.f);
				this->player->dash(dashDirection, 70.f, 18.f);
				lastLostHealth = runtime + 0.3f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				sf::Vector2f dashDirection(0.f, -1.f);
				this->player->dash(dashDirection, 70.f, 18.f);
				lastLostHealth = runtime + 0.3f;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				sf::Vector2f dashDirection(0.f, 1.f);
				this->player->dash(dashDirection, 70.f, 18.f);
				lastLostHealth = runtime + 0.5f;
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
	if (runtime != 0 && static_cast<int>(runtime) % 30 == 0)
	{
		this->lines.push_back(Line(*this->window, LineTypes::HEALING));
	}

	if (runtime != 0 && static_cast<int>(runtime) % 10 == 0)
	{
		for (size_t i = 0; i < 6; i++)
		{
			this->lines.push_back(Line(*this->window, LineTypes::PREPARING));
			lineSpawnTime = runtime; // กำหนด lineSpawnTime เมื่อสร้าง Line PREPARING
		}
	}

	// เพิ่มการตรวจสอบและการลบ DAMAGINGLINE ที่มีอายุเกิน 1 วินาที
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
			float yPosition = rand() % static_cast<int>(this->window->getSize().y - 50.f);

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
				this->spikes.push_back(new Spike(1600, yPosition,this->randSpikeType()));
				
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
		this->smalls.push_back(new Small(1700, randomY,SmallTypes::DEFAULTSMALL));
		
	}
}

void Game::spawnSquare()
{
	//Spawn small square.
	if (static_cast<int>(runtime) % 1 == 0)
	{
		int randomY = rand() % this->window->getSize().y;
		
		this->squares.push_back(new Square(-10, randomY,SquareTypes::DEFAULTSQUARE));
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
		square->move();
		
		if (square->getBound().left > this->window->getSize().x + square->getBound().width)
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
	if (this->player->getHp() <= 0)
	{
		//Main menu Button
		if (mainmenuButton.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y))
		{
			mainmenuButtonSelected = true;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				this->window->clear();
				this->resetGame();
				menuMusic.play();
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
}

void Game::spawnBall2()
{
	//Spawn spike every 3 second.
	if (runtime != 0 && static_cast<int>(runtime) % 3 == 0)
	{
		this->spikes.push_back(new Spike(1600, 10, SpikeTypes::BIGCIRCLE));
	}
}

void Game::spawnRectangle2()
{
	float yPosition = rand() % 1400 + 100.f;

	if (runtime != 0 && static_cast<int>(runtime) % 4 == 0)
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
}

void Game::spawnSquare2()
{
	if (static_cast<int>(runtime) % 1 == 0)
	{
		int randomY = rand() % this->window->getSize().y;
		int randomY2 = rand() % this->window->getSize().y;

		this->squares.push_back(new Square(1610, randomY, SquareTypes::SQUARE2));
		this->squares.push_back(new Square(1610, randomY2, SquareTypes::SQUARE2));
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
					if (runtime - lastLostHealth > 1)
					{
						this->player->loseHp(1);
						lastLostHealth = runtime;
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
			if (runtime - lastLostHealth > 1.5f)
			{
				this->player->loseHp(1);
				lastLostHealth = runtime;
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
			else if (runtime - lastLostHealth > 1.5f)
			{
				this->player->loseHp(1);
				lastLostHealth = runtime;
			}
		}
	}

	//Check the collision with small square.
	for (size_t i = 0; i < this->squares.size(); i++)
	{
		if (this->player->getBound().intersects(this->squares[i]->getBound()))
		{
			if (runtime - lastLostHealth > 1.5f)
			{
				this->player->loseHp(1);
				lastLostHealth = runtime;
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
				if (runtime - lastLostHealth > 1)
				{
					this->player->loseHp(1);
					lastLostHealth = runtime;
				}
				break;
			case LineTypes::HEALING:
				this->lines.erase(this->lines.begin() + i);
				this->lastLostHealth = runtime + 1;
				this->player->healHp();
				
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
				if (runtime - lastLostHealth > 1)
				{
					this->player->loseHp(1);
					lastLostHealth = runtime;
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
		if(this->player->getHp() > 0)this->runtime += 1.f;
		if (runtime > 2.f)
		{
			if (beatmap1) 
			{
				this->spawnBall();
				this->spawnLine();
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
				//this->spawnBall2();
			}
		}
		if (beatmap2)
		{
			if (!wave)this->spikes.push_back(new Spike(0, 704, SpikeTypes::WAVE));
			this->wave = true;
		}
		this->point += this->player->getHp();

		updateTimeClock.restart(); 
	}
	
	//Update Game
	this->updateInput();
	this->updatePlayerCollision();
	this->player->update();
	this->updateCollision();
	if(this->beatmap2) this->player->move(-0.3f, 0.f);
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
	this->updateGUI();
}

void Game::renderWorld()
{
	if (this->beatmap1 == true)this->window->draw(this->worldBackgroud);
	else if (this->beatmap2 == true)this->window->draw(this->worldBackgroud2);
	else this->window->draw(this->worldBackgroud);
}

void Game::renderBall()
{
	for (auto ball : this->balls)
	{
		ball .render(*this->window);
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
		this->player->render(*this->window);
		this->window->clear();
		this->window->draw(this->gameOverText);
		this->timeText.setPosition(
			this->window->getSize().x / 2.f - this->timeText.getGlobalBounds().width / 2.f + 80,
			this->window->getSize().y / 2.f - this->timeText.getGlobalBounds().height / 2.f + 84 );
		this->window->draw(this->timeText);
		this->window->draw(this->mainmenuButton);
		this->window->draw(mainmenuButton);
		music.stop();
	}

	//Game Finish
	if (runtime >= 187)
	{
		this->window->clear();
		
		this->window->draw(this->winText);
		this->timeText.setPosition(
			this->window->getSize().x / 2.f - this->timeText.getGlobalBounds().width / 2.f + 80,
			this->window->getSize().y / 2.f - this->timeText.getGlobalBounds().height / 2.f + 84);
		this->window->draw(this->timeText);
		this->window->draw(this->mainmenuButton);
		this->window->draw(mainmenuButton);
		music.stop();
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
				selectBeatmap = true;
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
				// Handle leaderboard button click
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

	this->window->display();
}

void Game::updateSelectBeatmap()
{
	if (this->cooldownButton == 100)this->updateButton2();
	else if(this->cooldownButton <= 100)this->cooldownButton += 10;
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
				selectBeatmap = false;
				beatmap1 = true;
				menuMusic.stop();
				initMusic();
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
				beatmap2 = true;
				menuMusic.stop();
				initMusic();
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
				selectBeatmap = false;
				beatmap3 = true;
				menuMusic.stop();
				initMusic();
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