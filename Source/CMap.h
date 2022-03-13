namespace game_framework {
	class CMap
	{
	public:
		CMap();
		void LoadBitmap();										// 載入圖形
		void OnShow();											// 將圖形貼到畫面
		void SetXY();											// 設定座標
	protected:
		CMovingBitmap background;	// 圖
		int map[14][14];
		int x, y;					// 座標
		int brickLength, brickWidth;
		CWall wall;
	};
}