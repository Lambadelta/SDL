#include "BattleState.h"

BattleState::BattleState(Manager* GSManager, SDL_Renderer* Renderer, Player* player, Trainer* trainer) : Gamestate(GSManager,Renderer)
{
	renderer = Renderer;
	PEntity = player;
	TEntity = trainer;
	PlayerAnim = new Timer(1);
	start();
}

BattleState::~BattleState()
{

}

bool BattleState::EventHandle()
{
	SDL_Event eve;
	while (SDL_PollEvent(&eve))
	{
		switch (eve.type)
		{
		case SDL_QUIT:
			break;
		case SDL_KEYDOWN:
			switch (eve.key.keysym.sym)
			{
			case SDLK_w:
				break;
			case SDLK_s:
				break;
			case SDLK_d:
				break;
			case SDLK_a:
				break;
			case SDLK_k:
				GSManager->RemoveLast();
				break;
			}
		}
	}
	return true;
}

void BattleState::update(float deltat)
{
	dt = deltat;
	PlayerAnim->updateTimer(dt);
	

}

void BattleState::draw()
{
	start();
	if (AnimationCount > 5)
	{
		/*PEntity->callDraw(renderer);*/
		TEntity->getStorage()->get(0)->callDraw(renderer);
	}
}

void BattleState::start()
{
	if (AnimationCount <= 5)
	{
		PEntity->battleAnimation(PlayerAnim, dt, renderer, AnimationCount);
	}
}
