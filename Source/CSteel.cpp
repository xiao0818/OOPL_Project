#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CSteel.h"

namespace game_framework {
	void CSteel::LoadBitmap()
	{
		bitmap.LoadBitmap(IDB_STEEL_BRICK);
	}

	void CSteel::Initialize(CMap *map, CPlayer *player1, CPlayer *player2, list<CBrick> *brick, list<CMonster> *monster)
	{
		mapRecord = map;
		player1Record = player1;
		player2Record = player2;
		brickRecord = brick;
		monsterRecord = monster;
		STEP_TARGET = 12;
		STEP_SIZE_X = 3;
		STEP_SIZE_Y = 2;
		type = CName::STEEL;
	}
}