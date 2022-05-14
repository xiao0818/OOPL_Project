#ifndef CBRICK_H
#define CBRICK_H

#include "CName.h"
#include "CDirection.h"
#include "CMap.h"
#include "CBrick.h"
#include "CMonster.h"

namespace game_framework {
	class CBrick
	{
	public:
		CBrick();
		int  GetIndexX();
		int  GetIndexY();
		bool IsMove();
		bool IsAlive();
		virtual void Initialize(CMap *map, list<CBrick> *brick, list<CMonster> *monster);
		virtual void LoadBitmap();
		void OnMove();
		void SpitedOut(CDirection faceTo, int ni, int nj, int nx, int ny);
		void Hit();
		void SetXY(int ni, int nj, int nx, int ny);
		void Swallowed(CDirection faceTo);
		void OnShow();
	protected:
		CMovingBitmap bitmap;
		int indexX, indexY;
		double x, y;
		CMap *mapRecord;
		list<CBrick> *brickRecord;
		list<CMonster> *monsterRecord;
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
		double STEP_SIZE_X;
		double STEP_SIZE_Y;
		CName type;
	};
}

#endif