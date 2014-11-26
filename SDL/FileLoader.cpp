#include "FileLoader.h"

FileLoader::FileLoader()
{

}

FileLoader::~FileLoader()
{

}

bool FileLoader::LoadMoeMonFile(Moemon* MoeMonList[])
{
	std::ifstream MoeMon("Asset/Entity/MoeMon.txt");

	
	//for (int i = 0; i < MOEMONNUMBER; i++)
	//{
	//	int id = -1;
	//	int health = -1;
	//	int level = -1;
	//	char* name = "";
	//	char* type = "";
	//	MoeMon >> id;
	//	MoeMon >> health;
	//	MoeMon >> level;
	//	/*MoeMon >> name;
	//	MoeMon >> type;*/

	//	if (MoeMon.fail())
	//	{
	//		printf("Error Loading MoeMon : Unexpected Error\n");
	//		return false;
	//	}

	//	if (id >= 001 && id <= 030)
	//	{
	//		MoeMonList[i] = new Moemon(id, health, level, name, type);
	//	}
	//}

	return true;
}

std::vector<Moemon> FileLoader::LoadMoeMonFile()
{
	std::ifstream MoeMon("Asset/Entity/MoeMon.txt", std::ios::in);
	if (!MoeMon)
	{
		printf("Unexpected Error has Occurred : MoeMon.txt has failed to load\n");
	}
	std::vector<Moemon> List;
	while (true)
	{
		int id = -1;
		int health = -1;
		int level = -1;
		char* name = "";
		char* type = "";
		MoeMon >> id;
		MoeMon >> health;
		MoeMon >> level;
		MoeMon.read(reinterpret_cast<char*> (name), 9);
		MoeMon.read(reinterpret_cast<char*> (type), 9);
		List.push_back(Moemon(id, health, level, name, type));

	}

	return List;
}