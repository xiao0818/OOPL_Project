#ifndef CSTEEL_H
#define CSTEEL_H

#include "CName.h"
#include "CDirection.h"
#include "CBrick.h"
#include "Cplayer.h"

namespace game_framework {
	class CSteel : public CBrick
	{
	public:
		void LoadBitmap() override;
		void Initialize(CMap *map, CPlayer *player1, CPlayer *player2, list<CBrick> *brick, list<CMonster> *monster) override;
	};
}

#endif