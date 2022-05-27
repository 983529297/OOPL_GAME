#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Stage.h"
#include "Stage2.h"

namespace game_framework {

	Stage2::Stage2() {
		
	}

	Stage2::~Stage2() {

	}
	
	void Stage2::countEnemyNum() {
		if (--dc == 0) {
			srand((unsigned)time(NULL));
			int random = rand() % 3;
			enemynum = random;
			dc = 70;
		}
		else {
			enemynum = -1;
		}
	}

	void Stage2::LoadBack() {
		background.LoadBitmap(IDB_BACK2);
		background.SetTopLeft((SIZE_X - background.Width()) / 2, 0);
	}

	void Stage2::OnShowBack() {
		background.ShowBitmap();
	}

	int Stage2::GetBackWidth() {
		return background.Width();
	}
}