#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CMonster.h"
#include <stdlib.h>
#include <time.h>

namespace game_framework {
	CMonster::CMonster()
	{
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		isHit = isFood = false;
		isAlive = true;
		movingLeftCount = movingRightCount = movingUpCount = movingDownCount = foodTime = 0;
		faceTo = SetMovingDirection();
		leftAnimation.SetDelayCount(2);
		rightAnimation.SetDelayCount(2);
		upAnimation.SetDelayCount(2);
		downAnimation.SetDelayCount(2);
	}

	int CMonster::GetIndexX()
	{
		return indexX;
	}

	int CMonster::GetIndexY()
	{
		return indexY;
	}

	int CMonster::GetNextIndexX()
	{
		if (faceTo == CDirection::LEFT)
		{
			return indexX - 1;
		}
		else if (faceTo == CDirection::RIGHT)
		{
			return indexX + 1;
		}
		else
		{
			return indexX;
		}
	}

	int CMonster::GetNextIndexY()
	{
		if (faceTo == CDirection::UP)
		{
			return indexY - 1;
		}
		else if (faceTo == CDirection::DOWN)
		{
			return indexY + 1;
		}
		else
		{
			return indexY;
		}
	}

	bool CMonster::IsFood()
	{
		return isFood;
	}

	bool CMonster::IsAlive()
	{
		return isAlive;
	}

	void CMonster::Initialize(CMap *map)
	{
		mapRecord = map;
	}

	void CMonster::LoadBitmap()
	{
	}

