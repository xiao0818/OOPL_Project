#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CWall.h"
#include "CGround.h"

namespace game_framework {
	CGround::CGround()
	{
		x = y = 0;
		brickNumberX = brickNumberY = 0;
		brickLength = 72;
		brickWidth = 48;
	}

	void CGround::LoadBitmap()
	{
		ground.LoadBitmap(IDB_GROUND);
	}

	void CGround::Initialize(int nx, int ny)
	{
		brickNumberX = nx;
		brickNumberY = ny;
	}

	void CGround::SetXY(int nx, int ny)
	{
		x = nx;
		y = ny;
	}

	void CGround::OnShow()
	{
		for (int i = 0; i < brickNumberY; i++)
		{
			for (int j = 0; j < brickNumberX; j++)
			{
				ground.SetTopLeft(x + brickLength * j, y + brickWidth * i);
				ground.ShowBitmap();
			}
		}
	}
}