#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Cat.h"
#include "Cat_friend.h"
#include <time.h>

namespace game_framework {

	Cat_friend::Cat_friend(string name, int blood, int attack, int walk_speed, int speed, int attack_pic, int walk_pic, int as) {
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
		SetXY(1550 , 760 + random - animation_walk.Height());
		center.x = this->x + animation_walk.Width() / 2;
		center.y = this->y + animation_walk.Height() / 2;
		this->hit_box = this->center.x - animation_walk.Width() / 2;
		this->attack_range = this->x - 50;
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

	bool Cat_friend::isThere(int x) {
		if (x > this->hit_box) {
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

	int Cat_friend::GetAttackRange() {
		return this->hit_box;
	}

	int Cat_friend::GetAttackPoint() {
		return this->attackPoint;
	}

	int Cat_friend::GetBloodPoint() {
		return this->blood;
	}

	bool Cat_friend::GetIsAttack() {
		return this->is_attack;
	}

	bool Cat_friend::GetIsFinalAttack() {
		return this->is_final_attack;
	}

	void Cat_friend::BeAttack(int attack) {
		this->blood = this->blood - attack;
	}

	void Cat_friend::SetAnimationReset() {
		this->reset = true;
	}

	bool Cat_friend::GetReset() {
		return this->reset;
	}

	void Cat_friend::AnimationReset() {
		animation_attack.Reset();
		animation_walk.Reset();
		this->reset = false;
	}

	int Cat_friend::Attack() {
		return attackPoint;
	}

	void Cat_friend::OnMove() {
		if (!is_attack) {
			animation_walk.OnMove();
			//AnimationReset();
			this->center.x = this->center.x - this->speedPoint;
		}
		else {
			animation_attack.OnMove();
			this->is_final_attack = animation_attack.IsFinalBitmap();
		}
		this->hit_box = this->center.x - animation_walk.Width() / 2;
	}

	void Cat_friend::ReOnMove() {
		this->is_attack = false;
		this->is_final_attack = false;
		animation_walk.OnMove();
		this->center.x = this->center.x - this->speedPoint;
		this->hit_box = this->center.x - animation_walk.Width() / 2;
	}

	void Cat_friend::LoadBitmap_Walk() {
		//char* filename[3] = { ".\\res\\f_marshmellow_walk_0.bmp",".\\res\\f_marshmellow_walk_1.bmp",".\\res\\f_marshmellow_walk_2.bmp" };
		for (int i = 0; i < walk_pic; i++) {
			string path = ".\\res\\cat\\" + name + "\\" + name + "_f_walk_" + to_string(i) + ".bmp";
			walkPath.push_back(path);
		}
		for (int i = 0; i < walk_pic; i++) {// ???J???e(??4?i?????c??)
			char* path = (char*)walkPath.at(i).c_str();
			animation_walk.AddBitmap(path, RGB(1, 1, 1));
		}
		animation_walk.SetDelayCount(walk_speed);
	}

	void Cat_friend::LoadBitmap_Attack() {
		//char* filename[3] = { ".\\res\\f_marshmellow_hit_0.bmp",".\\res\\f_marshmellow_hit_1.bmp",".\\res\\f_marshmellow_hit_2.bmp" };
		for (int i = 0; i < attack_pic; i++) {
			string path = ".\\res\\cat\\" + name + "\\" + name + "_f_attack_" + to_string(i) + ".bmp";
			attackPath.push_back(path);
		}
		for (int i = 0; i < attack_pic; i++) {
			char* path = (char*)attackPath.at(i).c_str();
			animation_attack.AddBitmap(path, RGB(1, 1, 1));
		}
		animation_attack.SetDelayCount(attackSpeed);
	}

	void Cat_friend::OnShow_Walk() {
		animation_walk.SetTopLeft(center.x - animation_walk.Width() / 2, center.y - animation_walk.Height() / 2);
		animation_walk.OnShow();
	}

	void Cat_friend::OnShow_Attack() {
		animation_attack.SetTopLeft(center.x - animation_attack.Width() / 2, center.y - animation_attack.Height() / 2);
		animation_attack.OnShow();
	}
}