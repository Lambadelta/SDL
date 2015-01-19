#ifndef HELPSTATE_H
#define HELPSTATE_H

#include "Gamestate.h"
#include "Manager.h"
#include "Background.h"

class Helpstate : public Gamestate
{
public:
	Helpstate(Manager*, SDL_Renderer*);
	~Helpstate();


	bool EventHandle();
	void update(float);
	void draw();

private:

	Background* Help;

};
#endif