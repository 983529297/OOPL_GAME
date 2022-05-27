/*
 * mygame.h: 本檔案儲遊戲本身的class的interface
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *   2006-02-08 V4.2
 *      1. Rename OnInitialUpdate() -> OnInit().
 *      2. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      3. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
*/

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
		CMovingBitmap logo;								// csie的logo
		CMovingBitmap start;								// csie的logo
		CMovingBitmap option;
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
		int x, y;
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
		CMovingBitmap	background;	// 背景圖
		CMovingBitmap	upgrade;
		CMovingBitmap	upgrade_black;
		CMovingBitmap	empty_block[5];
		CMovingBitmap	block[5];
		CMovingBitmap	slash;
		CMovingBitmap	slash_T;
		CMovingBitmap	slash_T_1;
		CInteger callPoint;
		CInteger callPointTotal;
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
		int x, y;
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
		int counter;	// 倒數之計數器
		CMovingBitmap win;
		CMovingBitmap lose;
		CMovingBitmap back;
	};

}