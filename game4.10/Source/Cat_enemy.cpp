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

	bool Cat_enemy::IsHit() {
		return true;
	}

	bool Cat_enemy::IsAlive() {
		return true;
	}

	bool Cat_enemy::IsEnemy() {
		return true;
	}

	void Cat_enemy::SetXY(int x, int y) {

	}

	void Cat_enemy::SetIsAlive(bool alive) {

	}

	void Cat_enemy::SetBlood(int blood) {

	}

	void Cat_enemy::Attack(Cat cat) {

	}

	void Cat_enemy::BeAttack(int attack) {
		this->blood = this->blood - attack;
	}

	void Cat_enemy::OnMove() {

	}

	void Cat_enemy::LoadBitmap() {
		bmp.LoadBitmapA(IDB_E_DOG_WALK_0);
	}

	void Cat_enemy::OnShow() {
		bmp.SetTopLeft(150, 250);
		bmp.ShowBitmap();
	}
}