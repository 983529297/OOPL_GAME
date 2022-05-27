#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Stage.h"
#include "Stage6.h"

namespace game_framework {

	Stage6::Stage6() {
		
	}

	Stage6::~Stage6() {

	}
	
	void Stage6::countEnemyNum() {
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

	void Stage6::LoadBack() {
		background.LoadBitmap(IDB_BACK6);
		background.SetTopLeft((SIZE_X - background.Width()) / 2, 0);
	}

	void Stage6::OnShowBack() {
		background.ShowBitmap();
	}

	int Stage6::GetBackWidth() {
		return background.Width();
	}
}