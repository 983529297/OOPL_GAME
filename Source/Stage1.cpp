#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Stage.h"
#include "Stage1.h"

namespace game_framework {

	Stage1::Stage1() {
		
	}

	Stage1::~Stage1() {

	}
	
	void Stage1::countEnemyNum() {
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
			dc = 100;
		}
		else {
			enemynum = -1;
		}
	}

	void Stage1::LoadBack() {
		background.LoadBitmap(IDB_BACK1);
		background.SetTopLeft((SIZE_X - background.Width()) / 2, 0);
	}

	void Stage1::OnShowBack() {
		background.ShowBitmap();
	}

	int Stage1::GetBackWidth() {
		return background.Width();
	}
}