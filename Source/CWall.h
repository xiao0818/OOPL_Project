namespace game_framework {
	class CWall
	{
	public:
		CWall();
		void LoadBitmap();
		void OnShow();
		void SetXY(int nx, int ny);
	protected:
		CMovingBitmap bitmap;
		int x, y;
	};
}