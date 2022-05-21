#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CPlayer.h"
#include "CAudioId.h"

namespace game_framework {
	CPlayer::CPlayer()
	{
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		isKeyLeftPressed = isKeyRightPressed = isKeyUpPressed = isKeyDownPressed = false;
		movingLeftCount = movingRightCount = movingUpCount = movingDownCount = 0;
		isOnMucus = isSwallowed = isEating = false;
		isSuccess = isFail = false;
		faceTo = CDirection::DOWN;
		leftAnimation.SetDelayCount(2);
		rightAnimation.SetDelayCount(2);
		upAnimation.SetDelayCount(2);
		downAnimation.SetDelayCount(2);
		leftWithFullAnimation.SetDelayCount(2);
		rightWithFullAnimation.SetDelayCount(2);
		upWithFullAnimation.SetDelayCount(2);
		downWithFullAnimation.SetDelayCount(2);
		eatLeftAnimation.SetDelayCount(2);
		eatRightAnimation.SetDelayCount(2);
		eatUpAnimation.SetDelayCount(2);
		eatDownAnimation.SetDelayCount(2);
		successAnimation.SetDelayCount(2);
		failAnimation.SetDelayCount(2);
	}

	int CPlayer::GetIndexX()
	{
		return indexX;
	}

	int CPlayer::GetIndexY()
	{
		return indexY;
	}

	int CPlayer::GetNextIndexX()
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

	int CPlayer::GetNextIndexY()
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

	bool CPlayer::IsSuccess()
	{
		return isSuccess;
	}

	bool CPlayer::IsFail()
	{
		return isFail;
	}

	void CPlayer::Fail()
	{
		isFail = true;
	}

	void CPlayer::Success()
	{
		isSuccess = true;
	}

	void CPlayer::Initialize(CMap *map, CShareData *shareData, list<CTrap> *trap, list<CBrick> *brick, list<CFood> *food, list<CMonster> *monster)
	{
		mapRecord = map;
		shareDataRecord = shareData;
		trapRecord = trap;
		brickRecord = brick;
		foodRecord = food;
		monsterRecord = monster;

		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		isKeyLeftPressed = isKeyRightPressed = isKeyUpPressed = isKeyDownPressed = false;
		movingLeftCount = movingRightCount = movingUpCount = movingDownCount = 0;
		faceTo = CDirection::DOWN;
		isOnMucus = isSwallowed = isEating = false;
		isSuccess = isFail = false;
	}

	void CPlayer::LoadBitmap()
	{
	}

