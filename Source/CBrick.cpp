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

	void CBrick::Initialize(CMap *map, list<CBrick> *brick, list<CMonster> *monster)
	{
		mapRecord = map;
		brickRecord = brick;
		monsterRecord = monster;
		SetStepAndType();
	}

	void CBrick::LoadBitmap()
	{
	}

	void CBrick::SetStepAndType()
	{
	}

	void CBrick::OnMove()
	{
		const int SWALLOWED_STEP_TARGET = 6;
		const int SWALLOWED_STEP_SIZE_X = 6;
		const int SWALLOWED_STEP_SIZE_Y = 4;
		const int BRICK_LENGTH = 36;
		const int BRICK_WIDTH = 24;

		if (isAlive)
		{
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
						mapRecord->SetBrickInMap(indexX - 1, indexY, CName::STONE);
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
										}
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
						isMovingLeft = false;
						Hit();
					}
				}
				else if (isMovingRight)
				{
					if ((mapRecord->GetBrickInMap(indexX + 1, indexY) == CName::SPACE && mapRecord->GetFoodInMap(indexX + 1, indexY) == CName::SPACE && mapRecord->GetMonsterInMap(indexX + 1, indexY) != CName::INVINCIBLE_TURTLE) || movingRightCount != 0)
					{
						x += STEP_SIZE_X;
						movingRightCount++;
						mapRecord->SetBrickInMap(indexX + 1, indexY, CName::STONE);
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
										}
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
						isMovingRight = false;
						Hit();
					}
				}
				else if (isMovingUp)
				{
					if ((mapRecord->GetBrickInMap(indexX, indexY - 1) == CName::SPACE && mapRecord->GetFoodInMap(indexX, indexY - 1) == CName::SPACE && mapRecord->GetMonsterInMap(indexX, indexY - 1) != CName::INVINCIBLE_TURTLE) || movingUpCount != 0)
					{
						y -= STEP_SIZE_Y;
						movingUpCount++;
						mapRecord->SetBrickInMap(indexX, indexY - 1, CName::STONE);
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
										}
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
						isMovingUp = false;
						Hit();
					}
				}
				else if (isMovingDown)
				{
					if ((mapRecord->GetBrickInMap(indexX, indexY + 1) == CName::SPACE && mapRecord->GetFoodInMap(indexX, indexY + 1) == CName::SPACE && mapRecord->GetMonsterInMap(indexX, indexY + 1) != CName::INVINCIBLE_TURTLE) || movingDownCount != 0)
					{
						y += STEP_SIZE_Y;
						movingDownCount++;
						mapRecord->SetBrickInMap(indexX, indexY + 1, CName::STONE);
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
										}
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
						isMovingDown = false;
						Hit();
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

	void CBrick::Hit()
	{
		if (type == CName::WOODEN)
		{
			mapRecord->SetBrickInMap(indexX, indexY, CName::SPACE);
			isAlive = false;
		}
		else if (type == CName::STONE || type == CName::STEEL)
		{
			isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
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
			bitmap.SetTopLeft(x, y - 12);
			bitmap.ShowBitmap();
		}
	}
}