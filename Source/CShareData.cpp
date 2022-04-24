#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CShareData.h"

namespace game_framework {
	CShareData::CShareData()
	{
		selectedLevelIndex = grade = 0;
		isMusicEnable = isSoundEnable = true;
		isSuccess = isFail = false;
	}

	void CShareData::InitializeState()
	{
		selectedLevelIndex = grade = 0;
		isSuccess = isFail = false;
	}

	void CShareData::SetSelectedLevelIndex(int level)
	{
		selectedLevelIndex = level;
	}

	int CShareData::GetSelectedLevelIndex()
	{
		return selectedLevelIndex;
	}

	int CShareData::GetGrade()
	{
		return grade;
	}

	void CShareData::AddGrade(int point)
	{
		grade += point;
	}

	bool CShareData::IsSuccess()
	{
		return isSuccess;
	}

	void CShareData::IsSuccess(bool flag)
	{
		isSuccess = flag;
	}

	bool CShareData::IsFail()
	{
		return isFail;
	}

	void CShareData::IsFail(bool flag)
	{
		isFail = flag;
	}

	bool CShareData::IsMusicEnable()
	{
		return isMusicEnable;
	}

	bool CShareData::IsSoundEnable()
	{
		return isSoundEnable;
	}

	void CShareData::IsMusicEnable(bool flag)
	{
		isMusicEnable = flag;
	}

	void CShareData::IsSoundEnable(bool flag)
	{
		isSoundEnable = flag;
	}
}