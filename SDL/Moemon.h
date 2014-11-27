#ifndef MOEMON_H
#define MOEMON_H

#include "Entity.h"

class Moemon : public Entity
{
public:
	Moemon(int id, int health, int attack, int defense, int SpAtk, int SpDef, int Speed, int level, std::string name, std::string type);
	
private:

	int i_ID;
	int i_Health;
	int i_Level;
	int i_Attack;
	int i_Defense;
	int i_SpAtk;
	int i_SpDef;
	int i_Speed;
	std::string s_MoeMonName;
	std::string s_Type;


};


#endif