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

	SrcRect.x = 64;
	SrcRect.y = 0;
	SrcRect.w = 64;
	SrcRect.h = 64;

	DescRect.x = 50;
	DescRect.y = 224;
	DescRect.w = (64 * 4);
	DescRect.h = (64 * 4);

	
}

void Moemon::setShiny()
{
	SrcRect.x += 64;
}

void Moemon::setEnemy()
{
	SrcRect.y = +64;
}

void Moemon::callDraw(SDL_Renderer* renderer)
{	
		SDL_RenderCopy(renderer, EntityTexture, &SrcRect, &DescRect);
		
}
void Moemon::setDescRect(SDL_Rect desc)
{
	DescRect = desc;
}
void Moemon::setLevel(int level)
{
	i_Health = i_Health*level;
	i_Attack = i_Attack*level;
	i_Defense = i_Defense*level;
	i_SpAtk = i_SpAtk*level;
	i_SpDef = i_SpDef*level;
	i_Speed = i_Speed*level;
	i_Level = i_Level*level;
}
