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
		movingCount = 0;
		faceTo = DOWN;
		leftAnimation.SetDelayCount(2);
		rightAnimation.SetDelayCount(2);
		upAnimation.SetDelayCount(2);
		downAnimation.SetDelayCount(2);
		leftWithFullAnimation.SetDelayCount(2);
		rightWithFullAnimation.SetDelayCount(2);
		upWithFullAnimation.SetDelayCount(2);
		downWithFullAnimation.SetDelayCount(2);
		isSwallowed = false;
	}

	int CPlayer::GetIndexX() {
		return indexX;
	}

	int CPlayer::GetIndexY() {
		return indexY;
	}

	void CPlayer::Initialize(int **map)
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
	}

	void CPlayer::OnMove()
	{
		const int STEP_TARGET = 8;
		const int STEP_SIZE_X = 9;
		const int STEP_SIZE_Y = 6;
		
		if (!isMovingLeft && !isMovingRight && !isMovingUp && !isMovingDown)
		{
			if (isKeyLeftPressed)
			{
				if (faceTo != LEFT)
				{
					faceTo = LEFT;
				}
				else
				{
					movingCount = 0;
					isMovingLeft = true;
				}
			}
			else if (isKeyRightPressed)
			{
				if (faceTo != RIGHT)
				{
					faceTo = RIGHT;
				}
				else
				{
					movingCount = 0;
					isMovingRight = true;
				}
			}
			else if (isKeyUpPressed)
			{
				if (faceTo != UP)
				{
					faceTo = UP;
				}
				else
				{
					movingCount = 0;
					isMovingUp = true;
				}
			}
			else if (isKeyDownPressed)
			{
				if (faceTo != DOWN)
				{
					faceTo = DOWN;
				}
				else
				{
					movingCount = 0;
					isMovingDown = true;
				}
			}
		}

		if (isMovingLeft)
		{
			if (mapRecord[indexX - 1][indexY] == 0)
			{
				leftAnimation.OnMove();
				leftWithFullAnimation.OnMove();
				x -= STEP_SIZE_X;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = 0;
					mapRecord[--indexX][indexY] = 1;
					movingCount = 0;
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
			if (mapRecord[indexX + 1][indexY] == 0)
			{
				rightAnimation.OnMove();
				rightWithFullAnimation.OnMove();
				x += STEP_SIZE_X;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = 0;
					mapRecord[++indexX][indexY] = 1;
					movingCount = 0;
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
			if (mapRecord[indexX][indexY - 1] == 0)
			{
				upAnimation.OnMove();
				upWithFullAnimation.OnMove();
				y -= STEP_SIZE_Y;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = 0;
					mapRecord[indexX][--indexY] = 1;
					movingCount = 0;
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
			if (mapRecord[indexX][indexY + 1] == 0)
			{
				downAnimation.OnMove();
				downWithFullAnimation.OnMove();
				y += STEP_SIZE_Y;
				movingCount++;
				if (movingCount == STEP_TARGET)
				{
					mapRecord[indexX][indexY] = 0;
					mapRecord[indexX][++indexY] = 1;
					movingCount = 0;
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

	void CPlayer::PressKeySpace(list<CStoneBrick> &stoneBrick)
	{
		if (!isMovingLeft && !isMovingRight && !isMovingUp && !isMovingDown)
		{
			if (isSwallowed == false)
			{
				if (faceTo == LEFT)
				{
					for (list<CStoneBrick>::iterator k = stoneBrick.begin(); k != stoneBrick.end(); k++)
					{
						if (k->GetIndexX() == indexX - 1 && k->GetIndexY() == indexY)
						{
							k->setAlive(false);
							mapRecord[k->GetIndexX()][k->GetIndexY()] = 0;
							swallowedBrick = k;
							isSwallowed = true;
						}
					}
				}
				else if (faceTo == RIGHT)
				{
					for (list<CStoneBrick>::iterator k = stoneBrick.begin(); k != stoneBrick.end(); k++)
					{
						if (k->GetIndexX() == indexX + 1 && k->GetIndexY() == indexY)
						{
							k->setAlive(false);
							mapRecord[k->GetIndexX()][k->GetIndexY()] = 0;
							swallowedBrick = k;
							isSwallowed = true;
						}
					}
				}
				else if (faceTo == UP)
				{
					for (list<CStoneBrick>::iterator k = stoneBrick.begin(); k != stoneBrick.end(); k++)
					{
						if (k->GetIndexX() == indexX && k->GetIndexY() == indexY - 1)
						{
							k->setAlive(false);
							mapRecord[k->GetIndexX()][k->GetIndexY()] = 0;
							swallowedBrick = k;
							isSwallowed = true;
						}
					}
				}
				else if (faceTo == DOWN)
				{
					for (list<CStoneBrick>::iterator k = stoneBrick.begin(); k != stoneBrick.end(); k++)
					{
						if (k->GetIndexX() == indexX && k->GetIndexY() == indexY + 1)
						{
							k->setAlive(false);
							mapRecord[k->GetIndexX()][k->GetIndexY()] = 0;
							swallowedBrick = k;
							isSwallowed = true;
						}
					}
				}
			}
			else if (isSwallowed == true)
			{
				if (faceTo == LEFT)
				{
					if (mapRecord[indexX - 1][indexY] == 0)
					{
						mapRecord[indexX - 1][indexY] = 3;
						swallowedBrick->SetXY(indexX - 1, indexY, x - 72, y);
						swallowedBrick->setAlive(true);
						isSwallowed = false;
					}
				}
				else if (faceTo == RIGHT)
				{
					if (mapRecord[indexX + 1][indexY] == 0)
					{
						mapRecord[indexX + 1][indexY] = 3;
						swallowedBrick->SetXY(indexX + 1, indexY, x + 72, y);
						swallowedBrick->setAlive(true);
						isSwallowed = false;
					}
				}
				else if (faceTo == UP)
				{
					if (mapRecord[indexX][indexY - 1] == 0)
					{
						mapRecord[indexX][indexY - 1] = 3;
						swallowedBrick->SetXY(indexX, indexY - 1, x, y - 48);
						swallowedBrick->setAlive(true);
						isSwallowed = false;
					}
				}
				else if (faceTo == DOWN)
				{
					if (mapRecord[indexX][indexY + 1] == 0)
					{
						mapRecord[indexX][indexY + 1] = 3;
						swallowedBrick->SetXY(indexX, indexY + 1, x, y + 48);
						swallowedBrick->setAlive(true);
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
		if (!isSwallowed)
		{
			if (faceTo == LEFT)
			{
				if (!isMovingLeft)
				{
					leftAnimation.Reset();
				}
				leftAnimation.SetTopLeft(x + (72 / 2) - (leftAnimation.Width() / 2), y + 46 - leftAnimation.Height());
				leftAnimation.OnShow();
			}
			else if (faceTo == RIGHT)
			{
				if (!isMovingRight)
				{
					rightAnimation.Reset();
				}
				rightAnimation.SetTopLeft(x + (72 / 2) - (rightAnimation.Width() / 2), y + 46 - rightAnimation.Height());
				rightAnimation.OnShow();
			}
			else if (faceTo == UP)
			{
				if (!isMovingUp)
				{
					upAnimation.Reset();
				}
				upAnimation.SetTopLeft(x + (72 / 2) - (upAnimation.Width() / 2), y + 46 - upAnimation.Height());
				upAnimation.OnShow();
			}
			else if (faceTo == DOWN)
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
			if (faceTo == LEFT)
			{
				if (!isMovingLeft)
				{
					leftWithFullAnimation.Reset();
				}
				leftWithFullAnimation.SetTopLeft(x + (72 / 2) - (leftWithFullAnimation.Width() / 2), y + 46 - leftWithFullAnimation.Height());
				leftWithFullAnimation.OnShow();
			}
			else if (faceTo == RIGHT)
			{
				if (!isMovingRight)
				{
					rightWithFullAnimation.Reset();
				}
				rightWithFullAnimation.SetTopLeft(x + (72 / 2) - (rightWithFullAnimation.Width() / 2), y + 46 - rightWithFullAnimation.Height());
				rightWithFullAnimation.OnShow();
			}
			else if (faceTo == UP)
			{
				if (!isMovingUp)
				{
					upWithFullAnimation.Reset();
				}
				upWithFullAnimation.SetTopLeft(x + (72 / 2) - (upWithFullAnimation.Width() / 2), y + 46 - upWithFullAnimation.Height());
				upWithFullAnimation.OnShow();
			}
			else if (faceTo == DOWN)
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