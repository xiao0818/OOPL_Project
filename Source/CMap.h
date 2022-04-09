#ifndef CMAP_H
#define CMAP_H

#include "CName.h"

namespace game_framework {
	class CMap
	{
	public:
		CMap();
		void Initialize();
		void SetPlayerInMap(int nx, int ny, CName name);
		CName GetPlayerInMap(int nx, int ny);
		void SetBrickInMap(int nx, int ny, CName name);
		CName GetBrickInMap(int nx, int ny);
		void SetFoodInMap(int nx, int ny, CName name);
		CName GetFoodInMap(int nx, int ny);
		void SetMonsterInMap(int nx, int ny, CName name);
		CName GetMonsterInMap(int nx, int ny);
	private:
		CName map[14][14];
		CName playerMap[14][14];
		CName brickMap[14][14];
		CName foodMap[14][14];
		CName monsterMap[14][14];
	};
}

#endif