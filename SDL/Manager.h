#ifndef MANAGER_H
#define MANAGER_H

#include "Gamestate.h"
#include <iostream>
#include <vector>

class Manager
{
public:
	~Manager();

	void Add(Gamestate* GS);
	void Change(Gamestate* GS);
	void RemoveLast();

	bool EventHandle();
	void update(float dt);
	void draw();

private:
	std::vector<Gamestate*> vGS;
};

#endif