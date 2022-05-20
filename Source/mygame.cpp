/*
 * mygame.cpp: 本檔案儲遊戲本身的class的implementation
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
 * History:
 *   2002-03-04 V3.1
 *          Add codes to demostrate the use of CMovingBitmap::ShowBitmap(CMovingBitmap &).
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *      2. Demo the use of CInteger in CGameStateRun.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *      1. Add codes to display IDC_GAMECURSOR in GameStateRun.
 *   2006-02-08 V4.2
 *      1. Revise sample screens to display in English only.
 *      2. Add code in CGameStateInit to demo the use of PostQuitMessage().
 *      3. Rename OnInitialUpdate() -> OnInit().
 *      4. Fix the bug that OnBeginState() of GameStateInit is not called.
 *      5. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      6. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2006-12-30
 *      1. Bug fix: fix a memory leak problem by replacing PostQuitMessage(0) as
 *         PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0).
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress. 
 *   2010-03-23 V4.6
 *      1. Demo MP3 support: use lake.mp3 to replace lake.wav.
*/

#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"
#include <fstream>
#include <iostream>
#include <sstream>
#ifndef _DEBUG
#define new DEBUG_NEW
#endif // !_DEBUG

namespace game_framework {
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////

CGameStateInit::CGameStateInit(CGame *g)
: CGameState(g)
{
}

void CGameStateInit::OnInit()
{
	ShowInitProgress(0);	// 一開始的loading進度為0%
	//
	// 開始載入資料
	//
	logo.LoadBitmap(IDB_OPEND);
	start.LoadBitmap(IDB_START, (0, 0, 255));
	option.LoadBitmap(IDB_OPTION, (0, 0, 255));
	win_option.LoadBitmap(IDB_WIN_OPTION, (0, 0, 255));
	close.LoadBitmap(IDB_CLOSE, (0, 0, 255));
	state_back.LoadBitmap(IDB_STAGE_BACK, (0, 0, 255));
	map.LoadBitmap(IDB_MAP);
	goBack.LoadBitmap(IDB_GOBACK, (0, 0, 255));
	stage1.LoadBitmap(IDB_STAGE1);
	stage2.LoadBitmap(IDB_STAGE2);
	stage3.LoadBitmap(IDB_STAGE3);
	stage4.LoadBitmap(IDB_STAGE4);
	stage5.LoadBitmap(IDB_STAGE5);
	stage6.LoadBitmap(IDB_STAGE6);
	stage7.LoadBitmap(IDB_STAGE7);
	stage8.LoadBitmap(IDB_STAGE8);
	stage9.LoadBitmap(IDB_STAGE9);
	stage10.LoadBitmap(IDB_STAGE10);
	battle.LoadBitmap(IDB_BATTLE, (0, 0, 255));
	cat_spot.LoadBitmap(IDB_STAGE_SPOT, (1, 1, 1));
	musicSound.LoadBitmap(IDB_MUSIC_SOUND, (0, 0, 255));
	musicSoundAnti.LoadBitmap(IDB_MUSIC_SOUND_ANTI, (0, 0, 255));
	gameSound.LoadBitmap(IDB_GAME_SOUND, (0, 0, 255));
	gameSoundAnti.LoadBitmap(IDB_GAME_SOUND_ANTI, (0, 0, 255));
	musicSound.SetTopLeft(530, 403);
	musicSoundAnti.SetTopLeft(530, 403);
	gameSound.SetTopLeft(673, 403);
	gameSoundAnti.SetTopLeft(673, 403);
	cat_spot.SetTopLeft(985 - cat_spot.Width() + 15, 503);
	battle.SetTopLeft(870, 630);
	stage1.SetTopLeft(985, 503);
	stage2.SetTopLeft(939, 387);
	stage3.SetTopLeft(868, 260);
	stage4.SetTopLeft(783, 118);
	stage5.SetTopLeft(588, 180);
	stage6.SetTopLeft(691, 284);
	stage7.SetTopLeft(603, 356);
	stage8.SetTopLeft(323, 443);
	stage9.SetTopLeft(208, 198);
	stage10.SetTopLeft(437, 82);
	goBack.SetTopLeft((SIZE_X - logo.Width()) / 2, 610);
	map.SetTopLeft((SIZE_X - logo.Width()) / 2, 62);
	logo.SetTopLeft((SIZE_X - logo.Width()) / 2, 0);//SIZE_Y/8);
	state_back.SetTopLeft((SIZE_X - logo.Width()) / 2, 0);//SIZE_Y/8);
	start.SetTopLeft(SIZE_X / 2 - 185, 399);//SIZE_Y/8);
	option.SetTopLeft(SIZE_X / 2 - 185, 500);//SIZE_Y/8);
	win_option.SetTopLeft(SIZE_X / 2 - 185, 250);//SIZE_Y/8);
	close.SetTopLeft(790, 250);
	start_size = 0.81;
	option_size = 0.81;
	game_sound_size = music_sound_size = close_size = 1;
	goBack_size = 1;
	battle_size = 1;
	stage1_size = stage2_size = stage3_size = stage4_size = stage5_size = stage6_size = stage7_size = stage8_size = stage9_size = stage10_size = 1;
	//
	// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
	//
	ready = true;
	CAudio::Instance()->Load(AUDIO_OP, "Sounds\\OP.mp3");
	if (music_op)
		CAudio::Instance()->Play(AUDIO_OP, true);
	else
		CAudio::Instance()->Stop(AUDIO_OP);
}

void CGameStateInit::OnBeginState()
{
	if (ready) {
		if (music_op)
			CAudio::Instance()->Play(AUDIO_OP, true);
		else
			CAudio::Instance()->Stop(AUDIO_OP);
	}
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	const char KEY_ESC = 27;
	const char KEY_SPACE = ' ';
	if (nChar == KEY_SPACE)
		GotoGameState(GAME_STATE_RUN);						// 切換至GAME_STATE_RUN
	else if (nChar == KEY_ESC)								// Demo 關閉遊戲的方法
		PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0);	// 關閉遊戲
}

