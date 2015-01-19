#include "GameplayState.h"


GameplayState::GameplayState(Manager* GSManager, SDL_Renderer* Renderer,int Width, int Height) : Gamestate(GSManager, Renderer)
{
	fLoader = new FileLoader;
	SCREEN_WIDTH = Width;
	SCREEN_HEIGHT = Height;
	Camera.x = 0;
	Camera.y = 0;
	Camera.w = 640;
	Camera.h = 480;
	Name = "Gameplay";
	MapID = 0;
	PlayerEntity = new Player(Rect(256,256, 32, 32), Rect(0, 0, 50, 50), "Asset/Entity/Player/player.png", renderer);
	Backgrounds = new Background("Asset/Maps/map.png", renderer);
	BGM = Mix_LoadMUS("Asset/Music/Route110.wav");
	Mix_PlayMusic(BGM, -1);
	Mix_VolumeMusic(30);
	Trainers = new Background("Asset/Entity/Trainers/OWtrainers.png", renderer);
	speed = 32;	
	initialspeed = speed;
	//Heal = Mix_LoadWAV("Asset/Music/Healing.wav");
	fLoader->LoadMoeMonFile(MoeMonList, renderer);
	fLoader->LoadSkillFile(SkillList,renderer);

	/*

	Debug Code

	*/
	Moemon* playerMoe = MoeMonList[34].clone();
	Moemon* playerMoe1 = MoeMonList[15].clone();
	playerMoe->getLearnedSkills()->add(SkillList[1].clone());
	playerMoe->getLearnedSkills()->add(SkillList[2].clone());
	playerMoe->getLearnedSkills()->add(SkillList[3].clone());
	playerMoe->getLearnedSkills()->add(SkillList[5].clone());
	playerMoe1->getLearnedSkills()->add(SkillList[6].clone());
	playerMoe1->getLearnedSkills()->add(SkillList[7].clone());
	playerMoe1->getLearnedSkills()->add(SkillList[2].clone());
	playerMoe1->getLearnedSkills()->add(SkillList[1].clone());
	PlayerEntity->getBag()->add(playerMoe, 5);
	PlayerEntity->getBag()->add(playerMoe1, 5);
	/*
	End of Debug code
	
	*/
	fLoader->LoadTileFile(TileList);
	fLoader->LoadMapFile(Route1, "Asset/Maps/Route 1.txt");
	fLoader->LoadMapFile(Route1OB, "Asset/Maps/Route 1 OBJ.txt");
	fLoader->LoadMapFile(Route1OW, "Asset/Maps/Route1OW.txt");
	fLoader->LoadMapFile(Village, "Asset/Maps/Village.txt");
	fLoader->LoadMapFile(VillageOB, "Asset/Maps/VillageOBJ.txt");
	fLoader->LoadMapFile(Town, "Asset/Maps/Town.txt");
	fLoader->LoadMapFile(TownOB, "Asset/Maps/TownOBJ.txt");
	fLoader->LoadTrainerFile(TrainerList, MoeMonList,SkillList, renderer);
	AnimTime = new Timer(1);
	placeTrainers();
	

}

GameplayState::~GameplayState()
{
	MoeMonList.clear();
	SkillList.clear();
	TileList.clear();
	Route1.clear();
	Route1OB.clear();
	TrainerList.clear();
	delete AnimTime;
	delete PlayerEntity;
	delete Backgrounds;
	delete fLoader;
}

bool GameplayState::EventHandle()
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
				getcollision(getposition() - 39, "");
				healMoemon(getposition() - 39);
				PlayerEntity->callMoveUp(true, AnimTime, Mapy, speed);
				wildEncounter();
				break;
			case SDLK_s:
				getcollision(getposition() + 39, "down");
				healMoemon(getposition() + 39);
				PlayerEntity->callMoveDown(true, AnimTime, Mapy, speed);
				wildEncounter();
				break;
			case SDLK_d:
				getcollision(getposition() + 1, "");
				healMoemon(getposition() + 1);
				PlayerEntity->callMoveRight(true, AnimTime, Mapx, speed);
				wildEncounter();
				break;
			case SDLK_a:
				getcollision(getposition() - 1, "");
				healMoemon(getposition() - 1);
				PlayerEntity->callMoveLeft(true, AnimTime, Mapx, speed);
				wildEncounter();
				break;
			case SDLK_k:
				//GSManager->Add(new BattleState(GSManager, renderer, PlayerEntity, wild));
				//GSManager->Add(new BattleState(GSManager, renderer, PlayerEntity, &TrainerList[0]));

				int debug = getposition();
				std::cout << debug << std::endl;
				break;
			}
		}
	}
	return true;
}

