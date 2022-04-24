#ifndef CGROUND_H
#define CGROUND_H

namespace game_framework {
	class CGround
	{
	public:
		CGround();
		void LoadBitmap();
		void Initialize(int nx, int ny);
		void OnShow();
		void SetXY(int nx ,int ny);
	protected:
		CMovingBitmap ground;
		int x, y;
		int brickLength, brickWidth;
		int brickNumberX, brickNumberY;
	};
}

#endif