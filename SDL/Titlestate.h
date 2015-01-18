#ifndef TITLESTATE_H
#define TITLESTATE_H

#include "Gamestate.h"
#include "Manager.h"
#include "Background.h"
#include "GameplayState.h"

class Titlestate : public Gamestate
{
public:
	Titlestate(Manager*, SDL_Renderer*);
	~Titlestate();


	bool EventHandle();
	void update(float dt);
	void draw();

private:

	Background* Menu;

};
#endif