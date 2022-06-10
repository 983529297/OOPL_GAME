#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Stage.h"
#include "Stage8.h"

namespace game_framework {

	Stage8::Stage8() {
		count = 0;
	}

	Stage8::~Stage8() {

	}
	
	void Stage8::countEnemyNum() {
		if (--dc == 0) {
			srand((unsigned)time(NULL));
			int random = rand() % 29;
			if (random < 20) {
				enemynum = rand() % 4;
			}
			else if (random < 24) {
				enemynum = 4;
			}
			else if (random < 28) {
				enemynum = 2 + (rand() % 2);
			}
			else {
				enemynum = 7;
			}
			if (count == 50) {
				enemynum = 8;
				count = 0;
			}
			else {
				count++;
			}
			dc = 70;
		}
		else {
			enemynum = -1;
		}
	}

	void Stage8::LoadBack() {
		background.LoadBitmap(IDB_BACK8);
		background.SetTopLeft((SIZE_X - background.Width()) / 2, 0);
	}

	void Stage8::OnShowBack() {
		background.ShowBitmap();
	}

	int Stage8::GetBackWidth() {
		return background.Width();
	}
}