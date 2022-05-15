/*
 * mygame.h: ���ɮ��x�C��������class��interface
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

#include "CName.h"
#include "CGround.h"
#include "CMap.h"
#include "CPlayer.h"
#include "CTrap.h"
#include "CSpike.h"
#include "CMucus.h"
#include "CMovingSpike.h"
#include "CSteppingSpike.h"
#include "CWall.h"
#include "CBrick.h"
#include "CStone.h"
#include "CWooden.h"
#include "CSteel.h"
#include "CFood.h"
#include "CMonster.h"
#include "CMud.h"
#include "CTurtle.h"
#include "CSkeleton.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C���}�Y�e������
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g, CShareData *data);
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnKeyUp(UINT, UINT, UINT); 				// �B�z��LUp���ʧ@
		void OnMouseMove(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@ 
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
	protected:
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMovingBitmap startPage;
		CMovingBitmap cross;
		CMovingBitmap musicButton;
		CMovingBitmap soundButton;
		CMovingBitmap backButton;
		CMovingBitmap playButton;
		CMovingBitmap scoresButton;
		CMovingBitmap helpButton;
		CMovingBitmap creditsButton;
		CMovingBitmap playerPage;
		CMovingBitmap levelPage;
		CMovingBitmap scoresPage;
		CMovingBitmap creditsPage;
		CAnimation player1Button;
		CAnimation player2Button;
		CAnimation helpPage;
		int levelSelect;
		int playerNumber;
		bool isOnMusicButton;
		bool isOnSoundButton;
		bool isOnBackButton;
		bool isOnPlayButton;
		bool isOnScoresButton;
		bool isOnHelpButton;
		bool isOnCreditsButton;
		bool isOnPlayerButton;
		bool isOnLevelButton;
		bool isPlayerPage;
		bool isLevelPage;
		bool isScoresPage;
		bool isHelpPage;
		bool isCreditsPage;
		const int CROSS_LENGTH = 40;
		const int CROSS_HEIGHT = 40;
		const int MUSIC_INDEX_X = 860;
		const int MUSIC_INDEX_Y = 10;
		const int SOUND_INDEX_X = 920;
		const int SOUND_INDEX_Y = 10;
		const int BACK_BUTTON_INDEX_X = 446;
		const int BACK_BUTTON_INDEX_Y = 629;
		const int BACK_BUTTON_LENGTH = 108;
		const int BACK_BUTTON_HEIGHT = 26;
		const int PLAY_BUTTON_INDEX_X = 445;
		const int PLAY_BUTTON_INDEX_Y = 496;
		const int PLAY_BUTTON_LENGTH = 111;
		const int PLAY_BUTTON_HEIGHT = 29;
		const int CREDITS_BUTTON_INDEX_X = 410;
		const int CREDITS_BUTTON_INDEX_Y = 613;
		const int CREDITS_BUTTON_LENGTH = 180;
		const int CREDITS_BUTTON_HEIGHT = 29;
		const int HELP_BUTTON_INDEX_X = 443;
		const int HELP_BUTTON_INDEX_Y = 574;
		const int HELP_BUTTON_LENGTH = 113;
		const int HELP_BUTTON_HEIGHT = 29;
		const int SCORES_BUTTON_INDEX_X = 415;
		const int SCORES_BUTTON_INDEX_Y = 535;
		const int SCORES_BUTTON_LENGTH = 166;
		const int SCORES_BUTTON_HEIGHT = 29;
		const int PLAYER1_BUTTON_INDEX_X = 120;
		const int PLAYER1_BUTTON_INDEX_Y = 90;
		const int PLAYER1_BUTTON_LENGTH = 362;
		const int PLAYER1_BUTTON_HEIGHT = 244;
		const int PLAYER2_BUTTON_INDEX_X = 504;
		const int PLAYER2_BUTTON_INDEX_Y = 90;
		const int PLAYER2_BUTTON_LENGTH = 384;
		const int PLAYER2_BUTTON_HEIGHT = 244;
		const int FIRST_LEVEL_BUTTON_INDEX_X = 132;
		const int FIRST_LEVEL_BUTTON_INDEX_Y = 228;
		const int FIRST_LEVEL_BUTTON_LENGTH = 60;
		const int FIRST_LEVEL_BUTTON_HEIGHT = 60;
		const int NEXT_LEVEL_BUTTON_DISTANCE_X = 75;
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g, CShareData *data);
		~CGameStateRun();
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnLButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
		void OnMouseMove(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@ 
		void OnRButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnRButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMap				map;
		CInteger			grade;
		CGround				ground;
		CPlayer				player1;
		CPlayer				player2;
		list<CPlayer>		player;
		list<CTrap>			trap;
		list<CWall>			wall;
		list<CBrick>		brick;
		list<CFood>			food;
		list<CMonster>		monster;
		int					gameEndConut;
		int					playerNumber;
		int					player1Count;
		int					player2Count;
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A(Game Over)
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g, CShareData *data);
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		int counter;	// �˼Ƥ��p�ƾ�
	};

}