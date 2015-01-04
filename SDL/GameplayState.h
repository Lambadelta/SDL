#ifndef GAMEPLAYSTATE_H
#define GAMEPLAYSTATE_H

#include "Gamestate.h"
#include "Manager.h"
#include "FileLoader.h"
#include "Player.h"
#include "Background.h"
#include "Entity.h"

class GameplayState : public Gamestate
{
public:
	GameplayState(Manager* GSManager, SDL_Renderer* renderer, int, int);
	~GameplayState();


	bool EventHandle();
	void update(float dt);
	void draw();
	void onInit();


private:
	///A time object for managing delta time
	Time time;
	///A FileLoader object for loading in the different files required
	FileLoader* fLoader;
	///A vector of Moemon that stores all the Moemon the application will use
	std::vector<Moemon> MoeMonList;
	///A vector of Skills that stores all of the MoeMon moves the application will use
	std::vector<Skill> SkillList;
	///A vector of Tiles that stores all of the tiles the application will use
	std::vector<Tile> TileList;

	std::vector<int> Route1;
	std::vector<int> Route1OB;
	///A Player object 
	Player* PlayerEntity;
	///A background object (subject to change)
	Background* Backgrounds;

	SDL_Rect Camera;

	Timer* AnimTime;

	int Mapx = 32;
	int Mapy = 32;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

	float speed;
	float deltatime;
};

#endif