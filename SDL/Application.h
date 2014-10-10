#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL.h>
#include "Vec4.h"

class Application
{
public:
	Application(Vec4 v4);
	~Application();

	bool callInit();
	int CallExecution();
	void callEvent(SDL_Event* Event);
	void callLoop();
	void callRenderer();
	void callCleanup();

private:
	bool GameLoop;
	SDL_Window* Display;
	int winPosX;
	int winPosY;
	int winWidth;
	int winHeight;

};

#endif