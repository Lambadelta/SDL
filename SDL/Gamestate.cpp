#include "GameplayState.h"
Gamestate::Gamestate(Manager* GSManager, SDL_Renderer* renderer)
{
	this->GSManager = GSManager;
	this->renderer = renderer;
}

