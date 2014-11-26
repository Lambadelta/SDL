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
	std::string str;
	for (int i = 0; i < MOEMONNUMBER; i++)
	{
		if (MoeMon.fail())
		{
			printf("Unexpected Error has Occurred: Stream failbit. Error");
		}
		if (MoeMon.bad())
		{
			printf("Unexpected Error has Occurred: Stream Badbit. Error");
		}
		int id = -1;
		int health = -1;
		int level = -1;
		std::string name;
		std::string type;
		MoeMon >> id;
		MoeMon >> health;
		MoeMon >> level;
		std::getline(MoeMon, name, ',');
		std::getline(MoeMon, type, '.');
		List.push_back(Moemon(id, health, level, name, type));

	}
}