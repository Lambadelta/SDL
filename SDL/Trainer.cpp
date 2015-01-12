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

