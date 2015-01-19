#include "SkillStorage.h"
SkillStorage::~SkillStorage()
{
	Storage.clear();
}

void SkillStorage::add(Skill* New)
{

	Storage.push_back(New);
}

void SkillStorage::remove(int i)
{
	Storage.erase(Storage.begin() + i);
}