	void CPlayer::OnMove()
	{
		const int STEP_TARGET = 8;
		const double STEP_SIZE_X = 4.5;
		const double STEP_SIZE_Y = 3;
		
		if (isEating) {
			eatLeftAnimation.OnMove();
			eatRightAnimation.OnMove();
			eatUpAnimation.OnMove();
			eatDownAnimation.OnMove();
		}

		if (eatLeftAnimation.IsFinalBitmap() && eatRightAnimation.IsFinalBitmap() && eatUpAnimation.IsFinalBitmap() && eatDownAnimation.IsFinalBitmap())
		{
			isEating = false;
			eatLeftAnimation.Reset();
			eatRightAnimation.Reset();
			eatUpAnimation.Reset();
			eatDownAnimation.Reset();
		}

		if (!isMovingLeft && !isMovingRight && !isMovingUp && !isMovingDown && !isEating)
		{
			if (isKeyLeftPressed)
			{
				if (faceTo != CDirection::LEFT)
				{
					faceTo = CDirection::LEFT;
				}
				else
				{
					movingLeftCount = 0;
					isMovingLeft = true;
				}
			}
			else if (isKeyRightPressed)
			{
				if (faceTo != CDirection::RIGHT)
				{
					faceTo = CDirection::RIGHT;
				}
				else
				{
					movingRightCount = 0;
					isMovingRight = true;
				}
			}
			else if (isKeyUpPressed)
			{
				if (faceTo != CDirection::UP)
				{
					faceTo = CDirection::UP;
				}
				else
				{
					movingUpCount = 0;
					isMovingUp = true;
				}
			}
			else if (isKeyDownPressed)
			{
				if (faceTo != CDirection::DOWN)
				{
					faceTo = CDirection::DOWN;
				}
				else
				{
					movingDownCount = 0;
					isMovingDown = true;
				}
			}
		}

		if (isMovingLeft)
		{
			if ((mapRecord->GetPlayerInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetBrickInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX - 1, indexY) != CName::MONSTER_FOOD && mapRecord->GetFoodInMap(indexX - 1, indexY) == CName::SPACE) || movingLeftCount != 0)
			{
				isOnMucus = (mapRecord->GetTrapInMap(indexX - 1, indexY) == CName::MUCUS);
				leftAnimation.OnMove();
				leftWithFullAnimation.OnMove();
				x -= STEP_SIZE_X;
				movingLeftCount++;
				mapRecord->SetPlayerInMap(indexX - 1, indexY, CName::PLAYER);
				if (movingLeftCount == STEP_TARGET)
				{
					mapRecord->SetPlayerInMap(indexX--, indexY, CName::SPACE);
					movingLeftCount = 0;
					isMovingLeft = isKeyLeftPressed || isOnMucus;
				}
			}
			else
			{
				isOnMucus = false;
				isMovingLeft = isKeyLeftPressed;
			}
		}
		else if (isMovingRight)
		{
			if ((mapRecord->GetPlayerInMap(indexX + 1, indexY) == CName::SPACE && mapRecord->GetBrickInMap(indexX + 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX + 1, indexY) != CName::MONSTER_FOOD && mapRecord->GetFoodInMap(indexX + 1, indexY) == CName::SPACE) || movingRightCount != 0)
			{
				isOnMucus = (mapRecord->GetTrapInMap(indexX + 1, indexY) == CName::MUCUS);
				rightAnimation.OnMove();
				rightWithFullAnimation.OnMove();
				x += STEP_SIZE_X;
				movingRightCount++;
				mapRecord->SetPlayerInMap(indexX + 1, indexY, CName::PLAYER);
				if (movingRightCount == STEP_TARGET)
				{
					mapRecord->SetPlayerInMap(indexX++, indexY, CName::SPACE);
					movingRightCount = 0;
					isMovingRight = isKeyRightPressed || isOnMucus;
				}
			}
			else
			{
				isOnMucus = false;
				isMovingRight = isKeyRightPressed;
			}
		}
		else if (isMovingUp)
		{
			if ((mapRecord->GetPlayerInMap(indexX, indexY - 1) == CName::SPACE && mapRecord->GetBrickInMap(indexX, indexY - 1) == CName::SPACE && mapRecord->GetMonsterInMap(indexX, indexY - 1) != CName::MONSTER_FOOD && mapRecord->GetFoodInMap(indexX, indexY - 1) == CName::SPACE) || movingUpCount != 0)
			{
				isOnMucus = (mapRecord->GetTrapInMap(indexX, indexY - 1) == CName::MUCUS);
				upAnimation.OnMove();
				upWithFullAnimation.OnMove();
				y -= STEP_SIZE_Y;
				movingUpCount++;
				mapRecord->SetPlayerInMap(indexX, indexY - 1, CName::PLAYER);
				if (movingUpCount == STEP_TARGET)
				{
					mapRecord->SetPlayerInMap(indexX, indexY--, CName::SPACE);
					movingUpCount = 0;
					isMovingUp = isKeyUpPressed || isOnMucus;
				}
			}
			else
			{
				isOnMucus = false;
				isMovingUp = isKeyUpPressed;
			}
		}
		else if (isMovingDown)
		{
			if ((mapRecord->GetPlayerInMap(indexX, indexY + 1) == CName::SPACE && mapRecord->GetBrickInMap(indexX, indexY + 1) == CName::SPACE && mapRecord->GetMonsterInMap(indexX, indexY + 1) != CName::MONSTER_FOOD && mapRecord->GetFoodInMap(indexX, indexY + 1) == CName::SPACE) || movingDownCount != 0)
			{
				isOnMucus = (mapRecord->GetTrapInMap(indexX, indexY + 1) == CName::MUCUS);
				downAnimation.OnMove();
				downWithFullAnimation.OnMove();
				y += STEP_SIZE_Y;
				movingDownCount++;
				mapRecord->SetPlayerInMap(indexX, indexY + 1, CName::PLAYER);
				if (movingDownCount == STEP_TARGET)
				{
					mapRecord->SetPlayerInMap(indexX, indexY++, CName::SPACE);
					movingDownCount = 0;
					isMovingDown = isKeyDownPressed || isOnMucus;
				}
			}
			else
			{
				isOnMucus = false;
				isMovingDown = isKeyDownPressed;
			}
		}

		for (list<CTrap>::iterator k = trapRecord->begin(); k != trapRecord->end(); k++)
		{
			if (k->GetIndexX() == indexX && k->GetIndexY() == indexY)
			{
				k->SteppedByPlayer();
			}
		}

