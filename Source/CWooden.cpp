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
		bitmap.AddBitmap(IDB_WOODEN_BRICK);
		bitmap.AddBitmap(IDB_WOODEN_BRICK_BREAK_001, RGB(255, 255, 255));
		bitmap.AddBitmap(IDB_WOODEN_BRICK_BREAK_002, RGB(255, 255, 255));
		bitmap.AddBitmap(IDB_WOODEN_BRICK_BREAK_002, RGB(255, 255, 255));
	}

	void CWooden::Initialize(CMap *map, CShareData *shareData, CPlayer *player1, CPlayer *player2, list<CBrick> *brick, list<CFood> *food, list<CMonster> *monster)
	{
		mapRecord = map;
		shareDataRecord = shareData;
		player1Record = player1;
		player2Record = player2;
		brickRecord = brick;
		foodRecord = food;
		monsterRecord = monster;
		STEP_TARGET = 8;
		STEP_SIZE_X = 4.5;
		STEP_SIZE_Y = 3;
		type = CName::WOODEN;
	}
}