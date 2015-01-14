#ifndef BATTLESTATE_H
#define BATTLESTATE_H

#include "Gamestate.h"
#include "Manager.h"
#include "Player.h"
#include "Trainer.h"
#include "Timer.h"
class BattleState : public Gamestate
{
public:
	BattleState(Manager* GSManager, SDL_Renderer*, Player*, Trainer* );
	~BattleState();

	bool EventHandle();
	void update(float dt);
	void draw();
	void start();

private:

	Player* PEntity;
	Trainer* TEntity;

	int TEMoemonNum;
	int PEMoemonNum;
	float dt;
	int AnimationCount = 0;
	Timer* PlayerAnim;

};


#endif
