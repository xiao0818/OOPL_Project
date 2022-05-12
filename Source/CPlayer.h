#ifndef CPLAYER_H
#define CPLAYER_H

#include "CName.h"
#include "CDirection.h"
#include "CMap.h"
#include "CTrap.h"
#include "CBrick.h"
#include "CFood.h"
#include "CMonster.h"

namespace game_framework {
	class CPlayer
	{
	public:
		CPlayer();
		int  GetIndexX();
		int  GetIndexY();
		bool IsSuccess();
		bool IsFail();
		void Fail();
		void Success();
		void Initialize(CMap *map, CShareData *shareData, list<CTrap> *trap, list<CBrick> *brick, list<CFood> *food, list<CMonster> *monster);
		void LoadBitmap();
		void OnMove();
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetMovingUp(bool flag);
		void SetMovingDown(bool flag);
		void PressKeySpace();
		void SetXY(int ni, int nj, int nx, int ny);
		void OnShow();
	protected:
		CAnimation leftAnimation;
		CAnimation rightAnimation;
		CAnimation upAnimation;
		CAnimation downAnimation;
		CAnimation leftWithFullAnimation;
		CAnimation rightWithFullAnimation;
		CAnimation upWithFullAnimation;
		CAnimation downWithFullAnimation;
		CAnimation eatLeftAnimation;
		CAnimation eatRightAnimation;
		CAnimation eatUpAnimation;
		CAnimation eatDownAnimation;
		CAnimation successAnimation;
		CAnimation failAnimation;
		int indexX, indexY;
		int x, y;
		bool isMovingDown;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isKeyDownPressed;
		bool isKeyLeftPressed;
		bool isKeyRightPressed;
		bool isKeyUpPressed;
		int movingLeftCount;
		int movingRightCount;
		int movingUpCount;
		int movingDownCount;
		CMap *mapRecord;
		CShareData *shareDataRecord;
		list<CTrap> *trapRecord;
		list<CBrick> *brickRecord;
		list<CFood> *foodRecord;
		list<CMonster> *monsterRecord;
		list<CBrick>::iterator swallowedBrick;
		CDirection faceTo;
		bool isOnMucus;
		bool isSwallowed;
		bool isEating;
		bool isSuccess;
		bool isFail;
	};
}

#endif