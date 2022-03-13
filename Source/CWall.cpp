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

	void CWall::LoadBitmap()
	{
		bitmap.LoadBitmap(IDB_WALL, RGB(0, 0, 0));
	}

	void CWall::SetXY(int nx, int ny)
	{
		x = nx - 1;
		y = ny - 26;
	}

	void CWall::OnShow()
	{
		bitmap.SetTopLeft(x, y);
		bitmap.ShowBitmap();
	}
}