#ifndef CFOOD_H
#define CFOOD_H

#include "CName.h"
#include "CDirection.h"
#include "CMap.h"

namespace game_framework {
	class CFood
	{
	public:
		CFood();
		int  GetIndexX();
		int  GetIndexY();
		void Initialize(CMap *map);
		bool IsAlive();
		void LoadBitmap(CName name);
		void OnMove();
		void SetXY(int ni, int nj, int nx, int ny);
		void Swallowed(CDirection faceTo);
		void OnShow();
	protected:
		CMovingBitmap bitmap;
		int indexX, indexY;
		double x, y;
		CMap *mapRecord;
		bool isMovingDown;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		int movingLeftCount;
		int movingRightCount;
		int movingUpCount;
		int movingDownCount;
		bool isAlive;
		bool isSwallowed;
	};
}

#endif