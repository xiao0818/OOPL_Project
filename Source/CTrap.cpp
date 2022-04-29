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

	bool CTrap::IsAggressive()
	{
		return isAggressive;
	}

	void CTrap::Initialize(CMap *map)
	{
	}

	void CTrap::LoadBitmap()
	{
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
		animation.SetTopLeft(x, y);
		animation.OnShow();
	}
}