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
								{CName::WALL, CName::SPACE, CName::SPACE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::SPACE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::WALL, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::WALL, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::WALL, CName::SPACE, CName::SPACE, CName::STONE, CName::SPACE, CName::SPACE, CName::STONE, CName::SPACE, CName::SPACE, CName::WALL, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::STONE, CName::SPACE, CName::SPACE, CName::STONE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::STONE, CName::STONE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::STONE, CName::STONE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::PLAYER, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::STONE, CName::SPACE, CName::SPACE, CName::STONE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::WALL, CName::SPACE, CName::SPACE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::SPACE, CName::SPACE, CName::WALL, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::WALL, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::WALL, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::SPACE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::SPACE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL} };

		for (int i = 0; i < 14; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				playerMap[i][j] = CName::SPACE;
				brickMap[i][j] = CName::SPACE;
				monsterMap[i][j] = CName::SPACE;

				if (map_init[j][i] == CName::PLAYER)
				{
					playerMap[i][j] = map_init[j][i];
				}
				else if (map_init[j][i] == CName::WALL || map_init[j][i] == CName::STONE || map_init[j][i] == CName::WOODEN || map_init[j][i] == CName::STEEL)
				{
					brickMap[i][j] = map_init[j][i];
				}
				else if (map_init[j][i] == CName::MUD)
				{
					monsterMap[i][j] = map_init[j][i];
				}
			}
		}
	}

	CMap::~CMap()
	{
	}

	void CMap::SetPlayerInMap(int nx, int ny, CName name)
	{
		playerMap[nx][ny] = name;
	}

	CName CMap::GetPlayerInMap(int nx, int ny)
	{
		return playerMap[nx][ny];
	}

	void CMap::SetBrickInMap(int nx, int ny, CName name)
	{
		brickMap[nx][ny] = name;
	}

	CName CMap::GetBrickInMap(int nx, int ny)
	{
		return brickMap[nx][ny];
	}

	void CMap::SetMonsterInMap(int nx, int ny, CName name)
	{
		monsterMap[nx][ny] = name;
	}

	CName CMap::GetMonsterInMap(int nx, int ny)
	{
		return monsterMap[nx][ny];
	}
}