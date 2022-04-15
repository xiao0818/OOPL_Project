#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CTurtle.h"
#include <stdlib.h>
#include <time.h>

namespace game_framework {
	void CTurtle::LoadBitmap() {
		leftAnimation.AddBitmap(IDB_TURTLE_MOVE_LEFT_001, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_TURTLE_MOVE_LEFT_002, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_TURTLE_MOVE_LEFT_003, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_TURTLE_MOVE_LEFT_004, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_TURTLE_MOVE_LEFT_005, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_TURTLE_MOVE_LEFT_006, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_TURTLE_MOVE_LEFT_007, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_TURTLE_MOVE_LEFT_008, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_TURTLE_MOVE_UP_001, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_TURTLE_MOVE_UP_002, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_TURTLE_MOVE_UP_003, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_TURTLE_MOVE_UP_004, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_TURTLE_MOVE_UP_005, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_TURTLE_MOVE_UP_006, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_TURTLE_MOVE_UP_007, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_TURTLE_MOVE_UP_008, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_TURTLE_MOVE_DOWN_001, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_TURTLE_MOVE_DOWN_002, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_TURTLE_MOVE_DOWN_003, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_TURTLE_MOVE_DOWN_004, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_TURTLE_MOVE_DOWN_005, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_TURTLE_MOVE_DOWN_006, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_TURTLE_MOVE_DOWN_007, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_TURTLE_MOVE_DOWN_008, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_TURTLE_MOVE_RIGHT_001, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_TURTLE_MOVE_RIGHT_002, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_TURTLE_MOVE_RIGHT_003, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_TURTLE_MOVE_RIGHT_004, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_TURTLE_MOVE_RIGHT_005, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_TURTLE_MOVE_RIGHT_006, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_TURTLE_MOVE_RIGHT_007, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_TURTLE_MOVE_RIGHT_008, RGB(0, 0, 0));


		hitLeftAnimation.AddBitmap(IDB_MUD_HIT_LEFT_001, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_MUD_HIT_LEFT_002, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_MUD_HIT_LEFT_003, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_MUD_HIT_LEFT_004, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_MUD_HIT_LEFT_005, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_MUD_HIT_LEFT_006, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_MUD_HIT_LEFT_007, RGB(0, 0, 0));
		hitLeftAnimation.AddBitmap(IDB_MUD_HIT_LEFT_008, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_MUD_HIT_RIGHT_001, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_MUD_HIT_RIGHT_002, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_MUD_HIT_RIGHT_003, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_MUD_HIT_RIGHT_004, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_MUD_HIT_RIGHT_005, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_MUD_HIT_RIGHT_006, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_MUD_HIT_RIGHT_007, RGB(0, 0, 0));
		hitRightAnimation.AddBitmap(IDB_MUD_HIT_RIGHT_008, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_MUD_HIT_DOWN_001, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_MUD_HIT_DOWN_002, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_MUD_HIT_DOWN_003, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_MUD_HIT_DOWN_004, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_MUD_HIT_DOWN_005, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_MUD_HIT_DOWN_006, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_MUD_HIT_DOWN_007, RGB(0, 0, 0));
		hitDownAnimation.AddBitmap(IDB_MUD_HIT_DOWN_008, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_MUD_HIT_UP_001, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_MUD_HIT_UP_002, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_MUD_HIT_UP_003, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_MUD_HIT_UP_004, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_MUD_HIT_UP_005, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_MUD_HIT_UP_006, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_MUD_HIT_UP_007, RGB(0, 0, 0));
		hitUpAnimation.AddBitmap(IDB_MUD_HIT_UP_008, RGB(0, 0, 0));
	}
};
