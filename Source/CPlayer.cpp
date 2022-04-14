#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CPlayer.h"

namespace game_framework {
	CPlayer::CPlayer()
	{
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		isKeyLeftPressed = isKeyRightPressed = isKeyUpPressed = isKeyDownPressed = false;
		movingLeftCount = movingRightCount = movingUpCount = movingDownCount = 0;
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
		isSwallowed = false;
		isEating = false;
	}

	int CPlayer::GetIndexX() {
		return indexX;
	}

	int CPlayer::GetIndexY() {
		return indexY;
	}

	void CPlayer::Initialize(CMap *map)
	{
		mapRecord = map;
	}

	void CPlayer::LoadBitmap()
	{
		leftAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_001, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_002, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_003, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_004, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_005, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_006, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_007, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_008, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_001, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_002, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_003, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_004, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_005, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_006, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_007, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_008, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_001, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_002, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_003, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_004, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_005, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_006, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_007, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_008, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_001, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_002, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_003, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_004, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_005, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_006, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_007, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_008, RGB(0, 0, 0));

		leftWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_WITH_FULL_001, RGB(0, 0, 0));
		leftWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_WITH_FULL_002, RGB(0, 0, 0));
		leftWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_WITH_FULL_003, RGB(0, 0, 0));
		leftWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_WITH_FULL_004, RGB(0, 0, 0));
		leftWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_WITH_FULL_005, RGB(0, 0, 0));
		leftWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_WITH_FULL_006, RGB(0, 0, 0));
		leftWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_WITH_FULL_007, RGB(0, 0, 0));
		leftWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_WITH_FULL_008, RGB(0, 0, 0));
		rightWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_WITH_FULL_001, RGB(0, 0, 0));
		rightWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_WITH_FULL_002, RGB(0, 0, 0));
		rightWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_WITH_FULL_003, RGB(0, 0, 0));
		rightWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_WITH_FULL_004, RGB(0, 0, 0));
		rightWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_WITH_FULL_005, RGB(0, 0, 0));
		rightWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_WITH_FULL_006, RGB(0, 0, 0));
		rightWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_WITH_FULL_007, RGB(0, 0, 0));
		rightWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_WITH_FULL_008, RGB(0, 0, 0));
		upWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_WITH_FULL_001, RGB(0, 0, 0));
		upWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_WITH_FULL_002, RGB(0, 0, 0));
		upWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_WITH_FULL_003, RGB(0, 0, 0));
		upWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_WITH_FULL_004, RGB(0, 0, 0));
		upWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_WITH_FULL_005, RGB(0, 0, 0));
		upWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_WITH_FULL_006, RGB(0, 0, 0));
		upWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_WITH_FULL_007, RGB(0, 0, 0));
		upWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_WITH_FULL_008, RGB(0, 0, 0));
		downWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_WITH_FULL_001, RGB(0, 0, 0));
		downWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_WITH_FULL_002, RGB(0, 0, 0));
		downWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_WITH_FULL_003, RGB(0, 0, 0));
		downWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_WITH_FULL_004, RGB(0, 0, 0));
		downWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_WITH_FULL_005, RGB(0, 0, 0));
		downWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_WITH_FULL_006, RGB(0, 0, 0));
		downWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_WITH_FULL_007, RGB(0, 0, 0));
		downWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_WITH_FULL_008, RGB(0, 0, 0));

		eatLeftAnimation.AddBitmap(IDB_PLAYER_EAT_LEFT_001, RGB(0, 0, 0));
		eatLeftAnimation.AddBitmap(IDB_PLAYER_EAT_LEFT_002, RGB(0, 0, 0));
		eatLeftAnimation.AddBitmap(IDB_PLAYER_EAT_LEFT_003, RGB(0, 0, 0));
		eatLeftAnimation.AddBitmap(IDB_PLAYER_EAT_LEFT_004, RGB(0, 0, 0));
		eatRightAnimation.AddBitmap(IDB_PLAYER_EAT_RIGHT_001, RGB(0, 0, 0));
		eatRightAnimation.AddBitmap(IDB_PLAYER_EAT_RIGHT_002, RGB(0, 0, 0));
		eatRightAnimation.AddBitmap(IDB_PLAYER_EAT_RIGHT_003, RGB(0, 0, 0));
		eatRightAnimation.AddBitmap(IDB_PLAYER_EAT_RIGHT_004, RGB(0, 0, 0));
		eatUpAnimation.AddBitmap(IDB_PLAYER_EAT_UP_001, RGB(0, 0, 0));
		eatUpAnimation.AddBitmap(IDB_PLAYER_EAT_UP_002, RGB(0, 0, 0));
		eatUpAnimation.AddBitmap(IDB_PLAYER_EAT_UP_003, RGB(0, 0, 0));
		eatUpAnimation.AddBitmap(IDB_PLAYER_EAT_UP_004, RGB(0, 0, 0));
		eatDownAnimation.AddBitmap(IDB_PLAYER_EAT_DOWN_001, RGB(0, 0, 0));
		eatDownAnimation.AddBitmap(IDB_PLAYER_EAT_DOWN_002, RGB(0, 0, 0));
		eatDownAnimation.AddBitmap(IDB_PLAYER_EAT_DOWN_003, RGB(0, 0, 0));
		eatDownAnimation.AddBitmap(IDB_PLAYER_EAT_DOWN_004, RGB(0, 0, 0));
	}

	void CPlayer::OnMove()
	{
		const int STEP_TARGET = 8;
		const int STEP_SIZE_X = 9;
		const int STEP_SIZE_Y = 6;
		
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
			if ((mapRecord->GetBrickInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX - 1, indexY) != CName::MUD_FOOD && mapRecord->GetFoodInMap(indexX - 1, indexY) == CName::SPACE) || movingLeftCount != 0)
			{
				leftAnimation.OnMove();
				leftWithFullAnimation.OnMove();
				x -= STEP_SIZE_X;
				movingLeftCount++;
				mapRecord->SetPlayerInMap(indexX - 1, indexY, CName::PLAYER);
				if (movingLeftCount == STEP_TARGET)
				{
					mapRecord->SetPlayerInMap(indexX--, indexY, CName::SPACE);
					movingLeftCount = 0;
					isMovingLeft = isKeyLeftPressed;
				}
			}
			else
			{
				isMovingLeft = isKeyLeftPressed;
			}
		}
		else if (isMovingRight)
		{
			if ((mapRecord->GetBrickInMap(indexX + 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX + 1, indexY) != CName::MUD_FOOD && mapRecord->GetFoodInMap(indexX + 1, indexY) == CName::SPACE) || movingRightCount != 0)
			{
				rightAnimation.OnMove();
				rightWithFullAnimation.OnMove();
				x += STEP_SIZE_X;
				movingRightCount++;
				mapRecord->SetPlayerInMap(indexX + 1, indexY, CName::PLAYER);
				if (movingRightCount == STEP_TARGET)
				{
					mapRecord->SetPlayerInMap(indexX++, indexY, CName::SPACE);
					movingRightCount = 0;
					isMovingRight = isKeyRightPressed;
				}
			}
			else
			{
				isMovingRight = isKeyRightPressed;
			}
		}
		else if (isMovingUp)
		{
			if ((mapRecord->GetBrickInMap(indexX, indexY - 1) == CName::SPACE && mapRecord->GetMonsterInMap(indexX, indexY - 1) != CName::MUD_FOOD && mapRecord->GetFoodInMap(indexX, indexY - 1) == CName::SPACE) || movingUpCount != 0)
			{
				upAnimation.OnMove();
				upWithFullAnimation.OnMove();
				y -= STEP_SIZE_Y;
				movingUpCount++;
				mapRecord->SetPlayerInMap(indexX, indexY - 1, CName::PLAYER);
				if (movingUpCount == STEP_TARGET)
				{
					mapRecord->SetPlayerInMap(indexX, indexY--, CName::SPACE);
					movingUpCount = 0;
					isMovingUp = isKeyUpPressed;
				}
			}
			else
			{
				isMovingUp = isKeyUpPressed;
			}
		}
		else if (isMovingDown)
		{
			if ((mapRecord->GetBrickInMap(indexX, indexY + 1) == CName::SPACE && mapRecord->GetMonsterInMap(indexX, indexY + 1) != CName::MUD_FOOD && mapRecord->GetFoodInMap(indexX, indexY + 1) == CName::SPACE) || movingDownCount != 0)
			{
				downAnimation.OnMove();
				downWithFullAnimation.OnMove();
				y += STEP_SIZE_Y;
				movingDownCount++;
				mapRecord->SetPlayerInMap(indexX, indexY + 1, CName::PLAYER);
				if (movingDownCount == STEP_TARGET)
				{
					mapRecord->SetPlayerInMap(indexX, indexY++, CName::SPACE);
					movingDownCount = 0;
					isMovingDown = isKeyDownPressed;
				}
			}
			else
			{
				isMovingDown = isKeyDownPressed;
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

	void CPlayer::PressKeySpace(CInteger *grade, list<CBrick> &brick, list<CFood> &food, list<CMud> &mud)
	{
		if (!isMovingLeft && !isMovingRight && !isMovingUp && !isMovingDown)
		{
			isEating = true;
			if (isSwallowed == false)
			{
				if (faceTo == CDirection::LEFT)
				{
					for (list<CBrick>::iterator k = brick.begin(); k != brick.end(); k++)
					{
						if (k->GetIndexX() == indexX - 1 && k->GetIndexY() == indexY && !k->IsMove())
						{
							k->Swallowed(faceTo);
							swallowedBrick = k;
							isSwallowed = true;
							return;
						}
					}
					for (list<CFood>::iterator k = food.begin(); k != food.end(); k++)
					{
						if (k->GetIndexX() == indexX - 1 && k->GetIndexY() == indexY)
						{
							k->Swallowed(faceTo);
							grade->Add(50);
							return;
						}
					}
					for (list<CMud>::iterator k = mud.begin(); k != mud.end(); k++)
					{
						if (k->GetIndexX() == indexX - 1 && k->GetIndexY() == indexY && k->IsFood())
						{
							k->Swallowed();
							grade->Add(100);
						}
					}
				}
				else if (faceTo == CDirection::RIGHT)
				{
					for (list<CBrick>::iterator k = brick.begin(); k != brick.end(); k++)
					{
						if (k->GetIndexX() == indexX + 1 && k->GetIndexY() == indexY && !k->IsMove())
						{
							k->Swallowed(faceTo);
							swallowedBrick = k;
							isSwallowed = true;
							return;
						}
					}
					for (list<CFood>::iterator k = food.begin(); k != food.end(); k++)
					{
						if (k->GetIndexX() == indexX + 1 && k->GetIndexY() == indexY)
						{
							k->Swallowed(faceTo);
							grade->Add(50);
							return;
						}
					}
					for (list<CMud>::iterator k = mud.begin(); k != mud.end(); k++)
					{
						if (k->GetIndexX() == indexX + 1 && k->GetIndexY() == indexY && k->IsFood())
						{
							k->Swallowed();
							grade->Add(100);
						}
					}
				}
				else if (faceTo == CDirection::UP)
				{
					for (list<CBrick>::iterator k = brick.begin(); k != brick.end(); k++)
					{
						if (k->GetIndexX() == indexX && k->GetIndexY() == indexY - 1 && !k->IsMove())
						{
							k->Swallowed(faceTo);
							swallowedBrick = k;
							isSwallowed = true;
							return;
						}
					}
					for (list<CFood>::iterator k = food.begin(); k != food.end(); k++)
					{
						if (k->GetIndexX() == indexX && k->GetIndexY() == indexY - 1)
						{
							k->Swallowed(faceTo);
							grade->Add(50);
							return;
						}
					}
					for (list<CMud>::iterator k = mud.begin(); k != mud.end(); k++)
					{
						if (k->GetIndexX() == indexX && k->GetIndexY() == indexY - 1 && k->IsFood())
						{
							k->Swallowed();
							grade->Add(100);
						}
					}
				}
				else if (faceTo == CDirection::DOWN)
				{
					for (list<CBrick>::iterator k = brick.begin(); k != brick.end(); k++)
					{
						if (k->GetIndexX() == indexX && k->GetIndexY() == indexY + 1 && !k->IsMove())
						{
							k->Swallowed(faceTo);
							swallowedBrick = k;
							isSwallowed = true;
							return;
						}
					}
					for (list<CFood>::iterator k = food.begin(); k != food.end(); k++)
					{
						if (k->GetIndexX() == indexX && k->GetIndexY() == indexY + 1)
						{
							k->Swallowed(faceTo);
							grade->Add(50);
							return;
						}
					}
					for (list<CMud>::iterator k = mud.begin(); k != mud.end(); k++)
					{
						if (k->GetIndexX() == indexX && k->GetIndexY() == indexY + 1 && k->IsFood())
						{
							k->Swallowed();
							grade->Add(100);
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
						swallowedBrick->SpitedOut(faceTo, indexX, indexY, x, y);
						isSwallowed = false;
					}
				}
				else if (faceTo == CDirection::RIGHT)
				{
					if (mapRecord->GetBrickInMap(indexX + 1, indexY) == CName::SPACE && mapRecord->GetFoodInMap(indexX + 1, indexY) == CName::SPACE)
					{
						swallowedBrick->SpitedOut(faceTo, indexX, indexY, x, y);
						isSwallowed = false;
					}
				}
				else if (faceTo == CDirection::UP)
				{
					if (mapRecord->GetBrickInMap(indexX, indexY - 1) == CName::SPACE && mapRecord->GetFoodInMap(indexX, indexY - 1) == CName::SPACE)
					{
						swallowedBrick->SpitedOut(faceTo, indexX, indexY, x, y);
						isSwallowed = false;
					}
				}
				else if (faceTo == CDirection::DOWN)
				{
					if (mapRecord->GetBrickInMap(indexX, indexY + 1) == CName::SPACE && mapRecord->GetFoodInMap(indexX, indexY + 1) == CName::SPACE)
					{
						swallowedBrick->SpitedOut(faceTo, indexX, indexY, x, y);
						isSwallowed = false;
					}
				}
			}
		}
	}

	void CPlayer::SetXY(int ni, int nj, int nx, int ny)
	{
		indexX = ni;
		indexY = nj;
		x = nx;
		y = ny;
	}

	void CPlayer::OnShow()
	{
		if (isEating)
		{
			if (faceTo == CDirection::LEFT)
			{
				eatLeftAnimation.SetTopLeft(x + (72 / 2) - (eatLeftAnimation.Width() / 2), y + 46 - eatLeftAnimation.Height());
				eatLeftAnimation.OnShow();
			}
			else if (faceTo == CDirection::RIGHT)
			{
				eatRightAnimation.SetTopLeft(x + (72 / 2) - (eatRightAnimation.Width() / 2), y + 46 - eatRightAnimation.Height());
				eatRightAnimation.OnShow();
			}
			else if (faceTo == CDirection::UP)
			{
				eatUpAnimation.SetTopLeft(x + (72 / 2) - (eatUpAnimation.Width() / 2), y + 46 - eatUpAnimation.Height());
				eatUpAnimation.OnShow();
			}
			else if (faceTo == CDirection::DOWN)
			{
				eatDownAnimation.SetTopLeft(x + (72 / 2) - (eatDownAnimation.Width() / 2), y + 46 - eatDownAnimation.Height());
				eatDownAnimation.OnShow();
			}
		}
		else if (!isSwallowed)
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
		else if(isSwallowed)
		{
			if (faceTo == CDirection::LEFT)
			{
				if (!isMovingLeft)
				{
					leftWithFullAnimation.Reset();
				}
				leftWithFullAnimation.SetTopLeft(x + (72 / 2) - (leftWithFullAnimation.Width() / 2), y + 46 - leftWithFullAnimation.Height());
				leftWithFullAnimation.OnShow();
			}
			else if (faceTo == CDirection::RIGHT)
			{
				if (!isMovingRight)
				{
					rightWithFullAnimation.Reset();
				}
				rightWithFullAnimation.SetTopLeft(x + (72 / 2) - (rightWithFullAnimation.Width() / 2), y + 46 - rightWithFullAnimation.Height());
				rightWithFullAnimation.OnShow();
			}
			else if (faceTo == CDirection::UP)
			{
				if (!isMovingUp)
				{
					upWithFullAnimation.Reset();
				}
				upWithFullAnimation.SetTopLeft(x + (72 / 2) - (upWithFullAnimation.Width() / 2), y + 46 - upWithFullAnimation.Height());
				upWithFullAnimation.OnShow();
			}
			else if (faceTo == CDirection::DOWN)
			{
				if (!isMovingDown)
				{
					downWithFullAnimation.Reset();
				}
				downWithFullAnimation.SetTopLeft(x + (72 / 2) - (downWithFullAnimation.Width() / 2), y + 46 - downWithFullAnimation.Height());
				downWithFullAnimation.OnShow();
			}
		}
	}
}