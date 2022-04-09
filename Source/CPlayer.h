#ifndef CPLAYER_H
#define CPLAYER_H

#include "CName.h"
#include "CDirection.h"
#include "CMap.h"
#include "CBrick.h"
#include "CFood.h"

namespace game_framework {
	class CPlayer
	{
	public:
		CPlayer();
		int  GetIndexX();
		int  GetIndexY();
		void Initialize(CMap *map);
		void LoadBitmap();
		void OnMove();
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetMovingUp(bool flag);
		void SetMovingDown(bool flag);
		void PressKeySpace(list<CBrick> &brick, list<CFood> &food, CMud *mud);
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
		CDirection faceTo;
		list<CBrick>::iterator swallowedBrick;
		bool isSwallowed;
		bool isEating;
	};
}

#endif