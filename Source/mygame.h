#include "Tower_enemy.h"
#include "Tower_friend.h"
#include "Cat.h"
#include "Cat_enemy.h"
#include "Cat_friend.h"
#include "Stage.h"
#include "SimpleFactory.h"


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////
	static int stagenum = 1;
	static int win_lose = -1; //-1未定 0輸 1贏
	static bool music_op = true;
	static bool music_game = true;

	enum AUDIO_ID {				// 定義各種音效的編號
		AUDIO_OP,				// 0
		AUDIO_NORM,				// 1
		AUDIO_HARD				// 2
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲開頭畫面物件
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////
	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnKeyUp(UINT, UINT, UINT); 				// 處理鍵盤Up的動作
		void OnMouseMove(UINT nFlags, CPoint point);	// 處理滑鼠的動作 
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
	protected:
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		bool ready = false;
		int win_state = 0;
		double game_sound_size;
		double music_sound_size;
		double start_size;
		double option_size;
		double close_size;
		double goBack_size;
		double battle_size;
		double stage1_size, stage2_size, stage3_size, stage4_size, stage5_size, stage6_size, stage7_size, stage8_size, stage9_size, stage10_size;
		CMovingBitmap logo;
		CMovingBitmap start;
		CMovingBitmap option;
		CMovingBitmap about;
		CMovingBitmap win_about;
		CMovingBitmap secretKey;
		CMovingBitmap win_option;
		CMovingBitmap close;
		CMovingBitmap state_back;
		CMovingBitmap map;
		CMovingBitmap goBack;
		CMovingBitmap battle;
		CMovingBitmap cat_spot;
		CMovingBitmap musicSound;
		CMovingBitmap musicSoundAnti;
		CMovingBitmap gameSound;
		CMovingBitmap gameSoundAnti;
		CMovingBitmap stage1, stage2, stage3, stage4, stage5, stage6, stage7, stage8, stage9, stage10;
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnLButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
		void OnMouseMove(UINT nFlags, CPoint point);	// 處理滑鼠的動作 
		void OnRButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnRButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
		void DeleteDeadCat(int position, bool side);
		void VectorSort();
		void readCSV();
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap	background;						// 背景圖
		CMovingBitmap	upgrade;
		CMovingBitmap	upgrade_black;
		CMovingBitmap	empty_block[5];
		CMovingBitmap	block[5];
		CMovingBitmap	slash;
		CMovingBitmap	slash_T;
		CMovingBitmap	slash_T_1;
		CInteger callPoint;
		CInteger callPointTotal;
		CInteger Point1;
		CInteger Point2;
		CInteger Point3;
		CInteger Point4;
		CInteger Point5;
		CIntegerTower friendTowerBlood;
		CIntegerTower friendTowerBloodTotal;
		CIntegerTower enemyTowerBlood;
		CIntegerTower enemyTowerBloodTotal;
		CIntegerTower upgradePoint;
		Tower_enemy tower_enemy;
		Tower_friend tower_friend;
		vector<Cat*> cat_enemy;
		vector<Cat*> cat_friend;
		vector<vector<string>> data_enemy;
		vector<vector<string>> data_friend;
		Stage *stage = nullptr;
		SimpleFactory *sf = nullptr;
		int enemyTowerHitRange;
		int friendTowerHitRange;
		int addPoint = 1;
		int weight;
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態(Game Over)
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		int counter;									// 倒數之計數器
		CMovingBitmap win;
		CMovingBitmap lose;
		CMovingBitmap back;
	};

}