void CGameStateInit::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	x = point.x;
	y = point.y;
	if (ready) {
		if (win_state == 0) {
			if (start.Left() < point.x && point.x < start.Left() + start.Width() && start.Top() < point.y && point.y < start.Top() + start.Height()) {
				start_size = 0.9;
				start.SetTopLeft(SIZE_X / 2 - 205, 390);//SIZE_Y/8);
				option.SetTopLeft(SIZE_X / 2 - 185, 500);//SIZE_Y/8);
				option_size = 0.81;
			}
			else if (option.Left() < point.x && point.x < option.Left() + option.Width() && option.Top() < point.y && point.y < option.Top() + option.Height()){
				option_size = 0.9;
				option.SetTopLeft(SIZE_X / 2 - 205, 491);//SIZE_Y/8);
				start.SetTopLeft(SIZE_X / 2 - 185, 399);//SIZE_Y/8);
				start_size = 0.81;
			}
			else {
				start.SetTopLeft(SIZE_X / 2 - 185, 399);//SIZE_Y/8);
				option.SetTopLeft(SIZE_X / 2 - 185, 500);//SIZE_Y/8);
				option_size = 0.81;
				start_size = 0.81;
			}
		}
		else if (win_state == 1){
			if (close.Left() < point.x && point.x < close.Left() + close.Width() && close.Top() < point.y && point.y < close.Top() + close.Height()) {
				close.SetTopLeft(790 - 5, 250 - 5);
				close_size = 1.1;
			}
			else if (musicSound.Left() < point.x && point.x < musicSound.Left() + musicSound.Width() && musicSound.Top() < point.y && point.y < musicSound.Top() + musicSound.Height()) {
				music_sound_size = 1.1;
			}
			else if (gameSound.Left() < point.x && point.x < gameSound.Left() + gameSound.Width() && gameSound.Top() < point.y && point.y < gameSound.Top() + gameSound.Height()) {
				game_sound_size = 1.1;

			}
			else {
				close.SetTopLeft(790, 250);
				game_sound_size = music_sound_size = close_size = 1;
			}
		}
		else {
			if (goBack.Left() < point.x && point.x < goBack.Left() + goBack.Width() && goBack.Top() < point.y && point.y < goBack.Top() + goBack.Height()) {
				goBack.SetTopLeft((SIZE_X - logo.Width()) / 2 - 5, 610 - 5);
				goBack_size = 1.1;
			}
			else if (stage1.Left() < point.x && point.x < stage1.Left() + stage1.Width() && stage1.Top() < point.y && point.y < stage1.Top() + stage1.Height()) {
				stage1_size = 1.1;
			}
			else if (stage2.Left() < point.x && point.x < stage2.Left() + stage2.Width() && stage2.Top() < point.y && point.y < stage2.Top() + stage2.Height()) {
				stage2_size = 1.1;
			}
			else if (stage3.Left() < point.x && point.x < stage3.Left() + stage3.Width() && stage3.Top() < point.y && point.y < stage3.Top() + stage3.Height()) {
				stage3_size = 1.1;

			}
			else if (stage4.Left() < point.x && point.x < stage4.Left() + stage4.Width() && stage4.Top() < point.y && point.y < stage4.Top() + stage4.Height()) {
				stage4_size = 1.1;

			}
			else if (stage5.Left() < point.x && point.x < stage5.Left() + stage5.Width() && stage5.Top() < point.y && point.y < stage5.Top() + stage5.Height()) {
				stage5_size = 1.1;

			}
			else if (stage6.Left() < point.x && point.x < stage6.Left() + stage6.Width() && stage6.Top() < point.y && point.y < stage6.Top() + stage6.Height()) {
				stage6_size = 1.1;

			}
			else if (stage7.Left() < point.x && point.x < stage7.Left() + stage7.Width() && stage7.Top() < point.y && point.y < stage7.Top() + stage7.Height()) {
				stage7_size = 1.1;

			}
			else if (stage8.Left() < point.x && point.x < stage8.Left() + stage8.Width() && stage8.Top() < point.y && point.y < stage8.Top() + stage8.Height()) {
				stage8_size = 1.1;

			}
			else if (stage9.Left() < point.x && point.x < stage9.Left() + stage9.Width() && stage9.Top() < point.y && point.y < stage9.Top() + stage9.Height()) {
				stage9_size = 1.1;

			}
			else if (stage10.Left() < point.x && point.x < stage10.Left() + stage10.Width() && stage10.Top() < point.y && point.y < stage10.Top() + stage10.Height()) {
				stage10_size = 1.1;

			}
			else if (battle.Left() < point.x && point.x < battle.Left() + battle.Width() && battle.Top() < point.y && point.y < battle.Top() + battle.Height()) {
				battle_size = 1.1;
				battle.SetTopLeft(850, 625);
			}
			else {
				goBack.SetTopLeft((SIZE_X - logo.Width()) / 2, 610);
				goBack_size = 1;
				stage1_size = stage2_size = stage3_size = stage4_size = stage5_size = stage6_size = stage7_size = stage8_size = stage9_size = stage10_size = 1;
				battle_size = 1;
				battle.SetTopLeft(870, 630);
			}
		}
	}
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (win_state == 0) {
		if (start.Left() < point.x && point.x < start.Left() + start.Width() && start.Top() < point.y && point.y < start.Top() + start.Height()) {
			win_state = 2;
		}
		else if (option.Left() < point.x && point.x < option.Left() + option.Width() && option.Top() < point.y && point.y < option.Top() + option.Height()) {
			win_state = 1;
		}
	}
	else if (win_state == 1) {
		if (close.Left() < point.x && point.x < close.Left() + close.Width() && close.Top() < point.y && point.y < close.Top() + close.Height()) {
			win_state = 0;
		}
		else if (musicSound.Left() < point.x && point.x < musicSound.Left() + musicSound.Width() && musicSound.Top() < point.y && point.y < musicSound.Top() + musicSound.Height()) {
			music_op = !music_op;
			if (music_op)
				CAudio::Instance()->Play(AUDIO_OP, true);
			else
				CAudio::Instance()->Stop(AUDIO_OP);
		}
		else if (gameSound.Left() < point.x && point.x < gameSound.Left() + gameSound.Width() && gameSound.Top() < point.y && point.y < gameSound.Top() + gameSound.Height()) {
			music_game = !music_game;
		}
	}
	else {
		if (goBack.Left() < point.x && point.x < goBack.Left() + goBack.Width() && goBack.Top() < point.y && point.y < goBack.Top() + goBack.Height()) {
			win_state = 0;
		}
		else if (stage1.Left() < point.x && point.x < stage1.Left() + stage1.Width() && stage1.Top() < point.y && point.y < stage1.Top() + stage1.Height()) {
			stagenum = 1;
			cat_spot.SetTopLeft(985 - cat_spot.Width() + 15, 503);
		}
		else if (stage2.Left() < point.x && point.x < stage2.Left() + stage2.Width() && stage2.Top() < point.y && point.y < stage2.Top() + stage2.Height()) {
			stagenum = 2;
			cat_spot.SetTopLeft(939 - cat_spot.Width() + 15, 387);
		}
		else if (stage3.Left() < point.x && point.x < stage3.Left() + stage3.Width() && stage3.Top() < point.y && point.y < stage3.Top() + stage3.Height()) {
			stagenum = 3;
			cat_spot.SetTopLeft(868 - cat_spot.Width() + 15, 260);
		}
		else if (stage4.Left() < point.x && point.x < stage4.Left() + stage4.Width() && stage4.Top() < point.y && point.y < stage4.Top() + stage4.Height()) {
			stagenum = 4;
			cat_spot.SetTopLeft(783 - cat_spot.Width() + 15, 118);
		}
		else if (stage5.Left() < point.x && point.x < stage5.Left() + stage5.Width() && stage5.Top() < point.y && point.y < stage5.Top() + stage5.Height()) {
			stagenum = 5;
			cat_spot.SetTopLeft(588 - cat_spot.Width() + 15, 180);
		}
		else if (stage6.Left() < point.x && point.x < stage6.Left() + stage6.Width() && stage6.Top() < point.y && point.y < stage6.Top() + stage6.Height()) {
			stagenum = 6;
			cat_spot.SetTopLeft(691 - cat_spot.Width() + 15, 284);
		}
		else if (stage7.Left() < point.x && point.x < stage7.Left() + stage7.Width() && stage7.Top() < point.y && point.y < stage7.Top() + stage7.Height()) {
			stagenum = 7;
			cat_spot.SetTopLeft(603 - cat_spot.Width() + 15, 356);
		}
		else if (stage8.Left() < point.x && point.x < stage8.Left() + stage8.Width() && stage8.Top() < point.y && point.y < stage8.Top() + stage8.Height()) {
			stagenum = 8;
			cat_spot.SetTopLeft(323 - cat_spot.Width() + 15, 443);
		}
		else if (stage9.Left() < point.x && point.x < stage9.Left() + stage9.Width() && stage9.Top() < point.y && point.y < stage9.Top() + stage9.Height()) {
			stagenum = 9;
			cat_spot.SetTopLeft(208 - cat_spot.Width() + 15, 198);
		}
		else if (stage10.Left() < point.x && point.x < stage10.Left() + stage10.Width() && stage10.Top() < point.y && point.y < stage10.Top() + stage10.Height()) {
			stagenum = 10;
			cat_spot.SetTopLeft(437 - cat_spot.Width() + 15, 82);
		}
		else if (battle.Left() < point.x && point.x < battle.Left() + battle.Width() && battle.Top() < point.y && point.y < battle.Top() + battle.Height()) {
			CAudio::Instance()->Stop(AUDIO_OP);
			GotoGameState(GAME_STATE_RUN);
		}
	}
}

