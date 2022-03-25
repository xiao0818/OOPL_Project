#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CStoneBrick.h"

namespace game_framework {
	CStoneBrick::CStoneBrick()
	{
		x = y = 0;
		isAlive = true;
	}

	int CStoneBrick::GetIndexX() {
		return indexX;
	}

	int CStoneBrick::GetIndexY() {
		return indexY;
	}

	void CStoneBrick::LoadBitmap()
	{
		bitmap.LoadBitmap(IDB_STONE_BRICK);
	}

	void CStoneBrick::SetXY(int ni, int nj, int nx, int ny)
	{
		indexX = ni;
		indexY = nj;
		x = nx;
		y = ny;
	}

	void CStoneBrick::setAlive(bool flag)
	{
		isAlive = flag;
	}

	void CStoneBrick::OnShow()
	{
		if (isAlive) {
			bitmap.SetTopLeft(x, y - 24);
			bitmap.ShowBitmap();
		}
	}
}