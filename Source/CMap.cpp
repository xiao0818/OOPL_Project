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
		brickNumberX = 0;
		brickNumberY = 0;
		playerIndexX = 0;
		playerIndexY = 0;
		undeleteFlag = false;
	}

	CMap::~CMap()
	{
		if (undeleteFlag)
		{
			DeleteMap();
		}
	}

	int CMap::GetBrickNumberX()
	{
		return brickNumberX;
	}

	int CMap::GetBrickNumberY()
	{
		return brickNumberY;
	}

	void CMap::SelectLevel(int levelNumber)
	{
		level = levelNumber;
		brickNumberX = levelBrickNumberX[level - 1];
		brickNumberY = levelBrickNumberY[level - 1];

		undeleteFlag = true;

		map = new CName *[brickNumberX];
		playerMap = new CName *[brickNumberX];
		trapMap = new CName *[brickNumberX];
		brickMap = new CName *[brickNumberX];
		foodMap = new CName *[brickNumberX];
		monsterMap = new CName *[brickNumberX];
		sidewallMap = new CName *[brickNumberX];
		for (int i = 0; i < brickNumberX; i++)
		{
			map[i] = new CName[brickNumberY];
			playerMap[i] = new CName [brickNumberY];
			trapMap[i] = new CName [brickNumberY];
			brickMap[i] = new CName [brickNumberY];
			foodMap[i] = new CName[brickNumberY];
			monsterMap[i] = new CName [brickNumberY];
			sidewallMap[i] = new CName [brickNumberY];

		}

		for (int i = 0; i < brickNumberX; i++)
		{
			for (int j = 0; j < brickNumberY; j++)
			{
				map[i][j] = mapInitLevel[level - 1][j][i];
			}
		}
	}

	void CMap::Initialize()
	{
		for (int i = 0; i < brickNumberX; i++)
		{
			for (int j = 0; j < brickNumberY; j++)
			{
				playerMap[i][j] = CName::SPACE;
				trapMap[i][j] = CName::SPACE;
				brickMap[i][j] = CName::SPACE;
				foodMap[i][j] = CName::SPACE;
				monsterMap[i][j] = CName::SPACE;
				sidewallMap[i][j] = CName::SPACE;

				if (map[i][j] == CName::PLAYER1 || map[i][j] == CName::PLAYER2)
				{
					playerMap[i][j] = map[i][j];
					playerIndexX = i;
					playerIndexY = j;
				}
				else if (map[i][j] == CName::SPIKE || map[i][j] == CName::MUCUS || map[i][j] == CName::MOVING || map[i][j] == CName::STEPPING)
				{
					trapMap[i][j] = map[i][j];
				}
				else if (map[i][j] == CName::WALL || map[i][j] == CName::STONE || map[i][j] == CName::WOODEN || map[i][j] == CName::STEEL || map[i][j] == CName::SLIME || map[i][j] == CName::BOMB)
				{
					brickMap[i][j] = map[i][j];
				}
				else if (map[i][j] == CName::APPLE || map[i][j] == CName::BREAD || map[i][j] == CName::CARROT || map[i][j] == CName::EGG || map[i][j] == CName::GRAPE || map[i][j] == CName::MUTTON || map[i][j] == CName::PIE || map[i][j] == CName::TOMATO || map[i][j] == CName::TURKEY)
				{
					foodMap[i][j] = map[i][j];
				}
				else if (map[i][j] == CName::MUD || map[i][j] == CName::TURTLE || map[i][j] == CName::SKELETON || map[i][j] == CName::FISH_MAN)
				{
					monsterMap[i][j] = map[i][j];
				}
				if (i == 0 || j == 0 || i == brickNumberX - 1 || j == brickNumberY - 1) {
					sidewallMap[i][j] = map[i][j];
				}
			}
		}
	}

	void CMap::DeleteMap()
	{
		for (int i = 0; i < brickNumberX; i++)
		{
			delete [] map[i];
			delete [] playerMap[i];
			delete [] trapMap[i];
			delete [] brickMap[i];
			delete [] foodMap[i];
			delete [] monsterMap[i];
			delete [] sidewallMap[i];
		}
		delete [] map;
		delete [] playerMap;
		delete [] trapMap;
		delete [] brickMap;
		delete [] foodMap;
		delete [] monsterMap;
		delete [] sidewallMap;

		undeleteFlag = false;
	}

	void CMap::SetPlayerInMap(int nx, int ny, CName name)
	{
		playerMap[nx][ny] = name;
		if (name == CName::PLAYER) {
			playerIndexX = nx;
			playerIndexY = ny;
		}
	}

	CName CMap::GetPlayerInMap(int nx, int ny)
	{
		return playerMap[nx][ny];
	}

	void CMap::SetTrapInMap(int nx, int ny, CName name)
	{
		trapMap[nx][ny] = name;
	}

	CName CMap::GetTrapInMap(int nx, int ny)
	{
		return trapMap[nx][ny];
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

	CName CMap::GetSidewallInMap(int nx, int ny)
	{
		return sidewallMap[nx][ny];
	}
}