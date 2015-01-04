#include "Moemon.h"

Moemon::Moemon(int id, int health, int attack, int defense, int SpAtk, int SpDef, int Speed, int level, std::string name, std::string type, std::string path, SDL_Renderer* renderer) : Entity(path, renderer)
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
	SDL_Texture* EntityTexture = NULL;
}
