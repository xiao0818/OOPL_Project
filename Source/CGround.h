namespace game_framework {
	class CGround
	{
	public:
		CGround();
		void LoadBitmap();										// ���J�ϧ�
		void OnShow();											// �N�ϧζK��e��
		void SetXY(int nx ,int ny);											// �]�w�y��
	protected:
		CMovingBitmap ground;
		int x, y;
		int brickLength, brickWidth;
	};
}