#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H

#include "Gamestate.h"
#include "Manager.h"
#include "FileLoader.h"
#include "Player.h"
#include "Background.h"
#include "Entity.h"
#include "Maptile.h"
#include "BattleState.h"

class GameplayState : public Gamestate
{
public:
	GameplayState(Manager*, SDL_Renderer*, int, int);
	~GameplayState();


	bool EventHandle();
	void update(float dt);
	void draw();
	bool getcollision(int, std::string);

	int getposition();
	Trainer* TrainerTest;

private:
	///A time object for managing delta time
	Time time;
	///A FileLoader object for loading in the different files required
	FileLoader* fLoader;
	///A vector of Moemon that stores all the Moemon the application will use
	std::vector<Moemon*> MoeMonList;
	///A vector of Skills that stores all of the MoeMon moves the application will use
	std::vector<Skill*> SkillList;
	///A vector of Tiles that stores all of the tiles the application will use
	std::vector<Tile> TileList;
	std::vector<Trainer> TrainerList;
	std::vector<Maptile> Route1;
	std::vector<Maptile> Route1OB;
	
	///A Player object 
	Player* PlayerEntity;
	///A background object (subject to change)
	Background* Backgrounds;

	SDL_Rect Camera;

	Timer* AnimTime;

	SDL_Rect test;
	int Mapx = 0;
	int Mapy = 0;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

	int initialspeed;
	int speed;
	float deltatime;

};

#endif