void CGameStateInit::OnShow()
{
	if (win_state == 0) {
		logo.ShowBitmap();
		start.ShowBitmap(start_size);
		option.ShowBitmap(option_size);
	}
	else if (win_state == 1) {
		logo.ShowBitmap();
		win_option.ShowBitmap();
		if (music_op)
			musicSound.ShowBitmap(music_sound_size);
		else
			musicSoundAnti.ShowBitmap(music_sound_size);
		if (music_game)
			gameSound.ShowBitmap(game_sound_size);
		else
			gameSoundAnti.ShowBitmap(game_sound_size);
		close.ShowBitmap(close_size);
	}
	else {
		state_back.ShowBitmap();
		map.ShowBitmap();
		goBack.ShowBitmap(goBack_size);
		stage1.ShowBitmap(stage1_size);
		stage2.ShowBitmap(stage2_size);
		stage3.ShowBitmap(stage3_size);
		stage4.ShowBitmap(stage4_size);
		stage5.ShowBitmap(stage5_size);
		stage6.ShowBitmap(stage6_size);
		stage7.ShowBitmap(stage7_size);
		stage8.ShowBitmap(stage8_size);
		stage9.ShowBitmap(stage9_size);
		stage10.ShowBitmap(stage10_size);
		battle.ShowBitmap(battle_size);
		cat_spot.ShowBitmap(0.6);
	}
	CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC
	CFont f,*fp;
	f.CreatePointFont(160,"Times New Roman");	// 產生 font f; 160表示16 point的字
	fp=pDC->SelectObject(&f);					// 選用 font f
	pDC->SetBkColor(RGB(0,0,0));
	pDC->SetTextColor(RGB(255,255,0));
	char str[80];								// Demo 數字對字串的轉換
	sprintf(str, "%d, %d", x, y);
	pDC->TextOut(240,210,str);
	pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
}								

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的結束狀態(Game Over)
/////////////////////////////////////////////////////////////////////////////

