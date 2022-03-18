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
	}

	int CPlayer::GetX1()
	{
		return x;
	}

	int CPlayer::GetY1()
	{
		return y;
	}

	int CPlayer::GetX2()
	{
		return x + animation.Width();
	}

	int CPlayer::GetY2()
	{
		return y + animation.Height();
	}

	void CPlayer::Initialize(int **map)
	{
		mapRecord = map;
		for (int i = 0; i < 14; i++) {
			for (int j = 0; j < 14; j++) {
				if (mapRecord[i][j] == 2) {
					indexX = i;
					indexY = j;
					break;
				}
			}
		}
	}

	void CPlayer::LoadBitmap()
	{
		animation.AddBitmap(IDB_PLAYER, RGB(0, 0, 0));
	}

	void CPlayer::OnMove()
	{
		const int STEP_SIZE = 2;
		animation.OnMove();
		if (isMovingLeft && mapRecord[indexX - 1][indexY] == 0) {
			x -= STEP_SIZE;
			moveCountForLeft++;
			if (moveCountForLeft == 36) {
				mapRecord[indexX][indexY] = 0;
				mapRecord[--indexX][indexY] = 2;
				moveCountForLeft = 0;
			}
		}
		if (isMovingRight && mapRecord[indexX + 1][indexY] == 0) {
			x += STEP_SIZE;
			moveCountForRight++;
			if (moveCountForRight == 36) {
				mapRecord[indexX][indexY] = 0;
				mapRecord[++indexX][indexY] = 2;
				moveCountForRight = 0;
			}
		}
		if (isMovingUp && mapRecord[indexX][indexY - 1] == 0)	{
			y -= STEP_SIZE;
			moveCountForUp++;
			if (moveCountForUp == 23) {
				mapRecord[indexX][indexY] = 0;
				mapRecord[indexX][--indexY] = 2;
				moveCountForUp = 0;
			}
		}
		if (isMovingDown && mapRecord[indexX][indexY + 1] == 0) {
			y += STEP_SIZE;
			moveCountForDown++;
			if (moveCountForDown == 23) {
				mapRecord[indexX][indexY] = 0;
				mapRecord[indexX][++indexY] = 2;
				moveCountForDown = 0;
			}
		}
	}

	void CPlayer::SetMovingLeft(bool flag)
	{
		isMovingLeft = flag;
	}

	void CPlayer::SetMovingRight(bool flag)
	{
		isMovingRight = flag;
	}

	void CPlayer::SetMovingUp(bool flag)
	{
		isMovingUp = flag;
	}

	void CPlayer::SetMovingDown(bool flag)
	{
		isMovingDown = flag;
	}

	void CPlayer::SetXY(int nx, int ny)
	{
		x = nx + (72 / 2) - (animation.Width() / 2);
		y = ny + 46 - animation.Height();
	}

	void CPlayer::OnShow()
	{
		animation.SetTopLeft(x, y);
		animation.OnShow();
	}
}