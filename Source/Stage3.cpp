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
			int random = rand() % 3;
			enemynum = random;
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