#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL.h>
#include "Vec4.h"
#include "EventHandler.h"
#include "LoadTexture.h"
#include "Animation.h"

class Application : protected Animation, protected LoadTexture, protected EventHandler
{
public:
	Application(Vec4 v4);
	~Application();

	Animation Player;
	

	bool callInit();
	int CallExecution();
	void callEvent(SDL_Event* Event);
	void callLoop();
	void callRenderer();
	void callCleanup();

protected:
	bool GameLoop;
	SDL_Window* Display;
	int winPosX;
	int winPosY;
	int winWidth;
	int winHeight;
	Vec2 v2;
	SourceRect sr1;
	SDL_Surface* PlayerTexture;
};

#endif