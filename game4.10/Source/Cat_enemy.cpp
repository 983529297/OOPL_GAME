#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Cat.h"
#include "Cat_enemy.h"

namespace game_framework {

	Cat_enemy::Cat_enemy(string name, int blood, int attack, int defence, int speed) {
		this->name = name;
		this->blood = blood;
		this->defancePoint = defence;
		this->attackPoint = attack;
		this->is_enemy = 1;
		this->speedPoint = speed;
		SetXY(130, 430);
		LoadBitmap_Walk();
		center.x = this->x + animation.Width() / 2;
		center.y = this->y + animation.Height() / 2;
		this->attack_range = this->x + 50;
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
		this->x = x;
		this->y = y;
	}

	void Cat_enemy::SetIsAlive(bool alive) {

	}

	void Cat_enemy::SetBlood(int blood) {

	}

	bool Cat_enemy::isThere(int x) {
		if (x < this->hit_box)
			return true;
		else
			return false;
	}


	void Cat_enemy::BeAttack(int attack) {
		this->blood = this->blood - attack;
	}

	int Cat_enemy::Attack() {
		return this->attackPoint;
	}

	void Cat_enemy::OnMove() {
		this->center.x = this->center.x + 1;
		animation.OnMove();
		this->hit_box = this->center.x + animation.Width() / 2;
	}

	void Cat_enemy::LoadBitmap_Walk() {
		char* filename[3] = { ".\\res\\e_dog_walk_0.bmp",".\\res\\e_dog_walk_1.bmp",".\\res\\e_dog_walk_2.bmp" };
		for (int i = 0; i < 3; i++)	// 載入動畫(由4張圖形構成)
			animation.AddBitmap(filename[i], RGB(255, 0, 0));
	}

	void Cat_enemy::LoadBitmap_Walk() {
		char* filename[3] = { ".\\res\\e_dog_walk_0.bmp",".\\res\\e_dog_walk_1.bmp",".\\res\\e_dog_walk_2.bmp" };
		for (int i = 0; i < 3; i++)	// 載入動畫(由4張圖形構成)
			animation.AddBitmap(filename[i], RGB(255, 0, 0));
	}

	void Cat_enemy::OnShow() {
		animation.SetTopLeft(center.x - animation.Width() / 2, center.y - animation.Height() / 2);
		animation.OnShow();
	}
}