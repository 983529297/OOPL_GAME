#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Cat.h"
#include "Cat_enemy.h"
#include <time.h>

namespace game_framework {

	Cat_enemy::Cat_enemy(string name, int blood, int attack, int walk_speed, int speed, int attack_pic, int walk_pic, int as) {
		srand((unsigned)time(NULL));
		int random = rand() % 20;
		this->name = name;
		this->blood = blood;
		this->walk_speed = walk_speed;
		this->attackPoint = attack;
		this->is_enemy = 1;
		this->speedPoint = speed;
		this->attack_pic = attack_pic;
		this->walk_pic = walk_pic;
		this->attackSpeed = as;
		LoadBitmap_Walk();
		LoadBitmap_Attack();
		SetXY(130, 760 + random - animation_walk.Height());
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
			animation_walk.Reset();
			return true;
		}
		else {
			this->is_attack = false;
			this->is_final_attack = false;
			animation_attack.Reset();
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

	void Cat_enemy::SetAnimationReset() {
		this->reset = true;
	}

	bool Cat_enemy::GetReset() {
		return this->reset;
	}

	void Cat_enemy::AnimationReset() {
		animation_attack.Reset();
		animation_walk.Reset();
		this->reset = false;
	}

	int Cat_enemy::Attack() {
		return this->attackPoint;
	}

	void Cat_enemy::OnMove() {
		if (!is_attack) {
			animation_walk.OnMove();
			//AnimationReset();
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
		//char* filename[3] = { ".\\res\\e_dog_walk_0.bmp",".\\res\\e_dog_walk_1.bmp",".\\res\\e_dog_walk_2.bmp" };
		for (int i = 0; i < attack_pic; i++) {
			string path = ".\\res\\enemy\\" + name + "\\" + name + "_attack_" + to_string(i) + ".bmp";
			attackPath.push_back(path);
		}
		for (int i = 0; i < attack_pic; i++) {
			char* path = (char *)attackPath.at(i).c_str();
			animation_attack.AddBitmap(path, RGB(1, 1, 1));
		}
		animation_attack.SetDelayCount(attackSpeed);
	}

	void Cat_enemy::LoadBitmap_Walk() {
		//char* filename[3] = { ".\\res\\e_dog_walk_0.bmp",".\\res\\e_dog_walk_1.bmp",".\\res\\e_dog_walk_2.bmp" };
		for (int i = 0; i < walk_pic; i++) {
			string path = ".\\res\\enemy\\" + name + "\\" + name + "_walk_" + to_string(i) + ".bmp";
			walkPath.push_back(path);
		}
		for (int i = 0; i < walk_pic; i++) {
			char* path = (char*)walkPath.at(i).c_str();
			animation_walk.AddBitmap(path, RGB(1, 1, 1));
		}
		animation_walk.SetDelayCount(walk_speed);
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