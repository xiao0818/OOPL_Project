#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CSpike.h"

namespace game_framework {
	void CSpike::Initialize(CMap * map)
	{
		mapRecord = map;
		isAggressive = true;
	}

	void CSpike::LoadBitmap()
	{
		animation.AddBitmap(IDB_SPIKE);
	}
}