#include "Trainer.h"

Trainer::Trainer(int ind, int xpos, int ypos, std::string path,SDL_Renderer* renderer, MoeMonStorage* temp) : Entity(path, renderer)
{
	index = ind;
	x = xpos;
	y = ypos;
	defeated = false;
	MoeMon = temp;
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
