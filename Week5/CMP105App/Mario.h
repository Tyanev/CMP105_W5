#pragma once

#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Mario:
	public GameObject
{
private:
	Animation idle;
	Animation walk;
	Animation duck;

	float speed;
	bool face;
	bool isIdle;
public:
	Mario();
	~Mario();

	void handleInput(float dt) override;
};