CGameStateOver::CGameStateOver(CGame *g)
: CGameState(g)
{
}

void CGameStateOver::OnMove()
{
	counter--;
	if (counter < 0)
		GotoGameState(GAME_STATE_INIT);
}

void CGameStateOver::OnBeginState()
{
	win.SetTopLeft((SIZE_X - back.Width()) / 2, 170);
	lose.SetTopLeft((SIZE_X - back.Width()) / 2, 170);
	counter = 30 * 2; // 5 seconds
}

void CGameStateOver::OnInit()
{
	win.LoadBitmap(IDB_WIN, (0, 0, 255));
	lose.LoadBitmap(IDB_LOSE, (0, 0, 255));
	back.LoadBitmap(IDB_OVERBACK);
	back.SetTopLeft((SIZE_X - back.Width()) / 2, 0);
	ShowInitProgress(66);	// 接個前一個狀態的進度，此處進度視為66%
	//
	// 開始載入資料
	//
	//
	// 最終進度為100%
	//
	ShowInitProgress(100);
}

void CGameStateOver::OnShow()
{
	CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
	CFont f,*fp;
	f.CreatePointFont(160,"Times New Roman");	// 產生 font f; 160表示16 point的字
	fp=pDC->SelectObject(&f);					// 選用 font f
	pDC->SetBkColor(RGB(0,0,0));
	pDC->SetTextColor(RGB(255,255,0));
	char str[80];								// Demo 數字對字串的轉換
	sprintf(str, "Game Over ! (%d)", counter / 30);
	pDC->TextOut(240,210,str);
	pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
	CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
	back.ShowBitmap();
	if (win_lose == 1)
	win.ShowBitmap();
	else
	lose.ShowBitmap();
}

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g)
: CGameState(g)
{
	sf = new SimpleFactory();
	//stage = sf->GetStage(1);
}

