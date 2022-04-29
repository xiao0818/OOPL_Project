#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CTrap.h"

namespace game_framework {
	CTrap::CTrap()
	{
		x = y = 0;
	}

	int CTrap::GetIndexX()
	{
		return indexX;
	}

	int CTrap::GetIndexY()
	{
		return indexY;
	}

	void CTrap::Initialize(CMap *map)
	{
		mapRecord = map;
	}

	void CTrap::LoadBitmap(CName name)
	{
		bitmap.LoadBitmap(IDB_SPIKE);
	}

	void CTrap::OnMove()
	{
	}

	void CTrap::SetXY(int ni, int nj, int nx, int ny)
	{
		indexX = ni;
		indexY = nj;
		x = nx;
		y = ny;
	}

	void CTrap::OnShow()
	{
		bitmap.SetTopLeft(x, y);
		bitmap.ShowBitmap();
	}
}