#ifndef CMUD_H
#define CMUD_H

#include "CDirection.h"
#include "CName.h"
#include "CMap.h"
#include "CMonster.h"

namespace game_framework {
	class CMud : public CMonster
	{
	public:
		void LoadBitmap() override;
	};
}

#endif