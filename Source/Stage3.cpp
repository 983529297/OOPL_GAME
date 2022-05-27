#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Stage.h"
#include "Stage3.h"

namespace game_framework {

	Stage3::Stage3() {
		
	}

	Stage3::~Stage3() {

	}
	
	void Stage3::countEnemyNum() {
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
			dc = 50;
		}
		else {
			enemynum = -1;
		}
	}

	void Stage3::LoadBack() {
		background.LoadBitmap(IDB_BACK3);
		background.SetTopLeft((SIZE_X - background.Width()) / 2, 0);
	}

	void Stage3::OnShowBack() {
		background.ShowBitmap();
	}

	int Stage3::GetBackWidth() {
		return background.Width();
	}
}