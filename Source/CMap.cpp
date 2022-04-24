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
		CName mapInitLevel1[14][14] = { {CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL},
								{CName::WALL, CName::MUD, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::MUD, CName::WALL},
								{CName::WALL, CName::SPACE, CName::SPACE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::SPACE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::WALL, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::WALL, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::WALL, CName::SPACE, CName::SPACE, CName::STONE, CName::SPACE, CName::SPACE, CName::STONE, CName::SPACE, CName::SPACE, CName::WALL, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::STONE, CName::SPACE, CName::SPACE, CName::STONE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::STONE, CName::STONE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::STONE, CName::STONE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::BREAD, CName::SPACE, CName::SPACE, CName::SPACE, CName::PLAYER, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::APPLE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::STONE, CName::MUTTON, CName::SPACE, CName::STONE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::WALL, CName::MUD, CName::SPACE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::SPACE, CName::SPACE, CName::WALL, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::WALL, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::MUD, CName::WALL, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::SPACE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::STONE, CName::SPACE, CName::SPACE, CName::WALL},
								{CName::WALL, CName::SPACE, CName::SPACE, CName::TURTLE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::SPACE, CName::MUD, CName::WALL},
								{CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL, CName::WALL} };

		for (int i = 0; i < 14; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				map[i][j] = mapInitLevel1[i][j];
			}
		}
	}

	int CMap::GetBrickNumberX()
	{
		return 14;
	}

	int CMap::GetBrickNumberY()
	{
		return 14;
	}

	void CMap::SelectLevel(int levelNumber)
	{
		level = levelNumber;
	}

	void CMap::Initialize()
	{
		for (int i = 0; i < 14; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				playerMap[i][j] = CName::SPACE;
				brickMap[i][j] = CName::SPACE;
				foodMap[i][j] = CName::SPACE;
				monsterMap[i][j] = CName::SPACE;

				if (map[j][i] == CName::PLAYER)
				{
					playerMap[i][j] = map[j][i];
				}
				else if (map[j][i] == CName::WALL || map[j][i] == CName::STONE || map[j][i] == CName::WOODEN || map[j][i] == CName::STEEL)
				{
					brickMap[i][j] = map[j][i];
				}
				else if (map[j][i] == CName::APPLE || map[j][i] == CName::BREAD || map[j][i] == CName::CARROT || map[j][i] == CName::EGG || map[j][i] == CName::GRAPE || map[j][i] == CName::MUTTON || map[j][i] == CName::PIE || map[j][i] == CName::TOMATO || map[j][i] == CName::TURKEY)
				{
					foodMap[i][j] = map[j][i];
				}
				else if (map[j][i] == CName::MUD || map[j][i] == CName::TURTLE)
				{
					monsterMap[i][j] = map[j][i];
				}
			}
		}
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

	void CMap::SetFoodInMap(int nx, int ny, CName name)
	{
		foodMap[nx][ny] = name;
	}

	CName CMap::GetFoodInMap(int nx, int ny)
	{
		return foodMap[nx][ny];
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