	void CMonster::OnMove()
	{
		const int FOOD_TIME_LIMIT = 90;
		const int STEP_TARGET = 24;
		const int STEP_SIZE_X = 3;
		const int STEP_SIZE_Y = 2;
		const int HIT_TARGET = 8;
		const int HIT_STEP_SIZE_X = 9;
		const int HIT_STEP_SIZE_Y = 6;

		if (!isMovingLeft && !isMovingRight && !isMovingDown && !isMovingUp && !isHit && !isFood && isAlive)
		{
			faceTo = SetMovingDirection();
			movingLeftCount = movingRightCount = movingUpCount = movingDownCount = 0;
			if (faceTo == CDirection::LEFT)
				isMovingLeft = true;
			else if (faceTo == CDirection::RIGHT)
				isMovingRight = true;
			else if (faceTo == CDirection::UP)
				isMovingUp = true;
			else if (faceTo == CDirection::DOWN)
				isMovingDown = true;
		}

		if (isFood)
		{
			hitLeftAnimation.OnMove();
			hitRightAnimation.OnMove();
			hitUpAnimation.OnMove();
			hitDownAnimation.OnMove();
			foodTime++;
			if (foodTime == FOOD_TIME_LIMIT)
			{
				isFood = false;
				isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
				foodTime = 0;
				mapRecord->SetMonsterInMap(indexX, indexY, CName::MUD);
			}
		}

		if (isHit)
		{
			if (isMovingLeft && movingLeftCount != 0)
			{
				hitLeftAnimation.OnMove();
				x -= STEP_SIZE_X;
				movingLeftCount++;
				mapRecord->SetMonsterInMap(indexX - 1, indexY, CName::MUD);
				if (movingLeftCount == STEP_TARGET)
				{
					mapRecord->SetMonsterInMap(indexX--, indexY, CName::SPACE);
					movingLeftCount = 0;
					isMovingLeft = false;
				}
			}
			else if (isMovingRight && movingRightCount != 0)
			{
				hitRightAnimation.OnMove();
				x += STEP_SIZE_X;
				movingRightCount++;
				mapRecord->SetMonsterInMap(indexX + 1, indexY, CName::MUD);
				if (movingRightCount == STEP_TARGET)
				{
					mapRecord->SetMonsterInMap(indexX++, indexY, CName::SPACE);
					movingRightCount = 0;
					isMovingRight = false;
				}
			}
			else if (isMovingUp && movingUpCount != 0)
			{
				hitUpAnimation.OnMove();
				y -= STEP_SIZE_Y;
				movingUpCount++;
				mapRecord->SetMonsterInMap(indexX, indexY - 1, CName::MUD);
				if (movingUpCount == STEP_TARGET)
				{
					mapRecord->SetMonsterInMap(indexX, indexY--, CName::SPACE);
					movingUpCount = 0;
					isMovingUp = false;
				}
			}
			else if (isMovingDown && movingDownCount != 0)
			{
				hitDownAnimation.OnMove();
				y += STEP_SIZE_Y;
				movingDownCount++;
				mapRecord->SetMonsterInMap(indexX, indexY + 1, CName::MUD);
				if (movingDownCount == STEP_TARGET)
				{
					mapRecord->SetMonsterInMap(indexX, indexY++, CName::SPACE);
					movingDownCount = 0;
					isMovingDown = false;
				}
			}
			else
			{
				if (faceTo == CDirection::LEFT)
				{
					hitLeftAnimation.OnMove();
					//x += HIT_STEP_SIZE_X;
					hitCount++;
					if (hitCount == HIT_TARGET)
					{
						//mapRecord->SetMonsterInMap(indexX, indexY, CName::SPACE);
						//mapRecord->SetMonsterInMap(++indexX, indexY, CName::MUD_FOOD);
						mapRecord->SetMonsterInMap(indexX, indexY, CName::MUD_FOOD);
						isFood = true;
						isHit = false;
						hitCount = 0;
					}
				}
				else if (faceTo == CDirection::RIGHT)
				{
					hitRightAnimation.OnMove();
					//x -= HIT_STEP_SIZE_X;
					hitCount++;
					if (hitCount == HIT_TARGET)
					{
						//mapRecord->SetMonsterInMap(indexX, indexY, CName::SPACE);
						//mapRecord->SetMonsterInMap(--indexX, indexY, CName::MUD_FOOD);
						mapRecord->SetMonsterInMap(indexX, indexY, CName::MUD_FOOD);
						isFood = true;
						isHit = false;
						hitCount = 0;
					}
				}
				else if (faceTo == CDirection::UP)
				{
					hitUpAnimation.OnMove();
					//y += HIT_STEP_SIZE_Y;
					hitCount++;
					if (hitCount == HIT_TARGET)
					{
						//mapRecord->SetMonsterInMap(indexX, indexY, CName::SPACE);
						//mapRecord->SetMonsterInMap(indexX, ++indexY, CName::MUD_FOOD);
						mapRecord->SetMonsterInMap(indexX, indexY, CName::MUD_FOOD);
						isFood = true;
						isHit = false;
						hitCount = 0;
					}
				}
				else if (faceTo == CDirection::DOWN)
				{
					hitDownAnimation.OnMove();
					//y -= HIT_STEP_SIZE_Y;
					hitCount++;
					if (hitCount == HIT_TARGET)
					{
						//mapRecord->SetMonsterInMap(indexX, indexY, CName::SPACE);
						//mapRecord->SetMonsterInMap(indexX, --indexY, CName::MUD_FOOD);
						mapRecord->SetMonsterInMap(indexX, indexY, CName::MUD_FOOD);
						isFood = true;
						isHit = false;
						hitCount = 0;
					}
				}
			}
		}

		if (!isHit && !isFood)
		{
			if (isMovingLeft)
			{
				if ((mapRecord->GetBrickInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetFoodInMap(indexX - 1, indexY) == CName::SPACE) || movingLeftCount != 0)
				{
					leftAnimation.OnMove();
					x -= STEP_SIZE_X;
					movingLeftCount++;
					mapRecord->SetMonsterInMap(indexX - 1, indexY, CName::MUD);
					if (movingLeftCount == STEP_TARGET)
					{
						mapRecord->SetMonsterInMap(indexX--, indexY, CName::SPACE);
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
				if ((mapRecord->GetBrickInMap(indexX + 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX + 1, indexY) == CName::SPACE && mapRecord->GetFoodInMap(indexX + 1, indexY) == CName::SPACE) || movingRightCount != 0)
				{
					rightAnimation.OnMove();
					x += STEP_SIZE_X;
					movingRightCount++;
					mapRecord->SetMonsterInMap(indexX + 1, indexY, CName::MUD);
					if (movingRightCount == STEP_TARGET)
					{
						mapRecord->SetMonsterInMap(indexX++, indexY, CName::SPACE);
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
				if ((mapRecord->GetBrickInMap(indexX, indexY - 1) == CName::SPACE && mapRecord->GetMonsterInMap(indexX, indexY - 1) == CName::SPACE && mapRecord->GetFoodInMap(indexX, indexY - 1) == CName::SPACE) || movingUpCount != 0)
				{
					upAnimation.OnMove();
					y -= STEP_SIZE_Y;
					movingUpCount++;
					mapRecord->SetMonsterInMap(indexX, indexY - 1, CName::MUD);
					if (movingUpCount == STEP_TARGET)
					{
						mapRecord->SetMonsterInMap(indexX, indexY--, CName::SPACE);
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
				if ((mapRecord->GetBrickInMap(indexX, indexY + 1) == CName::SPACE && mapRecord->GetMonsterInMap(indexX, indexY + 1) == CName::SPACE && mapRecord->GetFoodInMap(indexX, indexY + 1) == CName::SPACE) || movingDownCount != 0)
				{
					downAnimation.OnMove();
					y += STEP_SIZE_Y;
					movingDownCount++;
					mapRecord->SetMonsterInMap(indexX, indexY + 1, CName::MUD);
					if (movingDownCount == STEP_TARGET)
					{
						mapRecord->SetMonsterInMap(indexX, indexY++, CName::SPACE);
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

	CDirection CMonster::SetMovingDirection()
	{
		srand((unsigned int)time(NULL));

		int x = rand();
		int flag = x % 4;

		switch (flag) {
		case 0:
			return CDirection::RIGHT;
		case 1:
			return CDirection::LEFT;
		case 2:
			return CDirection::DOWN;
		case 3:
			return CDirection::UP;
		default:
			printf("ERROR!! in CMonster.cpp function SetMoveingDirection switch case to default");
			return CDirection::LEFT;
		};
	}

	void CMonster::SetXY(int ni, int nj, int nx, int ny)
	{
		indexX = ni;
		indexY = nj;
		x = nx;
		y = ny;
	}

	void CMonster::OnShow()
	{
		if (isAlive)
		{
			if (isHit || isFood)
			{
				if (faceTo == CDirection::LEFT)
				{
					hitLeftAnimation.SetTopLeft(x + (72 / 2) - (hitLeftAnimation.Width() / 2), y + 46 - hitLeftAnimation.Height());
					hitLeftAnimation.OnShow();
				}
				else if (faceTo == CDirection::RIGHT)
				{
					hitRightAnimation.SetTopLeft(x + (72 / 2) - (hitRightAnimation.Width() / 2), y + 46 - hitRightAnimation.Height());
					hitRightAnimation.OnShow();
				}
				else if (faceTo == CDirection::UP)
				{
					hitUpAnimation.SetTopLeft(x + (72 / 2) - (hitUpAnimation.Width() / 2), y + 46 - hitUpAnimation.Height());
					hitUpAnimation.OnShow();
				}
				else if (faceTo == CDirection::DOWN)
				{
					hitDownAnimation.SetTopLeft(x + (72 / 2) - (hitDownAnimation.Width() / 2), y + 46 - hitDownAnimation.Height());
					hitDownAnimation.OnShow();
				}
			}
			else
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
	}

	void CMonster::HitByBrick(CDirection tempDir)
	{
		if (!isHit && !isFood)
		{
			//ReturnBack();
			hitCount = 0;
			faceTo = tempDir;
			isHit = true;
		}
	}

	void CMonster::ReturnBack()
	{
		const int STEP_SIZE_X = 3;
		const int STEP_SIZE_Y = 2;
		if (faceTo == CDirection::LEFT)
		{
			hitLeftAnimation.OnMove();
			//x += STEP_SIZE_X;
			//movingCount--;
			x += STEP_SIZE_X * movingLeftCount;
			movingLeftCount = 0;
			mapRecord->SetMonsterInMap(indexX - 1, indexY, CName::SPACE);
		}
		else if (faceTo == CDirection::RIGHT)
		{
			hitRightAnimation.OnMove();
			//x -= STEP_SIZE_X;
			//movingCount--;
			x -= STEP_SIZE_X * movingRightCount;
			movingRightCount = 0;
			mapRecord->SetMonsterInMap(indexX + 1, indexY, CName::SPACE);
		}
		else if (faceTo == CDirection::UP)
		{
			hitUpAnimation.OnMove();
			//y += STEP_SIZE_Y;
			//movingCount--;
			y += STEP_SIZE_Y * movingUpCount;
			movingUpCount = 0;
			mapRecord->SetMonsterInMap(indexX, indexY - 1, CName::SPACE);
		}
		else if (faceTo == CDirection::DOWN)
		{
			hitDownAnimation.OnMove();
			//y -= STEP_SIZE_Y;
			//movingCount--;
			y -= STEP_SIZE_Y * movingDownCount;
			movingDownCount = 0;
			mapRecord->SetMonsterInMap(indexX, indexY + 1, CName::SPACE);
		}
	}

	void CMonster::Swallowed()
	{
		isAlive = isFood = false;
		mapRecord->SetMonsterInMap(indexX, indexY, CName::SPACE);
	}
	void CMonster::Reset()
	{
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		isHit = isFood = false;
		isAlive = true;
		movingLeftCount = movingRightCount = movingUpCount = movingDownCount = foodTime = 0;
		faceTo = SetMovingDirection();
	}
}