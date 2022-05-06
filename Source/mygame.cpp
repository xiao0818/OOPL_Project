/*
 * mygame.cpp: ���ɮ��x�C��������class��implementation
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
	// �o��class���C�����C���}�Y�e������
	/////////////////////////////////////////////////////////////////////////////

	CGameStateInit::CGameStateInit(CGame *g, CShareData *data)
	: CGameState(g, data)
	{
	}

	void CGameStateInit::OnInit()
	{
		//
		// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
		//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
		//
		ShowInitProgress(0);	// �@�}�l��loading�i�׬�0%
		//
		// �}�l���J���
		//
		startPage.LoadBitmap(IDB_COVER);
		cross.LoadBitmap(IDB_CROSS,RGB(255, 255, 255));
		musicButton.LoadBitmap(IDB_MUSIC);
		soundButton.LoadBitmap(IDB_SOUND);
		playButton.LoadBitmap(IDB_PLAY);
		playerPage.LoadBitmap(IDB_PLAYER);
		levelPage.LoadBitmap(IDB_LEVEL);
		Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
		//
		// ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
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
		isOnMusicButton = isOnSoundButton = isOnPlayButton = false;
		isOnPlayerButton = isOnLevelButton = false;
		isPlayerPage = isLevelPage = false;
		levelSelect = 0;
		shareData->InitializeState();
	}

	void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		//const char KEY_ESC = 27;
		//const char KEY_SPACE = ' ';
		//if (nChar == KEY_SPACE)
		//	GotoGameState(GAME_STATE_RUN);						// ������GAME_STATE_RUN
		//else if (nChar == KEY_ESC)								// Demo �����C������k
		//	PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0);	// �����C��
	}

	void CGameStateInit::OnMouseMove(UINT nFlags, CPoint point)
	{
		const int GROUND_X = (SIZE_X - 1000) / 2;
		const int GROUND_Y = (SIZE_Y - 725) / 2;
		const int MUSIC_INDEX_X = 860;
		const int MUSIC_INDEX_Y = 10;
		const int SOUND_INDEX_X = 920;
		const int SOUND_INDEX_Y = 10;
		const int CROSS_LENGTH = 40;
		const int CROSS_HEIGHT = 40;
		const int PLAY_BUTTON_INDEX_X = 444;
		const int PLAY_BUTTON_INDEX_Y = 496;
		const int PLAY_BUTTON_LENGTH = 111;
		const int PLAY_BUTTON_HEIGHT = 29;
		const int PLAYER_BUTTON_INDEX_X = 120;
		const int PLAYER_BUTTON_INDEX_Y = 80;
		const int PLAYER_BUTTON_LENGTH = 245;
		const int PLAYER_BUTTON_HEIGHT = 170;
		const int FIRST_LEVEL_BUTTON_INDEX_X = 132;
		const int FIRST_LEVEL_BUTTON_INDEX_Y = 228;
		const int FIRST_LEVEL_BUTTON_LENGTH = 60;
		const int FIRST_LEVEL_BUTTON_HEIGHT = 60;
		const int NEXT_LEVEL_BUTTON_DISTANCE_X = 75;

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

		if (isLevelPage)
		{
			for (int i = 0; i < 5; i++)
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
		else
		{
			if ((GROUND_X + PLAY_BUTTON_INDEX_X) < point.x && point.x < (GROUND_X + PLAY_BUTTON_INDEX_X + PLAY_BUTTON_LENGTH) && (GROUND_Y + PLAY_BUTTON_INDEX_Y) < point.y && point.y < (GROUND_Y + PLAY_BUTTON_INDEX_Y + PLAY_BUTTON_HEIGHT))
			{
				isOnPlayButton = true;
			}
			else
			{
				isOnPlayButton = false;
			}
		}
	}

	void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
	{
		if (isOnLevelButton)
		{
			shareData->SetSelectedLevelIndex(levelSelect);
			GotoGameState(GAME_STATE_RUN);
		}

		if (isOnPlayerButton)
		{
			isLevelPage = true;
			isPlayerPage = false;
		}

		if (isOnPlayButton)
		{
			isPlayerPage = true;
		}

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
		}

		if (isOnSoundButton)
		{
			shareData->IsSoundEnable(!shareData->IsSoundEnable());
		}
	}

	void CGameStateInit::OnShow()
	{
		const int GROUND_X = (SIZE_X - startPage.Width()) / 2;
		const int GROUND_Y = (SIZE_Y - startPage.Height()) / 2;
		const int CROSS_LENGTH = 40;
		const int CROSS_HEIGHT = 40;
		const int MUSIC_INDEX_X = 860;
		const int MUSIC_INDEX_Y = 10;
		const int SOUND_INDEX_X = 920;
		const int SOUND_INDEX_Y = 10;
		const int PLAY_BUTTON_LENGTH = 111;
		const int PLAY_BUTTON_HEIGHT = 30;
		const int PLAY_BUTTON_INDEX_X = 445;
		const int PLAY_BUTTON_INDEX_Y = 496;
		//
		// �K�Wlogo
		//
		if (isLevelPage)
		{
			levelPage.SetTopLeft(GROUND_X, GROUND_Y);
			levelPage.ShowBitmap();
		}
		else if (isPlayerPage)
		{
			playerPage.SetTopLeft(GROUND_X, GROUND_Y);
			playerPage.ShowBitmap();
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
		// Demo�ù��r�����ϥΡA���L�}�o�ɽкɶq�קK�����ϥΦr���A���CMovingBitmap����n
		//
		//CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		//CFont f,*fp;
		//f.CreatePointFont(160,"Times New Roman");	// ���� font f; 160���16 point���r
		//fp=pDC->SelectObject(&f);					// ��� font f
		//pDC->SetBkColor(RGB(0,0,0));
		//pDC->SetTextColor(RGB(255,255,0));
		//pDC->TextOut(120,220,"Please click mouse or press SPACE to begin.");
		//pDC->TextOut(5,395,"Press Ctrl-F to switch in between window mode and full screen mode.");
		//if (ENABLE_GAME_PAUSE)
		//	pDC->TextOut(5,425,"Press Ctrl-Q to pause the Game.");
		//pDC->TextOut(5,455,"Press Alt-F4 or ESC to Quit.");
		//pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		//CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	}								

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A(Game Over)
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
		// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
		//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
		//
		ShowInitProgress(66);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���66%
		//
		// �}�l���J���
		//
		Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
		
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
		// �̲׶i�׬�100%
		//
		ShowInitProgress(100);
	}

	void CGameStateOver::OnShow()
	{
		CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CFont f,*fp;
		f.CreatePointFont(160,"Times New Roman");	// ���� font f; 160���16 point���r
		fp=pDC->SelectObject(&f);					// ��� font f
		pDC->SetBkColor(RGB(0,0,0));
		pDC->SetTextColor(RGB(255,255,0));
		char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
		sprintf(str, "Game Over ! (%d)", counter / 30);
		pDC->TextOut(240,210,str);
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	}

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
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
				else if(map.GetMonsterInMap(i, j) == CName::MUD)
				{
					CMud tempMud;
					tempMud.Initialize(&map, &player);
					tempMud.LoadBitmap();
					tempMud.SetTypeFlag(CName::MUD);
					tempMud.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					monster.push_back(tempMud);
				}
				else if (map.GetMonsterInMap(i, j) == CName::TURTLE) {
					CTurtle tempTurtle;
					tempTurtle.Initialize(&map, &player);
					tempTurtle.LoadBitmap();
					tempTurtle.SetTypeFlag(CName::TURTLE);
					tempTurtle.SetXY(i, j, GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					monster.push_back(tempTurtle);
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
		const char KEY_LEFT = 0x25; // keyboard���b�Y
		const char KEY_UP = 0x26; // keyboard�W�b�Y
		const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
		const char KEY_DOWN = 0x28; // keyboard�U�b�Y
		const char KEY_SPACE = ' ';

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
		}
	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard���b�Y
		const char KEY_UP = 0x26; // keyboard�W�b�Y
		const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
		const char KEY_DOWN = 0x28; // keyboard�U�b�Y
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
		map.DeleteMap();
		GotoGameState(GAME_STATE_OVER);
	}

	void CGameStateRun::OnShow()
	{
		ground.OnShow();

		for (int j = 0; j < map.GetBrickNumberY(); j++)
		{
			for (list<CTrap>::iterator k = trap.begin(); k != trap.end(); k++)
			{
				if (k->GetIndexY() == j)
				{
					k->OnShow();
				}
			}
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