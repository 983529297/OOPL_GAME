#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Stage.h"
#include "Stage7.h"

namespace game_framework {

	Stage7::Stage7() {
		count = 0;
	}

	Stage7::~Stage7() {

	}
	
	void Stage7::countEnemyNum() {
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
				enemynum = 5 + (rand() % 2);
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
			dc = 90;
		}
		else {
			enemynum = -1;
		}
	}

	void Stage7::LoadBack() {
		background.LoadBitmap(IDB_BACK7);
		background.SetTopLeft((SIZE_X - background.Width()) / 2, 0);
	}

	void Stage7::OnShowBack() {
		background.ShowBitmap();
	}

	int Stage7::GetBackWidth() {
		return background.Width();
	}
}