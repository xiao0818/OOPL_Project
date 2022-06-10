#ifndef CBOMB_H
#define CBOMB_H

#include "CName.h"
#include "CDirection.h"
#include "CBrick.h"
#include "Cplayer.h"

namespace game_framework {
	class CBomb : public CBrick
	{
	public:
		void LoadBitmap() override;
		void Initialize(CMap *map, CShareData *shareData, CPlayer *player1, CPlayer *player2, list<CBrick> *brick, list<CFood> *food, list<CMonster> *monster) override;
	};
}

#endif