#ifndef CTRAP_H
#define CTRAP_H

#include "CName.h"
#include "CDirection.h"
#include "CMap.h"

namespace game_framework {
	class CTrap
	{
	public:
		CTrap();
		int  GetIndexX();
		int  GetIndexY();
		void Initialize(CMap *map);
		bool IsAlive();
		virtual void LoadBitmap(CName name);
		void OnMove();
		void SetXY(int ni, int nj, int nx, int ny);
		void OnShow();
	protected:
		CMovingBitmap bitmap;
		int indexX, indexY;
		int x, y;
		CMap *mapRecord;
	};
}

#endif