#include "Trainer.h"

Trainer::Trainer(int ind, int xpos, int ypos, std::string path,SDL_Renderer* renderer, MoeMonStorage*) : Entity(path, renderer)
{
	index = ind;
	x = xpos;
	y = ypos;
	defeated = false;
}

void Trainer::Move()
{

}

void Trainer::setDefeated(bool defeat)
{
	defeated = defeat;
}

bool Trainer::isDefeated()
{
	return defeated;
}

