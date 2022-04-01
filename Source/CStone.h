#ifndef CSTONE_H
#define CSTONE_H

#include "CName.h"
#include "CDirection.h"

namespace game_framework {
	class CStone
	{
	public:
		CStone();
		int  GetIndexX();
		int  GetIndexY();
		bool IsMove();
		void Initialize(CName **map);
		void LoadBitmap();
		void OnMove();
		void SpitedOut(CDirection faceTo, int ni, int nj, int nx, int ny);
		void SetXY(int ni, int nj, int nx, int ny);
		void Swallowed(CDirection faceTo);
		void OnShow();
	protected:
		CMovingBitmap bitmap;
		int indexX, indexY;
		int x, y;
		CName **mapRecord;
		bool isMovingDown;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		int movingCount;
		bool isAlive;
		bool isSwallowed;
	};
}

#endif