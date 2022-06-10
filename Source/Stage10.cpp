#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Stage.h"
#include "Stage10.h"

namespace game_framework {

	Stage10::Stage10() {
		
	}

	Stage10::~Stage10() {

	}
	
	void Stage10::countEnemyNum() {
		if (--dc == 0) {
			//srand((unsigned)time(NULL));
			//int random = rand() % 3;
			enemynum = 3;
			dc = 30;
		}
		else {
			enemynum = -1;
		}
	}

	void Stage10::LoadBack() {
		background.LoadBitmap(IDB_BACK10);
		background.SetTopLeft((SIZE_X - background.Width()) / 2, 0);
	}

	void Stage10::OnShowBack() {
		background.ShowBitmap();
	}

	int Stage10::GetBackWidth() {
		return background.Width();
	}
}