#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CMud.h"
#include <stdlib.h>
#include <time.h>

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
		const int STEP_TARGET = 8;
		const int STEP_SIZE_X = 9;
		const int STEP_SIZE_Y = 6;

		if (isMovingLeft)
		{
			if (mapRecord[indexX - 1][indexY] == CName::SPACE)
			{
				leftAnimation.OnMove();
				x -= STEP_SIZE_X;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = CName::SPACE;
					mapRecord[--indexX][indexY] = CName::PLAYER;
					movingCount = 0;
					isMovingLeft = isKeyLeftPressed;
				}
			}
			else
			{
				isMovingLeft = isKeyLeftPressed;
			}
		}
		else if (isMovingRight)
		{
			if (mapRecord[indexX + 1][indexY] == CName::SPACE)
			{
				rightAnimation.OnMove();
				x += STEP_SIZE_X;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = CName::SPACE;
					mapRecord[++indexX][indexY] = CName::PLAYER;
					movingCount = 0;
					isMovingRight = isKeyRightPressed;
				}
			}
			else
			{
				isMovingRight = isKeyRightPressed;
			}
		}
		else if (isMovingUp)
		{
			if (mapRecord[indexX][indexY - 1] == CName::SPACE)
			{
				upAnimation.OnMove();
				y -= STEP_SIZE_Y;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = CName::SPACE;
					mapRecord[indexX][--indexY] = CName::PLAYER;
					movingCount = 0;
					isMovingUp = isKeyUpPressed;
				}
			}
			else
			{
				isMovingUp = isKeyUpPressed;
			}
		}
		else if (isMovingDown)
		{
			if (mapRecord[indexX][indexY + 1] == CName::SPACE)
			{
				downAnimation.OnMove();
				y += STEP_SIZE_Y;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = CName::SPACE;
					mapRecord[indexX][++indexY] = CName::PLAYER;
					movingCount = 0;
					isMovingDown = isKeyDownPressed;
				}
			}
			else
			{
				isMovingDown = isKeyDownPressed;
			}
		}
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

	CDirection CMud::SetMovingDirection() {
		srand(time(NULL));

		int x = rand();
		int flag = x % 4;

		switch(flag){
			case 0:
				return CDirection::RIGHT;
			case 1:
				return CDirection::LEFT;
			case 2:
				return CDirection::DOWN;
			case 3:
				return CDirection::UP;
			default:
				printf("ERROR!! in CMud.cpp function SetMoveingDirection switch case to default");
				return CDirection::LEFT;
		};
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
		if (faceTo == CDirection::LEFT)
		{
			if (!isMovingLeft)
			{
				leftAnimation.Reset();
			}
			leftAnimation.SetTopLeft(x + (72 / 2) - (leftAnimation.Width() / 2), y + 46 - leftAnimation.Height());
			leftAnimation.OnShow();
		}
		else if (faceTo == CDirection::RIGHT)
		{
			if (!isMovingRight)
			{
				rightAnimation.Reset();
			}
			rightAnimation.SetTopLeft(x + (72 / 2) - (rightAnimation.Width() / 2), y + 46 - rightAnimation.Height());
			rightAnimation.OnShow();
		}
		else if (faceTo == CDirection::UP)
		{
			if (!isMovingUp)
			{
				upAnimation.Reset();
			}
			upAnimation.SetTopLeft(x + (72 / 2) - (upAnimation.Width() / 2), y + 46 - upAnimation.Height());
			upAnimation.OnShow();
		}
		else if (faceTo == CDirection::DOWN)
		{
			if (!isMovingDown)
			{
				downAnimation.Reset();
			}
			downAnimation.SetTopLeft(x + (72 / 2) - (downAnimation.Width() / 2), y + 46 - downAnimation.Height());
			downAnimation.OnShow();
		}
	}
}