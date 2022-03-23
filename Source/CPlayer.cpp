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
		isKeyLeftPressed = isKeyRightPressed = isKeyUpPressed = isKeyDownPressed = false;
		movingCount = 0;
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
		const int STEP_TARGET = 8;
		const int STEP_SIZE_X = 9;
		const int STEP_SIZE_Y = 6;
		animation.OnMove();
		
		if (!isMovingLeft && !isMovingRight && !isMovingUp && !isMovingDown)
		{
			if (isKeyLeftPressed)
			{
				movingCount = 0;
				isMovingLeft = true;
				animation.ClearBitmapList();
				animation.AddBitmap(IDB_PLAYER_MOVE_LEFT_001, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_LEFT_002, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_LEFT_003, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_LEFT_004, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_LEFT_005, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_LEFT_006, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_LEFT_007, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_LEFT_008, RGB(0, 0, 0));
			}
			else if (isKeyRightPressed)
			{
				movingCount = 0;
				isMovingRight = true;
				animation.ClearBitmapList();
				animation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_001, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_002, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_003, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_004, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_005, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_006, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_007, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_008, RGB(0, 0, 0));
			}
			else if (isKeyUpPressed)
			{
				movingCount = 0;
				isMovingUp = true;
				animation.ClearBitmapList();
				animation.AddBitmap(IDB_PLAYER_MOVE_UP_001, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_UP_002, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_UP_003, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_UP_004, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_UP_005, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_UP_006, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_UP_007, RGB(0, 0, 0));
				animation.AddBitmap(IDB_PLAYER_MOVE_UP_008, RGB(0, 0, 0));
			}
			else if (isKeyDownPressed)
			{
				movingCount = 0;
				isMovingDown = true;
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
		}

		if (isMovingLeft)
		{
			if (mapRecord[indexX - 1][indexY] == 0)
			{
				x -= STEP_SIZE_X;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = 0;
					mapRecord[--indexX][indexY] = 1;
					movingCount = 0;
					if (!isKeyLeftPressed)
					{
						isMovingLeft = false;
						animation.ClearBitmapList();
						animation.AddBitmap(IDB_PLAYER_MOVE_LEFT_001, RGB(0, 0, 0));
					}
				}
			}
			else
			{
				if (!isKeyLeftPressed)
				{
					isMovingLeft = false;
					animation.ClearBitmapList();
					animation.AddBitmap(IDB_PLAYER_MOVE_LEFT_001, RGB(0, 0, 0));
				}
			}
		}

		if (isMovingRight)
		{
			if (mapRecord[indexX + 1][indexY] == 0)
			{
				x += STEP_SIZE_X;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = 0;
					mapRecord[++indexX][indexY] = 1;
					movingCount = 0;
					if (!isKeyRightPressed)
					{
						isMovingRight = false;
						animation.ClearBitmapList();
						animation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_001, RGB(0, 0, 0));
					}
				}
			}
			else
			{
				if (!isKeyRightPressed)
				{
					isMovingRight = false;
					animation.ClearBitmapList();
					animation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_001, RGB(0, 0, 0));
				}
			}
		}

		if (isMovingUp)
		{
			if (mapRecord[indexX][indexY - 1] == 0)
			{
				y -= STEP_SIZE_Y;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = 0;
					mapRecord[indexX][--indexY] = 1;
					movingCount = 0;
					if (!isKeyUpPressed)
					{
						isMovingUp = false;
						animation.ClearBitmapList();
						animation.AddBitmap(IDB_PLAYER_MOVE_UP_001, RGB(0, 0, 0));
					}
				}
			}
			else
			{
				if (!isKeyUpPressed)
				{
					isMovingUp = false;
					animation.ClearBitmapList();
					animation.AddBitmap(IDB_PLAYER_MOVE_UP_001, RGB(0, 0, 0));
				}
			}
		}

		if (isMovingDown)
		{
			if (mapRecord[indexX][indexY + 1] == 0)
			{
				y += STEP_SIZE_Y;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = 0;
					mapRecord[indexX][++indexY] = 1;
					movingCount = 0;
					if (!isKeyDownPressed)
					{
						isMovingDown = false;
						animation.ClearBitmapList();
						animation.AddBitmap(IDB_PLAYER_MOVE_DOWN_001, RGB(0, 0, 0));
					}
				}
			}
			else
			{
				if (!isKeyDownPressed)
				{
					isMovingDown = false;
					animation.ClearBitmapList();
					animation.AddBitmap(IDB_PLAYER_MOVE_DOWN_001, RGB(0, 0, 0));
				}
			}
		}
	}

	void CPlayer::SetMovingLeft(bool flag)
	{
		isKeyLeftPressed = flag;
	}

	void CPlayer::SetMovingRight(bool flag)
	{
		isKeyRightPressed = flag;
	}

	void CPlayer::SetMovingUp(bool flag)
	{
		isKeyUpPressed = flag;
	}

	void CPlayer::SetMovingDown(bool flag)
	{
		isKeyDownPressed = flag;
	}

	void CPlayer::PressKeySpace()
	{

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