#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CPlayer.h"

namespace game_framework {
	CPlayer::CPlayer()
	{
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		moveCountForX = moveCountForY = 0;
		animation.SetDelayCount(2);
	}

	int CPlayer::GetX1()
	{
		return x;
	}

	int CPlayer::GetY1()
	{
		return y;
	}

	int CPlayer::GetX2()
	{
		return x + animation.Width();
	}

	int CPlayer::GetY2()
	{
		return y + animation.Height();
	}

	void CPlayer::Initialize(int **map)
	{
		mapRecord = map;
		for (int i = 0; i < 14; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				if (mapRecord[i][j] == 1)
				{
					indexX = i;
					indexY = j;
					break;
				}
			}
		}
	}

	void CPlayer::LoadBitmap()
	{
		animation.AddBitmap(IDB_PLAYER_MOVE_DOWN_001, RGB(0, 0, 0));
	}

	void CPlayer::OnMove()
	{
		const int STEP_TARGET = 12;
		const int STEP_SIZE_X = 6;
		const int STEP_SIZE_Y = 4;
		animation.OnMove();

		if (isMovingLeft)
		{
			if (moveCountForX != 0)
			{
				x -= STEP_SIZE_X;
				moveCountForX--;
				if (moveCountForX == -STEP_TARGET)
				{
					mapRecord[indexX][indexY] = 0;
					mapRecord[--indexX][indexY] = 1;
					moveCountForX = 0;
				}
			}
			else if (mapRecord[indexX - 1][indexY] == 0 && (moveCountForY == 0 || (moveCountForY < 0 && mapRecord[indexX - 1][indexY - 1] == 0) || (moveCountForY > 0 && mapRecord[indexX - 1][indexY + 1] == 0)))
			{
				x -= STEP_SIZE_X;
				moveCountForX--;
			}
		}
		if (isMovingRight)
		{
			if (moveCountForX != 0)
			{
				x += STEP_SIZE_X;
				moveCountForX++;
				if (moveCountForX == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = 0;
					mapRecord[++indexX][indexY] = 1;
					moveCountForX = 0;
				}
			}
			else if (mapRecord[indexX + 1][indexY] == 0 && (moveCountForY == 0 || (moveCountForY < 0 && mapRecord[indexX + 1][indexY - 1] == 0) || (moveCountForY > 0 && mapRecord[indexX + 1][indexY + 1] == 0)))
			{
				x += STEP_SIZE_X;
				moveCountForX++;
			}
		}
		if (isMovingUp)
		{
			if (moveCountForY != 0)
			{
				y -= STEP_SIZE_Y;
				moveCountForY--;
				if (moveCountForY == -STEP_TARGET)
				{
					mapRecord[indexX][indexY] = 0;
					mapRecord[indexX][--indexY] = 1;
					moveCountForY = 0;
				}
			}
			else if (mapRecord[indexX][indexY - 1] == 0 && (moveCountForX == 0 || (moveCountForX < 0 && mapRecord[indexX - 1][indexY - 1] == 0) || (moveCountForX > 0 && mapRecord[indexX + 1][indexY - 1] == 0)))
			{
				y -= STEP_SIZE_Y;
				moveCountForY--;
			}
		}
		if (isMovingDown)
		{
			if (moveCountForY != 0)
			{
				y += STEP_SIZE_Y;
				moveCountForY++;
				if (moveCountForY == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = 0;
					mapRecord[indexX][++indexY] = 1;
					moveCountForY = 0;
				}
			}
			else if (mapRecord[indexX][indexY + 1] == 0 && (moveCountForX == 0 || (moveCountForX < 0 && mapRecord[indexX - 1][indexY + 1] == 0) || (moveCountForX > 0 && mapRecord[indexX + 1][indexY + 1] == 0)))
			{
				y += STEP_SIZE_Y;
				moveCountForY++;
			}
		}
	}

	void CPlayer::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CPlayer::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CPlayer::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void CPlayer::SetMovingDown(bool flag)
	{
		if (isMovingDown == true && flag == false)
		{
			animation.ClearBitmapList();
			animation.AddBitmap(IDB_PLAYER_MOVE_DOWN_001, RGB(0, 0, 0));
		}
		else if (isMovingDown == false && flag == true)
		{
			animation.ClearBitmapList();
			animation.AddBitmap(IDB_PLAYER_MOVE_DOWN_001, RGB(0, 0, 0));
			animation.AddBitmap(IDB_PLAYER_MOVE_DOWN_002, RGB(0, 0, 0));
			animation.AddBitmap(IDB_PLAYER_MOVE_DOWN_003, RGB(0, 0, 0));
			animation.AddBitmap(IDB_PLAYER_MOVE_DOWN_004, RGB(0, 0, 0));
			animation.AddBitmap(IDB_PLAYER_MOVE_DOWN_005, RGB(0, 0, 0));
			animation.AddBitmap(IDB_PLAYER_MOVE_DOWN_006, RGB(0, 0, 0));
			animation.AddBitmap(IDB_PLAYER_MOVE_DOWN_007, RGB(0, 0, 0));
			animation.AddBitmap(IDB_PLAYER_MOVE_DOWN_008, RGB(0, 0, 0));
			animation.AddBitmap(IDB_PLAYER_MOVE_DOWN_009, RGB(0, 0, 0));
		}
		isMovingDown = flag;
	}

	void CPlayer::SetXY(int nx, int ny)
	{
		x = nx + (72 / 2) - (animation.Width() / 2);
		y = ny + 46 - animation.Height();
	}

	void CPlayer::OnShow()
	{
		animation.SetTopLeft(x, y);
		animation.OnShow();
	}
}