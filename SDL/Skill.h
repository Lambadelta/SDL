#ifndef SKILL_H
#define SKILL_H

#include <string>

class Skill
{
public:
	Skill(std::string name, std::string type, std::string description, int potency, int id, int acc, int cost);
	~Skill();

	std::string getName();
	std::string getDescription();
	std::string getType();
	int getPotency();
	int getID();
	int getAcc();
	int getCost();
	
private:
	int skillID;
	std::string name;
	std::string type;
	std::string description;
	int potency;
	int acc;
	int cost;
};

#endif