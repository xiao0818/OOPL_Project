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
		logo.LoadBitmap(IDB_START_TITLE);
		logoWithPlay.LoadBitmap(IDB_START_TITLE_WITH_PLAY);
		Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
		//
		// 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
		//
		CAudio::Instance()->Load(AUDIO_MENU, ".\\Resources\\audio\\Square_Meal_Menu.mp3");
		CAudio::Instance()->Load(AUDIO_MAIN, ".\\Resources\\audio\\Square_Meal_Main.mp3");
		CAudio::Instance()->Load(SOUND_SWALLOW, ".\\Resources\\sound\\swallow.mp3");
		CAudio::Instance()->Load(SOUND_SPIT_OUT, ".\\Resources\\sound\\spit_out.mp3");
		CAudio::Instance()->Load(SOUND_BRICK_HIT, ".\\Resources\\sound\\brick_hit.mp3");
		CAudio::Instance()->Load(SOUND_FAIL, ".\\Resources\\sound\\fail.mp3");
	}		

	void CGameStateInit::OnBeginState()
	{
	}

	void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		//const char KEY_ESC = 27;
		//const char KEY_SPACE = ' ';
		//if (nChar == KEY_SPACE)
		//	GotoGameState(GAME_STATE_RUN);						// 切換至GAME_STATE_RUN
		//else if (nChar == KEY_ESC)								// Demo 關閉遊戲的方法
		//	PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0);	// 關閉遊戲
	}

	void CGameStateInit::OnMouseMove(UINT nFlags, CPoint point)
	{
		if ((300 + 445) < point.x && point.x < (300 + 555) && (88 + 496) < point.y && point.y < (88 + 526))
		{
			isOnPlayButton = true;
		}
		else
		{
			isOnPlayButton = false;
		}
	}

	void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
	{
		if (isOnPlayButton)
		{
			GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
		}
	}

	void CGameStateInit::OnShow()
	{
		//
		// 貼上logo
		//
		if (isOnPlayButton)
		{
			logoWithPlay.SetTopLeft((SIZE_X - logo.Width()) / 2, (SIZE_Y - logo.Height()) / 2);
			logoWithPlay.ShowBitmap();
		}
		else
		{
			logo.SetTopLeft((SIZE_X - logo.Width()) / 2, (SIZE_Y - logo.Height()) / 2);
			logo.ShowBitmap();
		}
		//
		// Demo螢幕字型的使用，不過開發時請盡量避免直接使用字型，改用CMovingBitmap比較好
		//
		//CDC *pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC 
		//CFont f,*fp;
		//f.CreatePointFont(160,"Times New Roman");	// 產生 font f; 160表示16 point的字
		//fp=pDC->SelectObject(&f);					// 選用 font f
		//pDC->SetBkColor(RGB(0,0,0));
		//pDC->SetTextColor(RGB(255,255,0));
		//pDC->TextOut(120,220,"Please click mouse or press SPACE to begin.");
		//pDC->TextOut(5,395,"Press Ctrl-F to switch in between window mode and full screen mode.");
		//if (ENABLE_GAME_PAUSE)
		//	pDC->TextOut(5,425,"Press Ctrl-Q to pause the Game.");
		//pDC->TextOut(5,455,"Press Alt-F4 or ESC to Quit.");
		//pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
		//CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
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
		{
			CAudio::Instance()->Play(AUDIO_MENU, true);
			CAudio::Instance()->Stop(AUDIO_MAIN);
			GotoGameState(GAME_STATE_INIT);
		}
	}

	void CGameStateOver::OnBeginState()
	{
		CAudio::Instance()->Stop(AUDIO_MENU);
		CAudio::Instance()->Stop(AUDIO_MAIN);

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
		Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
		//
		// 最終進度為100%
		//
		ShowInitProgress(100);

		CAudio::Instance()->Play(AUDIO_MENU, true);
		CAudio::Instance()->Stop(AUDIO_MAIN);
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
	}

	void CGameStateRun::OnBeginState()
	{
		CAudio::Instance()->Stop(AUDIO_MENU);
		CAudio::Instance()->Play(AUDIO_MAIN, true);

		const int BRICK_LENGTH = 72;
		const int BRICK_WIDTH = 48;
		const int GROUND_X = (SIZE_X - BRICK_LENGTH * 14) / 2;
		const int GROUND_Y = (SIZE_Y - BRICK_WIDTH * 14) / 2;
		ground.SetXY(GROUND_X, GROUND_Y);

		wall.clear();
		brick.clear();
		food.clear();
		monster.clear();

		gameEndConut = 0;

		grade.SetInteger(0);
		grade.SetTopLeft(GROUND_X, GROUND_Y - 48);

		map.Initialize();

		player.Initialize(&map);

		for (int i = 0; i < 14; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				if (map.GetPlayerInMap(i, j) == CName::PLAYER)
				{
					player.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
				}
				else if(map.GetMonsterInMap(i, j) == CName::MUD)
				{
					CMud tempMud;
					tempMud.Initialize(&map);
					tempMud.LoadBitmap();
					tempMud.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					monster.push_back(tempMud);
				}
				else if (map.GetMonsterInMap(i, j) == CName::TURTLE) {
					CTurtle tempTurtle;
					tempTurtle.Initialize(&map);
					tempTurtle.LoadBitmap();
					tempTurtle.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					monster.push_back(tempTurtle);
				}
				else if (map.GetBrickInMap(i, j) == CName::WALL)
				{
					CWall tempWall;
					tempWall.LoadBitmap();
					tempWall.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					wall.push_back(tempWall);
				}
				else if (map.GetBrickInMap(i, j) == CName::STONE)
				{
					CStone tempStone;
					tempStone.Initialize(&map, &monster);
					tempStone.LoadBitmap();
					tempStone.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					brick.push_back(tempStone);
				}
				else if (map.GetBrickInMap(i, j) == CName::WOODEN)
				{
					CWooden tempWooden;
					tempWooden.Initialize(&map, &monster);
					tempWooden.LoadBitmap();
					tempWooden.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					brick.push_back(tempWooden);
				}
				else if (map.GetBrickInMap(i, j) == CName::STEEL)
				{
					CSteel tempSteel;
					tempSteel.Initialize(&map, &monster);
					tempSteel.LoadBitmap();
					tempSteel.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					brick.push_back(tempSteel);
				}
				else if (map.GetFoodInMap(i, j) == CName::APPLE || map.GetFoodInMap(i, j) == CName::BREAD || map.GetFoodInMap(i, j) == CName::CARROT || map.GetFoodInMap(i, j) == CName::EGG || map.GetFoodInMap(i, j) == CName::GRAPE || map.GetFoodInMap(i, j) == CName::MUTTON || map.GetFoodInMap(i, j) == CName::PIE || map.GetFoodInMap(i, j) == CName::TOMATO || map.GetFoodInMap(i, j) == CName::TURKEY)
				{
					CFood tempFood;
					tempFood.Initialize(&map);
					tempFood.LoadBitmap(map.GetFoodInMap(i, j));
					tempFood.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					food.push_back(tempFood);
				}
			}
		}
	}

	void CGameStateRun::OnMove()
	{
		player.OnMove();
		for (list<CBrick>::iterator k = brick.begin(); k != brick.end(); k++)
		{
			k->OnMove();
		}
		for (list<CFood>::iterator k = food.begin(); k != food.end(); k++)
		{
			k->OnMove();
		}
		for (list<CMonster>::iterator m = monster.begin(); m != monster.end(); m++)
		{
			m->OnMove();
		}

		bool gameAliveFlag = false;
		for (list<CMonster>::iterator m = monster.begin(); m != monster.end(); m++)
		{
			gameAliveFlag = gameAliveFlag || m->IsAlive();
		}
		if (gameAliveFlag == false)
		{
			gameEndConut++;
			if (gameEndConut == 5 * 30)
			{
				GotoGameState(GAME_STATE_OVER);
			}
		}
	}

	void CGameStateRun::OnInit()
	{
		ShowInitProgress(33);

		ground.LoadBitmap();
		grade.LoadBitmap();
		player.LoadBitmap();

		ShowInitProgress(50);
		Sleep(300);
	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard左箭頭
		const char KEY_UP = 0x26; // keyboard上箭頭
		const char KEY_RIGHT = 0x27; // keyboard右箭頭
		const char KEY_DOWN = 0x28; // keyboard下箭頭
		const char KEY_SPACE = ' ';
		if (nChar == KEY_LEFT)
			player.SetMovingLeft(true);
		if (nChar == KEY_RIGHT)
			player.SetMovingRight(true);
		if (nChar == KEY_UP)
			player.SetMovingUp(true);
		if (nChar == KEY_DOWN)
			player.SetMovingDown(true);
		if (nChar == KEY_SPACE)
			player.PressKeySpace(&grade, brick, food, monster);
	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard左箭頭
		const char KEY_UP = 0x26; // keyboard上箭頭
		const char KEY_RIGHT = 0x27; // keyboard右箭頭
		const char KEY_DOWN = 0x28; // keyboard下箭頭
		if (nChar == KEY_LEFT)
			player.SetMovingLeft(false);
		if (nChar == KEY_RIGHT)
			player.SetMovingRight(false);
		if (nChar == KEY_UP)
			player.SetMovingUp(false);
		if (nChar == KEY_DOWN)
			player.SetMovingDown(false);
	}

	void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)
	{
	}

	void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)
	{
	}

	void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)
	{
	}

	void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)
	{
	}

	void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)
	{
		GotoGameState(GAME_STATE_OVER);
	}

	void CGameStateRun::OnShow()
	{
		ground.OnShow();
		grade.ShowBitmap();

		for (int j = 0; j < 14; j++)
		{
			for (list<CWall>::iterator k = wall.begin(); k != wall.end(); k++)
			{
				if (k->GetIndexY() == j)
				{
					k->OnShow();
				}
			}
			for (list<CBrick>::iterator k = brick.begin(); k != brick.end(); k++)
			{
				if (k->GetIndexY() == j)
				{
					k->OnShow();
				}
			}
			for (list<CFood>::iterator k = food.begin(); k != food.end(); k++)
			{
				if (k->GetIndexY() == j)
				{
					k->OnShow();
				}
			}
			for (list<CMonster>::iterator m = monster.begin(); m != monster.end(); m++)
			{
				if (m->GetIndexY() == j)
				{
					m->OnShow();
				}
			}
			if (player.GetIndexY() == j)
			{
				player.OnShow();
			}
		}
	}
}