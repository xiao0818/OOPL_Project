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

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C���}�Y�e������
	/////////////////////////////////////////////////////////////////////////////

	CGameStateInit::CGameStateInit(CGame *g)
	: CGameState(g)
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
		logo.LoadBitmap(IDB_BACKGROUND);
		Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
		//
		// ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
		//
	}

	void CGameStateInit::OnBeginState()
	{
	}

	void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_ESC = 27;
		const char KEY_SPACE = ' ';
		if (nChar == KEY_SPACE)
			GotoGameState(GAME_STATE_RUN);						// ������GAME_STATE_RUN
		else if (nChar == KEY_ESC)								// Demo �����C������k
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0);	// �����C��
	}

	void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
	{
		GotoGameState(GAME_STATE_RUN);		// ������GAME_STATE_RUN
	}

	void CGameStateInit::OnShow()
	{
		//
		// �K�Wlogo
		//
		logo.SetTopLeft((SIZE_X - logo.Width())/2, SIZE_Y/8);
		logo.ShowBitmap();
		//
		// Demo�ù��r�����ϥΡA���L�}�o�ɽкɶq�קK�����ϥΦr���A���CMovingBitmap����n
		//
		CDC *pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC 
		CFont f,*fp;
		f.CreatePointFont(160,"Times New Roman");	// ���� font f; 160���16 point���r
		fp=pDC->SelectObject(&f);					// ��� font f
		pDC->SetBkColor(RGB(0,0,0));
		pDC->SetTextColor(RGB(255,255,0));
		pDC->TextOut(120,220,"Please click mouse or press SPACE to begin.");
		pDC->TextOut(5,395,"Press Ctrl-F to switch in between window mode and full screen mode.");
		if (ENABLE_GAME_PAUSE)
			pDC->TextOut(5,425,"Press Ctrl-Q to pause the Game.");
		pDC->TextOut(5,455,"Press Alt-F4 or ESC to Quit.");
		pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
		CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
	}								

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A(Game Over)
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
		// ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
		//     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
		//
		ShowInitProgress(66);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���66%
		//
		// �}�l���J���
		//
		Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
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

	CGameStateRun::CGameStateRun(CGame *g)
	: CGameState(g), WALL_NUMBER(74)
	{
		wall = new CWall [WALL_NUMBER];
	}

	CGameStateRun::~CGameStateRun()
	{
		delete [] wall;
	}

	void CGameStateRun::OnBeginState()
	{
		const int BRICK_LENGTH = 72;
		const int BRICK_WIDTH = 48;
		const int GROUND_X = (SIZE_X - BRICK_LENGTH * 14) / 2;
		const int GROUND_Y = (SIZE_Y - BRICK_WIDTH * 14) / 2;
		ground.SetXY(GROUND_X, GROUND_Y);

		int map_init[14][14] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
								{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								{1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
								{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
								{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
								{1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1},
								{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
								{1, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 1},
								{1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1},
								{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
								{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
								{1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
								{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
		map = new int *[14];
		for (int i = 0; i < 14; i++)
		{
			map[i] = new int[14];
		}
		for (int i = 0; i < 14; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				map[i][j] = map_init[i][j];
			}
		}


		player.Initialize(map);
		int count = 0;
		for (int i = 0; i < 14; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				if (map_init[i][j] == 1) {
					wall[count].SetXY(GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
					count++;
				}
				else if (map_init[i][j] == 2) {
					player.SetXY(GROUND_X + BRICK_LENGTH * i, GROUND_Y + BRICK_WIDTH * j);
				}
			}
		}
	}

	void CGameStateRun::OnMove()
	{
		player.OnMove();
	}

	void CGameStateRun::OnInit()
	{
		ShowInitProgress(33);

		ground.LoadBitmap();
		for (int i = 0; i < WALL_NUMBER; i++)
		{
				wall[i].LoadBitmap();
		}
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
		if (nChar == KEY_LEFT)
			player.SetMovingLeft(true);
		if (nChar == KEY_RIGHT)
			player.SetMovingRight(true);
		if (nChar == KEY_UP)
			player.SetMovingUp(true);
		if (nChar == KEY_DOWN)
			player.SetMovingDown(true);
	}

	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_LEFT = 0x25; // keyboard���b�Y
		const char KEY_UP = 0x26; // keyboard�W�b�Y
		const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
		const char KEY_DOWN = 0x28; // keyboard�U�b�Y
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
	}

	void CGameStateRun::OnShow()
	{
		ground.OnShow();
		for (int i = 0; i < WALL_NUMBER; i++)
		{
			wall[i].OnShow();
		}
		player.OnShow();
	}
}