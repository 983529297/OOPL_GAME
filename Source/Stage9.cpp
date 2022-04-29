#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Stage.h"
#include "Stage9.h"

namespace game_framework {

	Stage9::Stage9() {
		
	}

	Stage9::~Stage9() {

	}
	
	void Stage9::countEnemyNum() {
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

	void Stage9::LoadBack() {
		background.LoadBitmap(IDB_BACK9);
		background.SetTopLeft((SIZE_X - background.Width()) / 2, 0);
	}

	void Stage9::OnShowBack() {
		background.ShowBitmap();
	}

	int Stage9::GetBackWidth() {
		return background.Width();
	}
}