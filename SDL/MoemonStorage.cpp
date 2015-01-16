#include "MoemonStorage.h"


MoeMonStorage::MoeMonStorage()
{

}

MoeMonStorage::~MoeMonStorage()
{

}

void MoeMonStorage::add(Moemon* New, int level)
{
	Moemon* temp = New;
	temp->setLevel(level);
	Storage.push_back(New);
}

void MoeMonStorage::remove(int id)
{
	Storage.erase(Storage.begin() + id);
}

Moemon* MoeMonStorage::get(int id)
{
	return Storage[id];
}
