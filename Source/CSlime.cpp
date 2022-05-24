#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CSlime.h"

namespace game_framework {
	void CSlime::LoadBitmap()
	{
		bitmap.AddBitmap(IDB_SLIME_BRICK);
		bitmap.AddBitmap(IDB_SLIME_REBOUND_001);
		bitmap.AddBitmap(IDB_SLIME_REBOUND_002);
		bitmap.AddBitmap(IDB_SLIME_REBOUND_001);
		bitmap.AddBitmap(IDB_SLIME_REBOUND_002);
		bitmap.AddBitmap(IDB_SLIME_REBOUND_001);
		bitmap.AddBitmap(IDB_SLIME_REBOUND_002);
		bitmap.AddBitmap(IDB_SLIME_BRICK);
	}

	void CSlime::Initialize(CMap *map, CPlayer *player1, CPlayer *player2, list<CBrick> *brick, list<CFood> *food, list<CMonster> *monster)
	{
		mapRecord = map;
		player1Record = player1;
		player2Record = player2;
		brickRecord = brick;
		foodRecord = food;
		monsterRecord = monster;
		STEP_TARGET = 8;
		STEP_SIZE_X = 4.5;
		STEP_SIZE_Y = 3;
		type = CName::SLIME;
	}
}