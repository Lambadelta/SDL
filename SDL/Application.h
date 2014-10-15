#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL.h>
#include <sstream>
#include "Vec4.h"
#include "LoadTexture.h"
#include "Animation.h"
#include "Entity.h"


class Application
{
public:
	Application(Vec4 v4);
	~Application();
	

	bool callInit();
	int callExecution();
	void callEvent(SDL_Event* Event);
	void callLoop();
	void callRenderer();
	void callCleanup();
	void callSurface();

protected:
	bool GameLoop;
	SDL_Window* Display;
	int winPosX;
	int winPosY;
	int winWidth;
	int winHeight;
	//Vec2 v2;
	//SourceRect sr1;
	Entity* PlayerEntity;
	SDL_Surface* Background;
	SDL_Renderer * Renderer;
	LoadTexture* TextureLoader; 
	SDL_Rect BackRect;

	
};

#endif