#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CBrick.h"

namespace game_framework {
	CBrick::CBrick()
	{
		x = y = 0;
		isAlive = true;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		isSwallowed = false;
	}

	int CBrick::GetIndexX() {
		return indexX;
	}

	int CBrick::GetIndexY() {
		return indexY;
	}

	bool CBrick::IsMove()
	{
		return isMovingLeft || isMovingRight || isMovingUp || isMovingDown;
	}

	void CBrick::Initialize(CMap &map, CMud *mud)
	{
		mapRecord = map;
		mudRecord = mud;
	}

	void CBrick::LoadBitmap()
	{
		//bitmap.LoadBitmap(IDB_STONE_BRICK);
	}

	void CBrick::OnMove()
	{
		const int STEP_TARGET = 6;
		const int STEP_SIZE_X = 12;
		const int STEP_SIZE_Y = 8;
		const int BRICK_LENGTH = 72;
		const int BRICK_WIDTH = 48;

		if (isSwallowed)
		{
			if (isMovingLeft)
			{
				x -= STEP_SIZE_X;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord.SetCNameInMap(indexX, indexY, CName::SPACE);
					movingCount = 0;
					isMovingLeft = isSwallowed = isAlive = false;
				}
			}
			else if (isMovingRight)
			{
				x += STEP_SIZE_X;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord.SetCNameInMap(indexX, indexY, CName::SPACE);
					movingCount = 0;
					isMovingRight = isSwallowed = isAlive = false;
				}
			}
			else if (isMovingUp)
			{
				y -= STEP_SIZE_Y;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord.SetCNameInMap(indexX, indexY, CName::SPACE);
					movingCount = 0;
					isMovingUp = isSwallowed = isAlive = false;
				}
			}
			else if (isMovingDown)
			{
				y += STEP_SIZE_Y;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord.SetCNameInMap(indexX, indexY, CName::SPACE);
					movingCount = 0;
					isMovingDown = isSwallowed = isAlive = false;
				}
			}
		}
		else
		{
			if (isMovingLeft)
			{
				if (mapRecord.GetCNameInMap(indexX - 1, indexY) == CName::SPACE || mapRecord.GetCNameInMap(indexX - 1, indexY) == CName::PLAYER || mapRecord.GetCNameInMap(indexX - 1, indexY) == CName::MUD)
				{
					x -= STEP_SIZE_X;
					movingCount++;
					if (movingCount == STEP_TARGET)
					{
						if (mapRecord.GetCNameInMap(indexX - 1, indexY) == CName::MUD) {
							mudRecord->HitByBrick(CDirection::LEFT);
						}
						else {
							mapRecord.SetCNameInMap(indexX, indexY, CName::SPACE);
						}
						mapRecord.SetCNameInMap(--indexX, indexY, CName::STONE);
						movingCount = 0;
						isMovingLeft = (mapRecord.GetCNameInMap(indexX - 1, indexY) == CName::SPACE || mapRecord.GetCNameInMap(indexX - 1, indexY) == CName::PLAYER || mapRecord.GetCNameInMap(indexX - 1, indexY) == CName::MUD);
					}
				}
				else
				{
					isMovingLeft = false;
				}
			}
			else if (isMovingRight)
			{
				if (mapRecord.GetCNameInMap(indexX + 1, indexY) == CName::SPACE || mapRecord.GetCNameInMap(indexX + 1, indexY) == CName::PLAYER || mapRecord.GetCNameInMap(indexX + 1, indexY) == CName::MUD)
				{
					x += STEP_SIZE_X;
					movingCount++;
					if (movingCount == STEP_TARGET)
					{
						if (mapRecord.GetCNameInMap(indexX + 1, indexY) == CName::MUD) {
							mudRecord->HitByBrick(CDirection::RIGHT);
						}
						else {
							mapRecord.SetCNameInMap(indexX, indexY, CName::SPACE);
						}
						mapRecord.SetCNameInMap(++indexX, indexY, CName::STONE);
						movingCount = 0;
						isMovingRight = (mapRecord.GetCNameInMap(indexX + 1, indexY) == CName::SPACE || mapRecord.GetCNameInMap(indexX + 1, indexY) == CName::PLAYER || mapRecord.GetCNameInMap(indexX + 1, indexY) == CName::MUD);
					}
				}
				else
				{
					isMovingRight = false;
				}
			}
			else if (isMovingUp)
			{
				if (mapRecord.GetCNameInMap(indexX, indexY - 1) == CName::SPACE || mapRecord.GetCNameInMap(indexX, indexY - 1) == CName::PLAYER || mapRecord.GetCNameInMap(indexX, indexY - 1) == CName::MUD)
				{
					y -= STEP_SIZE_Y;
					movingCount++;
					if (movingCount == STEP_TARGET)
					{
						if (mapRecord.GetCNameInMap(indexX, indexY - 1) == CName::MUD) {
							mudRecord->HitByBrick(CDirection::UP);
						}
						else {
							mapRecord.SetCNameInMap(indexX, indexY, CName::SPACE);
						}
						mapRecord.SetCNameInMap(indexX, --indexY, CName::STONE);
						movingCount = 0;
						isMovingUp = (mapRecord.GetCNameInMap(indexX, indexY - 1) == CName::SPACE || mapRecord.GetCNameInMap(indexX, indexY - 1) == CName::PLAYER || mapRecord.GetCNameInMap(indexX, indexY - 1) == CName::MUD);
					}
				}
				else
				{
					isMovingUp = false;
				}
			}
			else if (isMovingDown)
			{
				if (mapRecord.GetCNameInMap(indexX, indexY + 1) == CName::SPACE || mapRecord.GetCNameInMap(indexX, indexY + 1) == CName::PLAYER || mapRecord.GetCNameInMap(indexX, indexY + 1) == CName::MUD)
				{
					y += STEP_SIZE_Y;
					movingCount++;
					if (movingCount == STEP_TARGET)
					{
						if (mapRecord.GetCNameInMap(indexX, indexY + 1) == CName::MUD) {
							mudRecord->HitByBrick(CDirection::DOWN);
						}
						else {
							mapRecord.SetCNameInMap(indexX, indexY, CName::SPACE);
						}
						mapRecord.SetCNameInMap(indexX, ++indexY, CName::STONE);
						movingCount = 0;
						isMovingDown = (mapRecord.GetCNameInMap(indexX, indexY + 1) == CName::SPACE || mapRecord.GetCNameInMap(indexX, indexY + 1) == CName::PLAYER || mapRecord.GetCNameInMap(indexX, indexY + 1) == CName::MUD);
					}
				}
				else
				{
					isMovingDown = false;
				}
			}
		}
	}

	void CBrick::SpitedOut(CDirection faceTo, int ni, int nj, int nx, int ny)
	{
		indexX = ni;
		indexY = nj;
		x = nx;
		y = ny;
		mapRecord.SetCNameInMap(indexX, indexY, CName::STONE);
		isAlive = true;
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

	void CBrick::SetXY(int ni, int nj, int nx, int ny)
	{
		indexX = ni;
		indexY = nj;
		x = nx;
		y = ny;
	}

	void CBrick::Swallowed(CDirection faceTo)
	{
		isSwallowed = true;
		movingCount = 0;
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

	void CBrick::OnShow()
	{
		if (isAlive) {
			bitmap.SetTopLeft(x, y - 24);
			bitmap.ShowBitmap();
		}
	}
}