#include "Moemon.h"

Moemon::Moemon(int id, int health, int attack, int defense, int SpAtk, int SpDef, int Speed, int level, std::string name, std::string type, std::string pathin, SDL_Renderer* rendererin) : Entity(pathin, rendererin)
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
	path = pathin;
	renderer = rendererin;

	EXP = 0;
	SrcRect.x = 0;
	SrcRect.y = 0;
	SrcRect.w = 64;
	SrcRect.h = 64;

	DescRect.x = 50;
	DescRect.y = 188;
	DescRect.w = (64 * 3);
	DescRect.h = (64 * 3);

	LearnedMoves = new SkillStorage();
	Name = new Text();
	Name->create(MoeMonName, renderer);
	createLevelText();
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
	Health = (((Health+50)*lvl)/50)+10;
	maxHealth = Health;
	Attack = (((Attack + 50)*lvl) / 50) + 5;
	Defense = (((Defense + 50)*lvl) / 50) + 5;
	SpAtk = (((SpAtk + 50)*lvl) / 50) + 5;
	SpDef = (((SpDef + 50)*lvl) / 50) + 5;
	Speed = (((Speed + 50)*lvl) / 50) + 5;
	Level = lvl;
}

SkillStorage* Moemon::getLearnedSkills()
{
	return LearnedMoves;
}

float Moemon::getHPPercentage()
{
	/*
	Basic dividing the current health by the max health, and then multipling it by 100;
	*/
	float Percentage = ((float)Health / (float)maxHealth) * 100.0f;
	return Percentage;
}

void Moemon::createLevelText()
{
	Lvl = new Text();
	std::string lvl = std::to_string(Level);
	Lvl->create(lvl, renderer);
}

void Moemon::cleanup()
{
	delete Name;
	delete Lvl;
	delete LearnedMoves;
}

void Moemon::checkIfLeveled()
{
	EXPtoLVL = Level * 10;

	if (EXP >= EXPtoLVL)
	{
		Level += 1;
		std::string lvl = std::to_string(Level);
		Lvl->create(lvl, renderer);
	}
}
