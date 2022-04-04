#ifndef CMAP_H
#define CMAP_H

#include "CName.h"

namespace game_framework {
	class CMap
	{
	public:
		CMap();
		void SetCNameInMap(int nx, int ny, CName name);
		CName GetCNameInMap(int nx, int ny);
	private:
		CName **map;
	};
}

#endif