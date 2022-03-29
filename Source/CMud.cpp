#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CMud.h"

namespace game_framework {
	CMud::CMud()
	{
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		movingCount = 0;
		faceTo = CDirection::DOWN;
		leftAnimation.SetDelayCount(2);
		rightAnimation.SetDelayCount(2);
		upAnimation.SetDelayCount(2);
		downAnimation.SetDelayCount(2);
	}

	int CMud::GetIndexX() {
		return indexX;
	}

	int CMud::GetIndexY() {
		return indexY;
	}

	void CMud::Initialize(CName **map)
	{
		mapRecord = map;
	}

	void CMud::LoadBitmap()
	{
		leftAnimation.AddBitmap(IDB_MUD_MOVE_LEFT_001, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_MUD_MOVE_LEFT_002, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_MUD_MOVE_LEFT_003, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_MUD_MOVE_LEFT_004, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_MUD_MOVE_LEFT_005, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_MUD_MOVE_LEFT_006, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_MUD_MOVE_LEFT_007, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_MUD_MOVE_LEFT_008, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_MUD_MOVE_RIGHT_001, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_MUD_MOVE_RIGHT_002, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_MUD_MOVE_RIGHT_003, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_MUD_MOVE_RIGHT_004, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_MUD_MOVE_RIGHT_005, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_MUD_MOVE_RIGHT_006, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_MUD_MOVE_RIGHT_007, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_MUD_MOVE_RIGHT_008, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_MUD_MOVE_UP_001, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_MUD_MOVE_UP_002, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_MUD_MOVE_UP_003, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_MUD_MOVE_UP_004, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_MUD_MOVE_UP_005, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_MUD_MOVE_UP_006, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_MUD_MOVE_UP_007, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_MUD_MOVE_UP_008, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_MUD_MOVE_DOWN_001, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_MUD_MOVE_DOWN_002, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_MUD_MOVE_DOWN_003, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_MUD_MOVE_DOWN_004, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_MUD_MOVE_DOWN_005, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_MUD_MOVE_DOWN_006, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_MUD_MOVE_DOWN_007, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_MUD_MOVE_DOWN_008, RGB(0, 0, 0));

		/*
		eatLeftAnimation.AddBitmap(IDB_PLAYER_EAT_LEFT_001, RGB(0, 0, 0));
		eatLeftAnimation.AddBitmap(IDB_PLAYER_EAT_LEFT_002, RGB(0, 0, 0));
		eatLeftAnimation.AddBitmap(IDB_PLAYER_EAT_LEFT_003, RGB(0, 0, 0));
		eatLeftAnimation.AddBitmap(IDB_PLAYER_EAT_LEFT_004, RGB(0, 0, 0));
		eatRightAnimation.AddBitmap(IDB_PLAYER_EAT_RIGHT_001, RGB(0, 0, 0));
		eatRightAnimation.AddBitmap(IDB_PLAYER_EAT_RIGHT_002, RGB(0, 0, 0));
		eatRightAnimation.AddBitmap(IDB_PLAYER_EAT_RIGHT_003, RGB(0, 0, 0));
		eatRightAnimation.AddBitmap(IDB_PLAYER_EAT_RIGHT_004, RGB(0, 0, 0));
		eatUpAnimation.AddBitmap(IDB_PLAYER_EAT_UP_001, RGB(0, 0, 0));
		eatUpAnimation.AddBitmap(IDB_PLAYER_EAT_UP_002, RGB(0, 0, 0));
		eatUpAnimation.AddBitmap(IDB_PLAYER_EAT_UP_003, RGB(0, 0, 0));
		eatUpAnimation.AddBitmap(IDB_PLAYER_EAT_UP_004, RGB(0, 0, 0));
		eatDownAnimation.AddBitmap(IDB_PLAYER_EAT_DOWN_001, RGB(0, 0, 0));
		eatDownAnimation.AddBitmap(IDB_PLAYER_EAT_DOWN_002, RGB(0, 0, 0));
		eatDownAnimation.AddBitmap(IDB_PLAYER_EAT_DOWN_003, RGB(0, 0, 0));
		eatDownAnimation.AddBitmap(IDB_PLAYER_EAT_DOWN_004, RGB(0, 0, 0));*/
	}

	void CMud::OnMove()
	{
		
	}

	void CMud::SetMovingLeft(bool flag)
	{
	}

	void CMud::SetMovingRight(bool flag)
	{
	}

	void CMud::SetMovingUp(bool flag)
	{
	}

	void CMud::SetMovingDown(bool flag)
	{
	}

	void CMud::SetXY(int ni, int nj, int nx, int ny)
	{
		indexX = ni;
		indexY = nj;
		x = nx;
		y = ny;
	}

	void CMud::OnShow()
	{
		
	}
}