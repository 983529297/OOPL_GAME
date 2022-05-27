#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Stage.h"
#include "Stage8.h"

namespace game_framework {

	Stage8::Stage8() {
		
	}

	Stage8::~Stage8() {

	}
	
	void Stage8::countEnemyNum() {
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

	void Stage8::LoadBack() {
		background.LoadBitmap(IDB_BACK8);
		background.SetTopLeft((SIZE_X - background.Width()) / 2, 0);
	}

	void Stage8::OnShowBack() {
		background.ShowBitmap();
	}

	int Stage8::GetBackWidth() {
		return background.Width();
	}
}