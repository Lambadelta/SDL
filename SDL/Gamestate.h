#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SDL.h>
#include <string>

class Manager;

class Gamestate
{
public:
	Gamestate(Manager* GSManager, SDL_Renderer* renderer);
	virtual ~Gamestate() {};

	virtual bool EventHandle() = 0;
	virtual void update(float dt) = 0;
	virtual void draw() = 0;

	std::string getname() {return Name;}
protected:

	Manager* GSManager;
	SDL_Renderer* renderer;
	std::string Name;
};

#endif