#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CMovingSpike.h"

namespace game_framework {
	void CMovingSpike::Initialize(CMap * map)
	{
		mapRecord = map;
		isAggressive = false;
		type = CName::MOVING;
	}

	void CMovingSpike::LoadBitmap()
	{
		animation.AddBitmap(IDB_MOVING_SPIKE_001);
		animation.AddBitmap(IDB_MOVING_SPIKE_001);
		animation.AddBitmap(IDB_MOVING_SPIKE_002);
		animation.AddBitmap(IDB_MOVING_SPIKE_002);
		animation.AddBitmap(IDB_MOVING_SPIKE_003);
		animation.AddBitmap(IDB_MOVING_SPIKE_003);
		animation.AddBitmap(IDB_MOVING_SPIKE_004);
		animation.AddBitmap(IDB_MOVING_SPIKE_004);
		animation.AddBitmap(IDB_MOVING_SPIKE_005);
		animation.AddBitmap(IDB_MOVING_SPIKE_005);
		animation.AddBitmap(IDB_MOVING_SPIKE_006);
		animation.AddBitmap(IDB_MOVING_SPIKE_006);
	}
}