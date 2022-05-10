#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CMucus.h"

namespace game_framework {
	void CMucus::Initialize(CMap * map)
	{
		mapRecord = map;
		isAggressive = false;
		type = CName::MUCUS;
	}

	void CMucus::LoadBitmap()
	{
		animation.AddBitmap(IDB_MUCUS);
	}
}