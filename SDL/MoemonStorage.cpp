#include "MoemonStorage.h"

MoeMonStorage::~MoeMonStorage()
{
	Storage.clear();
}

void MoeMonStorage::add(Moemon* New, int level)
{
	Moemon* temp = New;
	temp->setLevel(level);
	temp->createLevelText();
	Storage.push_back(temp);
}

void MoeMonStorage::remove(int id)
{
	Storage.erase(Storage.begin() + id);
}

Moemon* MoeMonStorage::get(int id)
{
	return Storage[id];
}
