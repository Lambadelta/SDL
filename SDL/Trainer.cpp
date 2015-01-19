#include "Trainer.h"

Trainer::Trainer(int ind, int xpos, int ypos, std::string path,SDL_Renderer* renderer, MoeMonStorage* temp) : Entity(path, renderer)
{
	index = ind;
	SrcRect = { xpos, ypos, 20, 20 };
	defeated = false;

	MoeMon = temp;
	for (unsigned int i = 0; i < MoeMon->getStorage().size(); i++)
	{
		MoeMon->get(i)->setEnemy();
	}
}

Trainer::Trainer(MoeMonStorage* wild, std::string path, SDL_Renderer* renderer) : Entity(path,renderer)
{
	wild->get(0)->setEnemy();
	MoeMon = wild;
}

Trainer::~Trainer()
{

}

void Trainer::Move()
{

}

void Trainer::setDefeated(bool defeat)
{
	defeated = defeat;
}

void Trainer::callDraw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, EntityTexture, &SrcRect, &DescRect);
}

void Trainer::BattleAnimation(SDL_Renderer* renderer)
{
	SDL_Rect AnimaRect = { 380, 40, 82 * 2.5, 82 * 2.5 };
	SDL_RenderCopy(renderer, EntityTexture, NULL, &AnimaRect);
}
