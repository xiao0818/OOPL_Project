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
		movingLeftCount = movingRightCount = movingUpCount = movingDownCount = 0;
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

	void CBrick::Initialize(CMap *map, list<CMonster> *monster)
	{
		mapRecord = map;
		monsterRecord = monster;
		SetStep();
	}

	void CBrick::LoadBitmap()
	{
	}

	void CBrick::SetStep()
	{
	}

	void CBrick::OnMove()
	{
		const int SWALLOWED_STEP_TARGET = 6;
		const int SWALLOWED_STEP_SIZE_X = 12;
		const int SWALLOWED_STEP_SIZE_Y = 8;
		const int BRICK_LENGTH = 72;
		const int BRICK_WIDTH = 48;

		if (isSwallowed)
		{
			if (isMovingLeft)
			{
				x -= SWALLOWED_STEP_SIZE_X;
				movingLeftCount++;
				if (movingLeftCount == SWALLOWED_STEP_TARGET)
				{
					mapRecord->SetBrickInMap(indexX, indexY, CName::SPACE);
					movingLeftCount = 0;
					isMovingLeft = isSwallowed = isAlive = false;
				}
			}
			else if (isMovingRight)
			{
				x += SWALLOWED_STEP_SIZE_X;
				movingRightCount++;
				if (movingRightCount == SWALLOWED_STEP_TARGET)
				{
					mapRecord->SetBrickInMap(indexX, indexY, CName::SPACE);
					movingRightCount = 0;
					isMovingRight = isSwallowed = isAlive = false;
				}
			}
			else if (isMovingUp)
			{
				y -= SWALLOWED_STEP_SIZE_Y;
				movingUpCount++;
				if (movingUpCount == SWALLOWED_STEP_TARGET)
				{
					mapRecord->SetBrickInMap(indexX, indexY, CName::SPACE);
					movingUpCount = 0;
					isMovingUp = isSwallowed = isAlive = false;
				}
			}
			else if (isMovingDown)
			{
				y += SWALLOWED_STEP_SIZE_Y;
				movingDownCount++;
				if (movingDownCount == SWALLOWED_STEP_TARGET)
				{
					mapRecord->SetBrickInMap(indexX, indexY, CName::SPACE);
					movingDownCount = 0;
					isMovingDown = isSwallowed = isAlive = false;
				}
			}
		}
		else
		{
			if (isMovingLeft)
			{
				if ((mapRecord->GetBrickInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetFoodInMap(indexX - 1, indexY) == CName::SPACE) || movingLeftCount != 0)
				{
					x -= STEP_SIZE_X;
					movingLeftCount++;
					mapRecord->SetBrickInMap(indexX - 1, indexY, CName::STONE);
					if (movingLeftCount == STEP_TARGET)
					{
						if (mapRecord->GetMonsterInMap(indexX - 1, indexY) == CName::MUD || mapRecord->GetMonsterInMap(indexX - 1, indexY) == CName::MUD_FOOD) {
							for (list<CMonster>::iterator k = monsterRecord->begin(); k != monsterRecord->end(); k++)
							{
								if ((k->GetIndexX() == indexX - 1 && k->GetIndexY() == indexY) || (k->GetNextIndexX() == indexX - 1 && k->GetNextIndexY() == indexY))
								{
									k->HitByBrick(CDirection::LEFT);
								}
							}
						}
						mapRecord->SetBrickInMap(indexX--, indexY, CName::SPACE);
						movingLeftCount = 0;
					}
				}
				else
				{
					isMovingLeft = false;
				}
			}
			else if (isMovingRight)
			{
				if ((mapRecord->GetBrickInMap(indexX + 1, indexY) == CName::SPACE && mapRecord->GetFoodInMap(indexX + 1, indexY) == CName::SPACE) || movingRightCount != 0)
				{
					x += STEP_SIZE_X;
					movingRightCount++;
					mapRecord->SetBrickInMap(indexX + 1, indexY, CName::STONE);
					if (movingRightCount == STEP_TARGET)
					{
						if (mapRecord->GetMonsterInMap(indexX + 1, indexY) == CName::MUD || mapRecord->GetMonsterInMap(indexX + 1, indexY) == CName::MUD_FOOD) {
							for (list<CMonster>::iterator k = monsterRecord->begin(); k != monsterRecord->end(); k++)
							{
								if ((k->GetIndexX() == indexX + 1 && k->GetIndexY() == indexY) || (k->GetNextIndexX() == indexX + 1 && k->GetNextIndexY() == indexY))
								{
									k->HitByBrick(CDirection::LEFT);
								}
							}
						}
						mapRecord->SetBrickInMap(indexX++, indexY, CName::SPACE);
						movingRightCount = 0;
					}
				}
				else
				{
					isMovingRight = false;
				}
			}
			else if (isMovingUp)
			{
				if ((mapRecord->GetBrickInMap(indexX, indexY - 1) == CName::SPACE && mapRecord->GetFoodInMap(indexX, indexY - 1) == CName::SPACE) || movingUpCount != 0)
				{
					y -= STEP_SIZE_Y;
					movingUpCount++;
					mapRecord->SetBrickInMap(indexX, indexY - 1, CName::STONE);
					if (movingUpCount == STEP_TARGET)
					{
						if (mapRecord->GetMonsterInMap(indexX, indexY - 1) == CName::MUD || mapRecord->GetMonsterInMap(indexX, indexY - 1) == CName::MUD_FOOD) {
							for (list<CMonster>::iterator k = monsterRecord->begin(); k != monsterRecord->end(); k++)
							{
								if ((k->GetIndexX() == indexX && k->GetIndexY() == indexY - 1) || (k->GetNextIndexX() == indexX && k->GetNextIndexY() == indexY - 1))
								{
									k->HitByBrick(CDirection::LEFT);
								}
							}
						}
						mapRecord->SetBrickInMap(indexX, indexY--, CName::SPACE);
						movingUpCount = 0;
					}
				}
				else
				{
					isMovingUp = false;
				}
			}
			else if (isMovingDown)
			{
				if ((mapRecord->GetBrickInMap(indexX, indexY + 1) == CName::SPACE && mapRecord->GetFoodInMap(indexX, indexY + 1) == CName::SPACE) || movingDownCount != 0)
				{
					y += STEP_SIZE_Y;
					movingDownCount++;
					mapRecord->SetBrickInMap(indexX, indexY + 1, CName::STONE);
					if (movingDownCount == STEP_TARGET)
					{
						if (mapRecord->GetMonsterInMap(indexX, indexY + 1) == CName::MUD || mapRecord->GetMonsterInMap(indexX, indexY + 1) == CName::MUD_FOOD) {
							for (list<CMonster>::iterator k = monsterRecord->begin(); k != monsterRecord->end(); k++)
							{
								if ((k->GetIndexX() == indexX && k->GetIndexY() == indexY + 1) || (k->GetNextIndexX() == indexX && k->GetNextIndexY() == indexY + 1))
								{
									k->HitByBrick(CDirection::LEFT);
								}
							}
						}
						mapRecord->SetBrickInMap(indexX, indexY++, CName::SPACE);
						movingDownCount = 0;
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
		mapRecord->SetBrickInMap(indexX, indexY, CName::STONE);
		isAlive = true;
		movingLeftCount = movingRightCount = movingUpCount = movingDownCount = 0;
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

	void CBrick::OnShow()
	{
		if (isAlive) {
			bitmap.SetTopLeft(x, y - 24);
			bitmap.ShowBitmap();
		}
	}
}