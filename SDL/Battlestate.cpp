#include "BattleState.h"

BattleState::BattleState(Manager* GSManager, SDL_Renderer* Renderer, Player* player, Trainer* trainer) : Gamestate(GSManager,Renderer)
{
	renderer = Renderer;
	PEntity = player;
	TEntity = trainer;
	PlayerAnim = new Timer(1);
}

BattleState::~BattleState()
{

}

bool BattleState::EventHandle()
{
	return true;
}

void BattleState::update(float dt)
{
	PlayerAnim->updateTimer(dt);
	

}

void BattleState::draw()
{
	PEntity->callDraw(renderer);
	TEntity->getStorage()->get(1)->callDraw();
}

void BattleState::start()
{

}
