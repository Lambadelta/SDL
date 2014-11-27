#include "Moemon.h"

Moemon::Moemon(int id, int health, int attack, int defense, int SpAtk, int SpDef, int Speed, int level, std::string name, std::string type) : Entity()
{
	i_ID = id;
	i_Health = health;	
	i_Attack = attack;
	i_Defense = defense;
	i_SpAtk = SpAtk;
	i_SpDef = SpDef;
	i_Speed = Speed;
	i_Level = level;
	s_MoeMonName = name;
	s_Type = type;

	SDL_Surface* EntitySurface = NULL;
	SDL_Texture* EntityTexture = NULL;
}
