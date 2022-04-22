#ifndef CMONSTER_H
#define	CMONSTER_H

#include "CDirection.h"
#include "CMap.h"

namespace game_framework {
	class CMonster {
	public:
		CMonster();
		int  GetIndexX();
		int  GetIndexY();
		int  GetNextIndexX();
		int  GetNextIndexY();
		CName GetTypeFlag();
		bool IsFood();
		bool IsAlive();
		bool IsInvincible();
		void Initialize(CMap *map);
		virtual void LoadBitmap();
		void OnMove();
		virtual void SetTypeFlag();
		CDirection SetMovingDirection();
		void SetXY(int ni, int nj, int nx, int ny);
		void OnShow();
		void HitByBrick(CDirection tempDir);
		void ReturnBack();
		void Swallowed();
		void Reset();
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
		CName typeFlag;
		bool isInvincible;
		bool isMovingDown;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isHit;
		bool isFood;
		int foodTime;
		int invincibleTime;
		int movingLeftCount;
		int movingRightCount;
		int movingUpCount;
		int movingDownCount;
		int hitCount;
		CMap *mapRecord;
		CDirection faceTo;
		bool isAlive;
	};
};

#endif
