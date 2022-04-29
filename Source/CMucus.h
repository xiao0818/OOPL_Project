#ifndef CMUCUS_H
#define CMUCUS_H

#include "CName.h"
#include "CDirection.h"
#include "CMap.h"
#include "CTrap.h"

namespace game_framework {
	class CMucus : public CTrap
	{
	public:
		void Initialize(CMap *map) override;
		void LoadBitmap() override;
	};
}

#endif