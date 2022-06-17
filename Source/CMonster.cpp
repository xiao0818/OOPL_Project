#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CMonster.h"
#include "CAudioId.h"
#include "CPlayer.h"

namespace game_framework {
	CMonster::CMonster()
	{
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		isHit = isFood = isSwallowed = isInvincible = isRush = isFly = false;
		isAlive = true;
		movingLeftCount = movingRightCount = movingUpCount = movingDownCount = foodTime = invincibleTime = 0;
		faceTo = GetNewMovingDirection();
		leftAnimation.SetDelayCount(2);
		rightAnimation.SetDelayCount(2);
		upAnimation.SetDelayCount(2);
		downAnimation.SetDelayCount(2);
		hitLeftAnimation.SetDelayCount(2);
		hitRightAnimation.SetDelayCount(2);
		hitUpAnimation.SetDelayCount(2);
		hitDownAnimation.SetDelayCount(2);
		rushDownAnimation.SetDelayCount(2);
		rushLeftAnimation.SetDelayCount(2);
		rushRightAnimation.SetDelayCount(2);
		rushUpAnimation.SetDelayCount(2);
		srand((unsigned int)time(NULL));
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

	CName CMonster::GetTypeFlag()
	{
		return type;
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

	bool CMonster::IsFly()
	{
		return isFly;
	}

	void CMonster::Initialize(CMap *map, CShareData *shareData, CPlayer *player1, CPlayer *player2)
	{
		mapRecord = map;
		shareDataRecord = shareData;
		player1Record = player1;
		player2Record = player2;
	}

	void CMonster::LoadBitmap()
	{
	}

	void CMonster::OnMove()
	{
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

		if (!isMovingLeft && !isMovingRight && !isMovingDown && !isMovingUp && !isHit && !isFood && !isSwallowed && isAlive && !isInvincible && !isRush)
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
					indexX = indexY = 0;
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
					indexX = indexY = 0;
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
					indexX = indexY = 0;
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
					indexX = indexY = 0;
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
			if (isRush)
			{
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
						isRush = false;
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
						isRush = false;
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
						isRush = false;
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
						isRush = false;
					}
				}
			}
			else if (isFly)
			{
				if (isMovingLeft)
				{
					if ((type == CName::FISH_MAN && mapRecord->GetSidewallInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX - 1, indexY) == CName::SPACE) || (type != CName::FISH_MAN && mapRecord->GetBrickInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetFoodInMap(indexX - 1, indexY) == CName::SPACE) || movingLeftCount != 0)
					{
						flyLeftAnimation.OnMove();
						x -= STEP_SIZE_X;
						movingLeftCount++;
						mapRecord->SetMonsterInMap(indexX - 1, indexY, type);
						ChangeFlyStatus();
						if (movingLeftCount == STEP_TARGET)
						{
							mapRecord->SetMonsterInMap(indexX--, indexY, CName::SPACE);
							movingLeftCount = 0;
							if (type == CName::FISH_MAN)
							{
								isMovingLeft = false;
							}
						}
					}
					else
					{
						isMovingLeft = false;
					}
				}
				else if (isMovingRight)
				{
					if ((type == CName::FISH_MAN && mapRecord->GetSidewallInMap(indexX + 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX + 1, indexY) == CName::SPACE) || (type != CName::FISH_MAN && mapRecord->GetBrickInMap(indexX + 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX + 1, indexY) == CName::SPACE && mapRecord->GetFoodInMap(indexX + 1, indexY) == CName::SPACE) || movingRightCount != 0)
					{
						flyRightAnimation.OnMove();
						x += STEP_SIZE_X;
						movingRightCount++;
						mapRecord->SetMonsterInMap(indexX + 1, indexY, type);
						ChangeFlyStatus();
						if (movingRightCount == STEP_TARGET)
						{
							mapRecord->SetMonsterInMap(indexX++, indexY, CName::SPACE);
							movingRightCount = 0;
							if (type == CName::FISH_MAN)
							{
								isMovingRight = false;
							}
						}
					}
					else
					{
						isMovingRight = false;
					}
				}
				else if (isMovingUp)
				{
					if ((type == CName::FISH_MAN && mapRecord->GetSidewallInMap(indexX, indexY - 1) == CName::SPACE && mapRecord->GetMonsterInMap(indexX, indexY - 1) == CName::SPACE) || (type != CName::FISH_MAN && mapRecord->GetBrickInMap(indexX, indexY - 1) == CName::SPACE && mapRecord->GetMonsterInMap(indexX, indexY - 1) == CName::SPACE && mapRecord->GetFoodInMap(indexX, indexY - 1) == CName::SPACE) || movingUpCount != 0)
					{
						flyUpAnimation.OnMove();
						y -= STEP_SIZE_Y;
						movingUpCount++;
						mapRecord->SetMonsterInMap(indexX, indexY - 1, type);
						ChangeFlyStatus();
						if (movingUpCount == STEP_TARGET)
						{
							mapRecord->SetMonsterInMap(indexX, indexY--, CName::SPACE);
							movingUpCount = 0;
							if (type == CName::FISH_MAN)
							{
								isMovingUp = false;
							}
						}
					}
					else
					{
						isMovingUp = false;
					}
				}
				else if (isMovingDown)
				{
					if ((type == CName::FISH_MAN && mapRecord->GetSidewallInMap(indexX, indexY + 1) == CName::SPACE && mapRecord->GetMonsterInMap(indexX, indexY + 1) == CName::SPACE) || (type != CName::FISH_MAN && mapRecord->GetBrickInMap(indexX, indexY + 1) == CName::SPACE && mapRecord->GetMonsterInMap(indexX, indexY + 1) == CName::SPACE && mapRecord->GetFoodInMap(indexX, indexY + 1) == CName::SPACE) || movingDownCount != 0)
					{
						flyDownAnimation.OnMove();
						y += STEP_SIZE_Y;
						movingDownCount++;
						mapRecord->SetMonsterInMap(indexX, indexY + 1, type);
						ChangeFlyStatus();
						if (movingDownCount == STEP_TARGET)
						{
							mapRecord->SetMonsterInMap(indexX, indexY++, CName::SPACE);
							movingDownCount = 0;
							if (type == CName::FISH_MAN)
							{
								isMovingDown = false;
							}
						}
					}
					else
					{
						isMovingDown = false;
					}
				}
			}
			else
			{
				if (isMovingLeft)
				{		
					if ((type == CName::FISH_MAN && mapRecord->GetSidewallInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX - 1, indexY) == CName::SPACE) || (type != CName::FISH_MAN && mapRecord->GetBrickInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetFoodInMap(indexX - 1, indexY) == CName::SPACE) || movingLeftCount != 0)
					{
						leftAnimation.OnMove();
						x -= STEP_SIZE_X;
						movingLeftCount++;
						mapRecord->SetMonsterInMap(indexX - 1, indexY, type);
						ChangeFlyStatus();
						if (movingLeftCount == STEP_TARGET)
						{
							mapRecord->SetMonsterInMap(indexX--, indexY, CName::SPACE);
							movingLeftCount = 0;
							ChangeRushStatus();
							if (type == CName::FISH_MAN)
							{
								isMovingLeft = false;
							}
						}
					}
					else
					{
						SetInvincible();
						isMovingLeft = false;
					}
				}
				else if (isMovingRight)
				{
					if ((type == CName::FISH_MAN && mapRecord->GetSidewallInMap(indexX + 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX + 1, indexY) == CName::SPACE) || (type != CName::FISH_MAN && mapRecord->GetBrickInMap(indexX + 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX + 1, indexY) == CName::SPACE && mapRecord->GetFoodInMap(indexX + 1, indexY) == CName::SPACE) || movingRightCount != 0)
					{
						rightAnimation.OnMove();
						x += STEP_SIZE_X;
						movingRightCount++;
						mapRecord->SetMonsterInMap(indexX + 1, indexY, type);
						ChangeFlyStatus();
						if (movingRightCount == STEP_TARGET)
						{
							mapRecord->SetMonsterInMap(indexX++, indexY, CName::SPACE);
							movingRightCount = 0;
							ChangeRushStatus();
							if (type == CName::FISH_MAN)
							{
								isMovingRight = false;
							}
						}
					}
					else
					{
						SetInvincible();
						isMovingRight = false;
					}
				}
				else if (isMovingUp)
				{
					if ((type == CName::FISH_MAN && mapRecord->GetSidewallInMap(indexX, indexY - 1) == CName::SPACE && mapRecord->GetMonsterInMap(indexX, indexY - 1) == CName::SPACE) || (type != CName::FISH_MAN && mapRecord->GetBrickInMap(indexX, indexY - 1) == CName::SPACE && mapRecord->GetMonsterInMap(indexX, indexY - 1) == CName::SPACE && mapRecord->GetFoodInMap(indexX, indexY - 1) == CName::SPACE) || movingUpCount != 0)
					{
						upAnimation.OnMove();
						y -= STEP_SIZE_Y;
						movingUpCount++;
						mapRecord->SetMonsterInMap(indexX, indexY - 1, type);
						ChangeFlyStatus();
						if (movingUpCount == STEP_TARGET)
						{
							mapRecord->SetMonsterInMap(indexX, indexY--, CName::SPACE);
							movingUpCount = 0;
							ChangeRushStatus();
							if (type == CName::FISH_MAN)
							{
								isMovingUp = false;
							}
						}
					}
					else
					{
						SetInvincible();
						isMovingUp = false;
					}
				}
				else if (isMovingDown)
				{
					if ((type == CName::FISH_MAN && mapRecord->GetSidewallInMap(indexX, indexY + 1) == CName::SPACE && mapRecord->GetMonsterInMap(indexX, indexY + 1) == CName::SPACE) || (type != CName::FISH_MAN && mapRecord->GetBrickInMap(indexX, indexY + 1) == CName::SPACE && mapRecord->GetMonsterInMap(indexX, indexY + 1) == CName::SPACE && mapRecord->GetFoodInMap(indexX, indexY + 1) == CName::SPACE) || movingDownCount != 0)
					{
						downAnimation.OnMove();
						y += STEP_SIZE_Y;
						movingDownCount++;
						mapRecord->SetMonsterInMap(indexX, indexY + 1, type);
						ChangeFlyStatus();
						if (movingDownCount == STEP_TARGET)
						{
							mapRecord->SetMonsterInMap(indexX, indexY++, CName::SPACE);
							movingDownCount = 0;
							ChangeRushStatus();
							if (type == CName::FISH_MAN)
							{
								isMovingDown = false;
							}
						}
					}
					else
					{
						SetInvincible();
						isMovingDown = false;
					}
				}
			}
		}
	}
	
	void CMonster::SetTypeFlag(CName name)
	{
		type = name;
	}

	CDirection CMonster::RandomDirection()
	{
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

	CDirection CMonster::GetNewMovingDirection()
	{
		CDirection nextDirection = RandomDirection();
		if (type == CName::FISH_MAN)
		{
			if (!player1Record->IsFail()) 
			{
				if (player1Record->GetIndexX() != GetIndexX() || player1Record->GetIndexY() != GetIndexY())
				{
					if (player1Record->GetIndexX() == GetIndexX())
					{
						while (!(nextDirection == CDirection::UP || nextDirection == CDirection::DOWN))
						{
							nextDirection = RandomDirection();
						}
					}

					else if (player1Record->GetIndexY() == GetIndexY())
					{
						while (!(nextDirection == CDirection::LEFT || nextDirection == CDirection::RIGHT))
						{
							nextDirection = RandomDirection();
						}
					}

					if (nextDirection == CDirection::LEFT || nextDirection == CDirection::RIGHT)
					{
						if (player1Record->GetIndexX() < GetIndexX())
						{
							nextDirection = CDirection::LEFT;
						}
						else if (player1Record->GetIndexX() > GetIndexX())
						{
							nextDirection = CDirection::RIGHT;
						}
					}

					if (nextDirection == CDirection::UP || nextDirection == CDirection::DOWN)
					{
						if (player1Record->GetIndexY() < GetIndexY())
						{
							nextDirection = CDirection::UP;
						}
						else if (player1Record->GetIndexY() > GetIndexY())
						{
							nextDirection = CDirection::DOWN;
						}
					}
				}
			}
			else if (!player2Record->IsFail())
			{
				if (player2Record->GetIndexX() != GetIndexX() || player2Record->GetIndexY() != GetIndexY())
				{
					if (player2Record->GetIndexX() == GetIndexX())
					{
						while (!(nextDirection == CDirection::UP || nextDirection == CDirection::DOWN))
						{
							nextDirection = RandomDirection();
						}
					}

					else if (player2Record->GetIndexY() == GetIndexY())
					{
						while (!(nextDirection == CDirection::LEFT || nextDirection == CDirection::RIGHT))
						{
							nextDirection = RandomDirection();
						}
					}

					if (nextDirection == CDirection::LEFT || nextDirection == CDirection::RIGHT)
					{
						if (player2Record->GetIndexX() < GetIndexX())
						{
							nextDirection = CDirection::LEFT;
						}
						else if (player2Record->GetIndexX() > GetIndexX())
						{
							nextDirection = CDirection::RIGHT;
						}
					}

					if (nextDirection == CDirection::UP || nextDirection == CDirection::DOWN)
					{
						if (player2Record->GetIndexY() < GetIndexY())
						{
							nextDirection = CDirection::UP;
						}
						else if (player2Record->GetIndexY() > GetIndexY())
						{
							nextDirection = CDirection::DOWN;
						}
					}
				}
			}
		}
		return nextDirection;
	}

	void CMonster::HitByBrick(CDirection tempDir)
	{
		if (!isHit && !isFood)
		{
			hitCount = 0;
			faceTo = tempDir;
			isHit = true;
			isFly = false;
		}
		else if (isFood)
		{
			foodTime = 0;
			faceTo = tempDir;
		}
		if (shareDataRecord->IsSoundEnable())
		{
			CAudio::Instance()->Play(SOUND_MONSTER_HIT, false);
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

	void CMonster::SetAlive(bool flag)
	{
		isAlive = flag;
	}

	void CMonster::SetInvincible()
	{
		if (type == CName::TURTLE)
		{
			isInvincible = true;
			mapRecord->SetMonsterInMap(indexX, indexY, CName::INVINCIBLE_TURTLE);
		}
		else
		{
			isInvincible = false;
		}
	}

	void CMonster::ChangeRushStatus()
	{
		if (type == CName::SKELETON)
		{
			if (!isRush)
			{
				rushDownAnimation.Reset();
				rushLeftAnimation.Reset();
				rushRightAnimation.Reset();
				rushUpAnimation.Reset();
			}
			if (player1Record->GetIndexX() == GetIndexX())
			{
				if (faceTo == CDirection::UP)
				{
					isRush = player1Record->GetIndexY() < GetIndexY();
				}
				if (faceTo == CDirection::DOWN)
				{
					isRush = player1Record->GetIndexY() > GetIndexY();
				}
			}
			else if (player2Record->GetIndexX() == GetIndexX())
			{
				if (faceTo == CDirection::UP)
				{
					isRush = player2Record->GetIndexY() < GetIndexY();
				}
				if (faceTo == CDirection::DOWN)
				{
					isRush = player2Record->GetIndexY() > GetIndexY();
				}
			}
			else if (player1Record->GetIndexY() == GetIndexY())
			{
				if (faceTo == CDirection::RIGHT)
				{
					isRush = player1Record->GetIndexX() > GetIndexX();
				}
				if (faceTo == CDirection::LEFT)
				{
					isRush = player1Record->GetIndexX() < GetIndexX();
				}
			}
			else if (player2Record->GetIndexY() == GetIndexY()) 
			{
				if (faceTo == CDirection::RIGHT)
				{
					isRush = player2Record->GetIndexX() > GetIndexX();
				}
				if (faceTo == CDirection::LEFT)
				{
					isRush = player2Record->GetIndexX() < GetIndexX();
				}
			}
		}
	}

	void CMonster::ChangeFlyStatus()
	{
		if (type == CName::FISH_MAN)
		{
			if (faceTo == CDirection::DOWN)
			{
				isFly = mapRecord->GetBrickInMap(GetIndexX(), GetIndexY() + 1) != CName::SPACE || mapRecord->GetFoodInMap(GetIndexX(), GetIndexY() + 1) != CName::SPACE || mapRecord->GetBrickInMap(GetIndexX(), GetIndexY()) != CName::SPACE || mapRecord->GetFoodInMap(GetIndexX(), GetIndexY()) != CName::SPACE;
			}
			else if (faceTo == CDirection::UP)
			{
				isFly = mapRecord->GetBrickInMap(GetIndexX(), GetIndexY() - 1) != CName::SPACE || mapRecord->GetFoodInMap(GetIndexX(), GetIndexY() - 1) != CName::SPACE || mapRecord->GetBrickInMap(GetIndexX(), GetIndexY()) != CName::SPACE || mapRecord->GetFoodInMap(GetIndexX(), GetIndexY()) != CName::SPACE;
			}
			else if (faceTo == CDirection::RIGHT)
			{
				isFly = mapRecord->GetBrickInMap(GetIndexX() + 1, GetIndexY()) != CName::SPACE || mapRecord->GetFoodInMap(GetIndexX() + 1, GetIndexY()) != CName::SPACE || mapRecord->GetBrickInMap(GetIndexX(), GetIndexY()) != CName::SPACE || mapRecord->GetFoodInMap(GetIndexX(), GetIndexY()) != CName::SPACE;
			}
			else if (faceTo == CDirection::LEFT)
			{
				isFly = mapRecord->GetBrickInMap(GetIndexX() - 1, GetIndexY()) != CName::SPACE || mapRecord->GetFoodInMap(GetIndexX() - 1, GetIndexY()) != CName::SPACE || mapRecord->GetBrickInMap(GetIndexX(), GetIndexY()) != CName::SPACE || mapRecord->GetFoodInMap(GetIndexX(), GetIndexY()) != CName::SPACE;
			}
			else {
				isFly = false;
			}
		}
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
		const int FLY_HEIGHT = 24;
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
			else if (isFly)
			{
				if (faceTo == CDirection::LEFT)
				{
					if (!isMovingLeft)
					{
						flyLeftAnimation.Reset();
					}
					flyLeftAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (flyLeftAnimation.Width() / 2), int(y) + BRICK_WIDTH - flyLeftAnimation.Height() - FLY_HEIGHT);
					flyLeftAnimation.OnShow();
				}
				else if (faceTo == CDirection::RIGHT)
				{
					if (!isMovingRight)
					{
						flyRightAnimation.Reset();
					}
					flyRightAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (flyRightAnimation.Width() / 2), int(y) + BRICK_WIDTH - flyRightAnimation.Height() - FLY_HEIGHT);
					flyRightAnimation.OnShow();
				}
				else if (faceTo == CDirection::UP)
				{
					if (!isMovingUp)
					{
						flyUpAnimation.Reset();
					}
					flyUpAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (flyUpAnimation.Width() / 2), int(y) + BRICK_WIDTH - flyUpAnimation.Height() - FLY_HEIGHT);
					flyUpAnimation.OnShow();
				}
				else if (faceTo == CDirection::DOWN)
				{
					if (!isMovingDown)
					{
						flyDownAnimation.Reset();
					}
					flyDownAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (flyDownAnimation.Width() / 2), int(y) + BRICK_WIDTH - flyDownAnimation.Height() - FLY_HEIGHT);
					flyDownAnimation.OnShow();
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


}