CGameStateRun::~CGameStateRun()
{
	delete sf;
	if (stage != nullptr) {
		TRACE("\n%d\n", 111111111);
		delete stage;
	}
	if (!cat_enemy.empty())
	{
		for (int i = 0; i < (int)cat_enemy.size(); i++) {
			delete cat_enemy[i];
		}
		cat_enemy.clear();
	}
	if (!cat_friend.empty())
	{
		for (int i = 0; i < (int)cat_friend.size(); i++) {
			delete cat_friend[i];
		}
		cat_friend.clear();
	}
}

void CGameStateRun::OnBeginState()
{
	addPoint = 1;
	//cat_enemy.clear();
	//cat_friend.clear();
	if (!cat_enemy.empty())
	{
		for (int i = 0; i < (int)cat_enemy.size(); i++) {
			delete cat_enemy[i];
		}
		cat_enemy.clear();
	}
	if (!cat_friend.empty())
	{
		for (int i = 0; i < (int)cat_friend.size(); i++) {
			delete cat_friend[i];
		}
		cat_friend.clear();
	}
	callPoint.SetInteger(0);
	callPoint.SetTopLeft(820, 0);
	callPointTotal.SetInteger(50);
	callPointTotal.SetTopLeft(1000, 0);
	friendTowerBlood.SetInteger(5000);
	friendTowerBlood.SetTopLeft(900, 220);
	friendTowerBloodTotal.SetInteger(5000);
	friendTowerBloodTotal.SetTopLeft(980, 220);
	enemyTowerBlood.SetInteger(500);
	enemyTowerBlood.SetTopLeft(-30, 220);
	enemyTowerBloodTotal.SetInteger(500);
	enemyTowerBloodTotal.SetTopLeft(50, 220);
	slash.SetTopLeft(970, 5);
	slash_T.SetTopLeft(1100, 225);
	slash_T_1.SetTopLeft(170, 225);
	upgradePoint.SetInteger(40);
	upgradePoint.SetTopLeft(-15, 690);
	//background.SetTopLeft((SIZE_X - background.Width()) / 2, 0);
	if (stage != nullptr)
		delete stage;
	stage = sf->GetStage(stagenum);
	stage->LoadBack();
	upgrade.SetTopLeft((SIZE_X - stage->GetBackWidth()) / 2, 555);
	upgrade_black.SetTopLeft((SIZE_X - stage->GetBackWidth()) / 2, 555);
	if (music_game) {
		CAudio::Instance()->Play(AUDIO_NORM, true);
		CAudio::Instance()->Play(AUDIO_HARD, true);
	}
	else {
		CAudio::Instance()->Stop(AUDIO_NORM);
		CAudio::Instance()->Stop(AUDIO_HARD);
	}
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	stage->countEnemyNum();
	int num = stage->getEnemyNum();
	int weight = 1;
	if (num != -1)
		cat_enemy.push_back(new Cat_enemy(data_enemy[num][0], stoi(data_enemy[num][2]) * weight, stoi(data_enemy[num][1]) * (weight / 10 + 1), stoi(data_enemy[num][3]), stoi(data_enemy[num][4]), stoi(data_enemy[num][8]), stoi(data_enemy[num][9]), stoi(data_enemy[num][5])));
	if (enemyTowerBlood.GetInteger() <= 0) {
		win_lose = 1;
		CAudio::Instance()->Stop(AUDIO_NORM);
		CAudio::Instance()->Stop(AUDIO_HARD);
		GotoGameState(GAME_STATE_OVER);
	}
	else if (friendTowerBlood.GetInteger() <= 0){
		win_lose = 0;
		CAudio::Instance()->Stop(AUDIO_NORM);
		CAudio::Instance()->Stop(AUDIO_HARD);
		GotoGameState(GAME_STATE_OVER);
	}
	VectorSort();
	if (callPoint.GetInteger() < callPointTotal.GetInteger())
		callPoint.Add(addPoint);
	if (callPoint.GetInteger() > callPointTotal.GetInteger())
		callPoint.SetInteger(callPointTotal.GetInteger());
	for (int i = 0; i < (int)cat_enemy.size(); i++) {
		if (!cat_friend.empty()) {
			cat_enemy[i]->isThere(cat_friend[0]->GetAttackRange());
			cat_enemy[i]->OnMove();//cat_friend[0]->BeAttack(cat_enemy[i]->BeAttack());
			if (cat_enemy[i]->GetIsFinalAttack() && cat_enemy[i]->GetIsAttack()) {
				cat_friend[0]->BeAttack(cat_enemy[i]->GetAttackPoint());
				cat_enemy[i]->SetAnimationReset();
				continue;
			}
		}
		else if(cat_enemy[i]->isThere(friendTowerHitRange)){
			cat_enemy[i]->OnMove();
			if (cat_enemy[i]->GetIsFinalAttack() && cat_enemy[i]->GetIsAttack()) {
				tower_friend.BeAttack(cat_enemy[i]->GetAttackPoint());
				friendTowerBlood.Add(-(cat_enemy[i]->GetAttackPoint()));
				cat_enemy[i]->SetAnimationReset();
				continue;
			}
		}
		else {
			cat_enemy[i]->ReOnMove();
		}
	}
	for (int i = 0; i < (int)cat_friend.size(); i++) {
		if (!cat_enemy.empty()) {
			cat_friend[i]->isThere(cat_enemy[0]->GetAttackRange());
			cat_friend[i]->OnMove();//cat_friend[0]->BeAttack(cat_enemy[i]->BeAttack());
			if (cat_friend[i]->GetIsFinalAttack() && cat_friend[i]->GetIsAttack()) {
				cat_enemy[0]->BeAttack(cat_friend[i]->GetAttackPoint());
				cat_friend[i]->SetAnimationReset();
				continue;
			}
		}
		else if(cat_friend[i]->isThere(enemyTowerHitRange)){
			cat_friend[i]->OnMove();
			if (cat_friend[i]->GetIsFinalAttack() && cat_friend[i]->GetIsAttack()) {
				tower_enemy.BeAttack(cat_friend[i]->GetAttackPoint());
				enemyTowerBlood.Add(-(cat_friend[i]->GetAttackPoint()));
				cat_friend[i]->SetAnimationReset();
				continue;
			}
		}
		else {
			cat_friend[i]->ReOnMove();
		}
	}
}

