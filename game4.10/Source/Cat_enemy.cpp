#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Cat.h"
#include "Cat_enemy.h"



namespace game_framework {

	Cat_enemy::Cat_enemy(string name, int blood, int attack, int defence) {
		this->name = name;
		this->blood = blood;
		this->defancePoint = defence;
		this->attackPoint = attack;
		this->is_enemy = 1;
	}

	Cat_enemy::~Cat_enemy() {

	}

	void Cat_enemy::BeAttack(int attack) {
		this->blood = this->blood - attack;
	}
}