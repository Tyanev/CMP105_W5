#pragma once

#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Ranger :
	public GameObject
{
	protected:
		Animation idle;
		int speed;
	public:
		Ranger();
		~Ranger();

		void handleInput(float dt) override;
};

