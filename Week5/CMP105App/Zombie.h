#pragma once

#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Zombie:
	public GameObject
{
protected:
	Animation walk;
	int speed;
public:
	Zombie(); 
	~Zombie();

	void handleInput(float dt) override;
};

