#include "Skill.h"

Skill::Skill(int id, int power, int pp, int accuracy, int statusinflict, std::string n, std::string t, std::string desc,SDL_Renderer* renderer)
{
	name = n;
	type = t;
	description = desc;
	potency = power;
	skillID = id;
	acc = accuracy;
	cost = pp;
	status = statusinflict;
	Name = new Text();
	Name->create(name, renderer);
}

Skill::~Skill()
{

}


std::string Skill::getDescription()
{
	return description;
}

std::string Skill::getType()
{
	return type;
}

int Skill::getAttack()
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
