#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CSteel.h"

namespace game_framework {
	//CSteel::CSteel()
	//{
	//	x = y = 0;
	//	isAlive = true;
	//	isMovingLeft = isMovingRight = isMovingUp = isMovingDown = false;
	//	isSwallowed = false;
	//}

	//int CSteel::GetIndexX() {
	//	return indexX;
	//}

	//int CSteel::GetIndexY() {
	//	return indexY;
	//}

	//bool CSteel::IsMove()
	//{
	//	return isMovingLeft || isMovingRight || isMovingUp || isMovingDown;
	//}

	//void CSteel::Initialize(CName **map)
	//{
	//	mapRecord = map;
	//}

	void CSteel::LoadBitmap()
	{
		bitmap.LoadBitmap(IDB_STEEL_BRICK);
	}

	//void CSteel::OnMove()
	//{
	//	const int STEP_TARGET = 6;
	//	const int STEP_SIZE_X = 12;
	//	const int STEP_SIZE_Y = 8;

	//	if (isSwallowed)
	//	{
	//		if (isMovingLeft)
	//		{
	//			x -= STEP_SIZE_X;
	//			movingCount++;
	//			if (movingCount == STEP_TARGET)
	//			{
	//				mapRecord[indexX][indexY] = CName::SPACE;
	//				movingCount = 0;
	//				isMovingLeft = isSwallowed = isAlive = false;
	//			}
	//		}
	//		else if (isMovingRight)
	//		{
	//			x += STEP_SIZE_X;
	//			movingCount++;
	//			if (movingCount == STEP_TARGET)
	//			{
	//				mapRecord[indexX][indexY] = CName::SPACE;
	//				movingCount = 0;
	//				isMovingRight = isSwallowed = isAlive = false;
	//			}
	//		}
	//		else if (isMovingUp)
	//		{
	//			y -= STEP_SIZE_Y;
	//			movingCount++;
	//			if (movingCount == STEP_TARGET)
	//			{
	//				mapRecord[indexX][indexY] = CName::SPACE;
	//				movingCount = 0;
	//				isMovingUp = isSwallowed = isAlive = false;
	//			}
	//		}
	//		else if (isMovingDown)
	//		{
	//			y += STEP_SIZE_Y;
	//			movingCount++;
	//			if (movingCount == STEP_TARGET)
	//			{
	//				mapRecord[indexX][indexY] = CName::SPACE;
	//				movingCount = 0;
	//				isMovingDown = isSwallowed = isAlive = false;
	//			}
	//		}
	//	}
	//	else
	//	{
	//		if (isMovingLeft)
	//		{
	//			if (mapRecord[indexX - 1][indexY] == CName::SPACE || mapRecord[indexX - 1][indexY] == CName::PLAYER || mapRecord[indexX - 1][indexY] == CName::MUD)
	//			{
	//				x -= STEP_SIZE_X;
	//				movingCount++;
	//				if (movingCount == STEP_TARGET)
	//				{
	//					mapRecord[indexX][indexY] = CName::SPACE;
	//					mapRecord[--indexX][indexY] = CName::STONE;
	//					movingCount = 0;
	//					isMovingLeft = (mapRecord[indexX - 1][indexY] == CName::SPACE || mapRecord[indexX - 1][indexY] == CName::PLAYER || mapRecord[indexX - 1][indexY] == CName::MUD);
	//				}
	//			}
	//			else
	//			{
	//				isMovingLeft = false;
	//			}
	//		}
	//		else if (isMovingRight)
	//		{
	//			if (mapRecord[indexX + 1][indexY] == CName::SPACE || mapRecord[indexX + 1][indexY] == CName::PLAYER || mapRecord[indexX + 1][indexY] == CName::MUD)
	//			{
	//				x += STEP_SIZE_X;
	//				movingCount++;
	//				if (movingCount == STEP_TARGET)
	//				{
	//					mapRecord[indexX][indexY] = CName::SPACE;
	//					mapRecord[++indexX][indexY] = CName::STONE;
	//					movingCount = 0;
	//					isMovingRight = (mapRecord[indexX + 1][indexY] == CName::SPACE || mapRecord[indexX + 1][indexY] == CName::PLAYER || mapRecord[indexX + 1][indexY] == CName::MUD);
	//				}
	//			}
	//			else
	//			{
	//				isMovingRight = false;
	//			}
	//		}
	//		else if (isMovingUp)
	//		{
	//			if (mapRecord[indexX][indexY - 1] == CName::SPACE || mapRecord[indexX][indexY - 1] == CName::PLAYER || mapRecord[indexX][indexY - 1] == CName::MUD)
	//			{
	//				y -= STEP_SIZE_Y;
	//				movingCount++;
	//				if (movingCount == STEP_TARGET)
	//				{
	//					mapRecord[indexX][indexY] = CName::SPACE;
	//					mapRecord[indexX][--indexY] = CName::STONE;
	//					movingCount = 0;
	//					isMovingUp = (mapRecord[indexX][indexY - 1] == CName::SPACE || mapRecord[indexX][indexY - 1] == CName::PLAYER || mapRecord[indexX][indexY - 1] == CName::MUD);
	//				}
	//			}
	//			else
	//			{
	//				isMovingUp = false;
	//			}
	//		}
	//		else if (isMovingDown)
	//		{
	//			if (mapRecord[indexX][indexY + 1] == CName::SPACE || mapRecord[indexX][indexY + 1] == CName::PLAYER || mapRecord[indexX][indexY + 1] == CName::MUD)
	//			{
	//				y += STEP_SIZE_Y;
	//				movingCount++;
	//				if (movingCount == STEP_TARGET)
	//				{
	//					mapRecord[indexX][indexY] = CName::SPACE;
	//					mapRecord[indexX][++indexY] = CName::STONE;
	//					movingCount = 0;
	//					isMovingDown = (mapRecord[indexX][indexY + 1] == CName::SPACE || mapRecord[indexX][indexY + 1] == CName::PLAYER || mapRecord[indexX][indexY + 1] == CName::MUD);
	//				}
	//			}
	//			else
	//			{
	//				isMovingDown = false;
	//			}
	//		}
	//	}
	//}

