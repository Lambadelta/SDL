#include "Creditsstate.h"

Creditsstate::Creditsstate(Manager*GSManager, SDL_Renderer* renderer) : Gamestate(GSManager, renderer)
{
	Credits = new Background("Asset/Menus/Credits.png", renderer);
}

Creditsstate::~Creditsstate()
{
	delete Credits;
}

bool Creditsstate::EventHandle()
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

void Creditsstate::update(float dt)
{

}

void Creditsstate::draw()
{
	SDL_Rect rect = { 0, 0, 640, 480 };
	Credits->callDraw(renderer, Credits->getTexture(), rect, rect);
}
