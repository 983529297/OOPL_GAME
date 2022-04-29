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
			int random = rand() % 3;
			enemynum = random;
			dc = 50;
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