#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL.h>
#include "Vec4.h"
#include "LoadTexture.h"
#include "Animation.h"
#include "Entity.h"

class Application : protected Animation, public LoadTexture
{
public:
	Application(Vec4 v4);
	~Application();
	

	bool callInit();
	int callExecution();
	void callEvent(SDL_Event* Event);
	void callQuery();
	void callLoop();
	void callTexture();
	void callRenderer();
	void callCleanup();

protected:
	bool GameLoop;
	SDL_Window* Display;
	int winPosX;
	int winPosY;
	int winWidth;
	int winHeight;
	//Vec2 v2;
	//SourceRect sr1;
	Entity*  PlayerEntity;
	SDL_Renderer * Renderer;
};

#endif