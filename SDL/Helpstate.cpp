#include "Helpstate.h"

Helpstate::Helpstate(Manager* GSManager, SDL_Renderer* renderer) : Gamestate(GSManager,renderer)
{
	Help = new Background("Asset/Menus/Help.png", renderer);
}

Helpstate::~Helpstate()
{
	delete Help;
}

bool Helpstate::EventHandle()
{
	SDL_Event eve;
	while (SDL_PollEvent(&eve))
	{
		switch (eve.type)
		{
		case SDL_QUIT:
			break;
		case SDL_KEYDOWN:
			switch (eve.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				GSManager->RemoveLast();
				break;
			}
		}
	}
	return true;
}

void Helpstate::update(float)
{

}

void Helpstate::draw()
{
	SDL_Rect rect = { 0, 0, 640, 480 };
	Help->callDraw(renderer, Help->getTexture(), rect, rect);
}
