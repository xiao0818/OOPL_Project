#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CWall.h"
#include "CMap.h"

namespace game_framework {
	CMap::CMap()
	{
		x = y = 0;
		brickLength = 72;
		brickWidth = 46;

		int map_init[14][14] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
								{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

		for (int i = 0; i < 14; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				map[i][j] = map_init[i][j];
			}
		}
	}

	void CMap::LoadBitmap()
	{
		ground.LoadBitmap(IDB_GROUND);
		wall.LoadBitmap();
	}

	void CMap::SetXY()
	{
		x = (SIZE_X - ground.Width() * 14) / 2;
		y = (SIZE_Y - ground.Height() * 14) / 2;
	}

	void CMap::OnShow()
	{
		for (int i = 0; i < 14; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				switch (map[i][j])
				{
					case 0:
						ground.SetTopLeft(x + brickLength * j, y + brickWidth * i);
						ground.ShowBitmap();
						break;
					case 1:
						wall.SetXY(x + brickLength * j, y + brickWidth * i);
						wall.OnShow();
						break;
					default:
						ASSERT(0);
				}
			}
		}
	}
}