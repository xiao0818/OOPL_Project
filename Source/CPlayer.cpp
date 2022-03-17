#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CPlayer.h"

namespace game_framework {
	CPlayer::CPlayer()
	{
		x = y = 0;
	}

	void CPlayer::LoadBitmap()
	{
		bitmap.LoadBitmap(IDB_PLAYER, RGB(0, 0, 0));
	}

	void CPlayer::SetXY(int nx, int ny)
	{
		x = nx;
		y = ny - 23;
	}

	void CPlayer::OnShow()
	{
		bitmap.SetTopLeft(x, y);
		bitmap.ShowBitmap();
	}
}