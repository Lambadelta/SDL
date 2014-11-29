#include "Skill.h"

Skill::Skill(std::string name, std::string type, std::string description, int potency, int id, int acc, int cost)
{
	name = name;
	type = type;
	description = description;
	potency = potency;
	skillID = id;
	acc = acc;
	cost = cost;
}

Skill::~Skill()
{

}

std::string Skill::getName()
{
	return name;
}

std::string Skill::getDescription()
{
	return description;
}

std::string Skill::getType()
{
	return type;
}

int Skill::getPotency()
{
	return potency;
}

int Skill::getID()
{
	return skillID;
}

int Skill::getAcc()
{
	return acc;
}

int Skill::getCost()
{
	return cost;
}
