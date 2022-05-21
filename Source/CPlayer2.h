#ifndef CPLAYER2_H
#define CPLAYER2_H

#include "Cplayer.h"

namespace game_framework {
	class CPlayer2 : public CPlayer
	{
	public:
		void LoadBitmap() override;
	};
}

#endif