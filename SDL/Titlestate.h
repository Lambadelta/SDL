#ifndef TITLESTATE_H
#define TITLESTATE_H

#include "Gamestate.h"
#include "Manager.h"
#include "Background.h"
#include "GameplayState.h"
#include "Creditsstate.h"
/**
@brief A class to create a title screen.

It is a derived class of Gamestate.
This is used to create the title menu of the game. 
When the game begins the class is destroyed through the manager.
*/
class Titlestate : public Gamestate
{
public:
	/**
	@brief This method takes in a pointer to a gamestate, and adds it to the gamestate vector.

	@param Manager* - A pointer to the manager.
	@param SDL_Renderer* - A pointer to the renderer the game is using.
	*/
	Titlestate(Manager*, SDL_Renderer*);

	~Titlestate();

	/**
	@brief This method takes in a pointer to a gamestate, and adds it to the gamestate vector.

	@param Gamestate* - A pointer to a gamestate.
	*/
	bool EventHandle();
	void update(float);
	void draw();

private:

	Background* Menu;

};
#endif