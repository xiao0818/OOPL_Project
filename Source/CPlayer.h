namespace game_framework {
	class CPlayer
	{
	public:
		CPlayer();
		int  GetX1();
		int  GetY1();
		int  GetX2();
		int  GetY2();
		void Initialize(int **map);
		void LoadBitmap();
		void OnMove();
		void OnShow();
		void SetMovingLeft(bool flag);
		void SetMovingRight(bool flag);
		void SetMovingUp(bool flag);
		void SetMovingDown(bool flag);
		void SetXY(int nx, int ny);
	protected:
		CAnimation animation;
		int x, y;
		int indexX, indexY;
		bool isMovingDown;
		bool isMovingLeft;
		bool isMovingRight;
		bool isMovingUp;
		int moveCountForX;
		int moveCountForY;
		int **mapRecord;
	};
}