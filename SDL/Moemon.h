#ifndef MOEMON_H
#define MOEMON_H

#include "Entity.h"

class Moemon : public Entity
{
public:
	Moemon(int id, int health, int level, char* name, char* type);
	~Moemon();
	
private:

	int i_ID;
	int i_Health;
	int i_Level;
	char* c_MoeMonName;
	char* c_Type;
	SDL_Surface* SpriteS;
	SDL_Texture* SpriteT;


};


#endif