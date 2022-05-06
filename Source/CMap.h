#ifndef CMAP_H
#define CMAP_H

#include "CName.h"

namespace game_framework {
	class CMap
	{
	public:
		CMap();
		~CMap();
		int GetBrickNumberX();
		int GetBrickNumberY();
		void SelectLevel(int levelNumber);
		void Initialize();
		void DeleteMap();
		void SetPlayerInMap(int nx, int ny, CName name);
		CName GetPlayerInMap(int nx, int ny);
		int GetPlayerIndexX();
		int GetPlayerIndexY();
		void SetTrapInMap(int nx, int ny, CName name);
		CName GetTrapInMap(int nx, int ny);
		void SetBrickInMap(int nx, int ny, CName name);
		CName GetBrickInMap(int nx, int ny);
		void SetFoodInMap(int nx, int ny, CName name);
		CName GetFoodInMap(int nx, int ny);
		void SetMonsterInMap(int nx, int ny, CName name);
		CName GetMonsterInMap(int nx, int ny);
	private:
		int level;
		CName **map;
		CName **playerMap;
		CName **trapMap;
		CName **brickMap;
		CName **foodMap;
		CName **monsterMap;
		const int levelBrickNumberX[5] = { 14, 14, 11, 16, 12};
		const int levelBrickNumberY[5] = { 14, 14, 18, 14, 17};
		int brickNumberX;
		int brickNumberY;
		int playerIndexX;
		int playerIndexY;
		bool undeleteFlag;
		CName mapInitLevel[5][18][22] =
		{
			{//1
				{  CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,    CName::MUD,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,    CName::MUD,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::SPACE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::STONE,  CName::SPACE,  CName::SPACE,  CName::STONE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::STONE,  CName::SPACE,  CName::SPACE,  CName::STONE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::STONE,  CName::STONE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::STONE,  CName::STONE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::BREAD,  CName::SPACE,  CName::SPACE,  CName::SPACE, CName::PLAYER,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::APPLE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::STONE, CName::MUTTON,  CName::SPACE,  CName::STONE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,    CName::MUD,  CName::SPACE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,    CName::MUD,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::SPACE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,    CName::MUD,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{ CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{ CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{ CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{ CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE}
			},
			{//2
				{  CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::SPACE,    CName::MUD,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,  CName::STONE,  CName::GRAPE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE, CName::TURKEY,  CName::STONE,   CName::WALL,    CName::MUD,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL, CName::WOODEN,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL, CName::WOODEN,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE, CName::TURTLE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL, CName::WOODEN,   CName::WALL,   CName::WALL, CName::WOODEN,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE, CName::PLAYER,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL, CName::TURTLE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL, CName::WOODEN,   CName::WALL,   CName::WALL, CName::WOODEN,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,    CName::MUD,   CName::WALL, CName::WOODEN,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL, CName::WOODEN,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,  CName::STONE, CName::TURKEY,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::GRAPE,  CName::STONE,  CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,    CName::MUD,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{ CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{ CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{ CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{ CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE}
			},
			{//3
				{  CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL, CName::PLAYER,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE, CName::TURTLE,  CName::SPACE,   CName::WALL,    CName::MUD,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,    CName::MUD,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::STONE,  CName::SPACE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,  CName::STEEL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::SPACE,  CName::STONE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,   CName::WALL,    CName::MUD,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL, CName::MUTTON,   CName::WALL,  CName::SPACE, CName::TURTLE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,    CName::MUD,   CName::WALL,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::STONE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,   CName::WALL,  CName::STEEL,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,    CName::MUD,  CName::SPACE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE, CName::TURKEY,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE, CName::TOMATO,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE}
			},
			{//4
				{  CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::STONE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,    CName::MUD,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,   CName::WALL,   CName::WALL, CName::WOODEN,   CName::WALL,   CName::WALL,   CName::WALL, CName::WOODEN,   CName::WALL,   CName::WALL,   CName::WALL,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,  CName::BREAD,   CName::WALL,  CName::SPACE,   CName::WALL, CName::TURKEY,   CName::WALL,  CName::SPACE,   CName::WALL, CName::CARROT,   CName::WALL,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL, CName::TURTLE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,    CName::MUD,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE, CName::TURTLE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,    CName::MUD,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,    CName::MUD,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL, CName::TURTLE,   CName::WALL,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,    CName::MUD,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::APPLE,   CName::WALL,  CName::SPACE,   CName::WALL, CName::MUTTON,   CName::WALL,  CName::SPACE,   CName::WALL, CName::TOMATO,   CName::WALL,  CName::SPACE,   CName::WALL,    CName::EGG,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,   CName::WALL,   CName::WALL, CName::WOODEN,   CName::WALL,   CName::WALL,   CName::WALL, CName::WOODEN,   CName::WALL,   CName::WALL,   CName::WALL, CName::WOODEN,   CName::WALL,   CName::WALL,  CName::STONE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL, CName::PLAYER,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::STONE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{ CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{ CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{ CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{ CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE}
			},
			{//5
				{  CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,    CName::MUD,  CName::SPACE,  CName::SPACE,  CName::SPACE,    CName::MUD,  CName::SPACE,  CName::SPACE,  CName::SPACE,    CName::MUD,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::STONE, CName::CARROT,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::GRAPE,  CName::STONE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::STONE,  CName::SPACE, CName::WOODEN, CName::WOODEN, CName::WOODEN, CName::WOODEN,  CName::SPACE,  CName::STONE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::STONE,  CName::SPACE, CName::WOODEN,  CName::SPACE,  CName::SPACE, CName::WOODEN,  CName::SPACE,  CName::STONE,    CName::MUD,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,    CName::MUD,  CName::STONE,  CName::SPACE, CName::WOODEN, CName::PLAYER,  CName::SPACE, CName::WOODEN,  CName::SPACE,  CName::STONE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::STONE,  CName::SPACE, CName::WOODEN,  CName::SPACE,  CName::SPACE, CName::WOODEN,  CName::SPACE,  CName::STONE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::STONE,  CName::APPLE, CName::WOODEN, CName::WOODEN, CName::WOODEN, CName::WOODEN,    CName::EGG,  CName::STONE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::STONE,  CName::SPACE, CName::WOODEN,  CName::SPACE,  CName::SPACE, CName::WOODEN,  CName::SPACE,  CName::STONE,    CName::MUD,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,    CName::MUD,  CName::STONE,  CName::SPACE, CName::WOODEN,  CName::SPACE,  CName::SPACE, CName::WOODEN,  CName::SPACE,  CName::STONE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::STONE,  CName::SPACE, CName::WOODEN,  CName::SPACE,  CName::SPACE, CName::WOODEN,  CName::SPACE,  CName::STONE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::STONE,  CName::SPACE, CName::WOODEN, CName::WOODEN, CName::WOODEN, CName::WOODEN,  CName::SPACE,  CName::STONE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::STONE,    CName::PIE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE, CName::TURKEY,  CName::STONE,    CName::MUD,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,    CName::MUD,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::STONE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,    CName::MUD,  CName::SPACE,  CName::SPACE,  CName::SPACE,    CName::MUD,  CName::SPACE,  CName::SPACE,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{  CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,   CName::WALL,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE},
				{ CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE,  CName::SPACE}
			}
		};
	};
}

#endif