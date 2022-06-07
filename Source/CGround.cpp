#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CWall.h"
#include "CGround.h"
#include "CAudioId.h"

namespace game_framework {
	CGround::CGround()
	{
		x = y = 0;
		brickNumberX = brickNumberY = 0;
		isBomb = false;
		bomb.SetDelayCount(3);
	}

	void CGround::LoadBitmap()
	{
		ground.LoadBitmapA(IDB_GROUND);
		bomb.AddBitmap(IDB_BOMB_BRICK_BREAK_001, RGB(255, 255, 255));
		bomb.AddBitmap(IDB_BOMB_BRICK_BREAK_001, RGB(255, 255, 255));
		bomb.AddBitmap(IDB_BOMB_BRICK_BREAK_002, RGB(255, 255, 255));
		bomb.AddBitmap(IDB_BOMB_BRICK_BREAK_002, RGB(255, 255, 255));
		bomb.AddBitmap(IDB_BOMB_BRICK_BREAK_003, RGB(255, 255, 255));
		bomb.AddBitmap(IDB_BOMB_BRICK_BREAK_003, RGB(255, 255, 255));
		bomb.AddBitmap(IDB_BOMB_BRICK_BREAK_004, RGB(255, 255, 255));
		bomb.AddBitmap(IDB_BOMB_BRICK_BREAK_004, RGB(255, 255, 255));
		bomb.AddBitmap(IDB_BOMB_BRICK_BREAK_005, RGB(255, 255, 255));
		bomb.AddBitmap(IDB_BOMB_BRICK_BREAK_005, RGB(255, 255, 255));
		bomb.AddBitmap(IDB_BOMB_BRICK_BREAK_006, RGB(255, 255, 255));
		bomb.AddBitmap(IDB_BOMB_BRICK_BREAK_006, RGB(255, 255, 255));
	}

	void CGround::Initialize(int nx, int ny, CShareData *shareData)
	{
		x = y = 0;
		isBomb = false;
		brickNumberX = nx;
		brickNumberY = ny;
		bomb.Reset();
		shareDataRecord = shareData;
	}

	void CGround::Bomb()
	{
		isBomb = true;
		if (shareDataRecord->IsSoundEnable())
		{
			CAudio::Instance()->Play(SOUND_BOMB, false);
		}
	}

	void CGround::OnMove()
	{
		if (isBomb)
		{
			if (!bomb.IsFinalBitmap())
			{
				bomb.OnMove();
			}
			else
			{
				isBomb = false;
			}
		}
	}

	void CGround::SetXY(int nx, int ny)
	{
		x = nx;
		y = ny;
	}

	void CGround::OnShow()
	{
		const int BRICK_LENGTH = 36;
		const int BRICK_WIDTH = 24;

		for (int i = 0; i < brickNumberY; i++)
		{
			for (int j = 0; j < brickNumberX; j++)
			{
				ground.SetTopLeft(x + BRICK_LENGTH * j, y + BRICK_WIDTH * i);
				ground.ShowBitmap();

				if (isBomb)
				{
					bomb.SetTopLeft(x + BRICK_LENGTH * j + (BRICK_LENGTH / 2) - (bomb.Width() / 2), y + BRICK_WIDTH * i + (BRICK_WIDTH / 2) - (bomb.Height() / 2));
					bomb.OnShow();
				}
			}
		}
	}
}