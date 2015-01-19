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
#include "Helpstate.h"

class GameplayState : public Gamestate
{
public:
	GameplayState(Manager*, SDL_Renderer*, int, int);
	~GameplayState();


	bool EventHandle();
	void update(float);
	void draw();
	bool getcollision(int, std::string);
	void wildEncounter();
	void placeTrainers();
	int getposition();
	void healMoemon(int);
	bool trainerBattleCollision();
	int getTrainerPosition(int);
	Trainer* TrainerTest;

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
	std::vector<Trainer> TrainerList;
	std::vector<Maptile> Route1;
	std::vector<Maptile> Route1OB;
	std::vector<Maptile> Route1OW;
	std::vector<Maptile> Village;
	std::vector<Maptile> VillageOB;
	std::vector<Maptile> Town;
	std::vector<Maptile> TownOB;
	std::vector<Maptile> Gym;
	std::vector<Maptile> GymOB;
	std::vector<Maptile> GymOW;
	std::vector<Trainer*> TrainerMap1;
	std::vector<Trainer*> TrainerMap2;
	///A Player object 
	Player* PlayerEntity;
	///A background object (subject to change)
	Background* Backgrounds;
	Background* Trainers;

	Mix_Chunk* Heal;
	Mix_Music* BGM;

	SDL_Rect Camera;

	Timer* AnimTime;

	SDL_Rect collisionTest;
	SDL_Rect trainerBattleTest;
	int Mapx = 0;
	int Mapy = 0;
	int PreviousMapx;
	int PreviousMapy;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

	int initialspeed;
	int speed;
	float deltatime;
	int MapID;
};

#endif