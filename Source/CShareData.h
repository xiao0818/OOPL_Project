#ifndef CSHAREDATA_H
#define CSHAREDATA_H

namespace game_framework {
	class CShareData
	{
	public:
		CShareData();
		void InitializeState();
		int GetGrade();
		void AddGrade(int point);
		bool IsSuccess();
		void IsSuccess(bool flag);
		bool IsFail();
		void IsFail(bool flag);
		bool IsMusicEnable();
		void IsMusicEnable(bool flag);
		bool IsSoundEnable();
		void IsSoundEnable(bool flag);
	protected:
		int selectedLevelIndex;
		int grade;
		bool isSuccess;
		bool isFail;
		bool isMusicEnable;
		bool isSoundEnable;
	};
}

#endif