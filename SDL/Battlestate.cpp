#include "BattleState.h"

BattleState::BattleState(Manager* GSManager, SDL_Renderer* Renderer, Player* player, Trainer* trainer) : Gamestate(GSManager,Renderer)
{
	renderer = Renderer;
	PEntity = player;
	TEntity = trainer;
	PlayerAnim = new Timer(2);
	Name = "Battle";
	Backgrounds = new Background("Asset/BattleBackgroundGrass.png", renderer);
	BattleTheme = Mix_LoadMUS("Asset/Music/LeaderTheme.wav");
	Mix_PlayMusic(BattleTheme, -1);
		TEntity->getStorage()->get(0)->setEnemy();
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
	
	SDL_Rect descRect;
	descRect.x = 0;
	descRect.y = 0;
	descRect.w = 640;
	descRect.h = 480;

	SDL_Rect ETrainerM;

	ETrainerM.x = 334;
	ETrainerM.y = 74;
	ETrainerM.w = (64 * 4);
	ETrainerM.h = (64 * 4);

	TEntity->getStorage()->get(0)->setDescRect(ETrainerM);
	Backgrounds->callDraw(renderer, Backgrounds->getTexture(), descRect, descRect);
	
	if (AnimationCount <= 5)
	{
		PEntity->battleAnimation(PlayerAnim, dt, renderer, AnimationCount);
	}
	if (AnimationCount >= 5)
	{
	
		PEntity->getBag()->get(0)->callDraw(renderer);
		TEntity->getStorage()->get(0)->callDraw(renderer);
	}
}
