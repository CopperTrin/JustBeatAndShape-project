#include "Spike.h"

void Spike::initVariable()
{
	
}

void Spike::initTexture()
{
		if (!this->texture.loadFromFile("Texture/spikeSheet.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
		}
		
		if (!this->texture2.loadFromFile("Texture/spikeSheet2.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
		}

		if (!this->texture3.loadFromFile("Texture/Circle.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
		}
		if (!this->texture4.loadFromFile("Texture/wavenew.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
		}
		if (!this->texture5.loadFromFile("Texture/cloudBackground.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
		}
		if (!this->texture6.loadFromFile("Texture/cloud.png"))
		{
			std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
		}
}


void Spike::initSpike()
{

	switch (this->type)
	{
	case DEFAULTSPIKE:
		this->spike.setTexture(this->texture);
		this->currentFrame = ::sf::IntRect(0, 0, 200, 200);
		this->spike.setTextureRect(this->currentFrame);

		//Resize
		this->spike.setScale(0.8f, 0.8f);
		break;
		
	case SPIKE2:
		this->spike.setTexture(this->texture2);
		this->currentFrame = ::sf::IntRect(0, 0, 200, 200);
		this->spike.setTextureRect(this->currentFrame);

		//Resize
		this->spike.setScale(0.8f, 0.8f);
		break;
	case WAVE:
		this->spike.setTexture(this->texture4);
		this->currentFrame = ::sf::IntRect(0, 0, 1600, 196);
		this->spike.setTextureRect(this->currentFrame);
		break;
	case CLOUDBACKGROUND:
		this->spike.setTexture(this->texture5);
		break;
	case CLOUD:
		this->spike.setTexture(this->texture6);
		this->spike.setScale(0.5f, 0.5f);
		break;
	}
	
}

void Spike::initAnimations()
{
	this->animationTimer.restart();
}

Spike::Spike(float pos_x, float pos_y, int type)
	:type(type)
{
	this->initTexture();
	this->initSpike();
	this->initAnimations();
	this->spike.setPosition(pos_x, pos_y);
}

Spike::~Spike()
{
}

const sf::FloatRect Spike::getBound() const
{
	return this->spike.getGlobalBounds();
}

const sf::Vector2f& Spike::getPos() const
{
	return this->spike.getPosition();
}

void Spike::updateAnimations()
{
	if (this->type == DEFAULTSPIKE || this->type == SPIKE2)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() > 0.015f)
		{
			this->currentFrame.left += 200.f;
			if (this->currentFrame.left >= 2000.f)
				this->currentFrame.left = 0.f;

			this->spike.setTextureRect(this->currentFrame);

			this->animationTimer.restart();
		}
	}
	else if  (this->type == WAVE)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() > 0.025f)
		{
			this->currentFrame.left += 5.f;
			if (this->currentFrame.left >= 1600.f)
				this->currentFrame.left = 0.f;
			

			this->spike.setTextureRect(this->currentFrame);

			this->animationTimer.restart();
		}
	}
	
}

//Function
void Spike::update()
{
	if (this->type != WAVE && this->type != CLOUDBACKGROUND)this->spike.move(-5.f, 0.f);
	this->updateAnimations();
}

void Spike::render(sf::RenderTarget* target)
{
	target->draw(this->spike);
}
