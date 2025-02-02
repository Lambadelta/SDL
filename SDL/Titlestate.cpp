#include "Titlestate.h"

Titlestate::Titlestate(Manager* GSManager, SDL_Renderer* renderer) : Gamestate(GSManager, renderer)
{
	Menu = new Background("Asset/Menus/TitleMenu.png", renderer);
	Title = Mix_LoadMUS("Asset/Music/Title.wav");
	Mix_PlayMusic(Title, -1);
	Mix_VolumeMusic(30);
}

Titlestate::~Titlestate()
{
	delete Menu;
	Mix_FreeMusic(Title);
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
				GSManager->Change(new GameplayState(GSManager, renderer, 640, 480));
				break;
			case SDLK_c:
				GSManager->Add(new Creditsstate(GSManager, renderer));
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
