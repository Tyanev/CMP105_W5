#include "Ranger.h"

Ranger::Ranger()
{
	setSize(sf::Vector2f(60, 115));
	setPosition(100, 300);
	//Idle
	idle.addFrame(sf::IntRect(0, 0, 12, 23));
	idle.addFrame(sf::IntRect(12, 0, 12, 23));
	idle.addFrame(sf::IntRect(24, 0, 12, 23));
	idle.addFrame(sf::IntRect(36, 0, 12, 23));
	idle.setFrameSpeed(1.f / 15.f);
}

Ranger::~Ranger()
{
}

void Ranger::handleInput(float dt)
{
	idle.animate(dt);
	setTextureRect(idle.getCurrentFrame());
}
