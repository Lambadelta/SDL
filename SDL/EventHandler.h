#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <SDL.H>

class EventHandler
{
public:
	EventHandler();
	~EventHandler();

	virtual void onEvent(SDL_Event* Event);
	virtual void onKeyUp();
	virtual void onKeyDown();
	virtual void onKeyLeft();
	virtual void onKeyRight();
	virtual void onKeyE();
	virtual void onKeySpace();
	virtual void onKeyEsc();
	virtual void onExit();

};


#endif