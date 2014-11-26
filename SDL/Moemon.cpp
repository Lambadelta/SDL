#include "Moemon.h"

Moemon::Moemon(int id, int health, int level, char* name, char* type) : Entity()
{
	i_ID = id;
	i_Health = health;
	i_Level = level;
	c_MoeMonName = name;
	c_Type = type;
	SDL_Surface* SpriteS = NULL;
	SDL_Texture* SpriteT = NULL;
}

Moemon::~Moemon()
{

}

