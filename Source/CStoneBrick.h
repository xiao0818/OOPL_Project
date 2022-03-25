#ifndef CSTONEBRICK_H
#define CSTONEBRICK_H

namespace game_framework {
	class CStoneBrick
	{
	public:
		CStoneBrick();
		int  GetIndexX();
		int  GetIndexY();
		void LoadBitmap();
		void SetXY(int ni, int nj, int nx, int ny);
		void setAlive(bool flag);
		void OnShow();
	protected:
		CMovingBitmap bitmap;
		int indexX, indexY;
		int x, y;
		bool isAlive;
	};
}

#endif