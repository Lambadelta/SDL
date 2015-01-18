#ifndef CREDITSSTATE_H
#define CREDITSSTATE_H

#include "Gamestate.h"
#include "Manager.h"
#include "Background.h"
#include "GameplayState.h"

class Creditsstate : public Gamestate
{
public:
	Creditsstate(Manager*, SDL_Renderer*);
	~Creditsstate();


	bool EventHandle();
	void update(float dt);
	void draw();

private:

	Background* Credits;

};
#endif