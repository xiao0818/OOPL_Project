#ifndef CSPIKE_H
#define CSPIKE_H

#include "CName.h"
#include "CDirection.h"
#include "CMap.h"
#include "CTrap.h"

namespace game_framework {
	class CSpike : public CTrap
	{
	public:
		void Initialize(CMap *map) override;
		void LoadBitmap() override;
	};
}

#endif