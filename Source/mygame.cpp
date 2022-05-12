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
#include "CAudioId.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲開頭畫面物件
	/////////////////////////////////////////////////////////////////////////////

	CGameStateInit::CGameStateInit(CGame *g, CShareData *data)
	: CGameState(g, data)
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
		startPage.LoadBitmap(IDB_COVER);
		cross.LoadBitmap(IDB_CROSS,RGB(255, 255, 255));
		musicButton.LoadBitmap(IDB_MUSIC);
		soundButton.LoadBitmap(IDB_SOUND);
		backButton.LoadBitmap(IDB_BACK);
		playButton.LoadBitmap(IDB_PLAY);
		scoresButton.LoadBitmap(IDB_SCORES);
		helpButton.LoadBitmap(IDB_HELP);
		creditsButton.LoadBitmap(IDB_CREDITS);
		playerPage.LoadBitmap(IDB_PLAYER_PAGE);
		levelPage.LoadBitmap(IDB_LEVEL);
		scoresPage.LoadBitmap(IDB_SCORES_PAGE);
		creditsPage.LoadBitmap(IDB_CREDITS_PAGE);

		playerButton.AddBitmap(IDB_PLAYER_BUTTON_001);
		playerButton.AddBitmap(IDB_PLAYER_BUTTON_002);
		playerButton.AddBitmap(IDB_PLAYER_BUTTON_003);
		playerButton.AddBitmap(IDB_PLAYER_BUTTON_004);
		playerButton.AddBitmap(IDB_PLAYER_BUTTON_005);
		playerButton.AddBitmap(IDB_PLAYER_BUTTON_006);
		playerButton.AddBitmap(IDB_PLAYER_BUTTON_007);
		playerButton.AddBitmap(IDB_PLAYER_BUTTON_008);

		helpPage.AddBitmap(IDB_HELP_PAGE_001);
		helpPage.AddBitmap(IDB_HELP_PAGE_002);
		helpPage.AddBitmap(IDB_HELP_PAGE_003);
		helpPage.AddBitmap(IDB_HELP_PAGE_004);
		helpPage.AddBitmap(IDB_HELP_PAGE_005);
		helpPage.AddBitmap(IDB_HELP_PAGE_006);
		helpPage.AddBitmap(IDB_HELP_PAGE_007);
		helpPage.AddBitmap(IDB_HELP_PAGE_008);
		helpPage.AddBitmap(IDB_HELP_PAGE_009);
		helpPage.AddBitmap(IDB_HELP_PAGE_010);
		helpPage.AddBitmap(IDB_HELP_PAGE_011);
		helpPage.AddBitmap(IDB_HELP_PAGE_012);
		helpPage.AddBitmap(IDB_HELP_PAGE_013);
		helpPage.AddBitmap(IDB_HELP_PAGE_014);
		helpPage.AddBitmap(IDB_HELP_PAGE_015);
		helpPage.AddBitmap(IDB_HELP_PAGE_016);
		helpPage.AddBitmap(IDB_HELP_PAGE_017);
		helpPage.AddBitmap(IDB_HELP_PAGE_018);
		helpPage.AddBitmap(IDB_HELP_PAGE_019);
		helpPage.AddBitmap(IDB_HELP_PAGE_020);
		helpPage.AddBitmap(IDB_HELP_PAGE_021);
		helpPage.AddBitmap(IDB_HELP_PAGE_022);
		helpPage.AddBitmap(IDB_HELP_PAGE_023);
		helpPage.AddBitmap(IDB_HELP_PAGE_024);
		helpPage.AddBitmap(IDB_HELP_PAGE_025);
		helpPage.AddBitmap(IDB_HELP_PAGE_026);
		helpPage.AddBitmap(IDB_HELP_PAGE_027);
		helpPage.AddBitmap(IDB_HELP_PAGE_028);
		helpPage.AddBitmap(IDB_HELP_PAGE_029);
		helpPage.AddBitmap(IDB_HELP_PAGE_030);
		helpPage.AddBitmap(IDB_HELP_PAGE_031);
		helpPage.AddBitmap(IDB_HELP_PAGE_032);
		helpPage.AddBitmap(IDB_HELP_PAGE_033);
		helpPage.AddBitmap(IDB_HELP_PAGE_034);
		helpPage.AddBitmap(IDB_HELP_PAGE_035);
		helpPage.AddBitmap(IDB_HELP_PAGE_036);
		helpPage.AddBitmap(IDB_HELP_PAGE_037);
		helpPage.AddBitmap(IDB_HELP_PAGE_038);
		helpPage.AddBitmap(IDB_HELP_PAGE_039);
		helpPage.AddBitmap(IDB_HELP_PAGE_040);
		helpPage.AddBitmap(IDB_HELP_PAGE_041);
		helpPage.AddBitmap(IDB_HELP_PAGE_042);
		helpPage.AddBitmap(IDB_HELP_PAGE_043);
		helpPage.AddBitmap(IDB_HELP_PAGE_044);
		helpPage.AddBitmap(IDB_HELP_PAGE_045);
		helpPage.AddBitmap(IDB_HELP_PAGE_046);
		helpPage.AddBitmap(IDB_HELP_PAGE_047);
		helpPage.AddBitmap(IDB_HELP_PAGE_048);
		helpPage.AddBitmap(IDB_HELP_PAGE_049);
		helpPage.AddBitmap(IDB_HELP_PAGE_050);
		helpPage.AddBitmap(IDB_HELP_PAGE_051);
		helpPage.AddBitmap(IDB_HELP_PAGE_052);
		helpPage.AddBitmap(IDB_HELP_PAGE_053);
		helpPage.AddBitmap(IDB_HELP_PAGE_054);
		helpPage.AddBitmap(IDB_HELP_PAGE_055);
		helpPage.AddBitmap(IDB_HELP_PAGE_056);
		helpPage.AddBitmap(IDB_HELP_PAGE_057);
		helpPage.AddBitmap(IDB_HELP_PAGE_058);

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
		isOnMusicButton = isOnSoundButton = isOnBackButton = false;
		isOnPlayButton = isOnScoresButton = isOnHelpButton = isOnCreditsButton = false;
		isOnPlayerButton = isOnLevelButton = false;
		isPlayerPage = isLevelPage = false;
		isScoresPage = isHelpPage = isCreditsPage = false;
		levelSelect = 0;
		shareData->InitializeState();
		playerButton.SetDelayCount(2);
		helpPage.SetDelayCount(2);
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
		const int GROUND_X = (SIZE_X - 1000) / 2;
		const int GROUND_Y = (SIZE_Y - 725) / 2;

		if ((GROUND_X + MUSIC_INDEX_X) < point.x && point.x < (GROUND_X + MUSIC_INDEX_X + CROSS_LENGTH) && (GROUND_Y + MUSIC_INDEX_Y) < point.y && point.y < (GROUND_Y + MUSIC_INDEX_Y + CROSS_HEIGHT))
		{
			isOnMusicButton = true;
		}
		else
		{
			isOnMusicButton = false;
		}

		if ((GROUND_X + SOUND_INDEX_X) < point.x && point.x < (GROUND_X + SOUND_INDEX_X + CROSS_LENGTH) && (GROUND_Y + SOUND_INDEX_Y) < point.y && point.y < (GROUND_Y + SOUND_INDEX_Y + CROSS_HEIGHT))
		{
			isOnSoundButton = true;
		}
		else
		{
			isOnSoundButton = false;
		}

		if (!isPlayerPage && !isLevelPage && !isScoresPage && !isHelpPage && !isCreditsPage)
		{
			if ((GROUND_X + PLAY_BUTTON_INDEX_X) < point.x && point.x < (GROUND_X + PLAY_BUTTON_INDEX_X + PLAY_BUTTON_LENGTH) && (GROUND_Y + PLAY_BUTTON_INDEX_Y) < point.y && point.y < (GROUND_Y + PLAY_BUTTON_INDEX_Y + PLAY_BUTTON_HEIGHT))
			{
				isOnPlayButton = true;
			}
			else
			{
				isOnPlayButton = false;
			}

			if ((GROUND_X + SCORES_BUTTON_INDEX_X) < point.x && point.x < (GROUND_X + SCORES_BUTTON_INDEX_X + SCORES_BUTTON_LENGTH) && (GROUND_Y + SCORES_BUTTON_INDEX_Y) < point.y && point.y < (GROUND_Y + SCORES_BUTTON_INDEX_Y + SCORES_BUTTON_HEIGHT))
			{
				isOnScoresButton = true;
			}
			else
			{
				isOnScoresButton = false;
			}

			if ((GROUND_X + HELP_BUTTON_INDEX_X) < point.x && point.x < (GROUND_X + HELP_BUTTON_INDEX_X + HELP_BUTTON_LENGTH) && (GROUND_Y + HELP_BUTTON_INDEX_Y) < point.y && point.y < (GROUND_Y + HELP_BUTTON_INDEX_Y + HELP_BUTTON_HEIGHT))
			{
				isOnHelpButton = true;
			}
			else
			{
				isOnHelpButton = false;
			}

			if ((GROUND_X + CREDITS_BUTTON_INDEX_X) < point.x && point.x < (GROUND_X + CREDITS_BUTTON_INDEX_X + CREDITS_BUTTON_LENGTH) && (GROUND_Y + CREDITS_BUTTON_INDEX_Y) < point.y && point.y < (GROUND_Y + CREDITS_BUTTON_INDEX_Y + CREDITS_BUTTON_HEIGHT))
			{
				isOnCreditsButton = true;
			}
			else
			{
				isOnCreditsButton = false;
			}
		}
		else
		{
			if ((GROUND_X + BACK_BUTTON_INDEX_X) < point.x && point.x < (GROUND_X + BACK_BUTTON_INDEX_X + BACK_BUTTON_LENGTH) && (GROUND_Y + BACK_BUTTON_INDEX_Y) < point.y && point.y < (GROUND_Y + BACK_BUTTON_INDEX_Y + BACK_BUTTON_HEIGHT))
			{
				isOnBackButton = true;
			}
			else
			{
				isOnBackButton = false;
			}

			if (isLevelPage)
			{
				for (int i = 0; i < 10; i++)
				{
					if ((GROUND_X + FIRST_LEVEL_BUTTON_INDEX_X + NEXT_LEVEL_BUTTON_DISTANCE_X * i) < point.x && point.x < (GROUND_X + FIRST_LEVEL_BUTTON_INDEX_X + NEXT_LEVEL_BUTTON_DISTANCE_X * i + FIRST_LEVEL_BUTTON_LENGTH) && (GROUND_Y + FIRST_LEVEL_BUTTON_INDEX_Y) < point.y && point.y < (GROUND_Y + FIRST_LEVEL_BUTTON_INDEX_Y + FIRST_LEVEL_BUTTON_HEIGHT))
					{
						levelSelect = i + 1;
						isOnLevelButton = true;
						break;
					}
					else
					{
						levelSelect = 0;
						isOnLevelButton = false;
					}
				}
			}
			else if (isPlayerPage)
			{
				if ((GROUND_X + PLAYER_BUTTON_INDEX_X) < point.x && point.x < (GROUND_X + PLAYER_BUTTON_INDEX_X + PLAYER_BUTTON_LENGTH) && (GROUND_Y + PLAYER_BUTTON_INDEX_Y) < point.y && point.y < (GROUND_Y + PLAYER_BUTTON_INDEX_Y + PLAYER_BUTTON_HEIGHT))
				{
					isOnPlayerButton = true;
				}
				else
				{
					isOnPlayerButton = false;
				}
			}
		}
	}

	void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
	{
		if (isOnMusicButton)
		{
			shareData->IsMusicEnable(!shareData->IsMusicEnable());
			if (shareData->IsMusicEnable())
			{
				CAudio::Instance()->Play(AUDIO_MENU, true);
				CAudio::Instance()->Stop(AUDIO_MAIN);
			}
			else
			{
				CAudio::Instance()->Stop(AUDIO_MENU);
				CAudio::Instance()->Stop(AUDIO_MAIN);
			}
			isOnMusicButton = false;
		}
		else if (isOnSoundButton)
		{
			shareData->IsSoundEnable(!shareData->IsSoundEnable());
			isOnSoundButton = false;
		}
		else if (isOnBackButton)
		{
			if (isLevelPage)
			{
				isLevelPage = false;
				isPlayerPage = true;
			}
			else if (isPlayerPage || isScoresPage || isHelpPage || isCreditsPage)
			{
				isPlayerPage = isScoresPage = isHelpPage = isCreditsPage = false;
			}
			isOnBackButton = false;
		}
		else if (isOnLevelButton)
		{
			shareData->SetSelectedLevelIndex(levelSelect);
			GotoGameState(GAME_STATE_RUN);
			isOnLevelButton = false;
		}
		else if (isOnPlayerButton)
		{
			isLevelPage = true;
			isPlayerPage = false;
			isOnPlayerButton = false;
		}
		else if (isOnPlayButton)
		{
			isPlayerPage = true;
			isOnPlayButton = false;
		}
		else if (isOnScoresButton)
		{
			isScoresPage = true;
			isOnScoresButton = false;
		}
		else if (isOnHelpButton)
		{
			isHelpPage = true;
			helpPage.Reset();
			isOnHelpButton = false;
		}
		else if (isOnCreditsButton)
		{
			isCreditsPage = true;
			isOnCreditsButton = false;
		}
	}

	void CGameStateInit::OnShow()
	{
		const int GROUND_X = (SIZE_X - startPage.Width()) / 2;
		const int GROUND_Y = (SIZE_Y - startPage.Height()) / 2;
		//
		// 貼上logo
		//
		if (isPlayerPage || isScoresPage || isHelpPage || isCreditsPage || isLevelPage)
		{
			if (isLevelPage)
			{
				levelPage.SetTopLeft(GROUND_X, GROUND_Y);
				levelPage.ShowBitmap();
			}
			else if (isPlayerPage)
			{
				playerPage.SetTopLeft(GROUND_X, GROUND_Y);
				playerPage.ShowBitmap();

				if (isOnPlayerButton)
				{
					playerButton.OnMove();
				}
				else
				{
					playerButton.Reset();
				}
				playerButton.SetTopLeft(GROUND_X + PLAYER_BUTTON_INDEX_X + PLAYER_BUTTON_LENGTH / 2 - playerButton.Width() / 2, GROUND_Y + PLAYER_BUTTON_INDEX_Y + PLAYER_BUTTON_HEIGHT / 2 - playerButton.Height() / 2);
				playerButton.OnShow();
			}
			else if (isScoresPage)
			{
				scoresPage.SetTopLeft(GROUND_X, GROUND_Y);
				scoresPage.ShowBitmap();
			}
			else if (isHelpPage)
			{
				helpPage.OnMove();
				helpPage.SetTopLeft(GROUND_X, GROUND_Y);
				helpPage.OnShow();
			}
			else if (isCreditsPage)
			{
				creditsPage.SetTopLeft(GROUND_X, GROUND_Y);
				creditsPage.ShowBitmap();
			}

			if (isOnBackButton)
			{
				backButton.SetTopLeft(GROUND_X + BACK_BUTTON_INDEX_X, GROUND_Y + BACK_BUTTON_INDEX_Y);
				backButton.ShowBitmap();
			}
		}
		else
		{
			startPage.SetTopLeft(GROUND_X, GROUND_Y);
			startPage.ShowBitmap();

			if (isOnPlayButton)
			{
				playButton.SetTopLeft(GROUND_X + PLAY_BUTTON_INDEX_X, GROUND_Y + PLAY_BUTTON_INDEX_Y);
				playButton.ShowBitmap();
			}
			else if (isOnScoresButton)
			{
				scoresButton.SetTopLeft(GROUND_X + SCORES_BUTTON_INDEX_X, GROUND_Y + SCORES_BUTTON_INDEX_Y);
				scoresButton.ShowBitmap();
			}
			else if (isOnHelpButton)
			{
				helpButton.SetTopLeft(GROUND_X + HELP_BUTTON_INDEX_X, GROUND_Y + HELP_BUTTON_INDEX_Y);
				helpButton.ShowBitmap();
			}
			else if (isOnCreditsButton)
			{
				creditsButton.SetTopLeft(GROUND_X + CREDITS_BUTTON_INDEX_X, GROUND_Y + CREDITS_BUTTON_INDEX_Y);
				creditsButton.ShowBitmap();
			}
		}

		if (isOnMusicButton)
		{
			musicButton.SetTopLeft(GROUND_X + MUSIC_INDEX_X, GROUND_Y + MUSIC_INDEX_Y);
			musicButton.ShowBitmap();
		}

		if (isOnSoundButton)
		{
			soundButton.SetTopLeft(GROUND_X + SOUND_INDEX_X, GROUND_Y + SOUND_INDEX_Y);
			soundButton.ShowBitmap();
		}

		if (!shareData->IsMusicEnable())
		{
			cross.SetTopLeft(GROUND_X + MUSIC_INDEX_X, GROUND_Y + MUSIC_INDEX_Y);
			cross.ShowBitmap();
		}

		if (!shareData->IsSoundEnable())
		{
			cross.SetTopLeft(GROUND_X + SOUND_INDEX_X, GROUND_Y + SOUND_INDEX_Y);
			cross.ShowBitmap();
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

	CGameStateOver::CGameStateOver(CGame *g, CShareData *data)
	: CGameState(g, data)
	{
	}

	void CGameStateOver::OnMove()
	{
		counter--;
		if (counter < 0)
		{
			if (shareData->IsMusicEnable())
			{
				CAudio::Instance()->Play(AUDIO_MENU, true);
				CAudio::Instance()->Stop(AUDIO_MAIN);
			}
			else
			{
				CAudio::Instance()->Stop(AUDIO_MENU);
				CAudio::Instance()->Stop(AUDIO_MAIN);
			}
			GotoGameState(GAME_STATE_INIT);
		}
	}

	void CGameStateOver::OnBeginState()
	{
		CAudio::Instance()->Stop(AUDIO_MENU);
		CAudio::Instance()->Stop(AUDIO_MAIN);

		counter = 30 * 3; // 3 seconds
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
		
		if (shareData->IsMusicEnable())
		{
			CAudio::Instance()->Play(AUDIO_MENU, true);
			CAudio::Instance()->Stop(AUDIO_MAIN);
		}
		else
		{
			CAudio::Instance()->Stop(AUDIO_MENU);
			CAudio::Instance()->Stop(AUDIO_MAIN);
		}
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

	CGameStateRun::CGameStateRun(CGame *g, CShareData *data)
	: CGameState(g, data)
	{
	}

	CGameStateRun::~CGameStateRun()
	{
	}

	void CGameStateRun::OnBeginState()
	{
		if (shareData->IsMusicEnable())
		{
			CAudio::Instance()->Stop(AUDIO_MENU);
			CAudio::Instance()->Play(AUDIO_MAIN, true);
		}
		else
		{
			CAudio::Instance()->Stop(AUDIO_MENU);
			CAudio::Instance()->Stop(AUDIO_MAIN);
		}
		
		map.SelectLevel(shareData->GetSelectedLevelIndex());
		map.Initialize();
		player.Initialize(&map, shareData, &trap, &brick, &food, &monster);

		const int BRICK_LENGTH = 72;
		const int BRICK_WIDTH = 48;
		const int GROUND_X = (SIZE_X - BRICK_LENGTH * map.GetBrickNumberX()) / 2;
		const int GROUND_Y = (SIZE_Y - BRICK_WIDTH * map.GetBrickNumberY()) / 2 + 24;
		ground.Initialize(map.GetBrickNumberX(), map.GetBrickNumberY());
		ground.SetXY(GROUND_X, GROUND_Y);
		grade.SetTopLeft(GROUND_X, GROUND_Y - 48);

		trap.clear();
		wall.clear();
		brick.clear();
		food.clear();
		monster.clear();

		gameEndConut = 0;

		for (int i = 0; i < map.GetBrickNumberX(); i++)
		{
			for (int j = 0; j < map.GetBrickNumberY(); j++)
			{
				if (map.GetPlayerInMap(i, j) == CName::PLAYER)
				{
					player.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
				}
				else if (map.GetTrapInMap(i, j) == CName::SPIKE)
				{
					CSpike tempSpike;
					tempSpike.Initialize(&map);
					tempSpike.LoadBitmap();
					tempSpike.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					trap.push_back(tempSpike);
				}
				else if (map.GetTrapInMap(i, j) == CName::MUCUS)
				{
					CMucus tempMucus;
					tempMucus.Initialize(&map);
					tempMucus.LoadBitmap();
					tempMucus.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					trap.push_back(tempMucus);
				}
				else if (map.GetTrapInMap(i, j) == CName::MOVING)
				{
					CMovingSpike tempMovingSpike;
					tempMovingSpike.Initialize(&map);
					tempMovingSpike.LoadBitmap();
					tempMovingSpike.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					trap.push_back(tempMovingSpike);
				}
				else if (map.GetTrapInMap(i, j) == CName::STEPPING)
				{
					CSteppingSpike tempSteppingSpike;
					tempSteppingSpike.Initialize(&map);
					tempSteppingSpike.LoadBitmap();
					tempSteppingSpike.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					trap.push_back(tempSteppingSpike);
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
					tempStone.Initialize(&map, &brick, &monster);
					tempStone.LoadBitmap();
					tempStone.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					brick.push_back(tempStone);
				}
				else if (map.GetBrickInMap(i, j) == CName::WOODEN)
				{
					CWooden tempWooden;
					tempWooden.Initialize(&map, &brick, &monster);
					tempWooden.LoadBitmap();
					tempWooden.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					brick.push_back(tempWooden);
				}
				else if (map.GetBrickInMap(i, j) == CName::STEEL)
				{
					CSteel tempSteel;
					tempSteel.Initialize(&map, &brick, &monster);
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
				else if(map.GetMonsterInMap(i, j) == CName::MUD)
				{
					CMud tempMud;
					tempMud.Initialize(&map);
					tempMud.LoadBitmap();
					tempMud.SetTypeFlag(CName::MUD);
					tempMud.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					monster.push_back(tempMud);
				}
				else if (map.GetMonsterInMap(i, j) == CName::TURTLE) {
					CTurtle tempTurtle;
					tempTurtle.Initialize(&map);
					tempTurtle.LoadBitmap();
					tempTurtle.SetTypeFlag(CName::TURTLE);
					tempTurtle.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					monster.push_back(tempTurtle);
				}
				else if (map.GetMonsterInMap(i, j) == CName::SKELETON) {
					CSkeleton tempSkeleton;
					tempSkeleton.Initialize(&map);
					tempSkeleton.LoadBitmap();
					tempSkeleton.SetTypeFlag(CName::SKELETON);
					tempSkeleton.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					monster.push_back(tempSkeleton);
				}
			}
		}
	}

	void CGameStateRun::OnMove()
	{
		player.OnMove();
		for (list<CTrap>::iterator k = trap.begin(); k != trap.end(); k++)
		{
			k->OnMove();
		}
		for (list<CBrick>::iterator k = brick.begin(); k != brick.end(); k++)
		{
			k->OnMove();
		}
		for (list<CFood>::iterator k = food.begin(); k != food.end(); k++)
		{
			k->OnMove();
		}
		for (list<CMonster>::iterator k = monster.begin(); k != monster.end(); k++)
		{
			k->OnMove();
		}
		if (player.IsSuccess() || player.IsFail())
		{
			gameEndConut++;
			if (gameEndConut == 3 * 30)
			{
				shareData->IsSuccess(player.IsSuccess());
				shareData->IsFail(player.IsFail());
				map.DeleteMap();
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
		const char KEY_R = 'R';

		if (!player.IsSuccess() && !player.IsFail())
		{
			if (nChar == KEY_LEFT)
				player.SetMovingLeft(true);
			if (nChar == KEY_RIGHT)
				player.SetMovingRight(true);
			if (nChar == KEY_UP)
				player.SetMovingUp(true);
			if (nChar == KEY_DOWN)
				player.SetMovingDown(true);
			if (nChar == KEY_SPACE)
				player.PressKeySpace();
			if (nChar == KEY_R)
				player.Fail();
		}
	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard左箭頭
		const char KEY_UP = 0x26; // keyboard上箭頭
		const char KEY_RIGHT = 0x27; // keyboard右箭頭
		const char KEY_DOWN = 0x28; // keyboard下箭頭
		if (!player.IsSuccess() && !player.IsFail())
		{
			if (nChar == KEY_LEFT)
				player.SetMovingLeft(false);
			if (nChar == KEY_RIGHT)
				player.SetMovingRight(false);
			if (nChar == KEY_UP)
				player.SetMovingUp(false);
			if (nChar == KEY_DOWN)
				player.SetMovingDown(false);
		}
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
		player.Success();
	}

	void CGameStateRun::OnShow()
	{
		ground.OnShow();

		for (list<CTrap>::iterator k = trap.begin(); k != trap.end(); k++)
		{
			k->OnShow();
		}

		for (int j = 0; j < map.GetBrickNumberY(); j++)
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
			for (list<CMonster>::iterator k = monster.begin(); k != monster.end(); k++)
			{
				if (k->GetIndexY() == j)
				{
					k->OnShow();
				}
			}
			if (player.GetIndexY() == j)
			{
				player.OnShow();
			}
		}

		grade.SetInteger(shareData->GetGrade());
		grade.ShowBitmap();
	}
}