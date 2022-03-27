#ifndef CPLAYER_H
#define CPLAYER_H

#include "CStoneBrick.h"

namespace game_framework {
	class CPlayer
	{
	public:
		CPlayer();
		int  GetIndexX();
		int  GetIndexY();
		void Initialize(int **map);
		void LoadBitmap();
		void OnMove();
		void OnShow();
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetMovingUp(bool flag);
		void SetMovingDown(bool flag);
		void PressKeySpace(list<CStoneBrick> &stoneBrick);
		void SetXY(int ni, int nj, int nx, int ny);
	protected:
		CAnimation leftAnimation;
		CAnimation rightAnimation;
		CAnimation upAnimation;
		CAnimation downAnimation;
		CAnimation leftWithFullAnimation;
		CAnimation rightWithFullAnimation;
		CAnimation upWithFullAnimation;
		CAnimation downWithFullAnimation;
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
		int **mapRecord;
		string faceTo;
		string LEFT = "LEFT";
		string RIGHT = "RIGHT";
		string UP = "UP";
		string DOWN = "DOWN";
		list<CStoneBrick>::iterator swallowedBrick;
		bool isSwallowed;
	};
}

#endif