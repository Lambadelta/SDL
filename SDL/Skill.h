#ifndef SKILL_H
#define SKILL_H

#include <string>
#include "Text.h"

class Skill
{
public:
	Skill(int, int, int, int, int, std::string, std::string, std::string, SDL_Renderer*);
	~Skill();

	std::string getDescription();
	std::string getType();
	int getAttack();
	int getID();
	int getAcc();
	int getCost();
	int getStatus();
	std::string getName(){if (name == "")	{	return NULL;	}	return name;	}
	Text* getText() { return Name; };
	
private:
	int skillID;
	std::string name;
	std::string type;
	std::string description;
	int potency;
	int acc;
	int cost;
	int status;
	Text* Name;
};

#endif