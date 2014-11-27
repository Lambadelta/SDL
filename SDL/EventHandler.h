#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "SDL.h"
#include "Time.h"
#include "Timer.h"
#include "Player.h"
#include <iostream>

/**
@brief A Class that represents the Event Handler

This class contains the methods to control events that happen during runtime.
It contains timers for different events, and can update the time.

*/
class EventHandler
{
public:
	/**
	@brief The constructor called on creation of the EventHandler

	It doesn't do anything.
	*/
	EventHandler();
	/**
	@brief The deconstructor called on destruction of the EventHandler

	*/
	~EventHandler();
	/**
	@brief A Method to update time

	@param Time - An object representing time
	*/
	void updateTime(Time dt);
	/**
	@brief A Method to control keyboard events

	@param SDL_Keycode - The keycode of the type of keyboard event
	@param Player* - An object representing the player
	@param Time - An object representing time
	*/
	void runKeyboard(SDL_Keycode move, Player* Trainer, Time dt);

	
protected:
	///A timer object for timing the player animation
	Timer* PlayerAnim;
};


#endif