#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL.h>
#include <sstream>
#include "Vec4.h"
#include "LoadTexture.h"
#include "Animation.h"
#include "Entity.h"
#include "Background.h"
#include "Tile.h"


class Application
{
public:
	Application();
	~Application();
	

	bool callInit();
	int callExecution();
	void callEvent(SDL_Event* Event);
	void callLoop();
	void callRenderer();
	void callCleanup();
	void callSurface();
	void callTexture();

protected:
	bool GameLoop;
	SDL_Window* Display;
	int SurfaceCall;
	//Vec2 v2;
	//SourceRect sr1;
	Entity* PlayerEntity;
	Background* Backgrounds;
	SDL_Renderer * Renderer;
	LoadTexture* TextureLoader;
	Tile* TileLoader;

	/* Assigning the size of the window*/
	const int WINDOW_X = 100;
	const int WINDOW_Y = 100;
	const int WINDOW_WIDTH = 1024;
	const int WINDOW_HEIGHT = 768;

	
};

#endif