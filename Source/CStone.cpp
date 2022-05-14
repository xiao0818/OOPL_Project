#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CStone.h"

namespace game_framework {
	void CStone::LoadBitmap()
	{
		bitmap.LoadBitmap(IDB_STONE_BRICK);
	}

	void CStone::Initialize(CMap * map, list<CBrick>* brick, list<CMonster>* monster)
	{
		mapRecord = map;
		brickRecord = brick;
		monsterRecord = monster;
		STEP_TARGET = 8;
		STEP_SIZE_X = 4.5;
		STEP_SIZE_Y = 3;
		type = CName::STONE;
	}
}