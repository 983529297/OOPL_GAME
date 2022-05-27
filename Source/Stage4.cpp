#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Stage.h"
#include "Stage4.h"

namespace game_framework {

	Stage4::Stage4() {
		
	}

	Stage4::~Stage4() {

	}
	
	void Stage4::countEnemyNum() {
		if (--dc == 0) {
			srand((unsigned)time(NULL));
			int random = rand() % 3;
			enemynum = random;
			dc = 90;
		}
		else {
			enemynum = -1;
		}
	}

	void Stage4::LoadBack() {
		background.LoadBitmap(IDB_BACK4);
		background.SetTopLeft((SIZE_X - background.Width()) / 2, 0);
	}

	void Stage4::OnShowBack() {
		background.ShowBitmap();
	}

	int Stage4::GetBackWidth() {
		return background.Width();
	}
}