#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CFood.h"

namespace game_framework {
	CFood::CFood()
	{
		x = y = 0;
		movingLeftCount = movingRightCount = movingUpCount = movingDownCount = 0;
		isAlive = true;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		isSwallowed = false;
	}

	int CFood::GetIndexX()
	{
		return indexX;
	}

	int CFood::GetIndexY()
	{
		return indexY;
	}

	void CFood::Initialize(CMap *map)
	{
		mapRecord = map;
	}

	bool CFood::IsAlive()
	{
		return isAlive;
	}

	void CFood::LoadBitmap(CName name)
	{
		if (name == CName::APPLE)
		{
			bitmap.LoadBitmap(IDB_APPLE, RGB(255, 255, 255));
		}
		else if (name == CName::BREAD)
		{
			bitmap.LoadBitmap(IDB_BREAD, RGB(255, 255, 255));
		}
		else if (name == CName::CARROT)
		{
			bitmap.LoadBitmap(IDB_CARROT, RGB(255, 255, 255));
		}
		else if (name == CName::EGG)
		{
			bitmap.LoadBitmap(IDB_EGG, RGB(255, 255, 255));
		}
		else if (name == CName::GRAPE)
		{
			bitmap.LoadBitmap(IDB_GRAPE, RGB(255, 255, 255));
		}
		else if (name == CName::MUTTON)
		{
			bitmap.LoadBitmap(IDB_MUTTON, RGB(255, 255, 255));
		}
		else if (name == CName::PIE)
		{
			bitmap.LoadBitmap(IDB_PIE, RGB(255, 255, 255));
		}
		else if (name == CName::TOMATO)
		{
			bitmap.LoadBitmap(IDB_TOMATO, RGB(255, 255, 255));
		}
		else if (name == CName::TURKEY)
		{
			bitmap.LoadBitmap(IDB_TURKEY, RGB(255, 255, 255));
		}
	}

	void CFood::OnMove()
	{
		const int STEP_TARGET = 6;
		const double STEP_SIZE_X = 6;
		const double STEP_SIZE_Y = 4;
		const int BRICK_LENGTH = 36;
		const int BRICK_WIDTH = 24;

		if (isMovingLeft)
		{
			x -= STEP_SIZE_X;
			movingLeftCount++;
			if (movingLeftCount == STEP_TARGET)
			{
				mapRecord->SetFoodInMap(indexX, indexY, CName::SPACE);
				movingLeftCount = 0;
				isMovingLeft = isSwallowed = isAlive = false;
			}
		}
		else if (isMovingRight)
		{
			x += STEP_SIZE_X;
			movingRightCount++;
			if (movingRightCount == STEP_TARGET)
			{
				mapRecord->SetFoodInMap(indexX, indexY, CName::SPACE);
				movingRightCount = 0;
				isMovingRight = isSwallowed = isAlive = false;
			}
		}
		else if (isMovingUp)
		{
			y -= STEP_SIZE_Y;
			movingUpCount++;
			if (movingUpCount == STEP_TARGET)
			{
				mapRecord->SetFoodInMap(indexX, indexY, CName::SPACE);
				movingUpCount = 0;
				isMovingUp = isSwallowed = isAlive = false;
			}
		}
		else if (isMovingDown)
		{
			y += STEP_SIZE_Y;
			movingDownCount++;
			if (movingDownCount == STEP_TARGET)
			{
				mapRecord->SetFoodInMap(indexX, indexY, CName::SPACE);
				movingDownCount = 0;
				isMovingDown = isSwallowed = isAlive = false;
			}
		}
	}

	void CFood::SetXY(int ni, int nj, int nx, int ny)
	{
		indexX = ni;
		indexY = nj;
		x = double(nx);
		y = double(ny);
	}

	void CFood::SetAlive(bool flag)
	{
		isAlive = flag;
	}

	void CFood::Swallowed(CDirection faceTo)
	{
		isSwallowed = true;
		movingLeftCount = movingRightCount = movingUpCount = movingDownCount = 0;
		if (faceTo == CDirection::LEFT)
		{
			isMovingRight = true;
		}
		else if (faceTo == CDirection::RIGHT)
		{
			isMovingLeft = true;
		}
		else if (faceTo == CDirection::UP)
		{
			isMovingDown = true;
		}
		else if (faceTo == CDirection::DOWN)
		{
			isMovingUp = true;
		}
	}

	void CFood::OnShow()
	{
		if (isAlive) {
			bitmap.SetTopLeft(int(x), int(y) - 12);
			bitmap.ShowBitmap();
		}
	}
}