#include "Zombie.h"

Zombie::Zombie()
{
	setSize(sf::Vector2f(55, 108));
	setPosition(100, 100);
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 10.f);
	speed = 150.f;
}

Zombie::~Zombie()
{
}

void Zombie::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::D))
	{
		move(sf::Vector2f(speed * dt, 0));
		walk.setFlipped(false);
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		move(sf::Vector2f(-speed * dt, 0));
		walk.setFlipped(true);
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}
}
