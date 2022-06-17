#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Tower_enemy.h"
#include "Cat.h"

namespace game_framework {

	Tower_enemy::Tower_enemy() {
		this->is_alive = 1;
		SetXY(0, 470); //220
	}

	Tower_enemy::~Tower_enemy() {

	}

	void Tower_enemy::SetBlood(int bloodPoint) {
		blood = bloodPoint;
	}

	void Tower_enemy::SetAttack(int attackPoint) {
		this->attackPoint = attackPoint;
	}

	void Tower_enemy::BeAttack(int attackPoint) {
		this->attackPoint = this->attackPoint - attackPoint;
	}

	void Tower_enemy::SetDefence(int defencekPoint) {
		this->defencePoint = defencekPoint;
	}

	bool Tower_enemy::IsAlive() {
		return is_alive;
	}

	void Tower_enemy::SetIsAlive(bool is_alive) {
		this->is_alive = is_alive;
	}

	void Tower_enemy::SetXY(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void Tower_enemy::LoadBitmap()
	{
		bmp.LoadBitmap(IDB_TOWER2, RGB(255, 0, 0));
		this->centerX = x + bmp.Width() / 2;
	}

	void Tower_enemy::OnShow()
	{
		bmp.SetTopLeft(x, y);
		bmp.ShowBitmap(0.7);
	}

	int Tower_enemy::GetHitBox() {
		return this->centerX;
	}
}