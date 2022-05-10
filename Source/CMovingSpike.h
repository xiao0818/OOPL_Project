#ifndef CMOVINGSPIKE_H
#define CMOVINGSPIKE_H

#include "CName.h"
#include "CDirection.h"
#include "CMap.h"
#include "CTrap.h"

namespace game_framework {
	class CMovingSpike : public CTrap
	{
	public:
		void Initialize(CMap *map) override;
		void LoadBitmap() override;
	};
}

#endif#pragma once
