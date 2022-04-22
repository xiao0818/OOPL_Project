#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CTurtle.h"
#include <stdlib.h>
#include <time.h>

namespace game_framework {

	void CTurtle::LoadBitmap() {
		leftAnimation.AddBitmap(IDB_TURTLE_MOVE_LEFT_001, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_TURTLE_MOVE_LEFT_002, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_TURTLE_MOVE_LEFT_003, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_TURTLE_MOVE_LEFT_004, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_TURTLE_MOVE_LEFT_005, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_TURTLE_MOVE_LEFT_006, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_TURTLE_MOVE_LEFT_007, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_TURTLE_MOVE_LEFT_008, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_TURTLE_MOVE_UP_001, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_TURTLE_MOVE_UP_002, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_TURTLE_MOVE_UP_003, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_TURTLE_MOVE_UP_004, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_TURTLE_MOVE_UP_005, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_TURTLE_MOVE_UP_006, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_TURTLE_MOVE_UP_007, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_TURTLE_MOVE_UP_008, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_TURTLE_MOVE_DOWN_001, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_TURTLE_MOVE_DOWN_002, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_TURTLE_MOVE_DOWN_003, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_TURTLE_MOVE_DOWN_004, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_TURTLE_MOVE_DOWN_005, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_TURTLE_MOVE_DOWN_006, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_TURTLE_MOVE_DOWN_007, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_TURTLE_MOVE_DOWN_008, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_TURTLE_MOVE_RIGHT_001, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_TURTLE_MOVE_RIGHT_002, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_TURTLE_MOVE_RIGHT_003, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_TURTLE_MOVE_RIGHT_004, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_TURTLE_MOVE_RIGHT_005, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_TURTLE_MOVE_RIGHT_006, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_TURTLE_MOVE_RIGHT_007, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_TURTLE_MOVE_RIGHT_008, RGB(0, 0, 0));


		hitLeftAnimation.AddBitmap(IDB_MUD_HIT_LEFT_001, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_MUD_HIT_LEFT_002, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_MUD_HIT_LEFT_003, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_MUD_HIT_LEFT_004, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_MUD_HIT_LEFT_005, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_MUD_HIT_LEFT_006, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_MUD_HIT_LEFT_007, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_MUD_HIT_LEFT_008, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_MUD_HIT_RIGHT_001, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_MUD_HIT_RIGHT_002, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_MUD_HIT_RIGHT_003, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_MUD_HIT_RIGHT_004, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_MUD_HIT_RIGHT_005, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_MUD_HIT_RIGHT_006, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_MUD_HIT_RIGHT_007, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_MUD_HIT_RIGHT_008, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_MUD_HIT_DOWN_001, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_MUD_HIT_DOWN_002, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_MUD_HIT_DOWN_003, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_MUD_HIT_DOWN_004, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_MUD_HIT_DOWN_005, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_MUD_HIT_DOWN_006, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_MUD_HIT_DOWN_007, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_MUD_HIT_DOWN_008, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_MUD_HIT_UP_001, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_MUD_HIT_UP_002, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_MUD_HIT_UP_003, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_MUD_HIT_UP_004, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_MUD_HIT_UP_005, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_MUD_HIT_UP_006, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_MUD_HIT_UP_007, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_MUD_HIT_UP_008, RGB(0, 0, 0));
	}

	void CTurtle::SetTypeFlag() {
		typeFlag = CName::TURTLE;
	}

	/*bool CTurtle::changeInvincible() {

		srand((unsigned int)time(NULL));

		int x = rand();
		int flag = x % 2;

		switch (flag) {
		case 1:
			return true;
		default:
			return false;
		}
	}*/

	/*void CTurtle::OnMove()
	{
		const int FOOD_TIME_LIMIT = 90;
		const int STEP_TARGET = 24;
		const int STEP_SIZE_X = 3;
		const int STEP_SIZE_Y = 2;
		const int HIT_TARGET = 8;
		const int HIT_STEP_SIZE_X = 9;
		const int HIT_STEP_SIZE_Y = 6;
		const int INVINCIBLE_TIME_MAX = 90;
		
		if (isInvincible) {
			invincibleTime++;
			if (invincibleTime == INVINCIBLE_TIME_MAX) {
				invincibleTime = 0;
				isInvincible = false;
			}
		}
		else {
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
					mapRecord->SetMonsterInMap(indexX, indexY, CName::TURTLE);
				}
			}

			if (isHit)
			{
				if (isMovingLeft && movingLeftCount != 0)
				{
					hitLeftAnimation.OnMove();
					x -= STEP_SIZE_X;
					movingLeftCount++;
					mapRecord->SetMonsterInMap(indexX - 1, indexY, CName::TURTLE);
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
					mapRecord->SetMonsterInMap(indexX + 1, indexY, CName::TURTLE);
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
					mapRecord->SetMonsterInMap(indexX, indexY - 1, CName::TURTLE);
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
					mapRecord->SetMonsterInMap(indexX, indexY + 1, CName::TURTLE);
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
							//mapRecord->SetMonsterInMap(++indexX, indexY, CName::TURTLE_FOOD);
							mapRecord->SetMonsterInMap(indexX, indexY, CName::TURTLE_FOOD);
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
							//mapRecord->SetMonsterInMap(--indexX, indexY, CName::TURTLE_FOOD);
							mapRecord->SetMonsterInMap(indexX, indexY, CName::TURTLE_FOOD);
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
							//mapRecord->SetMonsterInMap(indexX, ++indexY, CName::TURTLE_FOOD);
							mapRecord->SetMonsterInMap(indexX, indexY, CName::TURTLE_FOOD);
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
							//mapRecord->SetMonsterInMap(indexX, --indexY, CName::TURTLE_FOOD);
							mapRecord->SetMonsterInMap(indexX, indexY, CName::TURTLE_FOOD);
							isFood = true;
							isHit = false;
							hitCount = 0;
						}
					}
				}
			}

			if (!isHit && !isFood && movingDownCount == 0 && movingLeftCount == 0 && movingRightCount == 0 && movingUpCount == 0) {
				isInvincible = changeInvincible();
			}

			if (!isInvincible && !isHit && !isFood)
			{
				if (isMovingLeft)
				{
					if ((mapRecord->GetBrickInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetFoodInMap(indexX - 1, indexY) == CName::SPACE) || movingLeftCount != 0)
					{
						leftAnimation.OnMove();
						x -= STEP_SIZE_X;
						movingLeftCount++;
						mapRecord->SetMonsterInMap(indexX - 1, indexY, CName::TURTLE);
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
						mapRecord->SetMonsterInMap(indexX + 1, indexY, CName::TURTLE);
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
						mapRecord->SetMonsterInMap(indexX, indexY - 1, CName::TURTLE);
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
						mapRecord->SetMonsterInMap(indexX, indexY + 1, CName::TURTLE);
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
	}*/
};
