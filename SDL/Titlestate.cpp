#include "Titlestate.h"

Titlestate::Titlestate(Manager* GSManager, SDL_Renderer* renderer) : Gamestate(GSManager, renderer)
{
	Menu = new Background("Asset/Menus/TitleMenu.png", renderer);
}

Titlestate::~Titlestate()
{

}

bool Titlestate::EventHandle()
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
			case SDLK_RETURN:
				GSManager->Add(new GameplayState(GSManager, renderer, 640, 480));
				break;
			}
		}
	}
	return true;
}

void Titlestate::update(float dt)
{

}

void Titlestate::draw()
{
	SDL_Rect rect = { 0, 0, 640, 480 };
	Menu->callDraw(renderer, Menu->getTexture(), rect, rect);
}
