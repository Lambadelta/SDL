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
	PlayerEntity = new Player(Rect(256,256, 32, 32), Rect(0, 0, 50, 50), "Asset/Entity/Player/player.png", renderer);
	Backgrounds = new Background("Asset/Maps/map.png", renderer);
	speed = 32;	
	initialspeed = speed;
	fLoader->LoadMoeMonFile(MoeMonList, renderer);
	fLoader->LoadSkillFile(SkillList,renderer);

	/*

	Debug Code

	*/
	Moemon* playerMoe = MoeMonList[34].clone();
	Moemon* playerMoe1 = MoeMonList[15].clone();
	playerMoe->getLearnedSkills()->add(SkillList[0]);
	playerMoe->getLearnedSkills()->add(SkillList[1]);
	playerMoe->getLearnedSkills()->add(SkillList[2]);
	playerMoe->getLearnedSkills()->add(SkillList[4]);
	playerMoe1->getLearnedSkills()->add(SkillList[5]);
	playerMoe1->getLearnedSkills()->add(SkillList[4]);
	playerMoe1->getLearnedSkills()->add(SkillList[3]);
	playerMoe1->getLearnedSkills()->add(SkillList[1]);
	PlayerEntity->getBag()->add(playerMoe, 5);
	PlayerEntity->getBag()->add(playerMoe1, 5);
	/*
	End of Debug code
	
	*/
	fLoader->LoadTileFile(TileList);
	fLoader->LoadMapFile(Route1, "Asset/Maps/Route 1.txt");
	fLoader->LoadMapFile(Route1OB, "Asset/Maps/Route 1 OBJ.txt");
	fLoader->LoadTrainerFile(TrainerList, MoeMonList,SkillList, renderer);
	AnimTime = new Timer(1);

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
				PlayerEntity->callMoveUp(true, AnimTime, Mapy, speed);
				break;
			case SDLK_s:
				getcollision(getposition() + 39, "down");
				PlayerEntity->callMoveDown(true, AnimTime, Mapy, speed);
				break;
			case SDLK_d:
				getcollision(getposition() + 1, "");
				PlayerEntity->callMoveRight(true, AnimTime, Mapx, speed);
				break;
			case SDLK_a:
				getcollision(getposition() - 1, "");
				PlayerEntity->callMoveLeft(true, AnimTime, Mapx, speed);
				break;
			case SDLK_k:
				//Moemon* wild(MoeMonList[4]);
				//GSManager->Add(new BattleState(GSManager, renderer, PlayerEntity, wild));
				GSManager->Add(new BattleState(GSManager, renderer, PlayerEntity, &TrainerList[0]));

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
		test = PlayerEntity->getDescRect();
		Vec2 XY = PlayerEntity->XYpos();
	
}

void GameplayState::draw()
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
		if (Route1OB[pos].gettype() == 75)
		{
			speed = 64;
			return true;
		}
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
int GameplayState::getposition()
{
	test = PlayerEntity->getDescRect();
	int x = (test.x + Mapx) / 32;
	int y = (test.y + Mapy) / 32;

	int pos = (y * 39) + x;
	return pos;
}



