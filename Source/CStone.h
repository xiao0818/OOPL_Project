#ifndef CSTONE_H
#define CSTONE_H

#include "CName.h"
#include "CDirection.h"
#include "CBrick.h"

namespace game_framework {
	class CStone : public CBrick
	{
	public:
		void LoadBitmap() override;
		void SetStepAndType() override;
	};
}

#endif