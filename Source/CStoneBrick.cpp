#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CStoneBrick.h"

namespace game_framework {
	CStoneBrick::CStoneBrick()
	{
		x = y = 0;
		isAlive = true;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
	}

	int CStoneBrick::GetIndexX() {
		return indexX;
	}

	int CStoneBrick::GetIndexY() {
		return indexY;
	}

	bool CStoneBrick::IsMove()
	{
		return isMovingLeft || isMovingRight || isMovingUp || isMovingDown;
	}

	void CStoneBrick::Initialize(int **map)
	{
		mapRecord = map;
	}

	void CStoneBrick::LoadBitmap()
	{
		bitmap.LoadBitmap(IDB_STONE_BRICK);
	}

	void CStoneBrick::OnMove()
	{
		const int STEP_TARGET = 6;
		const int STEP_SIZE_X = 12;
		const int STEP_SIZE_Y = 8;

		if (isMovingLeft)
		{
			if (mapRecord[indexX - 1][indexY] == 0 || mapRecord[indexX - 1][indexY] == 1)
			{
				x -= STEP_SIZE_X;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = 0;
					mapRecord[--indexX][indexY] = 3;
					movingCount = 0;
					isMovingLeft = (mapRecord[indexX - 1][indexY] == 0 || mapRecord[indexX - 1][indexY] == 1);
				}
			}
			else
			{
				isMovingLeft = false;
			}
		}
		else if (isMovingRight)
		{
			if (mapRecord[indexX + 1][indexY] == 0 || mapRecord[indexX + 1][indexY] == 1)
			{
				x += STEP_SIZE_X;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = 0;
					mapRecord[++indexX][indexY] = 3;
					movingCount = 0;
					isMovingRight = (mapRecord[indexX + 1][indexY] == 0 || mapRecord[indexX + 1][indexY] == 1);
				}
			}
			else
			{
				isMovingRight = false;
			}
		}
		else if (isMovingUp)
		{
			if (mapRecord[indexX][indexY - 1] == 0 || mapRecord[indexX][indexY - 1] == 1)
			{
				y -= STEP_SIZE_Y;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = 0;
					mapRecord[indexX][--indexY] = 3;
					movingCount = 0;
					isMovingUp = (mapRecord[indexX][indexY - 1] == 0 || mapRecord[indexX][indexY - 1] == 1);
				}
			}
			else
			{
				isMovingUp = false;
			}
		}
		else if (isMovingDown)
		{
			if (mapRecord[indexX][indexY + 1] == 0 || mapRecord[indexX][indexY + 1] == 1)
			{
				y += STEP_SIZE_Y;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = 0;
					mapRecord[indexX][++indexY] = 3;
					movingCount = 0;
					isMovingDown = (mapRecord[indexX][indexY + 1] == 0 || mapRecord[indexX][indexY + 1] == 1);
				}
			}
			else
			{
				isMovingDown = false;
			}
		}
	}

	void CStoneBrick::SpitedOut(string faceTo)
	{
		movingCount = 0;
		if (faceTo == LEFT)
		{
			isMovingLeft = true;
		}
		else if (faceTo == RIGHT)
		{
			isMovingRight = true;
		}
		else if (faceTo == UP)
		{
			isMovingUp = true;
		}
		else if (faceTo == DOWN)
		{
			isMovingDown = true;
		}
	}

	void CStoneBrick::SetXY(int ni, int nj, int nx, int ny)
	{
		indexX = ni;
		indexY = nj;
		x = nx;
		y = ny;
	}

	void CStoneBrick::setAlive(bool flag)
	{
		isAlive = flag;
	}

	void CStoneBrick::OnShow()
	{
		if (isAlive) {
			bitmap.SetTopLeft(x, y - 24);
			bitmap.ShowBitmap();
		}
	}
}