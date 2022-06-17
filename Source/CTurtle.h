#ifndef CTURTLE_H
#define CTURTLE_H

#include "CDirection.h"
#include "CName.h"
#include "CMap.h"
#include "CMonster.h"

namespace game_framework {
	class CTurtle : public CMonster
	{
	public:
		void LoadBitmap() override;
	};
};

#endif