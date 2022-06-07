#ifndef CGROUND_H
#define CGROUND_H

namespace game_framework {
	class CGround
	{
	public:
		CGround();
		void LoadBitmap();
		void Initialize(int nx, int ny, CShareData *shareData);
		void Bomb();
		void OnMove();
		void OnShow();
		void SetXY(int nx ,int ny);
	protected:
		CMovingBitmap ground;
		CAnimation bomb;
		int x, y;
		int brickLength, brickWidth;
		int brickNumberX, brickNumberY;
		bool isBomb;
		CShareData *shareDataRecord;
	};
}

#endif