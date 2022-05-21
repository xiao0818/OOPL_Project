#ifndef CPLAYER1_H
#define CPLAYER1_H

#include "Cplayer.h"

namespace game_framework {
	class CPlayer1 : public CPlayer
	{
	public:
		void LoadBitmap() override;
	};
}

#endif