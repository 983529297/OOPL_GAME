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
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
	ShowInitProgress(0);	// 一開始的loading進度為0%
	//
	// 開始載入資料
	//
	logo.LoadBitmap(IDB_OPEND);
	start.LoadBitmap(IDB_START, (0, 0, 255));
	start.SetTopLeft(SIZE_X / 2 - 185, 399);//SIZE_Y/8);
	start_size = 0.81;
	//
	// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
	//
	ready = true;
}

void CGameStateInit::OnBeginState()
{
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
	if (ready) {
		if (start.Left() < point.x && point.x < start.Left() + start.Width() && start.Top() < point.y && point.y < start.Top() + start.Height()) {
			start_size = 0.9;
			start.SetTopLeft(SIZE_X / 2 - 205, 390);//SIZE_Y/8);
		}
		else {
			start.SetTopLeft(SIZE_X / 2 - 185, 399);//SIZE_Y/8);
			start_size = 0.81;
		}
	}
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (start.Left() < point.x && point.x < start.Left() + start.Width() && start.Top() < point.y && point.y < start.Top() + start.Height())
		GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
}

void CGameStateInit::OnShow()
{
	logo.SetTopLeft((SIZE_X - logo.Width()) / 2, 0);//SIZE_Y/8);
	logo.ShowBitmap();
	start.ShowBitmap(start_size);
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
	counter = 30 * 5; // 5 seconds
}

void CGameStateOver::OnInit()
{
	//
	// 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
	//     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	//
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
	CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
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
}

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame *g)
: CGameState(g)
{
}

CGameStateRun::~CGameStateRun()
{
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
	cat_enemy.clear();
	cat_friend.clear();
	callPoint.SetInteger(0);
	callPoint.SetTopLeft(820, 0);
	callPointTotal.SetInteger(50);
	callPointTotal.SetTopLeft(1000, 0);
	friendTowerBlood.SetInteger(500);
	friendTowerBlood.SetTopLeft(900, 220);
	friendTowerBloodTotal.SetInteger(500);
	friendTowerBloodTotal.SetTopLeft(980, 220);
	enemyTowerBlood.SetInteger(500);
	enemyTowerBlood.SetTopLeft(-30, 220);
	enemyTowerBloodTotal.SetInteger(500);
	enemyTowerBloodTotal.SetTopLeft(50, 220);
	slash.SetTopLeft(970, 5);
	slash_T.SetTopLeft(1100, 225);
	slash_T_1.SetTopLeft(170, 225);
	upgradePoint.SetInteger(40);
	upgradePoint.SetTopLeft(50, 50);
	background.SetTopLeft((SIZE_X - background.Width()) / 2, 0);
	upgrade.SetTopLeft((SIZE_X - background.Width()) / 2, 555);
	upgrade_black.SetTopLeft((SIZE_X - background.Width()) / 2, 555);
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	VectorSort();
	if (callPoint.GetInteger() < callPointTotal.GetInteger())
		callPoint.Add(1);
	for (int i = 0; i < (int)cat_enemy.size(); i++) {
		if (!cat_friend.empty()) {
			cat_enemy[i]->isThere(cat_friend[0]->GetAttackRange());
			cat_enemy[i]->OnMove();//cat_friend[0]->BeAttack(cat_enemy[i]->BeAttack());
			if (cat_enemy[i]->GetIsFinalAttack() && cat_enemy[i]->GetIsAttack()) {
				cat_friend[0]->BeAttack(cat_enemy[i]->GetAttackPoint());
				cat_enemy[i]->AnimationReset();
				continue;
			}
		}
		else if(cat_enemy[i]->isThere(friendTowerHitRange)){
			cat_enemy[i]->OnMove();
			if (cat_enemy[i]->GetIsFinalAttack() && cat_enemy[i]->GetIsAttack()) {
				tower_friend.BeAttack(cat_enemy[i]->GetAttackPoint());
				friendTowerBlood.Add(-(cat_enemy[i]->GetAttackPoint()));
				cat_enemy[i]->AnimationReset();
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
				cat_friend[i]->AnimationReset();
				continue;
			}
		}
		else if(cat_friend[i]->isThere(enemyTowerHitRange)){
			cat_friend[i]->OnMove();
			if (cat_friend[i]->GetIsFinalAttack() && cat_friend[i]->GetIsAttack()) {
				tower_enemy.BeAttack(cat_friend[i]->GetAttackPoint());
				enemyTowerBlood.Add(-(cat_friend[i]->GetAttackPoint()));
				cat_friend[i]->AnimationReset();
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
	ShowInitProgress(33);
	background.LoadBitmap(IDB_BACK1);
	tower_friend.LoadBitmap();
	tower_enemy.LoadBitmap();
	slash.LoadBitmap(IDB_SLASH, (0, 0, 255));
	slash_T.LoadBitmap(IDB_SLASH_T, (0, 0, 255));
	slash_T_1.LoadBitmap(IDB_SLASH_T, (0, 0, 255));
	upgrade.LoadBitmap(IDB_UPGRADE, (0, 0, 255));
	upgrade_black.LoadBitmap(IDB_UPGRADE_BLACK, (0, 0, 255));
	for (int i = 0; i < 5; i++)
		empty_block[i].LoadBitmap(IDB_EMPTY_BLOCK, (0, 0, 255));
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
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == 0x25)
		cat_enemy.push_back(new Cat_enemy("dog", 100, 50, 100, 10));
	else if (nChar == 0x26)
		cat_friend.push_back(new Cat_friend("marshmellow", 100, 100, 100, 5));
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	GotoGameState(GAME_STATE_OVER);
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
	
	background.ShowBitmap();
	for (int i = 0; i < 5; i++) {
		empty_block[i].SetTopLeft(330 + 160 * i, 600);
		empty_block[i].ShowBitmap();
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
	for (unsigned i = 0; i < cat_enemy.size(); i++) {
		if (!cat_enemy[i]->GetIsAttack())
			cat_enemy[i]->OnShow_Walk();
		else {
			cat_enemy[i]->OnShow_Attack();
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
}