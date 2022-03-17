namespace game_framework {
	class CPlayer
	{
	public:
		CPlayer();
		void LoadBitmap();										// 載入圖形
		void OnShow();											// 將圖形貼到畫面
		void SetXY(int nx, int ny);								// 設定座標
	protected:
		CMovingBitmap bitmap;		// 圖
		int x, y;					// 座標
	};
}