	//void CSteel::SpitedOut(CDirection faceTo, int ni, int nj, int nx, int ny)
	//{
	//	indexX = ni;
	//	indexY = nj;
	//	x = nx;
	//	y = ny;
	//	mapRecord[indexX][indexY] = CName::STONE;
	//	isAlive = true;
	//	movingCount = 0;
	//	if (faceTo == CDirection::LEFT)
	//	{
	//		isMovingLeft = true;
	//	}
	//	else if (faceTo == CDirection::RIGHT)
	//	{
	//		isMovingRight = true;
	//	}
	//	else if (faceTo == CDirection::UP)
	//	{
	//		isMovingUp = true;
	//	}
	//	else if (faceTo == CDirection::DOWN)
	//	{
	//		isMovingDown = true;
	//	}
	//}

	//void CSteel::SetXY(int ni, int nj, int nx, int ny)
	//{
	//	indexX = ni;
	//	indexY = nj;
	//	x = nx;
	//	y = ny;
	//}

	//void CSteel::Swallowed(CDirection faceTo)
	//{
	//	isSwallowed = true;
	//	movingCount = 0;
	//	if (faceTo == CDirection::LEFT)
	//	{
	//		isMovingRight = true;
	//	}
	//	else if (faceTo == CDirection::RIGHT)
	//	{
	//		isMovingLeft = true;
	//	}
	//	else if (faceTo == CDirection::UP)
	//	{
	//		isMovingDown = true;
	//	}
	//	else if (faceTo == CDirection::DOWN)
	//	{
	//		isMovingUp = true;
	//	}
	//}

	//void CSteel::OnShow()
	//{
	//	if (isAlive) {
	//		bitmap.SetTopLeft(x, y - 24);
	//		bitmap.ShowBitmap();
	//	}
	//}
}