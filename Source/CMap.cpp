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
		brickLength = 71;
		brickWidth = 44;

		int map_init[14][14] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
								{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
								{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
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
		background.LoadBitmap(IDB_GROUND_14_14);
		wall.LoadBitmap();
	}

	void CMap::SetXY()
	{
		x = (SIZE_X - background.Width()) / 2;
		y = (SIZE_Y - background.Height()) / 2;
	}

	void CMap::OnShow()
	{
		background.SetTopLeft(x, y);
		background.ShowBitmap();
		for (int i = 0; i < 14; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				switch (map[i][j])
				{
					case 0:
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