#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CMap.h"

namespace game_framework {
	CMap::CMap()
	{
		CName map_init[14][14] = { {CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL},
								{CName::WALL, CName::MUD, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::SPACE, CName::WOODEN, CName::WOODEN, CName::WOODEN, CName::WOODEN, CName::WOODEN, CName::WOODEN, CName::WOODEN, CName::WOODEN, CName::SPACE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::WALL, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::WALL, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::WALL, CName::SPACE, CName::SPACE, CName::STONE, CName::SPACE, CName::SPACE, CName::STONE, CName::SPACE, CName::SPACE, CName::WALL, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::STONE, CName::SPACE, CName::SPACE, CName::STONE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::STEEL, CName::STEEL, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::STEEL, CName::STEEL, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::PLAYER, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::STONE, CName::SPACE, CName::SPACE, CName::STONE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::WALL, CName::SPACE, CName::SPACE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::SPACE, CName::SPACE, CName::WALL, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::WALL, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::WALL, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::SPACE, CName::WOODEN, CName::WOODEN, CName::WOODEN, CName::WOODEN, CName::WOODEN, CName::WOODEN, CName::WOODEN, CName::WOODEN, CName::SPACE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL} };

		map = new CName *[14];
		for (int i = 0; i < 14; i++)
		{
			map[i] = new CName[14];
		}
		for (int i = 0; i < 14; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				map[i][j] = map_init[j][i];
			}
		}
	}

	void CMap::SetCNameInMap(int nx, int ny, CName name)
	{
		map[nx][ny] = name;
	}

	CName CMap::GetCNameInMap(int nx, int ny)
	{
		return map[nx][ny];
	}
}