		for (list<CMonster>::iterator k = monsterRecord->begin(); k != monsterRecord->end(); k++)
		{
			if (k->IsAlive() && k->GetIndexX() == indexX && k->GetIndexY() == indexY && !k->IsHit() && !k->IsFood())
			{
				isFail = true;
			}
		}

		for (list<CTrap>::iterator k = trapRecord->begin(); k != trapRecord->end(); k++)
		{
			if (k->GetIndexX() == indexX && k->GetIndexY() == indexY && k->IsAggressive())
			{
				isFail = true;
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
		if (!isMovingLeft && !isMovingRight && !isMovingUp && !isMovingDown)
		{
			isEating = true;
			if (isSwallowed == false)
			{
				if (faceTo == CDirection::LEFT)
				{
					for (list<CBrick>::iterator k = brickRecord->begin(); k != brickRecord->end(); k++)
					{
						if (k->GetIndexX() == indexX - 1 && k->GetIndexY() == indexY && !k->IsMove() && k->IsAlive())
						{
							k->Swallowed(faceTo);
							if (shareDataRecord->IsSoundEnable())
							{
								CAudio::Instance()->Play(SOUND_SWALLOW, false);
							}
							swallowedBrick = k;
							isSwallowed = true;
							return;
						}
					}
					for (list<CFood>::iterator k = foodRecord->begin(); k != foodRecord->end(); k++)
					{
						if (k->GetIndexX() == indexX - 1 && k->GetIndexY() == indexY && k->IsAlive())
						{
							k->Swallowed(faceTo);
							if (shareDataRecord->IsSoundEnable())
							{
								CAudio::Instance()->Play(SOUND_SWALLOW, false);
							}
							shareDataRecord->AddGrade(50);
							return;
						}
					}
					for (list<CMonster>::iterator k = monsterRecord->begin(); k != monsterRecord->end(); k++)
					{
						if (k->GetIndexX() == indexX - 1 && k->GetIndexY() == indexY && k->IsFood())
						{
							k->Swallowed(faceTo);
							if (shareDataRecord->IsSoundEnable())
							{
								CAudio::Instance()->Play(SOUND_SWALLOW, false);
							}
							shareDataRecord->AddGrade(100);
						}
					}
				}
				else if (faceTo == CDirection::RIGHT)
				{
					for (list<CBrick>::iterator k = brickRecord->begin(); k != brickRecord->end(); k++)
					{
						if (k->GetIndexX() == indexX + 1 && k->GetIndexY() == indexY && !k->IsMove() && k->IsAlive())
						{
							k->Swallowed(faceTo);
							if (shareDataRecord->IsSoundEnable())
							{
								CAudio::Instance()->Play(SOUND_SWALLOW, false);
							}
							swallowedBrick = k;
							isSwallowed = true;
							return;
						}
					}
					for (list<CFood>::iterator k = foodRecord->begin(); k != foodRecord->end(); k++)
					{
						if (k->GetIndexX() == indexX + 1 && k->GetIndexY() == indexY && k->IsAlive())
						{
							k->Swallowed(faceTo);
							if (shareDataRecord->IsSoundEnable())
							{
								CAudio::Instance()->Play(SOUND_SWALLOW, false);
							}
							shareDataRecord->AddGrade(50);
							return;
						}
					}
					for (list<CMonster>::iterator k = monsterRecord->begin(); k != monsterRecord->end(); k++)
					{
						if (k->GetIndexX() == indexX + 1 && k->GetIndexY() == indexY && k->IsFood())
						{
							k->Swallowed(faceTo);
							if (shareDataRecord->IsSoundEnable())
							{
								CAudio::Instance()->Play(SOUND_SWALLOW, false);
							}
							shareDataRecord->AddGrade(100);
						}
					}
				}
				else if (faceTo == CDirection::UP)
				{
					for (list<CBrick>::iterator k = brickRecord->begin(); k != brickRecord->end(); k++)
					{
						if (k->GetIndexX() == indexX && k->GetIndexY() == indexY - 1 && !k->IsMove() && k->IsAlive())
						{
							k->Swallowed(faceTo);
							if (shareDataRecord->IsSoundEnable())
							{
								CAudio::Instance()->Play(SOUND_SWALLOW, false);
							}
							swallowedBrick = k;
							isSwallowed = true;
							return;
						}
					}
					for (list<CFood>::iterator k = foodRecord->begin(); k != foodRecord->end(); k++)
					{
						if (k->GetIndexX() == indexX && k->GetIndexY() == indexY - 1 && k->IsAlive())
						{
							k->Swallowed(faceTo);
							if (shareDataRecord->IsSoundEnable())
							{
								CAudio::Instance()->Play(SOUND_SWALLOW, false);
							}
							shareDataRecord->AddGrade(50);
							return;
						}
					}
					for (list<CMonster>::iterator k = monsterRecord->begin(); k != monsterRecord->end(); k++)
					{
						if (k->GetIndexX() == indexX && k->GetIndexY() == indexY - 1 && k->IsFood())
						{
							k->Swallowed(faceTo);
							if (shareDataRecord->IsSoundEnable())
							{
								CAudio::Instance()->Play(SOUND_SWALLOW, false);
							}
							shareDataRecord->AddGrade(100);
						}
					}
				}
				else if (faceTo == CDirection::DOWN)
				{
					for (list<CBrick>::iterator k = brickRecord->begin(); k != brickRecord->end(); k++)
					{
						if (k->GetIndexX() == indexX && k->GetIndexY() == indexY + 1 && !k->IsMove() && k->IsAlive())
						{
							k->Swallowed(faceTo);
							if (shareDataRecord->IsSoundEnable())
							{
								CAudio::Instance()->Play(SOUND_SWALLOW, false);
							}
							swallowedBrick = k;
							isSwallowed = true;
							return;
						}
					}
					for (list<CFood>::iterator k = foodRecord->begin(); k != foodRecord->end(); k++)
					{
						if (k->GetIndexX() == indexX && k->GetIndexY() == indexY + 1 && k->IsAlive())
						{
							k->Swallowed(faceTo);
							if (shareDataRecord->IsSoundEnable())
							{
								CAudio::Instance()->Play(SOUND_SWALLOW, false);
							}
							shareDataRecord->AddGrade(50);
							return;
						}
					}
					for (list<CMonster>::iterator k = monsterRecord->begin(); k != monsterRecord->end(); k++)
					{
						if (k->GetIndexX() == indexX && k->GetIndexY() == indexY + 1 && k->IsFood())
						{
							k->Swallowed(faceTo);
							if (shareDataRecord->IsSoundEnable())
							{
								CAudio::Instance()->Play(SOUND_SWALLOW, false);
							}
							shareDataRecord->AddGrade(100);
						}
					}
				}
			}
			else if (isSwallowed == true)
			{
				if (faceTo == CDirection::LEFT)
				{
					if (mapRecord->GetBrickInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetFoodInMap(indexX - 1, indexY) == CName::SPACE)
					{
						swallowedBrick->SpitedOut(faceTo, indexX, indexY, int(x), int(y));
						if (shareDataRecord->IsSoundEnable())
						{
							CAudio::Instance()->Play(SOUND_SPIT_OUT, false);
						}
						isSwallowed = false;
					}
				}
				else if (faceTo == CDirection::RIGHT)
				{
					if (mapRecord->GetBrickInMap(indexX + 1, indexY) == CName::SPACE && mapRecord->GetFoodInMap(indexX + 1, indexY) == CName::SPACE)
					{
						swallowedBrick->SpitedOut(faceTo, indexX, indexY, int(x), int(y));
						if (shareDataRecord->IsSoundEnable())
						{
							CAudio::Instance()->Play(SOUND_SPIT_OUT, false);
						}
						isSwallowed = false;
					}
				}
				else if (faceTo == CDirection::UP)
				{
					if (mapRecord->GetBrickInMap(indexX, indexY - 1) == CName::SPACE && mapRecord->GetFoodInMap(indexX, indexY - 1) == CName::SPACE)
					{
						swallowedBrick->SpitedOut(faceTo, indexX, indexY, int(x), int(y));
						if (shareDataRecord->IsSoundEnable())
						{
							CAudio::Instance()->Play(SOUND_SPIT_OUT, false);
						}
						isSwallowed = false;
					}
				}
				else if (faceTo == CDirection::DOWN)
				{
					if (mapRecord->GetBrickInMap(indexX, indexY + 1) == CName::SPACE && mapRecord->GetFoodInMap(indexX, indexY + 1) == CName::SPACE)
					{
						swallowedBrick->SpitedOut(faceTo, indexX, indexY, int(x), int(y));
						if (shareDataRecord->IsSoundEnable())
						{
							CAudio::Instance()->Play(SOUND_SPIT_OUT, false);
						}
						isSwallowed = false;
					}
				}
			}
		}

		isSuccess = true;
		for (list<CMonster>::iterator k = monsterRecord->begin(); k != monsterRecord->end(); k++)
		{
			isSuccess = isSuccess && !k->IsAlive();
		}
	}

	void CPlayer::SetXY(int ni, int nj, int nx, int ny)
	{
		indexX = ni;
		indexY = nj;
		x = double(nx);
		y = double(ny);
	}

	void CPlayer::OnShow()
	{
		const int BRICK_LENGTH = 36;
		const int BRICK_WIDTH = 24;
		if (isFail)
		{
			failAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (eatLeftAnimation.Width() / 2), int(y) + BRICK_WIDTH - eatLeftAnimation.Height());
			failAnimation.OnShow();
			if (!failAnimation.IsFinalBitmap())
			{
				failAnimation.OnMove();
			}
		}
		else if (isSuccess)
		{
			successAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (eatLeftAnimation.Width() / 2), int(y) + BRICK_WIDTH - eatLeftAnimation.Height());
			successAnimation.OnShow();
			successAnimation.OnMove();
		}
		else
		{
			if (isEating)
			{
				if (faceTo == CDirection::LEFT)
				{
					eatLeftAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (eatLeftAnimation.Width() / 2), int(y) + BRICK_WIDTH - eatLeftAnimation.Height());
					eatLeftAnimation.OnShow();
				}
				else if (faceTo == CDirection::RIGHT)
				{
					eatRightAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (eatRightAnimation.Width() / 2), int(y) + BRICK_WIDTH - eatRightAnimation.Height());
					eatRightAnimation.OnShow();
				}
				else if (faceTo == CDirection::UP)
				{
					eatUpAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (eatUpAnimation.Width() / 2), int(y) + BRICK_WIDTH - eatUpAnimation.Height());
					eatUpAnimation.OnShow();
				}
				else if (faceTo == CDirection::DOWN)
				{
					eatDownAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (eatDownAnimation.Width() / 2), int(y) + BRICK_WIDTH - eatDownAnimation.Height());
					eatDownAnimation.OnShow();
				}
			}
			else if (!isSwallowed)
			{
				if (faceTo == CDirection::LEFT)
				{
					if (!isMovingLeft || isOnMucus)
					{
						leftAnimation.Reset();
					}
					leftAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (leftAnimation.Width() / 2), int(y) + BRICK_WIDTH - leftAnimation.Height());
					leftAnimation.OnShow();
				}
				else if (faceTo == CDirection::RIGHT)
				{
					if (!isMovingRight || isOnMucus)
					{
						rightAnimation.Reset();
					}
					rightAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (rightAnimation.Width() / 2), int(y) + BRICK_WIDTH - rightAnimation.Height());
					rightAnimation.OnShow();
				}
				else if (faceTo == CDirection::UP)
				{
					if (!isMovingUp || isOnMucus)
					{
						upAnimation.Reset();
					}
					upAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (upAnimation.Width() / 2), int(y) + BRICK_WIDTH - upAnimation.Height());
					upAnimation.OnShow();
				}
				else if (faceTo == CDirection::DOWN)
				{
					if (!isMovingDown || isOnMucus)
					{
						downAnimation.Reset();
					}
					downAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (downAnimation.Width() / 2), int(y) + BRICK_WIDTH - downAnimation.Height());
					downAnimation.OnShow();
				}
			}
			else if (isSwallowed)
			{
				if (faceTo == CDirection::LEFT)
				{
					if (!isMovingLeft || isOnMucus)
					{
						leftWithFullAnimation.Reset();
					}
					leftWithFullAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (leftWithFullAnimation.Width() / 2), int(y) + BRICK_WIDTH - leftWithFullAnimation.Height());
					leftWithFullAnimation.OnShow();
				}
				else if (faceTo == CDirection::RIGHT)
				{
					if (!isMovingRight || isOnMucus)
					{
						rightWithFullAnimation.Reset();
					}
					rightWithFullAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (rightWithFullAnimation.Width() / 2), int(y) + BRICK_WIDTH - rightWithFullAnimation.Height());
					rightWithFullAnimation.OnShow();
				}
				else if (faceTo == CDirection::UP)
				{
					if (!isMovingUp || isOnMucus)
					{
						upWithFullAnimation.Reset();
					}
					upWithFullAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (upWithFullAnimation.Width() / 2), int(y) + BRICK_WIDTH - upWithFullAnimation.Height());
					upWithFullAnimation.OnShow();
				}
				else if (faceTo == CDirection::DOWN)
				{
					if (!isMovingDown || isOnMucus)
					{
						downWithFullAnimation.Reset();
					}
					downWithFullAnimation.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (downWithFullAnimation.Width() / 2), int(y) + BRICK_WIDTH - downWithFullAnimation.Height());
					downWithFullAnimation.OnShow();
				}
			}
		}
	}
}