void GameplayState::update(float dt)
{
		deltatime = dt;
		AnimTime->updateTimer(dt);
		speed = (int)(speed * dt);
		collisionTest = PlayerEntity->getDescRect();
		Vec2 XY = PlayerEntity->XYpos();
		trainerBattleCollision();


	
}

void GameplayState::draw()
{

	
	if (MapID == 0)
	{
		int y = 0;
		int x = 0;
		for (unsigned int k = 0; k < Village.size(); k++)
		{
			SDL_Rect descRect;
			descRect.x = Village[k].getx() - Mapx;
			descRect.y = Village[k].gety() - Mapy;
			descRect.w = 32;
			descRect.h = 32;
			if (SDL_HasIntersection(&Camera, &descRect) == SDL_TRUE)
			{
				Backgrounds->callDraw(renderer, Backgrounds->getTexture(), descRect, TileList[Village[k].gettype()].getBox());
				Backgrounds->callDraw(renderer, Backgrounds->getTexture(), descRect, TileList[VillageOB[k].gettype()].getBox());
			}

			x++;
		}
	}
	if (MapID == 1)
	{
		int y = 0;
		int x = 0;
		for (unsigned int i = 0; i < Route1.size(); i++)
		{
			SDL_Rect descRect;
			descRect.x = Route1[i].getx() - Mapx;
			descRect.y = Route1[i].gety() - Mapy;
			descRect.w = 32;
			descRect.h = 32;
			if (SDL_HasIntersection(&Camera, &descRect) == SDL_TRUE)
			{
				Backgrounds->callDraw(renderer, Backgrounds->getTexture(), descRect, TileList[Route1[i].gettype()].getBox());
				Backgrounds->callDraw(renderer, Backgrounds->getTexture(), descRect, TileList[Route1OB[i].gettype()].getBox());
			}

			x++;
		}
		for (unsigned int j = 0; j < TrainerMap1.size(); j++)
		{
			SDL_Rect trainerRect = { TrainerMap1[j]->getDescRect().x - Mapx, TrainerMap1[j]->getDescRect().y - Mapy, 32, 32 };
			Trainers->callDraw(renderer, Trainers->getTexture(), trainerRect, TrainerMap1[j]->getSrcRect());
		}
	}
	if (MapID == 2)
	{
		int y = 0;
		int x = 0;
		for (unsigned int o = 0; o < Town.size(); o++)
		{
			SDL_Rect descRect;
			descRect.x = Town[o].getx() - Mapx;
			descRect.y = Town[o].gety() - Mapy;
			descRect.w = 32;
			descRect.h = 32;
			if (SDL_HasIntersection(&Camera, &descRect) == SDL_TRUE)
			{
				Backgrounds->callDraw(renderer, Backgrounds->getTexture(), descRect, TileList[Town[o].gettype()].getBox());
				Backgrounds->callDraw(renderer, Backgrounds->getTexture(), descRect, TileList[TownOB[o].gettype()].getBox());
			}

			x++;
		}
	}
	PlayerEntity->callDraw(renderer);
	
}


bool GameplayState::getcollision(int pos, std::string jump)
{
	if (pos < 0)
	{
		pos += 39;
		if (pos < 0)
		{
			return false;
		}
	}
	else
	{
		if (pos > 2808)
		{
			pos -= 39;
			if (pos > 2808)
			{
				return false;
			}
		}
	}
	if (jump == "down")
	{
		if (MapID == 1)
		{
			if (Route1OB[pos].gettype() == 75)
			{
				speed = 64;
				return true;
			}
		}
	}
	if (MapID == 0)
	{
		if (VillageOB[pos].gettype() == 326)
		{
			MapID = 1;
			return true;
		}
		if (TileList[VillageOB[pos].gettype()].getisWall() == true)
		{

			speed = 0;
			return true;
		}
		else
		{
			if (TileList[VillageOB[pos].gettype()].getisWall() == false)
			{
				speed = initialspeed;
				return false;
			}
		}
		return false;
	}
	if (MapID == 1)
	{
		if (Route1OB[pos].gettype() == 326)
		{
			MapID = 0;
			return true;
		}
		if (Route1OB[pos].gettype() == 328)
		{
			MapID = 2;
			Mapx = 0;
			Mapy = 0;
			return true;
		}
		if (TileList[Route1OB[pos].gettype()].getisWall() == true)
		{

			speed = 0;
			return true;
		}
		else
		{
			if (TileList[Route1OB[pos].gettype()].getisWall() == false)
			{
				speed = initialspeed;
				return false;
			}
		}
		return false;
	}
	if (MapID == 2)
	{
		if (TileList[TownOB[pos].gettype()].getisWall() == true)
		{

			speed = 0;
			return true;
		}
		else
		{
			if (TileList[TownOB[pos].gettype()].getisWall() == false)
			{
				speed = initialspeed;
				return false;
			}
		}
		return false;
	}
	}
