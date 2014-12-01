#include "Skill.h"

Skill::Skill(int id, int power, int pp, int accuracy, int statusinflict, std::string n, std::string t, std::string desc)
{
	name = n;
	type = t;
	description = desc;
	potency = power;
	skillID = id;
	acc = accuracy;
	cost = pp;
	status = statusinflict;
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

int Skill::getStatus()
{
	return status;
}
