#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Cat.h"
#include "Cat_friend.h"

namespace game_framework {

	Cat_friend::Cat_friend(string name, int blood, int attack, int defence, int speed) {
		this->name = name;
		this->blood = blood;
		this->defancePoint = defence;
		this->attackPoint = attack;
		this->is_enemy = 1;
		this->speedPoint = speed;
		SetXY(900, 430);
		LoadBitmap();
	}

	Cat_friend::~Cat_friend() {

	}

	bool Cat_friend::IsHit() {
		return true;
	}

	bool Cat_friend::IsAlive() {
		return true;
	}

	bool Cat_friend::IsEnemy() {
		return true;
	}

	void Cat_friend::SetXY(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void Cat_friend::SetIsAlive(bool alive) {

	}

	void Cat_friend::SetBlood(int blood) {

	}

	void Cat_friend::Attack(Cat* cat) {

	}

	void Cat_friend::BeAttack(int attack) {
		this->blood = this->blood - attack;
	}

	void Cat_friend::OnMove() {
		this->x = this->x - 1;
		animation.OnMove();
	}

	void Cat_friend::LoadBitmap() {
		char* filename[3] = { ".\\res\\f_marshmellow_walk_0.bmp",".\\res\\f_marshmellow_walk_1.bmp",".\\res\\f_marshmellow_walk_2.bmp" };
		for (int i = 0; i < 3; i++)	// 載入動畫(由4張圖形構成)
			animation.AddBitmap(filename[i], RGB(236, 28, 36));
	}

	void Cat_friend::OnShow() {
		animation.SetTopLeft(x, y);
		animation.OnShow();
	}
}