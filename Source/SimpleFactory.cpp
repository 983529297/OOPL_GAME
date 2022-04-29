#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Stage.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "Stage4.h"
#include "Stage5.h"
#include "Stage6.h"
#include "Stage7.h"
#include "Stage8.h"
#include "Stage9.h"
#include "Stage10.h"
#include "SimpleFactory.h"

namespace game_framework {

	SimpleFactory::SimpleFactory() {
		
	}

	SimpleFactory::~SimpleFactory() {

	}

	Stage* SimpleFactory::GetStage(int num) {
		switch (num)
		{
		case 1:
			return new Stage1();
			break;
		case 2:
			return new Stage2();
			break;
		case 3:
			return new Stage3();
			break;
		case 4:
			return new Stage4();
			break;
		case 5:
			return new Stage5();
			break;
		case 6:
			return new Stage6();
			break;
		case 7:
			return new Stage7();
			break;
		case 8:
			return new Stage8();
			break;
		case 9:
			return new Stage9();
			break;
		case 10:
			return new Stage10();
			break;
		default:
			return new Stage1();
			break;
		}
	}
}