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
		isHit = isFood = isSwallowed = isInvincible = isRush = false;
		isAlive = true;
		movingLeftCount = movingRightCount = movingUpCount = movingDownCount = foodTime = invincibleTime = 0;
		faceTo = GetNewMovingDirection();
		leftAnimation.SetDelayCount(2);
		rightAnimation.SetDelayCount(2);
		upAnimation.SetDelayCount(2);
		downAnimation.SetDelayCount(2);
		rushDownAnimation.SetDelayCount(2);
		rushLeftAnimation.SetDelayCount(2);
		rushRightAnimation.SetDelayCount(2);
		rushUpAnimation.SetDelayCount(2);
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
		if (faceTo == CDirection::LEFT && movingLeftCount != 0)
		{
			return indexX - 1;
		}
		else if (faceTo == CDirection::RIGHT && movingRightCount != 0)
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
		if (faceTo == CDirection::UP && movingUpCount != 0)
		{
			return indexY - 1;
		}
		else if (faceTo == CDirection::DOWN && movingDownCount != 0)
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

	bool CMonster::IsHit()
	{
		return isHit;
	}

	bool CMonster::IsAlive()
	{
		return isAlive;
	}

	bool CMonster::IsInvincible()
	{
		return isInvincible;
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
		if (type == CName::MUD || type == CName::TURTLE)
		{
			MudAndTurtleMove();
		}
		else if (type == CName::SKELETON)
		{
			SkeletonMove();
		}
	}
	
	void CMonster::SetTypeFlag(CName name)
	{
		type = name;
	}

	CDirection CMonster::GetNewMovingDirection()
	{
		srand((unsigned int)time(NULL));

		int x = rand();
		int flag = x % 4;

		switch (flag)
		{
		case 0:
			return CDirection::LEFT;
		case 1:
			return CDirection::RIGHT;
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
		x = double(nx);
		y = double(ny);
	}

	void CMonster::OnShow()
	{
		const int BRICK_LENGTH = 36;
		const int BRICK_WIDTH = 24;
		if (isAlive || isSwallowed)
		{
			if (isInvincible)
			{
				if (faceTo == CDirection::LEFT)
				{
					invincibleLeft.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (invincibleLeft.Width() / 2), int(y) + BRICK_WIDTH - invincibleLeft.Height());
					invincibleLeft.ShowBitmap();
				}
				else if (faceTo == CDirection::RIGHT)
				{
					invincibleRight.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (invincibleRight.Width() / 2), int(y) + BRICK_WIDTH - invincibleRight.Height());
					invincibleRight.ShowBitmap();
				}
				else if (faceTo == CDirection::UP)
				{
					invincibleUp.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (invincibleUp.Width() / 2), int(y) + BRICK_WIDTH - invincibleUp.Height());
					invincibleUp.ShowBitmap();
				}
				else if (faceTo == CDirection::DOWN)
				{
					invincibleDown.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (invincibleDown.Width() / 2), int(y) + BRICK_WIDTH - invincibleDown.Height());
					invincibleDown.ShowBitmap();
				}

			}
			else if (isHit || isFood || isSwallowed)
			{
				if (isHit)
				{
					hitLeftAnimation.Reset();
					hitDownAnimation.Reset();
					hitRightAnimation.Reset();
					hitUpAnimation.Reset();
				}
				if (faceTo == CDirection::LEFT)
				{
					hitLeftAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (hitLeftAnimation.Width() / 2), int(y) + BRICK_WIDTH - hitLeftAnimation.Height());
					hitLeftAnimation.OnShow();
				}
				else if (faceTo == CDirection::RIGHT)
				{
					hitRightAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (hitRightAnimation.Width() / 2), int(y) + BRICK_WIDTH - hitRightAnimation.Height());
					hitRightAnimation.OnShow();
				}
				else if (faceTo == CDirection::UP)
				{
					hitUpAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (hitUpAnimation.Width() / 2), int(y) + BRICK_WIDTH - hitUpAnimation.Height());
					hitUpAnimation.OnShow();
				}
				else if (faceTo == CDirection::DOWN)
				{
					hitDownAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (hitDownAnimation.Width() / 2), int(y) + BRICK_WIDTH - hitDownAnimation.Height());
					hitDownAnimation.OnShow();
				}
			}
			else if (isRush)
			{
				if (faceTo == CDirection::LEFT)
				{
					if (!isMovingLeft)
					{
						rushLeftAnimation.Reset();
					}
					rushLeftAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (rushLeftAnimation.Width() / 2), int(y) + BRICK_WIDTH - rushLeftAnimation.Height());
					rushLeftAnimation.OnShow();
				}
				else if (faceTo == CDirection::RIGHT)
				{
					if (!isMovingRight)
					{
						rushRightAnimation.Reset();
					}
					rushRightAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (rushRightAnimation.Width() / 2), int(y) + BRICK_WIDTH - rushRightAnimation.Height());
					rushRightAnimation.OnShow();
				}
				else if (faceTo == CDirection::UP)
				{
					if (!isMovingUp)
					{
						rushUpAnimation.Reset();
					}
					rushUpAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (rushUpAnimation.Width() / 2), int(y) + BRICK_WIDTH - rushUpAnimation.Height());
					rushUpAnimation.OnShow();
				}
				else if (faceTo == CDirection::DOWN)
				{
					if (!isMovingDown)
					{
						rushDownAnimation.Reset();
					}
					rushDownAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (rushDownAnimation.Width() / 2), int(y) + BRICK_WIDTH - rushDownAnimation.Height());
					rushDownAnimation.OnShow();
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
					leftAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (leftAnimation.Width() / 2), int(y) + BRICK_WIDTH - leftAnimation.Height());
					leftAnimation.OnShow();
				}
				else if (faceTo == CDirection::RIGHT)
				{
					if (!isMovingRight)
					{
						rightAnimation.Reset();
					}
					rightAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (rightAnimation.Width() / 2), int(y) + BRICK_WIDTH - rightAnimation.Height());
					rightAnimation.OnShow();
				}
				else if (faceTo == CDirection::UP)
				{
					if (!isMovingUp)
					{
						upAnimation.Reset();
					}
					upAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (upAnimation.Width() / 2), int(y) + BRICK_WIDTH - upAnimation.Height());
					upAnimation.OnShow();
				}
				else if (faceTo == CDirection::DOWN)
				{
					if (!isMovingDown)
					{
						downAnimation.Reset();
					}
					downAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (downAnimation.Width() / 2), int(y) + BRICK_WIDTH - downAnimation.Height());
					downAnimation.OnShow();
				}
			}
		}
	}

	void CMonster::HitByBrick(CDirection tempDir)
	{
		if (!isHit && !isFood)
		{
			hitCount = 0;
			faceTo = tempDir;
			isHit = true;
		}
		else if (isFood)
		{
			foodTime = 0;
			faceTo = tempDir;
		}
	}

	void CMonster::Swallowed(CDirection faceTo)
	{
		isAlive = false;
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

	void CMonster::Reset()
	{
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		isHit = isFood = isSwallowed = isInvincible = false;
		isAlive = true;
		movingLeftCount = movingRightCount = movingUpCount = movingDownCount = foodTime = invincibleTime = 0;
		faceTo = GetNewMovingDirection();
	}

	void CMonster::SetInvincible()
	{
		if (type == CName::TURTLE)
		{
			srand((unsigned int)time(NULL));
			int x = rand();
			int flag = x % 5;

			switch (flag)
			{
			case 0:
				isInvincible = true;
				mapRecord->SetMonsterInMap(indexX, indexY, CName::INVINCIBLE_TURTLE);
				break;
			default:
				isInvincible = false;
			}
		}
		else
		{
			isInvincible = false;
		}
	}

	void CMonster::MudAndTurtleMove() {
		const int FOOD_TIME_LIMIT = 30 * 3;
		const int INVINCIBLE_TIME_LIMIT = 30 * 2;
		const int STEP_TARGET = 24;
		const double STEP_SIZE_X = 1.5;
		const double STEP_SIZE_Y = 1;
		const int HIT_TARGET = 6;
		const double HIT_STEP_SIZE_X = 6;
		const double HIT_STEP_SIZE_Y = 4;
		const int SWALLOWED_STEP_TARGET = 6;
		const double SWALLOWED_STEP_SIZE_X = 6;
		const double SWALLOWED_STEP_SIZE_Y = 4;

		if (!isMovingLeft && !isMovingRight && !isMovingDown && !isMovingUp && !isHit && !isFood && !isSwallowed && isAlive && !isInvincible)
		{
			faceTo = GetNewMovingDirection();
			if (type == CName::TURTLE)
			{
				SetInvincible();
			}
			movingLeftCount = movingRightCount = movingUpCount = movingDownCount = 0;
			if (!isInvincible)
			{
				if (faceTo == CDirection::LEFT)
					isMovingLeft = true;
				else if (faceTo == CDirection::RIGHT)
					isMovingRight = true;
				else if (faceTo == CDirection::UP)
					isMovingUp = true;
				else if (faceTo == CDirection::DOWN)
					isMovingDown = true;
			}
		}

		if (isSwallowed)
		{
			if (isMovingLeft)
			{
				x -= SWALLOWED_STEP_SIZE_X;
				movingLeftCount++;
				if (movingLeftCount == SWALLOWED_STEP_TARGET)
				{
					mapRecord->SetMonsterInMap(indexX, indexY, CName::SPACE);
					movingLeftCount = 0;
					isMovingLeft = isSwallowed = false;
				}
			}
			else if (isMovingRight)
			{
				x += SWALLOWED_STEP_SIZE_X;
				movingRightCount++;
				if (movingRightCount == SWALLOWED_STEP_TARGET)
				{
					mapRecord->SetMonsterInMap(indexX, indexY, CName::SPACE);
					movingRightCount = 0;
					isMovingRight = isSwallowed = false;
				}
			}
			else if (isMovingUp)
			{
				y -= SWALLOWED_STEP_SIZE_Y;
				movingUpCount++;
				if (movingUpCount == SWALLOWED_STEP_TARGET)
				{
					mapRecord->SetMonsterInMap(indexX, indexY, CName::SPACE);
					movingUpCount = 0;
					isMovingUp = isSwallowed = false;
				}
			}
			else if (isMovingDown)
			{
				y += SWALLOWED_STEP_SIZE_Y;
				movingDownCount++;
				if (movingDownCount == SWALLOWED_STEP_TARGET)
				{
					mapRecord->SetMonsterInMap(indexX, indexY, CName::SPACE);
					movingDownCount = 0;
					isMovingDown = isSwallowed = false;
				}
			}
		}
		else if (isFood)
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
				mapRecord->SetMonsterInMap(indexX, indexY, type);
			}
		}
		else if (isHit)
		{
			if (isMovingLeft && movingLeftCount != 0)
			{
				hitLeftAnimation.OnMove();
				x -= STEP_SIZE_X;
				movingLeftCount++;
				mapRecord->SetMonsterInMap(indexX - 1, indexY, type);
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
				mapRecord->SetMonsterInMap(indexX + 1, indexY, type);
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
				mapRecord->SetMonsterInMap(indexX, indexY - 1, type);
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
				mapRecord->SetMonsterInMap(indexX, indexY + 1, type);
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
					hitCount++;
					if (hitCount == HIT_TARGET)
					{
						mapRecord->SetMonsterInMap(indexX, indexY, CName::MONSTER_FOOD);
						isFood = true;
						isHit = false;
						hitCount = 0;
					}
				}
				else if (faceTo == CDirection::RIGHT)
				{
					hitRightAnimation.OnMove();
					hitCount++;
					if (hitCount == HIT_TARGET)
					{
						mapRecord->SetMonsterInMap(indexX, indexY, CName::MONSTER_FOOD);
						isFood = true;
						isHit = false;
						hitCount = 0;
					}
				}
				else if (faceTo == CDirection::UP)
				{
					hitUpAnimation.OnMove();
					hitCount++;
					if (hitCount == HIT_TARGET)
					{
						mapRecord->SetMonsterInMap(indexX, indexY, CName::MONSTER_FOOD);
						isFood = true;
						isHit = false;
						hitCount = 0;
					}
				}
				else if (faceTo == CDirection::DOWN)
				{
					hitDownAnimation.OnMove();
					hitCount++;
					if (hitCount == HIT_TARGET)
					{
						mapRecord->SetMonsterInMap(indexX, indexY, CName::MONSTER_FOOD);
						isFood = true;
						isHit = false;
						hitCount = 0;
					}
				}
			}
		}
		else if (isInvincible)
		{
			invincibleTime++;
			if (invincibleTime == INVINCIBLE_TIME_LIMIT)
			{
				isInvincible = false;
				mapRecord->SetMonsterInMap(indexX, indexY, type);
				invincibleTime = 0;
			}
		}
		else if (!isHit && !isFood && !isInvincible)
		{
			if (isMovingLeft)
			{
				if ((mapRecord->GetBrickInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetFoodInMap(indexX - 1, indexY) == CName::SPACE) || movingLeftCount != 0)
				{
					leftAnimation.OnMove();
					x -= STEP_SIZE_X;
					movingLeftCount++;
					mapRecord->SetMonsterInMap(indexX - 1, indexY, type);
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
					mapRecord->SetMonsterInMap(indexX + 1, indexY, type);
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
					mapRecord->SetMonsterInMap(indexX, indexY - 1, type);
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
					mapRecord->SetMonsterInMap(indexX, indexY + 1, type);
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

	void CMonster::SkeletonMove() {
		const int FOOD_TIME_LIMIT = 30 * 3;
		const int INVINCIBLE_TIME_LIMIT = 30 * 2;
		const int STEP_TARGET = 24;
		const double STEP_SIZE_X = 1.5;
		const double STEP_SIZE_Y = 1;
		const int RUSH_STEP_TARGET = 8;
		const double RUSH_STEP_SIZE_X = 4.5;
		const double RUSH_STEP_SIZE_Y = 3;
		const int HIT_TARGET = 6;
		const double HIT_STEP_SIZE_X = 6;
		const double HIT_STEP_SIZE_Y = 4;
		const int SWALLOWED_STEP_TARGET = 6;
		const double SWALLOWED_STEP_SIZE_X = 6;
		const double SWALLOWED_STEP_SIZE_Y = 4;

		if (!isMovingLeft && !isMovingRight && !isMovingDown && !isMovingUp && !isHit && !isFood && !isSwallowed && isAlive && !isInvincible)
		{
			faceTo = GetNewMovingDirection();
			isRush = false;
			
			movingLeftCount = movingRightCount = movingUpCount = movingDownCount = 0;
			if (!isInvincible)
			{
				if (faceTo == CDirection::LEFT)
					isMovingLeft = true;
				else if (faceTo == CDirection::RIGHT)
					isMovingRight = true;
				else if (faceTo == CDirection::UP)
					isMovingUp = true;
				else if (faceTo == CDirection::DOWN)
					isMovingDown = true;
			}
		}

		if (isSwallowed)
		{
			if (isMovingLeft)
			{
				x -= SWALLOWED_STEP_SIZE_X;
				movingLeftCount++;
				if (movingLeftCount == SWALLOWED_STEP_TARGET)
				{
					mapRecord->SetMonsterInMap(indexX, indexY, CName::SPACE);
					movingLeftCount = 0;
					isMovingLeft = isSwallowed = false;
				}
			}
			else if (isMovingRight)
			{
				x += SWALLOWED_STEP_SIZE_X;
				movingRightCount++;
				if (movingRightCount == SWALLOWED_STEP_TARGET)
				{
					mapRecord->SetMonsterInMap(indexX, indexY, CName::SPACE);
					movingRightCount = 0;
					isMovingRight = isSwallowed = false;
				}
			}
			else if (isMovingUp)
			{
				y -= SWALLOWED_STEP_SIZE_Y;
				movingUpCount++;
				if (movingUpCount == SWALLOWED_STEP_TARGET)
				{
					mapRecord->SetMonsterInMap(indexX, indexY, CName::SPACE);
					movingUpCount = 0;
					isMovingUp = isSwallowed = false;
				}
			}
			else if (isMovingDown)
			{
				y += SWALLOWED_STEP_SIZE_Y;
				movingDownCount++;
				if (movingDownCount == SWALLOWED_STEP_TARGET)
				{
					mapRecord->SetMonsterInMap(indexX, indexY, CName::SPACE);
					movingDownCount = 0;
					isMovingDown = isSwallowed = false;
				}
			}
		}
		else if (isFood)
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
				mapRecord->SetMonsterInMap(indexX, indexY, type);
			}
		}
		else if (isHit)
		{
			if (isMovingLeft && movingLeftCount != 0)
			{
				hitLeftAnimation.OnMove();
				x -= STEP_SIZE_X;
				movingLeftCount++;
				mapRecord->SetMonsterInMap(indexX - 1, indexY, type);
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
				mapRecord->SetMonsterInMap(indexX + 1, indexY, type);
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
				mapRecord->SetMonsterInMap(indexX, indexY - 1, type);
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
				mapRecord->SetMonsterInMap(indexX, indexY + 1, type);
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
					hitCount++;
					if (hitCount == HIT_TARGET)
					{
						mapRecord->SetMonsterInMap(indexX, indexY, CName::MONSTER_FOOD);
						isFood = true;
						isHit = false;
						hitCount = 0;
					}
				}
				else if (faceTo == CDirection::RIGHT)
				{
					hitRightAnimation.OnMove();
					hitCount++;
					if (hitCount == HIT_TARGET)
					{
						mapRecord->SetMonsterInMap(indexX, indexY, CName::MONSTER_FOOD);
						isFood = true;
						isHit = false;
						hitCount = 0;
					}
				}
				else if (faceTo == CDirection::UP)
				{
					hitUpAnimation.OnMove();
					hitCount++;
					if (hitCount == HIT_TARGET)
					{
						mapRecord->SetMonsterInMap(indexX, indexY, CName::MONSTER_FOOD);
						isFood = true;
						isHit = false;
						hitCount = 0;
					}
				}
				else if (faceTo == CDirection::DOWN)
				{
					hitDownAnimation.OnMove();
					hitCount++;
					if (hitCount == HIT_TARGET)
					{
						mapRecord->SetMonsterInMap(indexX, indexY, CName::MONSTER_FOOD);
						isFood = true;
						isHit = false;
						hitCount = 0;
					}
				}
			}
		}
		else if (!isHit && !isFood && !isInvincible)
		{
			if (isRush) {
				if (isMovingLeft)
				{
					if ((mapRecord->GetBrickInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetFoodInMap(indexX - 1, indexY) == CName::SPACE) || movingLeftCount != 0)
					{
						rushLeftAnimation.OnMove();
						x -= RUSH_STEP_SIZE_X;
						movingLeftCount++;
						mapRecord->SetMonsterInMap(indexX - 1, indexY, type);
						if (movingLeftCount == RUSH_STEP_TARGET)
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
						rushRightAnimation.OnMove();
						x += RUSH_STEP_SIZE_X;
						movingRightCount++;
						mapRecord->SetMonsterInMap(indexX + 1, indexY, type);
						if (movingRightCount == RUSH_STEP_TARGET)
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
						rushUpAnimation.OnMove();
						y -= RUSH_STEP_SIZE_Y;
						movingUpCount++;
						mapRecord->SetMonsterInMap(indexX, indexY - 1, type);
						if (movingUpCount == RUSH_STEP_TARGET)
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
						rushDownAnimation.OnMove();
						y += RUSH_STEP_SIZE_Y;
						movingDownCount++;
						mapRecord->SetMonsterInMap(indexX, indexY + 1, type);
						if (movingDownCount == RUSH_STEP_TARGET)
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
			else {
				if (isMovingLeft)
				{
					if ((mapRecord->GetBrickInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetFoodInMap(indexX - 1, indexY) == CName::SPACE) || movingLeftCount != 0)
					{
						leftAnimation.OnMove();
						x -= STEP_SIZE_X;
						movingLeftCount++;
						mapRecord->SetMonsterInMap(indexX - 1, indexY, type);
						if (movingLeftCount == STEP_TARGET)
						{
							mapRecord->SetMonsterInMap(indexX--, indexY, CName::SPACE);
							movingLeftCount = 0;
							ChangeRushStatus();
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
						mapRecord->SetMonsterInMap(indexX + 1, indexY, type);
						if (movingRightCount == STEP_TARGET)
						{
							mapRecord->SetMonsterInMap(indexX++, indexY, CName::SPACE);
							movingRightCount = 0;
							ChangeRushStatus();
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
						mapRecord->SetMonsterInMap(indexX, indexY - 1, type);
						if (movingUpCount == STEP_TARGET)
						{
							mapRecord->SetMonsterInMap(indexX, indexY--, CName::SPACE);
							movingUpCount = 0;
							ChangeRushStatus();
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
						mapRecord->SetMonsterInMap(indexX, indexY + 1, type);
						if (movingDownCount == STEP_TARGET)
						{
							mapRecord->SetMonsterInMap(indexX, indexY++, CName::SPACE);
							movingDownCount = 0;
							ChangeRushStatus();
						}
					}
					else
					{
						isMovingDown = false;
					}
				}
			}
		}
	}

	void CMonster::ChangeRushStatus()
	{
		if (!isRush) {
			rushDownAnimation.Reset();
			rushLeftAnimation.Reset();
			rushRightAnimation.Reset();
			rushUpAnimation.Reset();
		}
		if (mapRecord->GetPlayerIndexX() == GetIndexX())
		{
			if (faceTo == CDirection::UP)
			{
				isRush = mapRecord->GetPlayerIndexY() < GetIndexY();
			}
			if (faceTo == CDirection::DOWN)
			{
				isRush = mapRecord->GetPlayerIndexY() > GetIndexY();
			}
		}
		else if(mapRecord->GetPlayerIndexY() == GetIndexY())
		{
			if (faceTo == CDirection::RIGHT)
			{
				isRush = mapRecord->GetPlayerIndexX() > GetIndexX();
			}
			if (faceTo == CDirection::LEFT)
			{
				isRush = mapRecord->GetPlayerIndexX() < GetIndexX();
			}
		}
	}
}