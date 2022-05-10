#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CSteppingSpike.h"

namespace game_framework {
	void CSteppingSpike::Initialize(CMap * map)
	{
		mapRecord = map;
		isAggressive = false;
		type = CName::STEPPING;
	}

	void CSteppingSpike::LoadBitmap()
	{
		animation.AddBitmap(IDB_STEPPING_SPIKE_001);
		animation.AddBitmap(IDB_STEPPING_SPIKE_002);
		animation.AddBitmap(IDB_STEPPING_SPIKE_003);
		animation.AddBitmap(IDB_STEPPING_SPIKE_004);
		animation.AddBitmap(IDB_STEPPING_SPIKE_005);
		animation.AddBitmap(IDB_STEPPING_SPIKE_006);
		animation.AddBitmap(IDB_STEPPING_SPIKE_007);
		animation.AddBitmap(IDB_STEPPING_SPIKE_008);
		animation.AddBitmap(IDB_STEPPING_SPIKE_009);
		animation.AddBitmap(IDB_STEPPING_SPIKE_010);
		animation.AddBitmap(IDB_STEPPING_SPIKE_011);
		animation.AddBitmap(IDB_STEPPING_SPIKE_012);
		animation.AddBitmap(IDB_STEPPING_SPIKE_013);
	}
}