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

	void CSteel::SetStepAndType()
	{
		STEP_TARGET = 12;
		STEP_SIZE_X = 3;
		STEP_SIZE_Y = 2;
		type = CName::STEEL;
	}
}