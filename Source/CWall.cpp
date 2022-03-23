#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CWall.h"

namespace game_framework {
	CWall::CWall()
	{
		x = y = 0;
	}

	int CWall::GetIndexX() {
		return indexX;
	}

	int CWall::GetIndexY() {
		return indexY;
	}

	void CWall::LoadBitmap()
	{
		bitmap.LoadBitmap(IDB_WALL);
		//bitmap.LoadBitmap(IDB_WALL, RGB(0, 0, 0));
	}

	void CWall::SetXY(int ni, int nj, int nx, int ny)
	{
		indexX = ni;
		indexY = nj;
		x = nx;
		y = ny - 23;
	}

	void CWall::OnShow()
	{
		bitmap.SetTopLeft(x, y);
		bitmap.ShowBitmap();
	}
}