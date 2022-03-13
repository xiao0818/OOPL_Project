namespace game_framework {
	class CMap
	{
	public:
		CMap();
		void LoadBitmap();										// ���J�ϧ�
		void OnShow();											// �N�ϧζK��e��
		void SetXY();											// �]�w�y��
	protected:
		CMovingBitmap background;	// ��
		int map[14][14];
		int x, y;					// �y��
		int brickLength, brickWidth;
		CWall wall;
	};
}