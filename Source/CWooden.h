#ifndef CWOODEN_H
#define CWOODEN_H

#include "CName.h"
#include "CDirection.h"
#include "CBrick.h"

namespace game_framework {
	class CWooden : public CBrick
	{
	public:
		void LoadBitmap() override;
		void SetStep() override;
	};
}

#endif