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

	SrcRect.x = 64;
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

	
}

Moemon::Moemon(const Moemon& mm) : Entity(mm.path,mm.renderer)
{
	ID = mm.ID;
	Health = mm.Health;
	Attack = mm.Attack;
	Defense = mm.Defense;
	SpAtk = mm.SpAtk;
	SpDef = mm.SpDef;
	Speed = mm.Speed;
	Level = mm.Level;
	MoeMonName = mm.MoeMonName;
	Type = mm.Type;
	path = mm.path;
	renderer = mm.renderer;

	SrcRect.x = 64;
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
