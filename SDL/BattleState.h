#ifndef BATTLESTATE_H
#define BATTLESTATE_H

#include "Gamestate.h"
#include "Manager.h"
#include "Player.h"
#include "Trainer.h"

class BattleState
{
public:
	BattleState(Manager* GSManager, SDL_Renderer* renderer, Player*, Trainer* );
	BattleState();

	bool EventHandle();
	void update(float dt);
	void draw();

private:

};


#endif