int GameplayState::getposition()
{
	collisionTest = PlayerEntity->getDescRect();
	int x = (collisionTest.x + Mapx) / 32;
	int y = (collisionTest.y + Mapy) / 32;

	int pos = (y * 39) + x;
	return pos;
}

void GameplayState::wildEncounter()
{
	if (MapID == 1)
	{
		if (Route1OB[getposition()].gettype() == 159)
		{
			int rng = AnimTime->randNum(1, 10);
			if (rng == 1)
			{
				Moemon* wild = (MoeMonList[AnimTime->randNum(0, MoeMonList.size())]).clone();
				wild->setLevel(AnimTime->randNum(5, 10));
				wild->getLearnedSkills()->add(SkillList[AnimTime->randNum(0, SkillList.size())].clone());
				wild->getLearnedSkills()->add(SkillList[AnimTime->randNum(0, SkillList.size())].clone());
				GSManager->Add(new BattleState(GSManager, renderer, PlayerEntity, wild));
			}

		}
	}
}

void GameplayState::placeTrainers()
{
		for (unsigned int i = 0; i < Route1OW.size(); i++)
		{
			if (Route1OW[i].gettype() < 14 && Route1OW[i].gettype() > 0)
			{
				Trainer* temp = TrainerList[Route1OW[i].gettype()].clone();
				temp->setDescRect(Route1OW[i].getrect());
				TrainerMap1.push_back(temp);
			}
		}
		for (unsigned int j = 0; j < TrainerMap1.size(); j++)
		{
			for (unsigned int k = 0; k < TrainerMap1[j]->getStorageSize(); k++)
			{
				TrainerMap1[j]->getBag()->get(k)->setLevel(AnimTime->randNum(5, 15));
			}
		}
	
}

bool GameplayState::trainerBattleCollision()
{
	if (MapID == 1)
	{
		for (unsigned int i = 0; i < TrainerMap1.size(); i++)
		{
			if (TrainerMap1[i]->isDefeated() == false)
			{
				if (Route1OB[getTrainerPosition(i) + 1].getindex() == getposition())
				{
					GSManager->Add(new BattleState(GSManager, renderer, PlayerEntity, TrainerMap1[i]));
					return true;
				}
				if (Route1OB[getTrainerPosition(i) + 2].getindex() == getposition())
				{
					GSManager->Add(new BattleState(GSManager, renderer, PlayerEntity, TrainerMap1[i]));
					return true;
				}
				if (Route1OB[getTrainerPosition(i) + 3].getindex() == getposition())
				{
					GSManager->Add(new BattleState(GSManager, renderer, PlayerEntity, TrainerMap1[i]));
					return true;
				}
					if (Route1OB[getTrainerPosition(i) - 1].getindex() == getposition())
					{
						GSManager->Add(new BattleState(GSManager, renderer, PlayerEntity, TrainerMap1[i]));
						return true;
					}
					if (Route1OB[getTrainerPosition(i) - 2].getindex() == getposition())
					{
						GSManager->Add(new BattleState(GSManager, renderer, PlayerEntity, TrainerMap1[i]));
						return true;
					}
					if (Route1OB[getTrainerPosition(i) - 3].getindex() == getposition())
					{
						GSManager->Add(new BattleState(GSManager, renderer, PlayerEntity, TrainerMap1[i]));
						return true;
					}
			}
		}
	}
}

int GameplayState::getTrainerPosition(int currentTrainer)
{
	trainerBattleTest = TrainerMap1[currentTrainer]->getDescRect();
	int x = (trainerBattleTest.x /*- Mapx*/) / 32;
	int y = (trainerBattleTest.y /*+ Mapy*/) / 32;

	int pos = ((y * 39) + x);
return pos;
}

void GameplayState::healMoemon(int pos)
{
	if (MapID == 1)
	{
		if (Route1OB[pos].gettype() == 163 || Route1OB[pos].gettype() == 164)
		{
			for (unsigned int i = 0; i < PlayerEntity->getStorageSize(); i++)
			{
				PlayerEntity->getBag()->get(i)->fullHeal();
				Mix_PlayChannel(-1, Heal, 0);
			}
		}
	}

}



