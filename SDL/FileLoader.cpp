#include "FileLoader.h"

FileLoader::FileLoader()
{

}

FileLoader::~FileLoader()
{

}


void FileLoader::LoadMoeMonFile(std::vector<Moemon> &List)
{
	std::ifstream MoeMon("Asset/Entity/MoeMon.txt");
	if (!MoeMon)
	{
		printf("Unexpected Error has Occurred : MoeMon.txt has failed to load\n");
	}
	for (int i = 0; i < MOEMONNUMBER; i++)
	{
		if (MoeMon.fail())
		{
			printf("Unexpected Error has Occurred: Stream failbit. Error\n");
		}
		if (MoeMon.bad())
		{
			printf("Unexpected Error has Occurred: Stream Badbit. Error\n");
		}
		int id = -1;	 int health = -1;
		int attack = -1; int defense = -1;
		int SpAtk = -1;	 int SpDef = -1;
		int Speed = -1;	 int level = -1;

		std::string name;	std::string type;

		MoeMon >> id;	    MoeMon >> health;
		MoeMon >> attack;	MoeMon >> defense;
		MoeMon >> SpAtk;	MoeMon >> SpDef;
		MoeMon >> Speed;    MoeMon >> level;
		std::getline(MoeMon, name, ',');
		std::getline(MoeMon, type, '.');

		List.push_back(Moemon(id, health, attack, defense, SpAtk, SpDef, Speed, level, name, type));

	}
}

void FileLoader::LoadSkillFile(std::vector<Skill>& List)
{
	std::ifstream SkillList("Asset/SkillList.txt");
	if (!SkillList)
	{
		printf("Unexpected Error has Occurred : SkillList.txt has failed to load\n");
	}
	for (int i = 0; i < SKILLNUMBER; i++)
	{
		if (SkillList.fail())
		{
			printf("Unexpected Error has Occurred: Stream failbit. Error\n");
		}
		if (SkillList.bad())
		{
			printf("Unexpected Error has Occurred: Stream Badbit. Error\n");
		}
		int id = -1;   int power = -1;
		int cost = -1; int acc = -1;
		int statusinflict = -1;
		std::string name; std::string type; std::string description;

		SkillList >> id;
		SkillList >> power;
		SkillList >> cost;
		SkillList >> acc;
		SkillList >> statusinflict;
		std::getline(SkillList, name, ',');
		std::getline(SkillList, type, ',');
		std::getline(SkillList, description, ';');

		List.push_back(Skill(id, power, cost, acc, statusinflict,name, type, description));


	}
}
void FileLoader::LoadTileFile(std::vector<Tile>& List)
{
	std::ifstream TileList("Asset/Tiles.txt");
	if (!TileList)
	{
		printf("Unexpected Error has Occurred : Tiles.txt has failed to load\n");
	}
	for (int i = 0; i < TILENUMBER; i++)
	{
		if (TileList.fail())
		{
			printf("Unexpected Error has Occurred: Stream failbit. Error\n");
		}
		if (TileList.bad())
		{
			printf("Unexpected Error has Occurred: Stream Badbit. Error\n");
		}
		int x = -1;
		int y = -1;
		int id = -1;

		TileList >> id;
		TileList >> y;
		TileList >> x;


		List.push_back(Tile(x, y, id));
	}
}

void FileLoader::LoadMapFile(std::vector<int>& Map)
{
	int Mapsize = -1;
	std::ifstream MapCoord("Asset/MapTest.txt");
	if (!MapCoord)
	{
		printf("Unexpected Error has Occurred : Tiles.txt has failed to load\n");
	}
	MapCoord >> Mapsize;
	for (int i = 0; i < Mapsize; i++)
	{
		if (MapCoord.fail())
		{
			printf("Unexpected Error has Occurred: Stream failbit. Error\n");
		}
		if (MapCoord.bad())
		{
			printf("Unexpected Error has Occurred: Stream Badbit. Error\n");
		}

		int tile = -1;

		MapCoord >> tile;

		Map.push_back(tile);

	}
		

}