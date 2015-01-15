#include "SkillStorage.h"

SkillStorage::SkillStorage()
{

}

SkillStorage::~SkillStorage()
{

}

void SkillStorage::add(Skill* New)
{
	Skill *temp = New;
	Storage.push_back(temp);
}

void SkillStorage::remove(int i)
{
	delete Storage[i];
	Storage.erase(Storage.begin() + i);
}

void SkillStorage::useSkill(int i)
{
	int cost = Storage[i]->getCost();
	int Potency = Storage[i]->getPotency();
	int Acc = Storage[i]->getAcc();
}