void CGameStateRun::DeleteDeadCat(int position, bool side) {
	if (side) {
		//delete[] cat_enemy[position];
		swap(cat_enemy[0], cat_enemy[cat_enemy.size() - 1]);
		delete cat_enemy[cat_enemy.size() - 1];
		cat_enemy.pop_back();
		//cat_enemy.shrink_to_fit();
	}
	else {
		swap(cat_friend[0], cat_friend[cat_friend.size() - 1]);
		delete cat_friend[cat_friend.size() - 1];
		cat_friend.pop_back();
		//cat_friend.shrink_to_fit();
	}
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	readCSV();
	ShowInitProgress(33);
	//background.LoadBitmap(IDB_BACK1);
	tower_friend.LoadBitmap();
	tower_enemy.LoadBitmap();
	slash.LoadBitmap(IDB_SLASH, (0, 0, 255));
	slash_T.LoadBitmap(IDB_SLASH_T, (0, 0, 255));
	slash_T_1.LoadBitmap(IDB_SLASH_T, (0, 0, 255));
	upgrade.LoadBitmap(IDB_UPGRADE, (0, 0, 255));
	upgrade_black.LoadBitmap(IDB_UPGRADE_BLACK, (0, 0, 255));
	unsigned i = 0;
	for (i = 0; i < data_friend.size(); i++) {
		string path = ".\\res\\cat\\" + data_friend[i][0] + "\\" + data_friend[i][0] + "_f_uni" + ".bmp";
		char* cpath = (char*)path.c_str();
		block[i].LoadBitmap(cpath, RGB(1, 1, 1));
	}
	for (int j = i; j < 5; j++)
		block[j].LoadBitmap(IDB_EMPTY_BLOCK, (0, 0, 255));
	callPoint.LoadBitmap();
	callPointTotal.LoadBitmap();
	friendTowerBlood.LoadBitmap();
	friendTowerBloodTotal.LoadBitmap();
	enemyTowerBlood.LoadBitmap();
	enemyTowerBloodTotal.LoadBitmap();
	upgradePoint.LoadBitmap();
	ShowInitProgress(50);
	this->enemyTowerHitRange = tower_enemy.GetHitBox();
	this->friendTowerHitRange = tower_friend.GetHitBox();
	CAudio::Instance()->Load(AUDIO_NORM, "Sounds\\NORM.mp3");
	CAudio::Instance()->Load(AUDIO_HARD, "Sounds\\HARD.mp3");
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == 0x31) {				//1
		cat_friend.push_back(new Cat_friend(data_friend[0][0], stoi(data_friend[0][2]), stoi(data_friend[0][1]), stoi(data_friend[0][3]), stoi(data_friend[0][4]), stoi(data_friend[0][8]), stoi(data_friend[0][9]), stoi(data_friend[0][5])));
		callPoint.Add(-stoi(data_friend[0][10]));
	}
	else if (nChar == 0x32) {			//2
		cat_friend.push_back(new Cat_friend(data_friend[1][0], stoi(data_friend[1][2]), stoi(data_friend[1][1]), stoi(data_friend[1][3]), stoi(data_friend[1][4]), stoi(data_friend[1][8]), stoi(data_friend[1][9]), stoi(data_friend[1][5])));
		callPoint.Add(-stoi(data_friend[1][10]));
	}
	else if (nChar == 0x33) {			//3
		cat_friend.push_back(new Cat_friend(data_friend[2][0], stoi(data_friend[2][2]), stoi(data_friend[2][1]), stoi(data_friend[2][3]), stoi(data_friend[2][4]), stoi(data_friend[2][8]), stoi(data_friend[2][9]), stoi(data_friend[2][5])));
		callPoint.Add(-stoi(data_friend[2][10]));
	}
	else if (nChar == 0x34) {			//4
		cat_friend.push_back(new Cat_friend(data_friend[3][0], stoi(data_friend[3][2]), stoi(data_friend[3][1]), stoi(data_friend[3][3]), stoi(data_friend[3][4]), stoi(data_friend[3][8]), stoi(data_friend[3][9]), stoi(data_friend[3][5])));
		callPoint.Add(-stoi(data_friend[3][10]));
	}
	else if (nChar == 0x35) {			//5
		cat_friend.push_back(new Cat_friend(data_friend[4][0], stoi(data_friend[4][2]), stoi(data_friend[4][1]), stoi(data_friend[4][3]), stoi(data_friend[4][4]), stoi(data_friend[4][8]), stoi(data_friend[4][9]), stoi(data_friend[4][5])));
		callPoint.Add(-stoi(data_friend[3][10]));
	}
	else if (nChar == 0x55 && callPoint.GetInteger() >= upgradePoint.GetInteger())		//u
	{
		callPoint.Add(-(upgradePoint.GetInteger()));
		upgradePoint.Add(40);
		callPointTotal.Add(50);
		addPoint += 1;
	}
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{//name, hp, ap, dp, ms, attack_pic, walk_pic, as
	if (block[0].Left() < point.x && point.x < block[0].Left() + block[0].Width() && block[0].Top() < point.y && point.y < block[0].Top() + block[0].Height() && callPoint.GetInteger() >= stoi(data_friend[0][10])) {				//1
		cat_friend.push_back(new Cat_friend(data_friend[0][0], stoi(data_friend[0][2]), stoi(data_friend[0][1]), stoi(data_friend[0][3]), stoi(data_friend[0][4]), stoi(data_friend[0][8]), stoi(data_friend[0][9]), stoi(data_friend[0][5])));
		callPoint.Add(-stoi(data_friend[0][10]));
	}
	else if (block[1].Left() < point.x && point.x < block[1].Left() + block[1].Width() && block[1].Top() < point.y && point.y < block[1].Top() + block[1].Height() && callPoint.GetInteger() >= stoi(data_friend[1][10])) {			//2
		cat_friend.push_back(new Cat_friend(data_friend[1][0], stoi(data_friend[1][2]), stoi(data_friend[1][1]), stoi(data_friend[1][3]), stoi(data_friend[1][4]), stoi(data_friend[1][8]), stoi(data_friend[1][9]), stoi(data_friend[1][5])));
		callPoint.Add(-stoi(data_friend[1][10]));
	}
	else if (block[2].Left() < point.x && point.x < block[2].Left() + block[2].Width() && block[0].Top() < point.y && point.y < block[2].Top() + block[2].Height() && callPoint.GetInteger() >= stoi(data_friend[2][10])) {			//3
		cat_friend.push_back(new Cat_friend(data_friend[2][0], stoi(data_friend[2][2]), stoi(data_friend[2][1]), stoi(data_friend[2][3]), stoi(data_friend[2][4]), stoi(data_friend[2][8]), stoi(data_friend[2][9]), stoi(data_friend[2][5])));
		callPoint.Add(-stoi(data_friend[2][10]));
	}
	else if (block[3].Left() < point.x && point.x < block[3].Left() + block[3].Width() && block[0].Top() < point.y && point.y < block[3].Top() + block[3].Height() && callPoint.GetInteger() >= stoi(data_friend[3][10])) {			//4
		cat_friend.push_back(new Cat_friend(data_friend[3][0], stoi(data_friend[3][2]), stoi(data_friend[3][1]), stoi(data_friend[3][3]), stoi(data_friend[3][4]), stoi(data_friend[3][8]), stoi(data_friend[3][9]), stoi(data_friend[3][5])));
		callPoint.Add(-stoi(data_friend[3][10]));
	}
	else if (block[4].Left() < point.x && point.x < block[4].Left() + block[4].Width() && block[0].Top() < point.y && point.y < block[4].Top() + block[4].Height() && callPoint.GetInteger() >= stoi(data_friend[4][10])) {			//5
		cat_friend.push_back(new Cat_friend(data_friend[4][0], stoi(data_friend[4][2]), stoi(data_friend[4][1]), stoi(data_friend[4][3]), stoi(data_friend[4][4]), stoi(data_friend[4][8]), stoi(data_friend[4][9]), stoi(data_friend[4][5])));
		callPoint.Add(-stoi(data_friend[3][10]));
	}
	else if (upgrade.Left() < point.x && point.x < upgrade.Left() + upgrade.Width() && upgrade.Top() < point.y && point.y < upgrade.Top() + upgrade.Height() && callPoint.GetInteger() >= upgradePoint.GetInteger())		//u
	{
		callPoint.Add(-(upgradePoint.GetInteger()));
		upgradePoint.Add(40);
		callPointTotal.Add(50);
		addPoint += 1;
	}
	/*
	win_lose = 1;
	CAudio::Instance()->Stop(AUDIO_NORM);
	CAudio::Instance()->Stop(AUDIO_HARD);
	GotoGameState(GAME_STATE_OVER);*/
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	// 沒事。如果需要處理滑鼠移動的話，寫code在這裡
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
	
}
//塔升級 每次40加50 最高8等
void CGameStateRun::OnShow()
{
	//background.ShowBitmap();
	stage->OnShowBack();
	for (int i = 0; i < 5; i++) {
		block[i].SetTopLeft(330 + 160 * i, 600);
		block[i].ShowBitmap();
	}
	tower_friend.OnShow();
	tower_enemy.OnShow();
	callPoint.ShowBitmap();
	callPointTotal.ShowBitmap();
	friendTowerBlood.ShowBitmap();
	friendTowerBloodTotal.ShowBitmap();
	enemyTowerBlood.ShowBitmap();
	enemyTowerBloodTotal.ShowBitmap();
	slash.ShowBitmap(1.2);
	slash_T.ShowBitmap(0.4);
	slash_T_1.ShowBitmap(0.4);
	if (upgradePoint.GetInteger() > callPoint.GetInteger()) {
		upgrade_black.ShowBitmap();
	}
	else {
		upgrade.ShowBitmap();
	}
	upgradePoint.ShowBitmap();
	for (unsigned i = 0; i < cat_enemy.size(); i++) {
		if (!cat_enemy[i]->GetIsAttack())
			cat_enemy[i]->OnShow_Walk();
		else {
			cat_enemy[i]->OnShow_Attack();
			if (cat_enemy[i]->GetReset())
				cat_enemy[i]->AnimationReset();
			if (cat_enemy[0]->GetBloodPoint() <= 0) {
				DeleteDeadCat(0, true);
			}
		}
	}
	for (unsigned i = 0; i < cat_friend.size(); i++) {
		if (!cat_friend[i]->GetIsAttack())
			cat_friend[i]->OnShow_Walk();
		else {
			cat_friend[i]->OnShow_Attack();
			if (cat_friend[i]->GetReset())
				cat_friend[i]->AnimationReset();
			if (cat_friend[0]->GetBloodPoint() <= 0) {
				DeleteDeadCat(0, false);
			}
		}
	}
}
void CGameStateRun::VectorSort() {
	for (unsigned i = 1; i < cat_enemy.size(); i++) {
		if (cat_enemy[0]->GetAttackRange() < cat_enemy[i]->GetAttackRange())
			swap(cat_enemy[0], cat_enemy[i]);
	}
	for (unsigned i = 1; i < cat_friend.size(); i++) {
		if (cat_friend[0]->GetAttackRange() > cat_friend[i]->GetAttackRange())
			swap(cat_friend[0], cat_friend[i]);
	}
}

