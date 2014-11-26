#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "SDL.h"
#include "Time.h"
#include "Timer.h"
#include "Player.h"
#include <iostream>

class EventHandler
{
public:
	EventHandler();
	~EventHandler();

	void updateTime(Time dt);
	void runKeyboard(SDL_Keycode move, Player* Trainer, Time dt);

	
protected:
	Timer* PlayerAnim;
};


#endif