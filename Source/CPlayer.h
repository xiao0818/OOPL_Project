namespace game_framework {
	class CPlayer
	{
	public:
		CPlayer();
		int  GetX1();
		int  GetY1();
		int  GetX2();
		int  GetY2();
		int  GetIndexX();
		int  GetIndexY();
		void Initialize(int **map);
		void LoadBitmap();
		void OnMove();
		void OnShow();
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetMovingUp(bool flag);
		void SetMovingDown(bool flag);
		void SetXY(int ni, int nj, int nx, int ny);
	protected:
		CAnimation animation;
		int indexX, indexY;
		int x, y;
		bool isMovingDown;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		bool isKeyDownPressed;
		bool isKeyLeftPressed;
		bool isKeyRightPressed;
		bool isKeyUpPressed;
		int movingCount;
		int **mapRecord;
	};
}