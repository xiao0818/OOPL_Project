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
		bool IsFood();
		bool IsHit();
		bool IsAlive();
		bool IsInvincible();
		void Initialize(CMap *map, CShareData *shareData);
		virtual void LoadBitmap();
		void OnMove();
		void SetTypeFlag(CName name);
		CDirection RandomDirection();
		CDirection GetNewMovingDirection();
		void HitByBrick(CDirection tempDir);
		void Swallowed(CDirection faceTo);
		void SetAlive(bool flag);
		void SetInvincible();
		void ChangeRushStatus();
		void SetXY(int ni, int nj, int nx, int ny);
		void OnShow();
	protected:
		CAnimation leftAnimation;
		CAnimation rightAnimation;
		CAnimation upAnimation;
		CAnimation downAnimation;
		CAnimation hitLeftAnimation;
		CAnimation hitRightAnimation;
		CAnimation hitUpAnimation;
		CAnimation hitDownAnimation;
		CAnimation rushLeftAnimation;
		CAnimation rushRightAnimation;
		CAnimation rushUpAnimation;
		CAnimation rushDownAnimation;
		CMovingBitmap invincibleRight;
		CMovingBitmap invincibleLeft;
		CMovingBitmap invincibleUp;
		CMovingBitmap invincibleDown;
		int indexX, indexY;
		double x, y;
		CName type;
		bool isInvincible;
		bool isMovingDown;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isHit;
		bool isFood;
		bool isSwallowed;
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
		bool isRush;
		CShareData *shareDataRecord;
	};
};

#endif
