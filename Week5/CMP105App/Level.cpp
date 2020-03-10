#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	zombie.setInput(input);
	mario.setInput(input);
	ranger.setInput(input);

	rangerTexture.loadFromFile("gfx/Ranger.png");
	zombTexture.loadFromFile("gfx/animZombie.png");
	marioTexture.loadFromFile("gfx/MarioSheetT.png");

	ranger.setTexture(&rangerTexture);
	mario.setTexture(&marioTexture);
	zombie.setTexture(&zombTexture);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	ranger.handleInput(dt);
	zombie.handleInput(dt);
	mario.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(ranger);
	window->draw(mario);
	window->draw(zombie);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color::Black);
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}