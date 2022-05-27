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
		ShowInitProgress(0);

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
		levelPage_2.LoadBitmap(IDB_LEVEL_2);
		scoresPage.LoadBitmap(IDB_SCORES_PAGE);
		creditsPage.LoadBitmap(IDB_CREDITS_PAGE);

		player1Button.AddBitmap(IDB_PLAYER_BUTTON_001);
		player1Button.AddBitmap(IDB_PLAYER_BUTTON_002);
		player1Button.AddBitmap(IDB_PLAYER_BUTTON_003);
		player1Button.AddBitmap(IDB_PLAYER_BUTTON_004);
		player1Button.AddBitmap(IDB_PLAYER_BUTTON_005);
		player1Button.AddBitmap(IDB_PLAYER_BUTTON_006);
		player1Button.AddBitmap(IDB_PLAYER_BUTTON_007);
		player1Button.AddBitmap(IDB_PLAYER_BUTTON_008);
		player2Button.AddBitmap(IDB_PLAYER2_BUTTON_001);
		player2Button.AddBitmap(IDB_PLAYER2_BUTTON_002);
		player2Button.AddBitmap(IDB_PLAYER2_BUTTON_003);
		player2Button.AddBitmap(IDB_PLAYER2_BUTTON_004);
		player2Button.AddBitmap(IDB_PLAYER2_BUTTON_005);
		player2Button.AddBitmap(IDB_PLAYER2_BUTTON_006);
		player2Button.AddBitmap(IDB_PLAYER2_BUTTON_007);
		player2Button.AddBitmap(IDB_PLAYER2_BUTTON_008);

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

		int temp[50] = {IDB_LEVEL_001, IDB_LEVEL_002, IDB_LEVEL_003, IDB_LEVEL_004, IDB_LEVEL_005, IDB_LEVEL_006, IDB_LEVEL_007, IDB_LEVEL_008, IDB_LEVEL_009, IDB_LEVEL_010,
						IDB_LEVEL_011, IDB_LEVEL_012, IDB_LEVEL_013, IDB_LEVEL_014, IDB_LEVEL_015, IDB_LEVEL_016, IDB_LEVEL_017, IDB_LEVEL_018, IDB_LEVEL_019, IDB_LEVEL_020,
						IDB_LEVEL_021, IDB_LEVEL_022, IDB_LEVEL_023, IDB_LEVEL_024, IDB_LEVEL_025, IDB_LEVEL_026, IDB_LEVEL_027, IDB_LEVEL_028, IDB_LEVEL_029, IDB_LEVEL_030,
						IDB_LEVEL_031, IDB_LEVEL_032, IDB_LEVEL_033, IDB_LEVEL_034, IDB_LEVEL_035, IDB_LEVEL_036, IDB_LEVEL_037, IDB_LEVEL_038, IDB_LEVEL_039, IDB_LEVEL_040,
						IDB_LEVEL_041, IDB_LEVEL_042, IDB_LEVEL_043, IDB_LEVEL_044, IDB_LEVEL_045, IDB_LEVEL_046, IDB_LEVEL_047, IDB_LEVEL_048, IDB_LEVEL_049, IDB_LEVEL_050};
		for (int i = 0; i < 50; i++)
			levelButton[i].LoadBitmap(temp[i]);

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
		levelSelect = playerNumber = 0;
		shareData->InitializeState();
		player1Button.SetDelayCount(2);
		player2Button.SetDelayCount(2);
		helpPage.SetDelayCount(3);
	}

	void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
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
				for (int i = 0; i < 50; i++)
				{
					int tens = i / 10;
					int digits = i % 10;
					if ((GROUND_X + FIRST_LEVEL_BUTTON_INDEX_X + NEXT_LEVEL_BUTTON_DISTANCE_X * digits) < point.x && point.x < (GROUND_X + FIRST_LEVEL_BUTTON_INDEX_X + NEXT_LEVEL_BUTTON_DISTANCE_X * digits + FIRST_LEVEL_BUTTON_LENGTH) && (GROUND_Y + FIRST_LEVEL_BUTTON_INDEX_Y + NEXT_LEVEL_BUTTON_DISTANCE_Y * tens) < point.y && point.y < (GROUND_Y + FIRST_LEVEL_BUTTON_INDEX_Y + NEXT_LEVEL_BUTTON_DISTANCE_Y * tens + FIRST_LEVEL_BUTTON_HEIGHT))
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
				if ((GROUND_X + PLAYER1_BUTTON_INDEX_X) < point.x && point.x < (GROUND_X + PLAYER1_BUTTON_INDEX_X + PLAYER1_BUTTON_LENGTH) && (GROUND_Y + PLAYER1_BUTTON_INDEX_Y) < point.y && point.y < (GROUND_Y + PLAYER1_BUTTON_INDEX_Y + PLAYER1_BUTTON_HEIGHT))
				{
					isOnPlayerButton = true;
					playerNumber = 1;
				}
				else if ((GROUND_X + PLAYER2_BUTTON_INDEX_X) < point.x && point.x < (GROUND_X + PLAYER2_BUTTON_INDEX_X + PLAYER2_BUTTON_LENGTH) && (GROUND_Y + PLAYER2_BUTTON_INDEX_Y) < point.y && point.y < (GROUND_Y + PLAYER2_BUTTON_INDEX_Y + PLAYER2_BUTTON_HEIGHT))
				{
					isOnPlayerButton = true;
					playerNumber = 2;
				}
				else
				{
					isOnPlayerButton = false;
					playerNumber = 0;
				}
			}
		}
	}

	void CGameStateInit::OnLButtonUp(UINT nFlags, CPoint point)
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
			shareData->SetPlayerNumber(playerNumber);
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

		if (isPlayerPage || isScoresPage || isHelpPage || isCreditsPage || isLevelPage)
		{
			if (isLevelPage)
			{
				if (playerNumber == 1)
				{
					levelPage.SetTopLeft(GROUND_X, GROUND_Y);
					levelPage.ShowBitmap();
				}
				else if (playerNumber == 2)
				{
					levelPage_2.SetTopLeft(GROUND_X, GROUND_Y);
					levelPage_2.ShowBitmap();
				}

				if (isOnLevelButton)
				{
					int level = levelSelect - 1;
					int tens = level / 10;
					int digits = level % 10;
					levelButton[level].SetTopLeft(GROUND_X + FIRST_LEVEL_BUTTON_INDEX_X + NEXT_LEVEL_BUTTON_DISTANCE_X * digits, GROUND_Y + FIRST_LEVEL_BUTTON_INDEX_Y + NEXT_LEVEL_BUTTON_DISTANCE_Y * tens);
					levelButton[level].ShowBitmap();
				}
			}
			else if (isPlayerPage)
			{
				playerPage.SetTopLeft(GROUND_X, GROUND_Y);
				playerPage.ShowBitmap();

				if (isOnPlayerButton)
				{
					if (playerNumber == 1)
					{
						player1Button.OnMove();
						player1Button.SetTopLeft(GROUND_X + PLAYER1_BUTTON_INDEX_X + PLAYER1_BUTTON_LENGTH / 2 - player1Button.Width() / 2, GROUND_Y + PLAYER1_BUTTON_INDEX_Y + PLAYER1_BUTTON_HEIGHT / 2 - player1Button.Height() / 2);
						player1Button.OnShow();
					}
					else if (playerNumber == 2)
					{
						player2Button.OnMove();
						player2Button.SetTopLeft(GROUND_X + PLAYER2_BUTTON_INDEX_X + PLAYER2_BUTTON_LENGTH / 2 - player2Button.Width() / 2, GROUND_Y + PLAYER2_BUTTON_INDEX_Y + PLAYER2_BUTTON_HEIGHT / 2 - player2Button.Height() / 2);
						player2Button.OnShow();
					}
				}
				else
				{
					player1Button.Reset();
					player2Button.Reset();
				}
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

		if (isOnMusicButton || isOnSoundButton || isOnPlayButton || isOnScoresButton || isOnHelpButton || isOnCreditsButton || isOnPlayerButton || isOnLevelButton || isOnBackButton)
		{
			SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR_LINK));
		}
		else
		{
			SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR_ARROW));
		}
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
		player1Success.OnMove();
		player2Success.OnMove();
	}

	void CGameStateOver::OnBeginState()
	{
		isSuccess = shareData->IsSuccess() && (shareData->GetSelectedLevelIndex() != 50);
		isFail = shareData->IsFail();
		isEnd = shareData->IsSuccess() && (shareData->GetSelectedLevelIndex() == 50);
		playerNumber = shareData->GetPlayerNumber();
		isOnMusicButton = false;
		isOnSoundButton = false;
		isOnBackButton = false;
		isOnNextLevelButton = false;
		isOnTryAgainButton = false;
		score.SetInteger(shareData->GetGrade());
		player1Success.SetDelayCount(2);
		player2Success.SetDelayCount(2);
	}

	void CGameStateOver::OnInit()
	{
		ShowInitProgress(66);

		score.LoadBitmap();
		successPage.LoadBitmap(IDB_SUCCESS_PAGE);
		failPage.LoadBitmap(IDB_FAIL_PAGE);
		endPage.LoadBitmap(IDB_END_PAGE);
		cross.LoadBitmap(IDB_CROSS, RGB(255, 255, 255));
		musicButton.LoadBitmap(IDB_MUSIC);
		soundButton.LoadBitmap(IDB_SOUND);
		backButton.LoadBitmap(IDB_BACK);
		nextLevelButton.LoadBitmap(IDB_NEXT_LEVEL);
		tryAgainButton.LoadBitmap(IDB_TRY_AGAIN);
		
		player1Success.AddBitmap(IDB_END_PLAYER1_SUCCESS_001);
		player1Success.AddBitmap(IDB_END_PLAYER1_SUCCESS_002);
		player1Success.AddBitmap(IDB_END_PLAYER1_SUCCESS_003);
		player1Success.AddBitmap(IDB_END_PLAYER1_SUCCESS_004);
		player1Success.AddBitmap(IDB_END_PLAYER1_SUCCESS_005);
		player1Success.AddBitmap(IDB_END_PLAYER1_SUCCESS_006);
		player1Fail.LoadBitmap(IDB_END_PLAYER1_FAIL_001);

		player2Success.AddBitmap(IDB_END_PLAYER2_SUCCESS_001);
		player2Success.AddBitmap(IDB_END_PLAYER2_SUCCESS_002);
		player2Success.AddBitmap(IDB_END_PLAYER2_SUCCESS_003);
		player2Success.AddBitmap(IDB_END_PLAYER2_SUCCESS_004);
		player2Success.AddBitmap(IDB_END_PLAYER2_SUCCESS_005);
		player2Success.AddBitmap(IDB_END_PLAYER2_SUCCESS_006);
		player2Fail.LoadBitmap(IDB_END_PLAYER2_FAIL_001);

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

		ShowInitProgress(100);
	}

	void CGameStateOver::OnMouseMove(UINT nFlags, CPoint point)
	{
		const int GROUND_X = (SIZE_X - successPage.Width()) / 2;
		const int GROUND_Y = (SIZE_Y - successPage.Height()) / 2;

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

		if ((GROUND_X + BACK_BUTTON_INDEX_X) < point.x && point.x < (GROUND_X + BACK_BUTTON_INDEX_X + BACK_BUTTON_LENGTH) && (GROUND_Y + BACK_BUTTON_INDEX_Y) < point.y && point.y < (GROUND_Y + BACK_BUTTON_INDEX_Y + BACK_BUTTON_HEIGHT))
		{
			isOnBackButton = true;
		}
		else
		{
			isOnBackButton = false;
		}

		if (isSuccess)
		{
			if ((GROUND_X + NEXT_LEVEL_BUTTON_INDEX_X) < point.x && point.x < (GROUND_X + NEXT_LEVEL_BUTTON_INDEX_X + NEXT_LEVEL_BUTTON_LENGTH) && (GROUND_Y + NEXT_LEVEL_BUTTON_INDEX_Y) < point.y && point.y < (GROUND_Y + NEXT_LEVEL_BUTTON_INDEX_Y + NEXT_LEVEL_BUTTON_HEIGHT))
			{
				isOnNextLevelButton = true;
			}
			else
			{
				isOnNextLevelButton = false;
			}
		}
		else if (isFail)
		{
			if ((GROUND_X + TRY_AGAIN_BUTTON_INDEX_X) < point.x && point.x < (GROUND_X + TRY_AGAIN_BUTTON_INDEX_X + TRY_AGAIN_BUTTON_LENGTH) && (GROUND_Y + TRY_AGAIN_BUTTON_INDEX_Y) < point.y && point.y < (GROUND_Y + TRY_AGAIN_BUTTON_INDEX_Y + TRY_AGAIN_BUTTON_HEIGHT))
			{
				isOnTryAgainButton = true;
			}
			else
			{
				isOnTryAgainButton = false;
			}
		}
	}

	void CGameStateOver::OnLButtonUp(UINT nFlags, CPoint point)
	{
		if (isOnMusicButton)
		{
			shareData->IsMusicEnable(!shareData->IsMusicEnable());
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
			isOnMusicButton = false;
		}
		else if (isOnSoundButton)
		{
			shareData->IsSoundEnable(!shareData->IsSoundEnable());
			isOnSoundButton = false;
		}
		else if (isOnBackButton)
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
		else if (isOnNextLevelButton)
		{
			shareData->SetSelectedLevelIndex(shareData->GetSelectedLevelIndex() + 1);
			shareData->SetGrade(0);
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
			GotoGameState(GAME_STATE_RUN);
		}
		else if (isOnTryAgainButton)
		{
			shareData->SetGrade(0);
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
			GotoGameState(GAME_STATE_RUN);
		}
	}

	void CGameStateOver::OnShow()
	{
		const int GROUND_X = (SIZE_X - successPage.Width()) / 2;
		const int GROUND_Y = (SIZE_Y - successPage.Height()) / 2;

		if (isEnd)
		{
			endPage.SetTopLeft(GROUND_X, GROUND_Y);
			endPage.ShowBitmap();
		}
		else if (isSuccess)
		{
			successPage.SetTopLeft(GROUND_X, GROUND_Y);
			successPage.ShowBitmap();
			if (playerNumber == 1)
			{
				player1Success.SetTopLeft(GROUND_X + PLAYER_INDEX_X, GROUND_Y + PLAYER_INDEX_Y);
				player1Success.OnShow();
			}
			else if (playerNumber == 2)
			{
				player1Success.SetTopLeft(GROUND_X + PLAYER1_INDEX_X, GROUND_Y + PLAYER_INDEX_Y);
				player1Success.OnShow();
				player2Success.SetTopLeft(GROUND_X + PLAYER2_INDEX_X, GROUND_Y + PLAYER_INDEX_Y);
				player2Success.OnShow();
			}
		}
		else if (isFail)
		{
			failPage.SetTopLeft(GROUND_X, GROUND_Y);
			failPage.ShowBitmap();
			if (playerNumber == 1)
			{
				player1Fail.SetTopLeft(GROUND_X + PLAYER_INDEX_X, GROUND_Y + PLAYER_INDEX_Y);
				player1Fail.ShowBitmap();
			}
			else if (playerNumber == 2)
			{
				player1Fail.SetTopLeft(GROUND_X + PLAYER1_INDEX_X, GROUND_Y + PLAYER_INDEX_Y);
				player1Fail.ShowBitmap();
				player2Fail.SetTopLeft(GROUND_X + PLAYER2_INDEX_X, GROUND_Y + PLAYER_INDEX_Y);
				player2Fail.ShowBitmap();
			}
		}

		if (!isEnd)
		{
			score.SetTopLeft(GROUND_X + SCORE_INDEX_X, GROUND_Y + SCORE_INDEX_Y);
			score.ShowBitmap();
		}
		else if (isEnd)
		{
			score.SetTopLeft(GROUND_X + SCORE_INDEX_X, GROUND_Y + SCORE_INDEX_Y_FOR_END);
			score.ShowBitmap();
		}

		if (isOnBackButton)
		{
			backButton.SetTopLeft(GROUND_X + BACK_BUTTON_INDEX_X, GROUND_Y + BACK_BUTTON_INDEX_Y);
			backButton.ShowBitmap();
		}

		if (isOnNextLevelButton)
		{
			nextLevelButton.SetTopLeft(GROUND_X + NEXT_LEVEL_BUTTON_INDEX_X, GROUND_Y + NEXT_LEVEL_BUTTON_INDEX_Y);
			nextLevelButton.ShowBitmap();
		}

		if (isOnTryAgainButton)
		{
			tryAgainButton.SetTopLeft(GROUND_X + TRY_AGAIN_BUTTON_INDEX_X, GROUND_Y + TRY_AGAIN_BUTTON_INDEX_Y);
			tryAgainButton.ShowBitmap();
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

		if (isOnMusicButton || isOnSoundButton || isOnNextLevelButton || isOnTryAgainButton || isOnBackButton)
		{
			SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR_LINK));
		}
		else
		{
			SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR_ARROW));
		}
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

		isCPressed = false;
		isOPressed = false;
		isMPressed = false;
		isBPressed = false;
		
		playerNumber = shareData->GetPlayerNumber();
		map.SelectLevel(shareData->GetSelectedLevelIndex());
		map.Initialize();
		player1.Initialize(&map, shareData, &trap, &brick, &food, &monster);
		player2.Initialize(&map, shareData, &trap, &brick, &food, &monster);

		const int BRICK_LENGTH = 36;
		const int BRICK_WIDTH = 24;
		const int GROUND_X = (SIZE_X - BRICK_LENGTH * map.GetBrickNumberX()) / 2;
		const int GROUND_Y = (SIZE_Y - BRICK_WIDTH * map.GetBrickNumberY()) / 2;
		ground.Initialize(map.GetBrickNumberX(), map.GetBrickNumberY());
		ground.SetXY(GROUND_X, GROUND_Y);
		grade.SetTopLeft(GROUND_X, GROUND_Y - 36);

		trap.clear();
		wall.clear();
		brick.clear();
		food.clear();
		monster.clear();

		gameEndConut = 3 * 30;
		player1Count = 3 * 30;
		player2Count = 3 * 30;

		for (int i = 0; i < map.GetBrickNumberX(); i++)
		{
			for (int j = 0; j < map.GetBrickNumberY(); j++)
			{
				if (map.GetPlayerInMap(i, j) == CName::PLAYER1)
				{
					player1.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
				}
				else if (map.GetPlayerInMap(i, j) == CName::PLAYER2)
				{
					if (playerNumber == 1)
					{
						map.SetPlayerInMap(i, j, CName::SPACE);
						player2.Fail();
						player2Count = 0;
					}
					else if (playerNumber)
					{
						player2.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					}
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
					tempStone.Initialize(&map, &player1, &player2, &brick, &food, &monster);
					tempStone.LoadBitmap();
					tempStone.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					brick.push_back(tempStone);
				}
				else if (map.GetBrickInMap(i, j) == CName::WOODEN)
				{
					CWooden tempWooden;
					tempWooden.Initialize(&map, &player1, &player2, &brick, &food, &monster);
					tempWooden.LoadBitmap();
					tempWooden.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					brick.push_back(tempWooden);
				}
				else if (map.GetBrickInMap(i, j) == CName::STEEL)
				{
					CSteel tempSteel;
					tempSteel.Initialize(&map, &player1, &player2, &brick, &food, &monster);
					tempSteel.LoadBitmap();
					tempSteel.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					brick.push_back(tempSteel);
				}
				else if (map.GetBrickInMap(i, j) == CName::SLIME)
				{
					CSlime tempSlime;
					tempSlime.Initialize(&map, &player1, &player2, &brick, &food, &monster);
					tempSlime.LoadBitmap();
					tempSlime.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					brick.push_back(tempSlime);
				}
				else if (map.GetBrickInMap(i, j) == CName::BOMB)
				{
					CBomb tempBomb;
					tempBomb.Initialize(&map, &player1, &player2, &brick, &food, &monster);
					tempBomb.LoadBitmap();
					tempBomb.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					brick.push_back(tempBomb);
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
		ground.OnMove();
		player1.OnMove();
		if (playerNumber == 2)
		{
			player2.OnMove();
		}
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
		if (playerNumber == 1)
		{
			if (player1.IsSuccess() || player1.IsFail())
			{
				gameEndConut--;
				if (gameEndConut == 0)
				{
					shareData->IsSuccess(player1.IsSuccess());
					shareData->IsFail(player1.IsFail());
					map.DeleteMap();
					GotoGameState(GAME_STATE_OVER);
				}
			}
		}
		else if (playerNumber == 2)
		{
			if (player1.IsFail() && player1Count != 0)
			{
				player1Count--;
			}
			if (player2.IsFail() && player2Count!= 0)
			{
				player2Count--;
			}
			if (player1Count == 0)
			{
				map.SetPlayerInMap(player1.GetIndexX(), player1.GetIndexY(), CName::SPACE);
			}
			if (player2Count == 0)
			{
				map.SetPlayerInMap(player2.GetIndexX(), player2.GetIndexY(), CName::SPACE);
			}
			if (player1.IsSuccess() || player2.IsSuccess() || (player1.IsFail() && player2.IsFail()))
			{
				gameEndConut--;
				if (gameEndConut == 0)
				{
					shareData->IsSuccess(player1.IsSuccess() || player2.IsSuccess());
					shareData->IsFail(player1.IsFail() && player2.IsFail());
					map.DeleteMap();
					GotoGameState(GAME_STATE_OVER);
				}
			}
		}
	}

	void CGameStateRun::OnInit()
	{
		ShowInitProgress(33);

		ground.LoadBitmap();
		grade.LoadBitmap();
		player1.LoadBitmap();
		player2.LoadBitmap();

		ShowInitProgress(50);
	}

	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_R = 0x52;
		const char KEY_LEFT = 0x25; // keyboard左箭頭
		const char KEY_RIGHT = 0x27; // keyboard右箭頭
		const char KEY_UP = 0x26; // keyboard上箭頭
		const char KEY_DOWN = 0x28; // keyboard下箭頭
		const char KEY_SPACE = 0x20;
		const char KEY_A = 0x41;
		const char KEY_D = 0x44;
		const char KEY_W = 0x57;
		const char KEY_S = 0x53;
		const char KEY_CTRL = 0x11;
		const char KEY_C = 0x43;
		const char KEY_O = 0x4F;
		const char KEY_M = 0x4D;
		const char KEY_B = 0x42;

		if (nChar == KEY_R)
		{
			player1.Fail();
			if (playerNumber == 2)
			{
				player2.Fail();
			}
		}

		if (!player1.IsSuccess() && !player1.IsFail())
		{
			if (nChar == KEY_LEFT)
			{
				player1.SetMovingLeft(true);
			}
			if (nChar == KEY_RIGHT)
			{
				player1.SetMovingRight(true);
			}
			if (nChar == KEY_UP)
			{
				player1.SetMovingUp(true);
			}
			if (nChar == KEY_DOWN)
			{
				player1.SetMovingDown(true);
			}
			if (nChar == KEY_SPACE)
			{
				player1.PressKeySpace();
			}
		}

		if (playerNumber == 2)
		{
			if (!player2.IsSuccess() && !player2.IsFail())
			{
				if (nChar == KEY_A)
				{
					player2.SetMovingLeft(true);
				}
				if (nChar == KEY_D)
				{
					player2.SetMovingRight(true);
				}
				if (nChar == KEY_W)
				{
					player2.SetMovingUp(true);
				}
				if (nChar == KEY_S)
				{
					player2.SetMovingDown(true);
				}
				if (nChar == KEY_CTRL)
				{
					player2.PressKeySpace();
				}
			}
		}

		if (nChar == KEY_C)
		{
			isCPressed = true;
		}
		if (nChar == KEY_O)
		{
			isOPressed = true;
		}
		if (nChar == KEY_M)
		{
			isMPressed = true;
		}
		if (nChar == KEY_B)
		{
			isBPressed = true;
		}

		if (isCPressed && isOPressed && isMPressed && isBPressed)
		{
			ground.Bomb();
			monster.clear();
			food.clear();
		}
	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard左箭頭
		const char KEY_RIGHT = 0x27; // keyboard右箭頭
		const char KEY_UP = 0x26; // keyboard上箭頭
		const char KEY_DOWN = 0x28; // keyboard下箭頭
		const char KEY_SPACE = 0x20;
		const char KEY_A = 0x41;
		const char KEY_D = 0x44;
		const char KEY_W = 0x57;
		const char KEY_S = 0x53;
		const char KEY_CTRL = 0x11;
		const char KEY_C = 0x43;
		const char KEY_O = 0x4F;
		const char KEY_M = 0x4D;
		const char KEY_B = 0x42;

		if (!player1.IsSuccess() && !player1.IsFail())
		{
			if (nChar == KEY_LEFT)
			{
				player1.SetMovingLeft(false);
			}
			if (nChar == KEY_RIGHT)
			{
				player1.SetMovingRight(false);
			}
			if (nChar == KEY_UP)
			{
				player1.SetMovingUp(false);
			}
			if (nChar == KEY_DOWN)
			{
				player1.SetMovingDown(false);
			}
		}

		if (playerNumber == 2)
		{
			if (!player2.IsSuccess() && !player2.IsFail())
			{
				if (nChar == KEY_A)
				{
					player2.SetMovingLeft(false);
				}
				if (nChar == KEY_D)
				{
					player2.SetMovingRight(false);
				}
				if (nChar == KEY_W)
				{
					player2.SetMovingUp(false);
				}
				if (nChar == KEY_S)
				{
					player2.SetMovingDown(false);
				}
			}
		}

		if (nChar == KEY_C)
		{
			isCPressed = false;
		}
		if (nChar == KEY_O)
		{
			isOPressed = false;
		}
		if (nChar == KEY_M)
		{
			isMPressed = false;
		}
		if (nChar == KEY_B)
		{
			isBPressed = false;
		}
	}

	void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)
	{
	}

	void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)
	{
	}

	void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)
	{
	}

	void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)
	{
	}

	void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)
	{
		player1.Success();
		if (playerNumber == 2)
		{
			player2.Success();
		}
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
			if (player1.GetIndexY() == j && player1Count != 0)
			{
				player1.OnShow();
			}
			if (playerNumber == 2)
			{
				if (player2.GetIndexY() == j && player2Count != 0)
				{
					player2.OnShow();
				}
			}
		}

		grade.SetInteger(shareData->GetGrade());
		grade.ShowBitmap();
	}
}