#ifndef MOEMON_H
#define MOEMON_H

#include "Entity.h"

class Moemon : public Entity
{
public:
	Moemon(int id, int health, int level, std::string name, std::string type);
	
private:

	int i_ID;
	int i_Health;
	int i_Level;
	std::string s_MoeMonName;
	std::string s_Type;


};


#endif