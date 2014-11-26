#include "Moemon.h"

Moemon::Moemon(int id, int health, int level, std::string name, std::string type) : Entity()
{
	i_ID = id;
	i_Health = health;
	i_Level = level;
	s_MoeMonName = name;
	s_Type = type;
	SDL_Surface* EntitySurface = NULL;
	SDL_Texture* EntityTexture = NULL;
}
