#ifndef CSTEEL_H
#define CSTEEL_H

#include "CName.h"
#include "CDirection.h"
#include "CBrick.h"

namespace game_framework {
	class CSteel : public CBrick
	{
	public:
		void LoadBitmap() override;
		void SetStepAndType() override;
	};
}

#endif