#ifndef SKILL_H
#define SKILL_H

#include <string>

class Skill
{
public:
	Skill(int id, int power, int pp, int accuracy, int statusinflict, std::string n, std::string t, std::string desc);
	~Skill();

	std::string getName();
	std::string getDescription();
	std::string getType();
	int getPotency();
	int getID();
	int getAcc();
	int getCost();
	int getStatus();
	
private:
	int skillID;
	std::string name;
	std::string type;
	std::string description;
	int potency;
	int acc;
	int cost;
	int status;
};

#endif