#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Stage.h"
#include "Stage5.h"

namespace game_framework {

	Stage5::Stage5() {
		
	}

	Stage5::~Stage5() {

	}
	
	void Stage5::countEnemyNum() {
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
			dc = 70;
		}
		else {
			enemynum = -1;
		}
	}

	void Stage5::LoadBack() {
		background.LoadBitmap(IDB_BACK5);
		background.SetTopLeft((SIZE_X - background.Width()) / 2, 0);
	}

	void Stage5::OnShowBack() {
		background.ShowBitmap();
	}

	int Stage5::GetBackWidth() {
		return background.Width();
	}
}