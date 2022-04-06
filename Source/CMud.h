#ifndef CMUD_H
#define CMUD_H

#include "CDirection.h"
#include "CName.h"
#include "CMap.h"

namespace game_framework {
	class CMud
	{
	public:
		CMud();
		int  GetIndexX();
		int  GetIndexY();
		bool IsFood();
		bool IsAlive();
		void Initialize(CMap *map);
		void LoadBitmap();
		void OnMove();
		CDirection SetMovingDirection();
		void SetXY(int ni, int nj, int nx, int ny);
		void OnShow();
		void HitByBrick(CDirection tempDir);
		void ReturnBack();
		void Swallowed();
	protected:
		CAnimation leftAnimation;
		CAnimation rightAnimation;
		CAnimation upAnimation;
		CAnimation downAnimation;
		CAnimation hitLeftAnimation;
		CAnimation hitRightAnimation;
		CAnimation hitUpAnimation;
		CAnimation hitDownAnimation;
		int indexX, indexY;
		int x, y;
		bool isMovingDown;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isHit;
		bool isFood;
		int foodTime;
		int movingLeftCount;
		int movingRightCount;
		int movingUpCount;
		int movingDownCount;
		int hitCount;
		CMap *mapRecord;
		CDirection faceTo;
		bool isAlive;
	};
}

#endif