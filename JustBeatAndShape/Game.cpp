#include "Game.h"


void Game::initVariable()
{
	this->endGame = false;
	this->lastBallUpdate = 0;
	this->lastLostHealth = 0;
	this->spaceKeyPressed = false;
	this->point = 0;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->beatmap1 = false;
	this->music1 = false;
}

void Game::initWorld()
{
	//Load a texture from file
	if (!this->worldBackgroudTex.loadFromFile("Texture/world.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	this->worldBackgroud.setTexture(this->worldBackgroudTex);
}

void Game::initMenu()
{
	//Load a texture from file
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

	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(60);
	this->gameOverText.setFillColor(sf::Color::Red);
	this->gameOverText.setString("GAME OVER");
	this->gameOverText.setPosition(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f);

	//Init player GUI
	this->gameProcessBar.setSize(sf::Vector2f(600.f, 10.f));
	this->gameProcessBar.setFillColor(sf::Color::White);
	this->gameProcessBar.setPosition(500.f, 40.f);


	this->gameProcessBarBack.setSize(sf::Vector2f(600.f, 10.f));
	this->gameProcessBarBack.setFillColor(sf::Color(25, 25, 25, 200));
	this->gameProcessBarBack.setPosition(500.f, 40.f);

}

void Game::initMusic()
{
	if (!this->music.openFromFile("Music/music.ogg"))
	{
		std::cout << "ERROR::GAME::INITMUSIC::COULD NOT LOAD a.ogg" << "\n";
	}
	music.setVolume(10);
	music.play();
}

void Game::initMenuMusic()
{
	if (!this->menuMusic.openFromFile("Music/menu.ogg"))
	{
		std::cout << "ERROR::GAME::INITMUSIC::COULD NOT LOAD a.ogg" << "\n";
	}
	menuMusic.setVolume(10);
	menuMusic.play();
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
}

Game::~Game()
{
}

//Run
void Game::run()
{

		while (this->window->isOpen())
		{
			this->updatePollEvents();
			if (beatmap1 == true)
			{	
				this->update();
				this->render();
			}
			if (beatmap1 == false)
			{
				this->updateMenu();
				this->renderMenu();
			}
		}
}



void Game::playMusic()
{
	if(music1 == 1)
		music.play();
}

void Game::updatePollEvents()
{
	while (this->window->pollEvent(sfmlEvent))
	{
		if (sfmlEvent.Event::type == sf::Event::Closed)
			this->window->close();
		if (sfmlEvent.Event::KeyPressed && sfmlEvent.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
		if (sfmlEvent.Event::KeyPressed && sfmlEvent.Event::key.code == sf::Keyboard::O)
		{
			this->beatmap1 = true;
			this->menuMusic.stop();
			this->initMusic();
			updateTimeClock.restart();
			clock.restart();
		}
			
	}
}

void Game::updateInput()
{
	//Move Player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f, 0.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (!spaceKeyPressed)  // ตรวจสอบว่าปุ่ม Space ถูกกดครั้งแรกหรือไม่
		{
			spaceKeyPressed = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				sf::Vector2f dashDirection(-1.f, 0.f);
				this->player->dash(dashDirection, 50.f, 12.f);
				lastLostHealth = elapsedSeconds + 1.f;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				sf::Vector2f dashDirection(1.f, 0.f);
				this->player->dash(dashDirection, 50.f, 12.f);
				lastLostHealth = elapsedSeconds + 1.f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				sf::Vector2f dashDirection(0.f, -1.f);
				this->player->dash(dashDirection, 50.f, 12.f);
				lastLostHealth = elapsedSeconds + 1.f;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				sf::Vector2f dashDirection(0.f, 1.f);
				this->player->dash(dashDirection, 50.f, 12.f);
				lastLostHealth = elapsedSeconds + 1.f;
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
	float ballSpawnTime = 0;

	if (elapsedSeconds != 0 && elapsedSeconds % 5 == 0 )
	{
		this->balls.clear();
		for (size_t i = 0; i < 2; i++)
		{
			this->balls.push_back(Ball(*this->window, BallTypes::DEFAULT));
		}
		ballSpawnTime = elapsedSeconds;
	}
	if (elapsedSeconds - ballSpawnTime > 4)
	{
		for (Ball& ball : balls)
		{
			ball.setType(BallTypes::DAMAGING);
		}
		
	}
	

	
}

void Game::spawnSpike()
{
	if (elapsedSeconds != 0 && elapsedSeconds % 3 == 0)
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
				this->spikes.push_back(new Spike(1600, yPosition));
			}
		}
	}
}

void Game::spawnSmall()
{
	if (elapsedSeconds % 1 == 0)
	{
		int randomY = rand() % this->window->getSize().y;
		this->smalls.push_back(new Small(1700, randomY));
		
	}
}

void Game::spawnSquare()
{
	if (elapsedSeconds % 1 == 0)
	{
		int randomY = rand() % this->window->getSize().y;
		
		this->squares.push_back(new Square(-10, randomY));
	}
}

void Game::updateSpike()
{
	//Update
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
	//Update
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
	//Update
	unsigned counter = 0;
	for (auto* square : this->squares)
	{
		square->update();
		square->move(1);
		
		if (square->getBound().left > this->window->getSize().x + square->getBound().width)
		{
			//Delete enemies 
			delete this->squares.at(counter);
			this->squares.erase(this->squares.begin() + counter);
		}
		++counter;
	}
}

void Game::updateCollision()
{
	//Check the collision
	for (size_t i = 0; i < this->balls.size(); i++)
	{
		if (this->player->getBound().intersects(this->balls[i].getShape().getGlobalBounds()))
		{
			switch (this->balls[i].getType())
			{
				case BallTypes::DAMAGING:
					if (elapsedSeconds - lastLostHealth > 1)
					{
						this->player->loseHp(1);
						lastLostHealth = elapsedSeconds;
					}
					break;
			}
		}
	}

	for (size_t i = 0; i < this->spikes.size(); i++)
	{
		if (this->player->getBound().intersects(this->spikes[i]->getBound()))
		{
			if (elapsedSeconds - lastLostHealth > 1.5f)
			{
				this->player->loseHp(1);
				lastLostHealth = elapsedSeconds;
			}
		}
	}

	for (size_t i = 0; i < this->smalls.size(); i++)
	{
		if (this->player->getBound().intersects(this->smalls[i]->getBound()))
		{
			if (elapsedSeconds - lastLostHealth > 1.5f)
			{
				this->player->loseHp(1);
				lastLostHealth = elapsedSeconds;
			}
		}
	}

	for (size_t i = 0; i < this->squares.size(); i++)
	{
		if (this->player->getBound().intersects(this->squares[i]->getBound()))
		{
			if (elapsedSeconds - lastLostHealth > 1.5f)
			{
				this->player->loseHp(1);
				lastLostHealth = elapsedSeconds;
			}
		}
	}
}



void Game::updateGUI()
{
	std::stringstream ss;


	ss << "Time : " << std::fixed << std::setprecision(0) << this->elapsed.asSeconds() << "\n"
		<< "Point : " << this->point;

	this->timeText.setString(ss.str());

	float GamePercent = elapsedSeconds / 187.0f; 
	this->gameProcessBar.setSize(sf::Vector2f(600.0f * GamePercent, this->gameProcessBar.getSize().y));
}

//Update / Render
void Game::update()
{
	this->elapsed = clock.getElapsedTime();
	this->elapsedUpdateTime = updateTimeClock.getElapsedTime();
	if (std::floor(elapsedUpdateTime.asSeconds()) == 1.0f)
	{
		this->elapsedSeconds = (floor(this->elapsed.asSeconds()));
		this->point += this->player->getHp();
		this->spawnBall();
		this->spawnSpike();
		this->spawnSmall();
		this->spawnSquare();

		
		updateTimeClock.restart(); 
	}
	this->updateInput();
	this->updatePlayerCollision();
	this->player->update();
	this->updateCollision();
	this->updateSpike();
	this->updateSmall();
	this->updateSquare();
	this->updateGUI();
}

void Game::renderWorld()
{
	this->window->draw(this->worldBackgroud);
}

void Game::renderBall()
{
	for (auto ball : this->balls)
	{
		ball .render(*this->window);
	}
}

void Game::renderSpike()
{
	for (auto* spike : this->spikes)
	{
		spike->render(this->window);
	}
}

void Game::renderSmall()
{
	for (auto* small : this->smalls)
	{
		small->render(this->window);
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

	this->renderBall();

	this->renderSpike();

	this->renderSmall();

	this->renderSquare();
	
	this->renderGUI();

	//Game over screen
	if (this->player->getHp() <= 0)
	{
		this->player->render(*this->window);
		this->window->clear();
		this->window->draw(this->gameOverText);
		music.stop();
	}

	this->window->display();
}


/// Menu
void Game::renderMenuBackground()
{
	this->window->draw(this->menu);
}

void Game::updateMenu()
{
}

void Game::renderMenu()
{
	this->window->clear();
	this->renderMenuBackground();
	this->window->display();
}
