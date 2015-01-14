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

void Moemon::setShiny()
{
	x = 32;
}

void Moemon::callDraw(SDL_Renderer* renderer)
{
	SrcRect.x = 0;
	SrcRect.y = 0;
	SrcRect.w = 40;
	SrcRect.h = 30;

	DescRect.x = 300;
	DescRect.y = 400;
	DescRect.w = 40;
	DescRect.h = 30;
	SDL_RenderCopy(renderer, EntityTexture, &SrcRect, &DescRect);
}