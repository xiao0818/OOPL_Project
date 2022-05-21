#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CPlayer1.h"

namespace game_framework {
	void CPlayer1::LoadBitmap()
	{
		leftAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_001, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_002, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_003, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_004, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_005, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_006, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_007, RGB(0, 0, 0));
		leftAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_008, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_001, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_002, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_003, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_004, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_005, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_006, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_007, RGB(0, 0, 0));
		rightAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_008, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_001, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_002, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_003, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_004, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_005, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_006, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_007, RGB(0, 0, 0));
		upAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_008, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_001, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_002, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_003, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_004, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_005, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_006, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_007, RGB(0, 0, 0));
		downAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_008, RGB(0, 0, 0));

		leftWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_WITH_FULL_001, RGB(0, 0, 0));
		leftWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_WITH_FULL_002, RGB(0, 0, 0));
		leftWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_WITH_FULL_003, RGB(0, 0, 0));
		leftWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_WITH_FULL_004, RGB(0, 0, 0));
		leftWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_WITH_FULL_005, RGB(0, 0, 0));
		leftWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_WITH_FULL_006, RGB(0, 0, 0));
		leftWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_WITH_FULL_007, RGB(0, 0, 0));
		leftWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_LEFT_WITH_FULL_008, RGB(0, 0, 0));
		rightWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_WITH_FULL_001, RGB(0, 0, 0));
		rightWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_WITH_FULL_002, RGB(0, 0, 0));
		rightWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_WITH_FULL_003, RGB(0, 0, 0));
		rightWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_WITH_FULL_004, RGB(0, 0, 0));
		rightWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_WITH_FULL_005, RGB(0, 0, 0));
		rightWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_WITH_FULL_006, RGB(0, 0, 0));
		rightWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_WITH_FULL_007, RGB(0, 0, 0));
		rightWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_RIGHT_WITH_FULL_008, RGB(0, 0, 0));
		upWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_WITH_FULL_001, RGB(0, 0, 0));
		upWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_WITH_FULL_002, RGB(0, 0, 0));
		upWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_WITH_FULL_003, RGB(0, 0, 0));
		upWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_WITH_FULL_004, RGB(0, 0, 0));
		upWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_WITH_FULL_005, RGB(0, 0, 0));
		upWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_WITH_FULL_006, RGB(0, 0, 0));
		upWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_WITH_FULL_007, RGB(0, 0, 0));
		upWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_UP_WITH_FULL_008, RGB(0, 0, 0));
		downWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_WITH_FULL_001, RGB(0, 0, 0));
		downWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_WITH_FULL_002, RGB(0, 0, 0));
		downWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_WITH_FULL_003, RGB(0, 0, 0));
		downWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_WITH_FULL_004, RGB(0, 0, 0));
		downWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_WITH_FULL_005, RGB(0, 0, 0));
		downWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_WITH_FULL_006, RGB(0, 0, 0));
		downWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_WITH_FULL_007, RGB(0, 0, 0));
		downWithFullAnimation.AddBitmap(IDB_PLAYER_MOVE_DOWN_WITH_FULL_008, RGB(0, 0, 0));

		eatLeftAnimation.AddBitmap(IDB_PLAYER_EAT_LEFT_001, RGB(0, 0, 0));
		eatLeftAnimation.AddBitmap(IDB_PLAYER_EAT_LEFT_002, RGB(0, 0, 0));
		eatLeftAnimation.AddBitmap(IDB_PLAYER_EAT_LEFT_003, RGB(0, 0, 0));
		eatLeftAnimation.AddBitmap(IDB_PLAYER_EAT_LEFT_004, RGB(0, 0, 0));
		eatRightAnimation.AddBitmap(IDB_PLAYER_EAT_RIGHT_001, RGB(0, 0, 0));
		eatRightAnimation.AddBitmap(IDB_PLAYER_EAT_RIGHT_002, RGB(0, 0, 0));
		eatRightAnimation.AddBitmap(IDB_PLAYER_EAT_RIGHT_003, RGB(0, 0, 0));
		eatRightAnimation.AddBitmap(IDB_PLAYER_EAT_RIGHT_004, RGB(0, 0, 0));
		eatUpAnimation.AddBitmap(IDB_PLAYER_EAT_UP_001, RGB(0, 0, 0));
		eatUpAnimation.AddBitmap(IDB_PLAYER_EAT_UP_002, RGB(0, 0, 0));
		eatUpAnimation.AddBitmap(IDB_PLAYER_EAT_UP_003, RGB(0, 0, 0));
		eatUpAnimation.AddBitmap(IDB_PLAYER_EAT_UP_004, RGB(0, 0, 0));
		eatDownAnimation.AddBitmap(IDB_PLAYER_EAT_DOWN_001, RGB(0, 0, 0));
		eatDownAnimation.AddBitmap(IDB_PLAYER_EAT_DOWN_002, RGB(0, 0, 0));
		eatDownAnimation.AddBitmap(IDB_PLAYER_EAT_DOWN_003, RGB(0, 0, 0));
		eatDownAnimation.AddBitmap(IDB_PLAYER_EAT_DOWN_004, RGB(0, 0, 0));

		successAnimation.AddBitmap(IDB_PLAYER_SUCCESS_001, RGB(0, 0, 0));
		successAnimation.AddBitmap(IDB_PLAYER_SUCCESS_002, RGB(0, 0, 0));
		successAnimation.AddBitmap(IDB_PLAYER_SUCCESS_003, RGB(0, 0, 0));
		successAnimation.AddBitmap(IDB_PLAYER_SUCCESS_004, RGB(0, 0, 0));
		successAnimation.AddBitmap(IDB_PLAYER_SUCCESS_005, RGB(0, 0, 0));
		successAnimation.AddBitmap(IDB_PLAYER_SUCCESS_006, RGB(0, 0, 0));
		failAnimation.AddBitmap(IDB_PLAYER_FAIL_001, RGB(0, 0, 0));
		failAnimation.AddBitmap(IDB_PLAYER_FAIL_002, RGB(0, 0, 0));
		failAnimation.AddBitmap(IDB_PLAYER_FAIL_003, RGB(0, 0, 0));
	}
}