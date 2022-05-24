#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CBomb.h"

namespace game_framework {
	void CBomb::LoadBitmap()
	{
		bitmap.AddBitmap(IDB_BOMB_BRICK);
		bitmap.AddBitmap(IDB_BOMB_BRICK_BREAK_001);
		bitmap.AddBitmap(IDB_BOMB_BRICK_BREAK_002);
		bitmap.AddBitmap(IDB_BOMB_BRICK_BREAK_003);
		bitmap.AddBitmap(IDB_BOMB_BRICK_BREAK_004);
		bitmap.AddBitmap(IDB_BOMB_BRICK_BREAK_005);
		bitmap.AddBitmap(IDB_BOMB_BRICK_BREAK_006);
	}

	void CBomb::Initialize(CMap *map, CPlayer *player1, CPlayer *player2, list<CBrick> *brick, list<CMonster> *monster)
	{
		mapRecord = map;
		player1Record = player1;
		player2Record = player2;
		brickRecord = brick;
		monsterRecord = monster;
		STEP_TARGET = 8;
		STEP_SIZE_X = 4.5;
		STEP_SIZE_Y = 3;
		type = CName::BOMB;
	}
}