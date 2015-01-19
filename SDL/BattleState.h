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
#include "Titlestate.h"

class BattleState : public Gamestate
{
public:
	BattleState(Manager*, SDL_Renderer*, Player*, Moemon*);
	BattleState(Manager*, SDL_Renderer*, Player*, Trainer* );
	BattleState(Manager*, SDL_Renderer*, Player*, Trainer*,bool);
	~BattleState();

	bool EventHandle();
	void update(float);
	void draw();
	void menu();
	void init();
	void textInit();
	bool useSkill();
	float STAB();
	void AI();
	void checkPDefeat();
	void checkTDefeat();

private:

	Player* PEntity;
	Trainer* TEntity;
	MoeMonStorage* Wild;

	int TEMoemonNum;
	int PEMoemonNum;
	int MenuSelection;
	float dt;
	bool MBattleMenu;
	bool PlayerTurn;
	int EnemySelection;
	int AnimationCount = 0;
	bool GymBattle;
	Timer* PlayerAnim;
	Background* Backgrounds;
	Background* Menu;
	Background* HealthBars;
	Background* Health;
	Mix_Music* BattleTheme;
	std::vector<Text*> TMenu;
	std::vector<Text*> TSMenu;

	SDL_Rect THealthBar;
	SDL_Rect PHealthBar;

	SDL_Rect TNameLoc;
	SDL_Rect PNameLoc;
	SDL_Rect TLevelLoc;
	SDL_Rect PLevelLoc;
};


#endif
