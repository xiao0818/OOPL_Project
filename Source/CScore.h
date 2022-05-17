#ifndef CSCORE_H
#define CSCORE_H

namespace game_framework {
	class CScore {
	public:
		CScore(int = 4);			// default 4 digits
		void Add(int n);			// �W�[��ƭ�
		int  GetInteger();			// �^�Ǿ�ƭ�
		virtual void LoadBitmap();			// ���J0..9�έt�����ϧ�
		void SetInteger(int);		// �]�w��ƭ�
		void SetTopLeft(int, int);	// �N�ʵe�����W���y�в��� (x,y)
		void ShowBitmap();			// �N�ʵe�K��ù�
	private:
		const int NUMDIGITS;			// �@���NUMDIGITS�Ӧ��
		static CMovingBitmap digit[11]; // �x�s0..9�έt�����ϧ�(bitmap)
		int x, y;						// ��ܪ��y��
		int n;							// ��ƭ�
		bool isBmpLoaded;				// �O�_�w�g���J�ϧ�
	};
}

#endif
