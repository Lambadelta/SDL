#ifndef BATTLESTATE_H
#define BATTLESTATE_H

#include "Gamestate.h"
#include "Manager.h"
#include "Player.h"
#include "Trainer.h"
#include "Timer.h"
#include "Background.h"
#include <SDL_mixer.h>
#include "Text.h"

class BattleState : public Gamestate
{
public:
	BattleState(Manager* GSManager, SDL_Renderer*, Player*, Trainer* );
	~BattleState();

	bool EventHandle();
	void update(float dt);
	void draw();
	void menu();
	void textInit();
	void useSkill();
	float STAB();
	void AI();

private:

	Player* PEntity;
	Trainer* TEntity;

	int TEMoemonNum;
	int PEMoemonNum;
	int MenuSelection;
	float dt;
	bool MBattleMenu;
	bool PlayerTurn;
	int EnemySelection;
	int AnimationCount = 0;
	Timer* PlayerAnim;
	Background* Backgrounds;
	Background* Menu;
	Mix_Music* BattleTheme;
	Text* textManager;
	std::vector<Text*> TMenu;
	std::vector<Text*> TSMenu;
};


#endif
