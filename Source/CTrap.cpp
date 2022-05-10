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
		indexX = indexY = 0;
		isStepped = false;
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
		if (type == CName::MOVING)
		{
			animation.OnMove();
			if (animation.GetCurrentBitmapNumber() >= 4 && animation.GetCurrentBitmapNumber() <= 9)
			{
				isAggressive = true;
			}
			else
			{
				isAggressive = false;
			}
		}

		if (type == CName::STEPPING)
		{
			if (isStepped)
			{
				animation.OnMove();
				if (animation.GetCurrentBitmapNumber() >= 4 && animation.GetCurrentBitmapNumber() <= 9)
				{
					isAggressive = true;
				}
				else
				{
					isAggressive = false;
				}
				if (animation.GetCurrentBitmapNumber() == 0)
				{
					isStepped = false;
					animation.OnMove();
				}
			}
		}
	}

	void CTrap::SteppedByPlayer()
	{
		TRACE("asdf\n");
		isStepped = true;
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