void CGameStateRun::readCSV() {
	//name, ap, hp, dp, ms, as, at, range, attack_pic, walk_pic, cost
	data_enemy = {
		{"e000", "100", "200", "50", "3", "7", "single", "5", "4", "3"},
		{"e001", "100", "200", "50", "3", "7", "single", "5", "4", "4"},
		{"e005", "100", "200", "50", "3", "7", "single", "5", "7", "11"},
		{"e012", "100", "200", "50", "3", "7", "single", "5", "3", "6"},
		{"e013", "100", "200", "50", "3", "7", "single", "5", "3", "6"},
		{"e015", "100", "200", "50", "3", "7", "single", "5", "4", "5"},
		{"e016", "100", "200", "50", "3", "7", "single", "5", "3", "6"},
		{"e018", "100", "200", "50", "3", "7", "single", "5", "3", "3"},
	};
	data_friend = {
		{"f000", "100", "200", "50", "3", "7", "single", "5", "4", "3", "50"},
		{"f001", "100", "200", "50", "2", "7", "single", "5", "4", "3", "50"},
		{"f004", "100", "200", "50", "2", "7", "single", "5", "4", "4", "50"},
		{"f008", "100", "200", "50", "2", "7", "single", "5", "7", "6", "50"},
		{"f018", "100", "200", "50", "2", "3", "single", "5", "8", "4", "50"},
	};
	/*ifstream infile_friend("data_friend.csv", ios::in);
	if (!infile_friend) {
		exit(1);
	}
	string line;
	string str;
	getline(infile_friend, line);
	while (getline(infile_friend, line)) {
		stringstream sstream(line);
		vector<string> one_cat;
		while (getline(sstream, str, ',')) {
			one_cat.push_back(str);
		}
		data_friend.push_back(one_cat);
	}
	ifstream infile_enemy("data_enemy.csv", ios::in);
	if (!infile_enemy) {
		exit(1);
	}
	getline(infile_enemy, line);
	while (getline(infile_enemy, line)) {
		stringstream sstream(line);
		vector<string> one_cat;
		while (getline(sstream, str, ',')) {
			one_cat.push_back(str);
		}
		data_enemy.push_back(one_cat);
	}*/
}
}