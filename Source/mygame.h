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

#include "CName.h"
#include "CGround.h"
#include "CMap.h"
#include "CPlayer1.h"
#include "CPlayer2.h"
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
#include "CSlime.h"
#include "CBomb.h"
#include "CFood.h"
#include "CMonster.h"
#include "CMud.h"
#include "CTurtle.h"
#include "CSkeleton.h"
#include "CFish.h"
#include "CScore.h"

namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲開頭畫面物件
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g, CShareData *data);
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnKeyUp(UINT, UINT, UINT); 				// 處理鍵盤Up的動作
		void OnMouseMove(UINT nFlags, CPoint point);	// 處理滑鼠的動作 
		void OnLButtonUp(UINT nFlags, CPoint point);  // 處理滑鼠的動作
	protected:
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap startPage;
		CMovingBitmap cross;
		CMovingBitmap musicButton;
		CMovingBitmap soundButton;
		CMovingBitmap backButton;
		CMovingBitmap playButton;
		CMovingBitmap aboutButton;
		CMovingBitmap helpButton;
		CMovingBitmap creditsButton;
		CMovingBitmap playerPage;
		CMovingBitmap levelPage;
		CMovingBitmap levelPage_2;
		CMovingBitmap aboutPage;
		CMovingBitmap creditsPage;
		CAnimation player1Button;
		CAnimation player2Button;
		CAnimation helpPage;
		CMovingBitmap levelButton[50];
		int levelSelect;
		int playerNumber;
		bool isOnMusicButton;
		bool isOnSoundButton;
		bool isOnBackButton;
		bool isOnPlayButton;
		bool isOnAboutButton;
		bool isOnHelpButton;
		bool isOnCreditsButton;
		bool isOnPlayerButton;
		bool isOnLevelButton;
		bool isPlayerPage;
		bool isLevelPage;
		bool isAboutPage;
		bool isHelpPage;
		bool isCreditsPage;
		const int PAGE_LENGTH = 1324;
		const int PAGE_HEIGHT = 960;
		const int MUSIC_INDEX_X = 1140;
		const int MUSIC_INDEX_Y = 13;
		const int SOUND_INDEX_X = 1219;
		const int SOUND_INDEX_Y = 13;
		const int CROSS_LENGTH = 53;
		const int CROSS_HEIGHT = 53;
		const int BACK_BUTTON_INDEX_X = 591;
		const int BACK_BUTTON_INDEX_Y = 833;
		const int BACK_BUTTON_LENGTH = 143;
		const int BACK_BUTTON_HEIGHT = 34;
		const int PLAY_BUTTON_INDEX_X = 589;
		const int PLAY_BUTTON_INDEX_Y = 657;
		const int PLAY_BUTTON_LENGTH = 147;
		const int PLAY_BUTTON_HEIGHT = 38;
		const int CREDITS_BUTTON_INDEX_X = 543;
		const int CREDITS_BUTTON_INDEX_Y = 812;
		const int CREDITS_BUTTON_LENGTH = 239;
		const int CREDITS_BUTTON_HEIGHT = 38;
		const int ABOUT_BUTTON_INDEX_X = 567;
		const int ABOUT_BUTTON_INDEX_Y = 707;
		const int ABOUT_BUTTON_LENGTH = 180;
		const int ABOUT_BUTTON_HEIGHT = 38;
		const int HELP_BUTTON_INDEX_X = 587;
		const int HELP_BUTTON_INDEX_Y = 760;
		const int HELP_BUTTON_LENGTH = 150;
		const int HELP_BUTTON_HEIGHT = 38;
		const int PLAYER1_BUTTON_INDEX_X = 159;
		const int PLAYER1_BUTTON_INDEX_Y = 120;
		const int PLAYER1_BUTTON_LENGTH = 480;
		const int PLAYER1_BUTTON_HEIGHT = 323;
		const int PLAYER2_BUTTON_INDEX_X = 668;
		const int PLAYER2_BUTTON_INDEX_Y = 120;
		const int PLAYER2_BUTTON_LENGTH = 509;
		const int PLAYER2_BUTTON_HEIGHT = 323;
		const int FIRST_LEVEL_BUTTON_INDEX_X = 177;
		const int FIRST_LEVEL_BUTTON_INDEX_Y = 303;
		const int LEVEL_BUTTON_LENGTH = 76;
		const int LEVEL_BUTTON_HEIGHT = 75;
		const int NEXT_LEVEL_BUTTON_DISTANCE_X = 199;
		const int NEXT_LEVEL_BUTTON_DISTANCE_Y = 97;
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g, CShareData *data);
		~CGameStateRun();
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
		void OnMouseMove(UINT nFlags, CPoint point);	// 處理滑鼠的動作 
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnLButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
		void OnRButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnRButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMap map;
		CInteger grade;
		CGround	ground;
		CPlayer1	player1;
		CPlayer2	player2;
		list<CTrap>	trap;
		list<CWall>	wall;
		list<CBrick> brick;
		list<CFood>	food;
		list<CMonster> monster;
		int	gameEndConut;
		int	playerNumber;
		int	player1Count;
		int	player2Count;
		bool isCPressed;
		bool isOPressed;
		bool isMPressed;
		bool isBPressed;
	};

	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態(Game Over)
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g, CShareData *data);
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
		void OnMouseMove(UINT nFlags, CPoint point);	// 處理滑鼠的動作 
		void OnLButtonUp(UINT nFlags, CPoint point);  // 處理滑鼠的動作
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CScore score;
		CMovingBitmap successPage;
		CMovingBitmap failPage;
		CMovingBitmap endPage;
		CMovingBitmap cross;
		CMovingBitmap musicButton;
		CMovingBitmap soundButton;
		CMovingBitmap backButton;
		CMovingBitmap nextLevelButton;
		CMovingBitmap tryAgainButton;
		CAnimation player1Success;
		CMovingBitmap player1Fail;
		CAnimation player2Success;
		CMovingBitmap player2Fail;
		bool isSuccess;
		bool isFail;
		bool isEnd;
		bool isOnMusicButton;
		bool isOnSoundButton;
		bool isOnBackButton;
		bool isOnNextLevelButton;
		bool isOnTryAgainButton;
		int playerNumber;
		const int CROSS_LENGTH = 53;
		const int CROSS_HEIGHT = 53;
		const int MUSIC_INDEX_X = 1140;
		const int MUSIC_INDEX_Y = 13;
		const int SOUND_INDEX_X = 1219;
		const int SOUND_INDEX_Y = 13;
		const int BACK_BUTTON_INDEX_X = 217;
		const int BACK_BUTTON_INDEX_Y = 835;
		const int BACK_BUTTON_LENGTH = 143;
		const int BACK_BUTTON_HEIGHT = 34;
		const int NEXT_LEVEL_BUTTON_INDEX_X = 794;
		const int NEXT_LEVEL_BUTTON_INDEX_Y = 835;
		const int NEXT_LEVEL_BUTTON_LENGTH = 319;
		const int NEXT_LEVEL_BUTTON_HEIGHT = 31;
		const int TRY_AGAIN_BUTTON_INDEX_X = 868;
		const int TRY_AGAIN_BUTTON_INDEX_Y = 835;
		const int TRY_AGAIN_BUTTON_LENGTH = 266;
		const int TRY_AGAIN_BUTTON_HEIGHT = 30;
		const int SCORE_INDEX_X = 701;
		const int SCORE_INDEX_Y = 478;
		const int SCORE_INDEX_Y_FOR_END = 175;
		const int PLAYER_INDEX_X = 583;
		const int PLAYER1_INDEX_X = 510;
		const int PLAYER2_INDEX_X = 669;
		const int PLAYER_INDEX_Y = 224;
	};

}