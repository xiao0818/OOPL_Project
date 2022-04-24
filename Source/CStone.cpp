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

	void CStone::SetStep()
	{
		STEP_TARGET = 6;
		STEP_SIZE_X = 12;
		STEP_SIZE_Y = 8;
	}
}