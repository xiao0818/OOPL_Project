namespace game_framework {
	class CGround
	{
	public:
		CGround();
		void LoadBitmap();
		void OnShow();
		void SetXY(int nx ,int ny);
	protected:
		CMovingBitmap ground;
		int x, y;
		int brickLength, brickWidth;
	};
}