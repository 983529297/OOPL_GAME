#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Tower_friend.h"
#include "Cat.h"

namespace game_framework {

	Tower_friend::Tower_friend() {
		this->is_alive = 1;
		SetXY(1000, 250);
	}

	Tower_friend::~Tower_friend() {

	}

	void Tower_friend::SetBlood(int bloodPoint) {
		blood = bloodPoint;
	}

	void Tower_friend::SetAttack(int attackPoint) {
		this->attackPoint = attackPoint;
	}

	void Tower_friend::BeAttack(int attackPoint) {
		this->attackPoint = this->attackPoint - attackPoint;
	}

	void Tower_friend::SetDefence(int defencekPoint) {
		this->defencePoint = defencekPoint;
	}

	bool Tower_friend::IsAlive() {
		return is_alive;
	}

	void Tower_friend::SetIsAlive(bool is_alive) {
		this->is_alive = is_alive;
	}

	/*bool Tower_enemy::CheckEnemy(Cat* enemy) {

	}*/

	void Tower_friend::SetXY(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void Tower_friend::LoadBitmap()
	{
		bmp.LoadBitmap(IDB_TOWER1, RGB(255, 0, 0));
		this->centerX = x + bmp.Width() / 4;
	}

	void Tower_friend::OnShow()
	{
		bmp.SetTopLeft(x, y);
		bmp.ShowBitmap(0.7);
	}

	int Tower_friend::GetHitBox() {
		return this->centerX;
	}
}