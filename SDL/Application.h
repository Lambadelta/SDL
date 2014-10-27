#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL.h>
#include <sstream>
#include <SDL_image.h>
#include "Vec4.h"
#include "LoadTexture.h"
#include "Animation.h"
#include "Background.h"
#include "Tile.h"
#include "Time.h"
#include "Player.h"


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
	Player* PlayerEntity;
	Background* Backgrounds;
	SDL_Renderer * Renderer;
	LoadTexture* TextureLoader;
	Tile* TileLoader;
	Time time;
	Timer* Anim;
	float ftime;
	/* Assigning the size of the window*/
	const int WINDOW_X = 100;
	const int WINDOW_Y = 100;
	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;
	const int WINDOW_FPS = 60;
	const int WINDOW_TICKS_PER_FRAME = 1000 / WINDOW_FPS;

	/*debug*/

	float ftimer;

	
};

#endif