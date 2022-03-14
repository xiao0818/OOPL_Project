namespace game_framework {
	class CGround
	{
	public:
		CGround();
		void LoadBitmap();										// 載入圖形
		void OnShow();											// 將圖形貼到畫面
		void SetXY(int nx ,int ny);											// 設定座標
	protected:
		CMovingBitmap ground;
		int x, y;
		int brickLength, brickWidth;
	};
}