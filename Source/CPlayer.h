namespace game_framework {
	class CPlayer
	{
	public:
		CPlayer();
		void LoadBitmap();										// ���J�ϧ�
		void OnShow();											// �N�ϧζK��e��
		void SetXY(int nx, int ny);								// �]�w�y��
	protected:
		CMovingBitmap bitmap;		// ��
		int x, y;					// �y��
	};
}