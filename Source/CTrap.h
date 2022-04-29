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
		bool IsAggressive();
		virtual void Initialize(CMap *map);
		virtual void LoadBitmap();
		void OnMove();
		void SetXY(int ni, int nj, int nx, int ny);
		void OnShow();
	protected:
		CAnimation animation;
		bool isAggressive;
		int indexX, indexY;
		int x, y;
		CMap *mapRecord;
	};
}

#endif