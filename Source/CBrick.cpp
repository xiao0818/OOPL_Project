#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CBrick.h"
#include "CPlayer.h"

namespace game_framework {
	CBrick::CBrick()
	{
		x = y = 0;
		movingLeftCount = movingRightCount = movingUpCount = movingDownCount = 0;
		isAlive = true;
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
		isSwallowed = isHit = isBombCounting = isBomb = false;
		bitmap.SetDelayCount(2);
		reboundStepCount = 3;
		bombCount = 10 * 30;
	}

	int CBrick::GetIndexX()
	{
		return indexX;
	}

	int CBrick::GetIndexY()
	{
		return indexY;
	}

	bool CBrick::IsMove()
	{
		return isMovingLeft || isMovingRight || isMovingUp || isMovingDown;
	}

	bool CBrick::IsAlive()
	{
		return isAlive;
	}

	void CBrick::Initialize(CMap *map, CPlayer *player1, CPlayer *player2, list<CBrick> *brick, list<CFood> *food, list<CMonster> *monster)
	{
	}

	void CBrick::LoadBitmap()
	{
	}

	void CBrick::OnMove()
	{
		const int SWALLOWED_STEP_TARGET = 6;
		const double SWALLOWED_STEP_SIZE_X = 6;
		const double SWALLOWED_STEP_SIZE_Y = 4;
		const int BRICK_LENGTH = 36;
		const int BRICK_WIDTH = 24;

		if (isAlive)
		{
			if (isBombCounting)
			{
				if (bombCount-- == 0)
				{
					if (type == CName::BOMB)
					{
						Bomb();
					}
				}
			}

			if (isBomb)
			{
				mapRecord->SetBrickInMap(indexX, indexY, CName::SPACE);

				for (list<CMonster>::iterator k = monsterRecord->begin(); k != monsterRecord->end(); k++)
				{
					if (indexX - 1 <= k->GetIndexX() && k->GetIndexX() <= indexX + 1 && indexY - 1 <= k->GetIndexY() && k->GetIndexY() <= indexY + 1 && k->IsAlive())
					{
						k->SetAlive(false);
						mapRecord->SetMonsterInMap(k->GetIndexX(), k->GetIndexY(), CName::SPACE);
					}
				}

				for (list<CBrick>::iterator k = brickRecord->begin(); k != brickRecord->end(); k++)
				{
					if (indexX - 1 <= k->GetIndexX() && k->GetIndexX() <= indexX + 1 && indexY - 1 <= k->GetIndexY() && k->GetIndexY() <= indexY + 1 && k->IsAlive())
					{
						k->Bomb();
						mapRecord->SetBrickInMap(k->GetIndexX(), k->GetIndexY(), CName::SPACE);
					}
				}

				for (list<CFood>::iterator k = foodRecord->begin(); k != foodRecord->end(); k++)
				{
					if (indexX - 1 <= k->GetIndexX() && k->GetIndexX() <= indexX + 1 && indexY - 1 <= k->GetIndexY() && k->GetIndexY() <= indexY + 1 && k->IsAlive())
					{
						k->SetAlive(false);
						mapRecord->SetFoodInMap(k->GetIndexX(), k->GetIndexY(), CName::SPACE);
					}
				}

				if (indexX - 1 <= player1Record->GetIndexX() && player1Record->GetIndexX() <= indexX + 1 && indexY - 1 <= player1Record->GetIndexY() && player1Record->GetIndexY() <= indexY + 1 && !player1Record->IsFail())
				{
					player1Record->Fail();
				}

				if (indexX - 1 <= player2Record->GetIndexX() && player2Record->GetIndexX() <= indexX + 1 && indexY - 1 <= player2Record->GetIndexY() && player2Record->GetIndexY() <= indexY + 1 && !player2Record->IsFail())
				{
					player2Record->Fail();
				}

				if (!bitmap.IsFinalBitmap())
				{
					bitmap.OnMove();
				}
				else
				{
					isAlive = false;
				}
			}

			if (isHit)
			{
				if (!bitmap.IsFinalBitmap())
				{
					bitmap.OnMove();
				}
				else
				{
					bitmap.Reset();
					isHit = false;
					if (type == CName::WOODEN)
					{
						isAlive = false;
					}
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
					if ((mapRecord->GetBrickInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetFoodInMap(indexX - 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX - 1, indexY) != CName::INVINCIBLE_TURTLE) || movingLeftCount != 0)
					{
						x -= STEP_SIZE_X;
						movingLeftCount++;
						mapRecord->SetBrickInMap(indexX - 1, indexY, type);
						if (movingLeftCount == STEP_TARGET)
						{
							mapRecord->SetBrickInMap(indexX--, indexY, CName::SPACE);
							movingLeftCount = 0;
							if (mapRecord->GetMonsterInMap(indexX, indexY) != CName::SPACE) {
								for (list<CMonster>::iterator k = monsterRecord->begin(); k != monsterRecord->end(); k++)
								{
									if (((k->GetIndexX() == indexX && k->GetIndexY() == indexY) || (k->GetNextIndexX() == indexX && k->GetNextIndexY() == indexY)) && k->IsAlive())
									{
										k->HitByBrick(CDirection::LEFT);
										if (type == CName::WOODEN)
										{
											Hit();
											return;
										}
									}
								}
							}
							if (mapRecord->GetPlayerInMap(indexX, indexY) != CName::SPACE) {
								if (((player1Record->GetIndexX() == indexX && player1Record->GetIndexY() == indexY) || (player1Record->GetNextIndexX() == indexX && player1Record->GetNextIndexY() == indexY)) && !player1Record->IsFail())
								{
									player1Record->Fail();
									if (type == CName::WOODEN)
									{
										Hit();
										return;
									}
								}
							}
							if (mapRecord->GetPlayerInMap(indexX, indexY) != CName::SPACE) {
								if (((player2Record->GetIndexX() == indexX && player2Record->GetIndexY() == indexY) || (player2Record->GetNextIndexX() == indexX && player2Record->GetNextIndexY() == indexY)) && !player2Record->IsFail())
								{
									player2Record->Fail();
									if (type == CName::WOODEN)
									{
										Hit();
										return;
									}
								}
							}
							if (mapRecord->GetBrickInMap(indexX - 1, indexY) != CName::SPACE) {
								for (list<CBrick>::iterator k = brickRecord->begin(); k != brickRecord->end(); k++)
								{
									if ((k->GetIndexX() == indexX - 1 && k->GetIndexY() == indexY) && k->IsAlive())
									{
										k->Hit();
										Hit();
									}
								}
							}
						}
					}
					else
					{
						Hit();
						isMovingLeft = false;
					}
				}
				else if (isMovingRight)
				{
					if ((mapRecord->GetBrickInMap(indexX + 1, indexY) == CName::SPACE && mapRecord->GetFoodInMap(indexX + 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX + 1, indexY) != CName::INVINCIBLE_TURTLE) || movingRightCount != 0)
					{
						x += STEP_SIZE_X;
						movingRightCount++;
						mapRecord->SetBrickInMap(indexX + 1, indexY, type);
						if (movingRightCount == STEP_TARGET)
						{
							mapRecord->SetBrickInMap(indexX++, indexY, CName::SPACE);
							movingRightCount = 0;
							if (mapRecord->GetMonsterInMap(indexX, indexY) != CName::SPACE) {
								for (list<CMonster>::iterator k = monsterRecord->begin(); k != monsterRecord->end(); k++)
								{
									if (((k->GetIndexX() == indexX && k->GetIndexY() == indexY) || (k->GetNextIndexX() == indexX && k->GetNextIndexY() == indexY)) && k->IsAlive())
									{
										k->HitByBrick(CDirection::RIGHT);
										if (type == CName::WOODEN)
										{
											Hit();
											return;
										}
									}
								}
							}
							if (mapRecord->GetPlayerInMap(indexX, indexY) != CName::SPACE) {
								if (((player1Record->GetIndexX() == indexX && player1Record->GetIndexY() == indexY) || (player1Record->GetNextIndexX() == indexX && player1Record->GetNextIndexY() == indexY)) && !player1Record->IsFail())
								{
									player1Record->Fail();
									if (type == CName::WOODEN)
									{
										Hit();
										return;
									}
								}
							}
							if (mapRecord->GetPlayerInMap(indexX, indexY) != CName::SPACE) {
								if (((player2Record->GetIndexX() == indexX && player2Record->GetIndexY() == indexY) || (player2Record->GetNextIndexX() == indexX && player2Record->GetNextIndexY() == indexY)) && !player2Record->IsFail())
								{
									player2Record->Fail();
									if (type == CName::WOODEN)
									{
										Hit();
										return;
									}
								}
							}
							if (mapRecord->GetBrickInMap(indexX + 1, indexY) != CName::SPACE) {
								for (list<CBrick>::iterator k = brickRecord->begin(); k != brickRecord->end(); k++)
								{
									if ((k->GetIndexX() == indexX + 1 && k->GetIndexY() == indexY) && k->IsAlive())
									{
										k->Hit();
										Hit();
									}
								}
							}
						}
					}
					else
					{
						Hit();
						isMovingRight = false;
					}
				}
				else if (isMovingUp)
				{
					if ((mapRecord->GetBrickInMap(indexX, indexY - 1) == CName::SPACE && mapRecord->GetFoodInMap(indexX, indexY - 1) == CName::SPACE && mapRecord->GetMonsterInMap(indexX, indexY - 1) != CName::INVINCIBLE_TURTLE) || movingUpCount != 0)
					{
						y -= STEP_SIZE_Y;
						movingUpCount++;
						mapRecord->SetBrickInMap(indexX, indexY - 1, type);
						if (movingUpCount == STEP_TARGET)
						{
							mapRecord->SetBrickInMap(indexX, indexY--, CName::SPACE);
							movingUpCount = 0;
							if (mapRecord->GetMonsterInMap(indexX, indexY) != CName::SPACE) {
								for (list<CMonster>::iterator k = monsterRecord->begin(); k != monsterRecord->end(); k++)
								{
									if (((k->GetIndexX() == indexX && k->GetIndexY() == indexY) || (k->GetNextIndexX() == indexX && k->GetNextIndexY() == indexY)) && k->IsAlive())
									{
										k->HitByBrick(CDirection::UP);
										if (type == CName::WOODEN)
										{
											Hit();
											return;
										}
									}
								}
							}
							if (mapRecord->GetPlayerInMap(indexX, indexY) != CName::SPACE) {
								if (((player1Record->GetIndexX() == indexX && player1Record->GetIndexY() == indexY) || (player1Record->GetNextIndexX() == indexX && player1Record->GetNextIndexY() == indexY)) && !player1Record->IsFail())
								{
									player1Record->Fail();
									if (type == CName::WOODEN)
									{
										Hit();
										return;
									}
								}
							}
							if (mapRecord->GetPlayerInMap(indexX, indexY) != CName::SPACE) {
								if (((player2Record->GetIndexX() == indexX && player2Record->GetIndexY() == indexY) || (player2Record->GetNextIndexX() == indexX && player2Record->GetNextIndexY() == indexY)) && !player2Record->IsFail())
								{
									player2Record->Fail();
									if (type == CName::WOODEN)
									{
										Hit();
										return;
									}
								}
							}
							if (mapRecord->GetBrickInMap(indexX, indexY - 1) != CName::SPACE) {
								for (list<CBrick>::iterator k = brickRecord->begin(); k != brickRecord->end(); k++)
								{
									if ((k->GetIndexX() == indexX && k->GetIndexY() == indexY - 1) && k->IsAlive())
									{
										k->Hit();
										Hit();
									}
								}
							}
						}
					}
					else
					{
						Hit();
						isMovingUp = false;
					}
				}
				else if (isMovingDown)
				{
					if ((mapRecord->GetBrickInMap(indexX, indexY + 1) == CName::SPACE && mapRecord->GetFoodInMap(indexX, indexY + 1) == CName::SPACE && mapRecord->GetMonsterInMap(indexX, indexY + 1) != CName::INVINCIBLE_TURTLE) || movingDownCount != 0)
					{
						y += STEP_SIZE_Y;
						movingDownCount++;
						mapRecord->SetBrickInMap(indexX, indexY + 1, type);
						if (movingDownCount == STEP_TARGET)
						{
							mapRecord->SetBrickInMap(indexX, indexY++, CName::SPACE);
							movingDownCount = 0;
							if (mapRecord->GetMonsterInMap(indexX, indexY) != CName::SPACE) {
								for (list<CMonster>::iterator k = monsterRecord->begin(); k != monsterRecord->end(); k++)
								{
									if (((k->GetIndexX() == indexX && k->GetIndexY() == indexY) || (k->GetNextIndexX() == indexX && k->GetNextIndexY() == indexY)) && k->IsAlive())
									{
										k->HitByBrick(CDirection::DOWN);
										if (type == CName::WOODEN)
										{
											Hit();
											return;
										}
									}
								}
							}
							if (mapRecord->GetPlayerInMap(indexX, indexY) != CName::SPACE) {
								if (((player1Record->GetIndexX() == indexX && player1Record->GetIndexY() == indexY) || (player1Record->GetNextIndexX() == indexX && player1Record->GetNextIndexY() == indexY)) && !player1Record->IsFail())
								{
									player1Record->Fail();
									if (type == CName::WOODEN)
									{
										Hit();
										return;
									}
								}
							}
							if (mapRecord->GetPlayerInMap(indexX, indexY) != CName::SPACE) {
								if (((player2Record->GetIndexX() == indexX && player2Record->GetIndexY() == indexY) || (player2Record->GetNextIndexX() == indexX && player2Record->GetNextIndexY() == indexY)) && !player2Record->IsFail())
								{
									player2Record->Fail();
									if (type == CName::WOODEN)
									{
										Hit();
										return;
									}
								}
							}
							if (mapRecord->GetBrickInMap(indexX, indexY + 1) != CName::SPACE) {
								for (list<CBrick>::iterator k = brickRecord->begin(); k != brickRecord->end(); k++)
								{
									if ((k->GetIndexX() == indexX && k->GetIndexY() == indexY + 1) && k->IsAlive())
									{
										k->Hit();
										Hit();
									}
								}
							}
						}
					}
					else
					{
						Hit();
						isMovingDown = false;
					}
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
		mapRecord->SetBrickInMap(indexX, indexY, type);
		isAlive = true;
		movingLeftCount = movingRightCount = movingUpCount = movingDownCount = 0;
		reboundStepCount = 3;
		if (type == CName::BOMB)
		{
			bombCount = 10 * 30;
			isBombCounting = true;
		}
		
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

	void CBrick::Hit()
	{
		if (type == CName::WOODEN)
		{
			mapRecord->SetBrickInMap(indexX, indexY, CName::SPACE);
			isHit = true;
		}
		else if (type == CName::SLIME)
		{
			if (isMovingLeft)
			{
				isMovingLeft = false;
				isMovingRight = true;
			}
			else if (isMovingRight)
			{
				isMovingRight = false;
				isMovingLeft = true;
			}
			else if (isMovingUp)
			{
				isMovingUp = false;
				isMovingDown = true;
			}
			else if (isMovingDown)
			{
				isMovingDown = false;
				isMovingUp = true;
			}
			if (reboundStepCount-- >= 0)
			{
				mapRecord->SetBrickInMap(indexX, indexY, CName::SLIME);
				isHit = true;
				return;
			}
		}
		isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
	}

	void CBrick::Bomb()
	{
		isBomb = true;
	}

	void CBrick::SetXY(int ni, int nj, int nx, int ny)
	{
		indexX = ni;
		indexY = nj;
		x = double(nx);
		y = double(ny);
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
		const int BRICK_LENGTH = 36;
		const int BRICK_WIDTH = 24;

		if (isAlive) {
			bitmap.SetTopLeft(int(x) + (BRICK_LENGTH / 2) - (bitmap.Width() / 2), int(y) + (BRICK_WIDTH / 2) - (bitmap.Height() / 2) - 6);
			bitmap.OnShow();
		}
	}
}