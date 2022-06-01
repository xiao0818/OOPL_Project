#ifndef CFISH_H
#define CFISH_H

#include "CDirection.h"
#include "CName.h"
#include "CMap.h"
#include "CMonster.h"

namespace game_framework {
	class CFish : public CMonster
	{
	public:
		void LoadBitmap() override;
	};
}

#endif