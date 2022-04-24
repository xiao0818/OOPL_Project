#ifndef CBRICK_H
#define CBRICK_H

#include "CName.h"
#include "CDirection.h"
#include "CMap.h"
#include "CMonster.h"

namespace game_framework {
	class CBrick
	{
	public:
		CBrick();
		int  GetIndexX();
		int  GetIndexY();
		bool IsMove();
		void Initialize(CMap *map, list<CMonster> *monster);
		virtual void LoadBitmap();
		virtual void SetStep();
		void SetTypeFlag(CName name);
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
		list<CMonster> *monsterRecord;
		CName type;
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
		int STEP_TARGET;
		int STEP_SIZE_X;
		int STEP_SIZE_Y;
	};
}

#endif