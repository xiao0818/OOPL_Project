#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CFish.h"
#include <stdlib.h>
#include <time.h>

namespace game_framework {
	void CFish::LoadBitmap()
	{
		leftAnimation.AddBitmap(IDB_FISH_MOVE_LEFT_001, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_FISH_MOVE_LEFT_002, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_FISH_MOVE_LEFT_003, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_FISH_MOVE_LEFT_004, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_FISH_MOVE_LEFT_005, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_FISH_MOVE_LEFT_006, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_FISH_MOVE_LEFT_007, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_FISH_MOVE_LEFT_008, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_FISH_MOVE_RIGHT_001, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_FISH_MOVE_RIGHT_002, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_FISH_MOVE_RIGHT_003, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_FISH_MOVE_RIGHT_004, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_FISH_MOVE_RIGHT_005, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_FISH_MOVE_RIGHT_006, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_FISH_MOVE_RIGHT_007, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_FISH_MOVE_RIGHT_008, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_FISH_MOVE_UP_001, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_FISH_MOVE_UP_002, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_FISH_MOVE_UP_003, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_FISH_MOVE_UP_004, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_FISH_MOVE_UP_005, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_FISH_MOVE_UP_006, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_FISH_MOVE_UP_007, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_FISH_MOVE_UP_008, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_FISH_MOVE_DOWN_001, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_FISH_MOVE_DOWN_002, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_FISH_MOVE_DOWN_003, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_FISH_MOVE_DOWN_004, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_FISH_MOVE_DOWN_005, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_FISH_MOVE_DOWN_006, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_FISH_MOVE_DOWN_007, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_FISH_MOVE_DOWN_008, RGB(0, 0, 0));

		hitLeftAnimation.AddBitmap(IDB_FISH_HIT_LEFT_001, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_FISH_HIT_LEFT_002, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_FISH_HIT_LEFT_003, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_FISH_HIT_LEFT_004, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_FISH_HIT_LEFT_005, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_FISH_HIT_LEFT_006, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_FISH_HIT_LEFT_007, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_FISH_HIT_LEFT_008, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_FISH_HIT_RIGHT_001, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_FISH_HIT_RIGHT_002, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_FISH_HIT_RIGHT_003, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_FISH_HIT_RIGHT_004, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_FISH_HIT_RIGHT_005, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_FISH_HIT_RIGHT_006, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_FISH_HIT_RIGHT_007, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_FISH_HIT_RIGHT_008, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_FISH_HIT_DOWN_001, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_FISH_HIT_DOWN_002, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_FISH_HIT_DOWN_003, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_FISH_HIT_DOWN_004, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_FISH_HIT_DOWN_005, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_FISH_HIT_DOWN_006, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_FISH_HIT_DOWN_007, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_FISH_HIT_DOWN_008, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_FISH_HIT_UP_001, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_FISH_HIT_UP_002, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_FISH_HIT_UP_003, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_FISH_HIT_UP_004, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_FISH_HIT_UP_005, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_FISH_HIT_UP_006, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_FISH_HIT_UP_007, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_FISH_HIT_UP_008, RGB(0, 0, 0));

		flyLeftAnimation.AddBitmap(IDB_FISH_FLY_L_001, RGB(0, 0, 0));
		flyLeftAnimation.AddBitmap(IDB_FISH_FLY_L_002, RGB(0, 0, 0));
		flyLeftAnimation.AddBitmap(IDB_FISH_FLY_L_003, RGB(0, 0, 0));
		flyLeftAnimation.AddBitmap(IDB_FISH_FLY_L_004, RGB(0, 0, 0));
		flyLeftAnimation.AddBitmap(IDB_FISH_FLY_L_005, RGB(0, 0, 0));
		flyLeftAnimation.AddBitmap(IDB_FISH_FLY_L_006, RGB(0, 0, 0));
		flyLeftAnimation.AddBitmap(IDB_FISH_FLY_L_007, RGB(0, 0, 0));
		flyLeftAnimation.AddBitmap(IDB_FISH_FLY_L_008, RGB(0, 0, 0));
		flyRightAnimation.AddBitmap(IDB_FISH_FLY_R_001, RGB(0, 0, 0));
		flyRightAnimation.AddBitmap(IDB_FISH_FLY_R_002, RGB(0, 0, 0));
		flyRightAnimation.AddBitmap(IDB_FISH_FLY_R_003, RGB(0, 0, 0));
		flyRightAnimation.AddBitmap(IDB_FISH_FLY_R_004, RGB(0, 0, 0));
		flyRightAnimation.AddBitmap(IDB_FISH_FLY_R_005, RGB(0, 0, 0));
		flyRightAnimation.AddBitmap(IDB_FISH_FLY_R_006, RGB(0, 0, 0));
		flyRightAnimation.AddBitmap(IDB_FISH_FLY_R_007, RGB(0, 0, 0));
		flyRightAnimation.AddBitmap(IDB_FISH_FLY_R_008, RGB(0, 0, 0));
		flyDownAnimation.AddBitmap(IDB_FISH_FLY_D_001, RGB(0, 0, 0));
		flyDownAnimation.AddBitmap(IDB_FISH_FLY_D_002, RGB(0, 0, 0));
		flyDownAnimation.AddBitmap(IDB_FISH_FLY_D_003, RGB(0, 0, 0));
		flyDownAnimation.AddBitmap(IDB_FISH_FLY_D_004, RGB(0, 0, 0));
		flyDownAnimation.AddBitmap(IDB_FISH_FLY_D_005, RGB(0, 0, 0));
		flyDownAnimation.AddBitmap(IDB_FISH_FLY_D_006, RGB(0, 0, 0));
		flyDownAnimation.AddBitmap(IDB_FISH_FLY_D_007, RGB(0, 0, 0));
		flyDownAnimation.AddBitmap(IDB_FISH_FLY_D_008, RGB(0, 0, 0));
		flyUpAnimation.AddBitmap(IDB_FISH_FLY_U_001, RGB(0, 0, 0));
		flyUpAnimation.AddBitmap(IDB_FISH_FLY_U_002, RGB(0, 0, 0));
		flyUpAnimation.AddBitmap(IDB_FISH_FLY_U_003, RGB(0, 0, 0));
		flyUpAnimation.AddBitmap(IDB_FISH_FLY_U_004, RGB(0, 0, 0));
		flyUpAnimation.AddBitmap(IDB_FISH_FLY_U_005, RGB(0, 0, 0));
		flyUpAnimation.AddBitmap(IDB_FISH_FLY_U_006, RGB(0, 0, 0));
		flyUpAnimation.AddBitmap(IDB_FISH_FLY_U_007, RGB(0, 0, 0));
		flyUpAnimation.AddBitmap(IDB_FISH_FLY_U_008, RGB(0, 0, 0));
	}
}