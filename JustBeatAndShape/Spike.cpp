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
}

void Spike::initSpike()
{
	this->spike.setTexture(this->texture);
	this->currentFrame = ::sf::IntRect(0, 0, 200, 200);
	this->spike.setTextureRect(this->currentFrame);

	//Resize
	this->spike.setScale(0.8f, 0.8f);
}

void Spike::initAnimations()
{
	this->animationTimer.restart();
}

Spike::Spike(float pos_x, float pos_y)
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
	if (this->animationTimer.getElapsedTime().asSeconds() > 0.015f) 
	{
		this->currentFrame.left += 200.f;
		if (this->currentFrame.left >= 2000.f)
			this->currentFrame.left = 0.f;

		this->spike.setTextureRect(this->currentFrame);

		this->animationTimer.restart();
	}
}

//Function
void Spike::update()
{
	this->spike.move(-5.f, 0.f);
	this->updateAnimations();
}

void Spike::render(sf::RenderTarget* target)
{
	target->draw(this->spike);
}
