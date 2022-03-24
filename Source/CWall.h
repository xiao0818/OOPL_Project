namespace game_framework {
	class CWall
	{
	public:
		CWall();
		int  GetIndexX();
		int  GetIndexY();
		void LoadBitmap();
		void SetXY(int ni, int nj, int nx, int ny);
		void OnShow();
	protected:
		CMovingBitmap bitmap;
		int indexX, indexY;
		int x, y;
	};
}