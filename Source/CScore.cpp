#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CScore.h"

namespace game_framework {
	CMovingBitmap CScore::digit[11];

	CScore::CScore(int digits)
		: NUMDIGITS(digits)
	{
		isBmpLoaded = false;
	}

	void CScore::Add(int x)
	{
		n += x;
	}

	int CScore::GetInteger()
	{
		return n;
	}

	void CScore::LoadBitmap()
	{
		//
		// digit[i]��class varibale�A�ҥH�����קK����LoadBitmap
		//
		if (!isBmpLoaded) {
			int d[11] = { IDB_NUMBER_0,IDB_NUMBER_1,IDB_NUMBER_2,IDB_NUMBER_3,IDB_NUMBER_4,IDB_NUMBER_5,IDB_NUMBER_6,IDB_NUMBER_7,IDB_NUMBER_8,IDB_NUMBER_9,IDB_MINUS };
			for (int i = 0; i < 11; i++)
				digit[i].LoadBitmap(d[i]);
			isBmpLoaded = true;
		}
	}

	void CScore::SetInteger(int i)
	{
		n = i;
	}

	void CScore::SetTopLeft(int nx, int ny)		// �N�ʵe�����W���y�в��� (x,y)
	{
		x = nx; y = ny;
	}

	void CScore::ShowBitmap()
	{
		int nx;		// ����ܦ�ƪ� x �y��
		int MSB;	// �̥���(�t�Ÿ�)����ƪ��ƭ�
		if (n >= 0) {
			MSB = n;
			nx = x + digit[0].Width()*(NUMDIGITS - 1);
		}
		else {
			MSB = -n;
			nx = x + digit[0].Width()*NUMDIGITS;
		}
		for (int i = 0; i < NUMDIGITS; i++) {
			int d = MSB % 10;
			MSB /= 10;
			digit[d].SetTopLeft(nx, y);
			digit[d].ShowBitmap();
			nx -= digit[d].Width();
		}
		if (n < 0) { // �p�G�p��0�A�h��ܭt��
			digit[10].SetTopLeft(nx, y);
			digit[10].ShowBitmap();
		}
	}
}