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
		bitmap.LoadBitmap(IDB_WOODEN_BRICK);
	}

	void CWooden::SetStepAndType()
	{
		STEP_TARGET = 6;
		STEP_SIZE_X = 12;
		STEP_SIZE_Y = 8;
		type = CName::WOODEN;
	}
}