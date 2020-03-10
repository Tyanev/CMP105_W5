#include "Mario.h"

Mario::Mario()
{
	setSize(sf::Vector2f(60, 84));
	setPosition(sf::Vector2f(100, 200));
	speed = 150.f;
	face = 0;
	//idle
	idle.addFrame(sf::IntRect(0, 0, 15, 21));
	//walk
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(1.f / 10.f);
	//duck
	duck.addFrame(sf::IntRect(0, 41, 16, 20));
	duck.addFrame(sf::IntRect(16, 41, 16, 20));
	duck.setFrameSpeed(1.f / 100.f);
}

Mario::~Mario()
{
}

void Mario::handleInput(float dt)
{
	isIdle = 1;
	if (input->isKeyDown(sf::Keyboard::D) || input->isKeyDown(sf::Keyboard::A))
	{
		isIdle = 0;
		setSize(sf::Vector2f(60, 84));
		if (input->isKeyDown(sf::Keyboard::D))
		{
			face = 0;
			if (speed < 0) { speed *= -1; }
		}
		if (input->isKeyDown(sf::Keyboard::A))
		{
			face = 1;
			if (speed > 0) { speed *= -1; }
		}
		move(sf::Vector2f(speed * dt, 0));
		walk.setFlipped(face);
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}
	else if (input->isKeyDown(sf::Keyboard::S))
	{
		isIdle = 0;
		setSize(sf::Vector2f(64, 80));
		if (face){duck.setFlipped(true);}
		else {duck.setFlipped(false);}
		duck.setLooping(false);
		duck.animate(dt);
		setTextureRect(duck.getCurrentFrame());
	}
	if (isIdle)
	{
		setSize(sf::Vector2f(60, 84));
		if (face) { idle.setFlipped(true); }
		else { idle.setFlipped(false); }
		idle.animate(dt);
		setTextureRect(idle.getCurrentFrame());
	}
}
