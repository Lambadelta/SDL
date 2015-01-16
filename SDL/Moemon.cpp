#include "Moemon.h"

Moemon::Moemon(int id, int health, int attack, int defense, int SpAtk, int SpDef, int Speed, int level, std::string name, std::string type, std::string path, SDL_Renderer* renderer) : Entity(path, renderer)
{
	ID = id;
	Health = health;	
	Attack = attack;
	Defense = defense;
	SpAtk = SpAtk;
	SpDef = SpDef;
	Speed = Speed;
	Level = level;
	MoeMonName = name;
	Type = type;

	SrcRect.x = 64;
	SrcRect.y = 0;
	SrcRect.w = 64;
	SrcRect.h = 64;

	DescRect.x = 50;
	DescRect.y = 188;
	DescRect.w = (64 * 3);
	DescRect.h = (64 * 3);

	LearnedMoves = new SkillStorage();

	
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
void Moemon::setLevel(int lvl)
{
	Health = Health*lvl;
	maxHealth = Health;
	Attack = Attack*lvl;
	Defense = Defense*lvl;
	SpAtk = SpAtk*lvl;
	SpDef = SpDef*lvl;
	Speed = Speed*lvl;
	Level = lvl;
}

SkillStorage* Moemon::getLearnedSkills()
{
	return LearnedMoves;
}
