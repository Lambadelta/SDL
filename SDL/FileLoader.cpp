#include "FileLoader.h"

FileLoader::FileLoader()
{

}

FileLoader::~FileLoader()
{

}


void FileLoader::LoadMoeMonFile(std::vector<Moemon> &List, SDL_Renderer* renderer)
{
	int Moemonsize = -1;
	std::ifstream MoeMon("Asset/Entity/Moemon/MoeMon.txt");
	if (!MoeMon)
	{
		printf("Unexpected Error has Occurred : MoeMon.txt has failed to load\n");
	}
	MoeMon >> Moemonsize;
	for (int i = 0; i < Moemonsize; i++) 
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
		std::string path;   std::string remove;

		MoeMon >> id;	    MoeMon >> health;
		MoeMon >> attack;	MoeMon >> defense;
		MoeMon >> SpAtk;	MoeMon >> SpDef;
		MoeMon >> Speed;    MoeMon >> level;
		std::getline(MoeMon, remove, ',');
		std::getline(MoeMon, name, ',');
		std::getline(MoeMon, type, ',');
		std::getline(MoeMon, path, ';');

		List.push_back(Moemon(id, health, attack, defense, SpAtk, SpDef, Speed, level, name, type, path, renderer));

	}
	MoeMon.close();
}

void FileLoader::LoadSkillFile(std::vector<Skill>& List, SDL_Renderer* renderer)
{
	int Skillsize = -1;
	std::ifstream SkillList("Asset/SkillList.txt");
	if (!SkillList)
	{
		printf("Unexpected Error has Occurred : SkillList.txt has failed to load\n");
	}
	SkillList >> Skillsize;
	for (int i = 0; i < Skillsize; i++)
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

		List.push_back(Skill(id, power, cost, acc, statusinflict,name, type, description,renderer));


	}
	SkillList.close();
}
void FileLoader::LoadTileFile(std::vector<Tile>& List)
{
	int tilesize = -1;
	std::ifstream TileList("Asset/Tiles.txt");
	if (!TileList)
	{
		printf("Unexpected Error has Occurred : Tiles.txt has failed to load\n");
	}
	TileList >> tilesize;
	for (int i = 0; i < tilesize; i++)
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
		bool collision = 0;

		TileList >> id;
		TileList >> y;
		TileList >> x;
		TileList >> collision;

		List.push_back(Tile(x, y, id, collision));
	}
	TileList.close();
}

void FileLoader::LoadMapFile(std::vector<Maptile>& Map, std::string path)
{
	std::vector<int>Tempmap;
	int Mapsize = -1;
	std::ifstream MapCoord(path);
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

		Tempmap.push_back(tile);

	}

	int y = 0;
	int x = 0;
	for (unsigned int j = 0; j < Tempmap.size(); j++)
	{

		if (Tempmap[j] == 0)
		{
			y += 1;
			x = -1;
		}

		int type = Tempmap[j];
		Map.push_back(Maptile(j, x * 32, y * 32, type));
		x++;
	}
	MapCoord.close();

}

void FileLoader::LoadTrainerFile(std::vector<Trainer>& List, std::vector<Moemon>& Ref,std::vector<Skill>& SRef, SDL_Renderer* renderer)
{
	int Trainersize = -1;
	std::ifstream TrainerList("Asset/Entity/Trainers/Trainer.txt");
	if (!TrainerList)
	{
		printf("Unexpected Error has Occurred : Trainers.txt has failed to load\n");
	}
	TrainerList >> Trainersize;
	for (int i = 0; i < Trainersize; i++)
	{
		int id = -1;
		int x = -1;
		int y = -1;
		std::string image;
		int mmone = -1;	    int mmtwo = -1;
		int level1 = -1;		int level2 = -1;
		int mmones1 = -1; int mmones2 = -1;
		int mmtwos1 = -1; int mmtwos2 = -1;
		std::string remove;
		
		TrainerList >> id; 
		TrainerList >> x;
		TrainerList >> y;
		TrainerList >> mmone;
		TrainerList >> level1;
		TrainerList >> mmones1;
		TrainerList >> mmones2;
		TrainerList >> mmtwo;
		TrainerList >> level2;
		TrainerList >> mmtwos1;
		TrainerList >> mmtwos2;
		std::getline(TrainerList, remove, ',');
		std::getline(TrainerList, image, ';');
		MoeMonStorage * temp = new MoeMonStorage();
		SkillStorage* temp1 = new SkillStorage();
		SkillStorage* temp2 = new SkillStorage();
		temp->add(Ref[mmone].clone(), level1);
		temp1->add(SRef[mmones1].clone());
		temp1->add(SRef[mmones2].clone());
		temp->add(Ref[mmtwo].clone(), level2);
		temp2->add(SRef[mmtwos1].clone());
		temp2->add(SRef[mmtwos2].clone());
		temp->get(0)->setLearnedSkills(temp1);
		temp->get(1)->setLearnedSkills(temp2);
		List.push_back(Trainer(id, (x * 20), (y * 20), image, renderer, temp->clone()));
		//delete temp;



	}
	TrainerList.close();
}
