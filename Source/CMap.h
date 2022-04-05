#ifndef CMAP_H
#define CMAP_H

#include "CName.h"

namespace game_framework {
	class CMap
	{
	public:
		CMap();
		~CMap();
		void SetPlayerInMap(int nx, int ny, CName name);
		CName GetPlayerInMap(int nx, int ny);
		void SetBrickInMap(int nx, int ny, CName name);
		CName GetBrickInMap(int nx, int ny);
		void SetMonsterInMap(int nx, int ny, CName name);
		CName GetMonsterInMap(int nx, int ny);
	private:
		CName playerMap[14][14];
		CName brickMap[14][14];
		CName monsterMap[14][14];
	};
}

#endif