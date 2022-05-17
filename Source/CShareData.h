#ifndef CSHAREDATA_H
#define CSHAREDATA_H

namespace game_framework {
	class CShareData
	{
	public:
		CShareData();
		void InitializeState();
		void SetSelectedLevelIndex(int level);
		int GetSelectedLevelIndex();
		int GetGrade();
		void SetPlayerNumber(int number);
		int GetPlayerNumber();
		void AddGrade(int point);
		void SetGrade(int point);
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
		int playerNumber;
		bool isSuccess;
		bool isFail;
		bool isMusicEnable;
		bool isSoundEnable;
	};
}

#endif