#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CStone.h"

namespace game_framework {
	CStone::CStone()
	{
		x = y = 0;
		isAlive = true;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
	}

	int CStone::GetIndexX() {
		return indexX;
	}

	int CStone::GetIndexY() {
		return indexY;
	}

	bool CStone::IsMove()
	{
		return isMovingLeft || isMovingRight || isMovingUp || isMovingDown;
	}

	void CStone::Initialize(CName **map)
	{
		mapRecord = map;
	}

	void CStone::LoadBitmap()
	{
		bitmap.LoadBitmap(IDB_STONE_BRICK);
	}

	void CStone::OnMove()
	{
		const int STEP_TARGET = 6;
		const int STEP_SIZE_X = 12;
		const int STEP_SIZE_Y = 8;

		if (isMovingLeft)
		{
			if (mapRecord[indexX - 1][indexY] == CName::SPACE || mapRecord[indexX - 1][indexY] == CName::PLAYER)
			{
				x -= STEP_SIZE_X;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = CName::SPACE;
					mapRecord[--indexX][indexY] = CName::STONE;
					movingCount = 0;
					isMovingLeft = (mapRecord[indexX - 1][indexY] == CName::SPACE || mapRecord[indexX - 1][indexY] == CName::PLAYER);
				}
			}
			else
			{
				isMovingLeft = false;
			}
		}
		else if (isMovingRight)
		{
			if (mapRecord[indexX + 1][indexY] == CName::SPACE || mapRecord[indexX + 1][indexY] == CName::PLAYER)
			{
				x += STEP_SIZE_X;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = CName::SPACE;
					mapRecord[++indexX][indexY] = CName::STONE;
					movingCount = 0;
					isMovingRight = (mapRecord[indexX + 1][indexY] == CName::SPACE || mapRecord[indexX + 1][indexY] == CName::PLAYER);
				}
			}
			else
			{
				isMovingRight = false;
			}
		}
		else if (isMovingUp)
		{
			if (mapRecord[indexX][indexY - 1] == CName::SPACE || mapRecord[indexX][indexY - 1] == CName::PLAYER)
			{
				y -= STEP_SIZE_Y;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = CName::SPACE;
					mapRecord[indexX][--indexY] = CName::STONE;
					movingCount = 0;
					isMovingUp = (mapRecord[indexX][indexY - 1] == CName::SPACE || mapRecord[indexX][indexY - 1] == CName::PLAYER);
				}
			}
			else
			{
				isMovingUp = false;
			}
		}
		else if (isMovingDown)
		{
			if (mapRecord[indexX][indexY + 1] == CName::SPACE || mapRecord[indexX][indexY + 1] == CName::PLAYER)
			{
				y += STEP_SIZE_Y;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = CName::SPACE;
					mapRecord[indexX][++indexY] = CName::STONE;
					movingCount = 0;
					isMovingDown = (mapRecord[indexX][indexY + 1] == CName::SPACE || mapRecord[indexX][indexY + 1] == CName::PLAYER);
				}
			}
			else
			{
				isMovingDown = false;
			}
		}
	}

	void CStone::SpitedOut(CDirection faceTo)
	{
		movingCount = 0;
		if (faceTo == CDirection::LEFT)
		{
			isMovingLeft = true;
		}
		else if (faceTo == CDirection::RIGHT)
		{
			isMovingRight = true;
		}
		else if (faceTo == CDirection::UP)
		{
			isMovingUp = true;
		}
		else if (faceTo == CDirection::DOWN)
		{
			isMovingDown = true;
		}
	}

	void CStone::SetXY(int ni, int nj, int nx, int ny)
	{
		indexX = ni;
		indexY = nj;
		x = nx;
		y = ny;
	}

	void CStone::setAlive(bool flag)
	{
		isAlive = flag;
	}

	void CStone::OnShow()
	{
		if (isAlive) {
			bitmap.SetTopLeft(x, y - 24);
			bitmap.ShowBitmap();
		}
	}
}