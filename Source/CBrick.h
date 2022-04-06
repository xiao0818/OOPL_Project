#ifndef CBRICK_H
#define CBRICK_H

#include "CName.h"
#include "CDirection.h"
#include "CMap.h"
#include "CMud.h"

namespace game_framework {
	class CBrick
	{
	public:
		CBrick();
		int  GetIndexX();
		int  GetIndexY();
		bool IsMove();
		void Initialize(CMap *map, CMud *mud);
		virtual void LoadBitmap();
		void OnMove();
		void SpitedOut(CDirection faceTo, int ni, int nj, int nx, int ny);
		void SetXY(int ni, int nj, int nx, int ny);
		void Swallowed(CDirection faceTo);
		void OnShow();
	protected:
		CMovingBitmap bitmap;
		int indexX, indexY;
		int x, y;
		CMap *mapRecord;
		CMud *mudRecord;
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