#ifndef CPLAYER_H
#define CPLAYER_H

#include "CName.h"
#include "CDirection.h"
#include "CStone.h"

namespace game_framework {
	class CPlayer
	{
	public:
		CPlayer();
		int  GetIndexX();
		int  GetIndexY();
		void Initialize(CName **map);
		void LoadBitmap();
		void OnMove();
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetMovingUp(bool flag);
		void SetMovingDown(bool flag);
		void PressKeySpace(list<CStone> &Stone);
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
		int movingCount;
		CName **mapRecord;
		CDirection faceTo;
		list<CStone>::iterator swallowedBrick;
		bool isSwallowed;
		bool isEating;
	};
}

#endif