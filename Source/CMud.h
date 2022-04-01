#ifndef CMUD_H
#define CMUD_H

#include "CDirection.h"
#include "CName.h"

namespace game_framework {
	class CMud
	{
	public:
		CMud();
		int  GetIndexX();
		int  GetIndexY();
		void Initialize(CName **map);
		void LoadBitmap();
		void OnMove();
		CDirection SetMovingDirection();
		void SetXY(int ni, int nj, int nx, int ny);
		void OnShow();
	protected:
		CAnimation leftAnimation;
		CAnimation rightAnimation;
		CAnimation upAnimation;
		CAnimation downAnimation;
		// CAnimation eatLeftAnimation;
		// CAnimation eatRightAnimation;
		// CAnimation eatUpAnimation;
		// CAnimation eatDownAnimation;
		int indexX, indexY;
		int x, y;
		bool isMovingDown;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isHit;
		bool isFood;
		int foodTime;
		int movingCount;
		CName **mapRecord;
		CDirection faceTo;
	};
}

#endif