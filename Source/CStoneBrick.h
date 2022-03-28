#ifndef CSTONEBRICK_H
#define CSTONEBRICK_H

namespace game_framework {
	class CStoneBrick
	{
	public:
		CStoneBrick();
		int  GetIndexX();
		int  GetIndexY();
		void Initialize(int **map);
		void LoadBitmap();
		void OnMove();
		void SpitedOut(string faceTo);
		void SetXY(int ni, int nj, int nx, int ny);
		void setAlive(bool flag);
		void OnShow();
	protected:
		CMovingBitmap bitmap;
		int indexX, indexY;
		int x, y;
		int **mapRecord;
		bool isMovingDown;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		int movingCount;
		bool isAlive;
		string LEFT = "LEFT";
		string RIGHT = "RIGHT";
		string UP = "UP";
		string DOWN = "DOWN";
	};
}

#endif