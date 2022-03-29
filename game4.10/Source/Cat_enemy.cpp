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
		LoadBitmap_Attack();
		center.x = this->x + animation_walk.Width() / 2;
		center.y = this->y + animation_walk.Height() / 2;
		this->hit_box = this->center.x + animation_walk.Width() / 2;
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
		if (x < this->hit_box) {
			this->is_attack = true;
			return true;
		}
		else {
			this->is_attack = false;
			this->is_final_attack = false;
			return false;
		}
	}

	int Cat_enemy::GetAttackRange() {
		return this->hit_box;
	}

	int Cat_enemy::GetAttackPoint() {
		return this->attackPoint;
	}

	int Cat_enemy::GetBloodPoint() {
		return this->blood;
	}

	bool Cat_enemy::GetIsAttack() {
		return this->is_attack;
	}

	bool Cat_enemy::GetIsFinalAttack() {
		return this->is_final_attack;
	}

	void Cat_enemy::BeAttack(int attack) {
		this->blood = this->blood - attack;
	}

	void Cat_enemy::AnimationReset() {
		animation_attack.Reset();
		animation_walk.Reset();
		is_final_attack = false;
		is_attack = false;
	}

	int Cat_enemy::Attack() {
		return this->attackPoint;
	}

	void Cat_enemy::OnMove() {
		if (!is_attack) {
			animation_walk.OnMove();
			this->center.x = this->center.x + this->speedPoint;
		}
		else {
			animation_attack.OnMove();
			this->is_final_attack = animation_attack.IsFinalBitmap();
		}
		this->hit_box = this->center.x + animation_walk.Width() / 2;
	}

	void Cat_enemy::ReOnMove() {
		this->is_attack = false;
		this->is_final_attack = false;
		animation_walk.OnMove();
		this->center.x = this->center.x + this->speedPoint;
		this->hit_box = this->center.x + animation_walk.Width() / 2;
	}

	void Cat_enemy::LoadBitmap_Attack() {
		char* filename[3] = { ".\\res\\e_dog_walk_0.bmp",".\\res\\e_dog_walk_1.bmp",".\\res\\e_dog_walk_2.bmp" };
		for (int i = 0; i < 3; i++)	// 載入動畫(由4張圖形構成)
			animation_walk.AddBitmap(filename[i], RGB(255, 0, 0));
	}

	void Cat_enemy::LoadBitmap_Walk() {
		char* filename[3] = { ".\\res\\e_dog_walk_0.bmp",".\\res\\e_dog_walk_1.bmp",".\\res\\e_dog_walk_2.bmp" };
		for (int i = 0; i < 3; i++)	// 載入動畫(由4張圖形構成)
			animation_attack.AddBitmap(filename[i], RGB(255, 0, 0));
	}

	void Cat_enemy::OnShow_Walk() {
		animation_walk.SetTopLeft(center.x - animation_walk.Width() / 2, center.y - animation_walk.Height() / 2);
		animation_walk.OnShow();
	}

	void Cat_enemy::OnShow_Attack() {
		animation_attack.SetTopLeft(center.x - animation_attack.Width() / 2, center.y - animation_attack.Height() / 2);
		animation_attack.OnShow();
	}
}