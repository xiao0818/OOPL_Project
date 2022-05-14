#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CWooden.h"

namespace game_framework {
	void CWooden::LoadBitmap()
	{
		bitmap.LoadBitmap(IDB_WOODEN_BRICK);
	}

	void CWooden::Initialize(CMap * map, list<CBrick>* brick, list<CMonster>* monster)
	{
		mapRecord = map;
		brickRecord = brick;
		monsterRecord = monster;
		STEP_TARGET = 8;
		STEP_SIZE_X = 4.5;
		STEP_SIZE_Y = 3;
		type = CName::WOODEN;
	}
}