#include "GameplayState.h"


GameplayState::GameplayState(Manager* GSManager, SDL_Renderer* Renderer,int Width, int Height) : Gamestate(GSManager, Renderer)
{
	fLoader = new FileLoader;
	//PlayerEntity = NULL;
	//Backgrounds = NULL;
	SCREEN_WIDTH = Width;
	SCREEN_HEIGHT = Height;
	Camera.x = 0;
	Camera.y = 0;
	Camera.w = 640;
	Camera.h = 480;
	Name = "Gameplay";
	PlayerEntity = new Player(Rect(/*100, 100*/224,224, 32, 32), Rect(0, 0, 50, 50), "Asset/Entity/Player/player.png", renderer);
	Backgrounds = new Background("Asset/map.png", renderer);
	speed = 32.0f;
	fLoader->LoadMoeMonFile(MoeMonList, renderer);
	fLoader->LoadSkillFile(SkillList);
	fLoader->LoadTileFile(TileList);
	fLoader->LoadMapFile(Route1, "Asset/Route 1.txt");
	fLoader->LoadMapFile(Route1OB, "Asset/Route 1 OBJ.txt");
	AnimTime = new Timer(2);
}

GameplayState::~GameplayState()
{

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
				PlayerEntity->callMoveUp(true, AnimTime, Mapy, speed);
				getcollision(getposition());
				/*Mapy -= speed;*/
				break;
			case SDLK_s:
				PlayerEntity->callMoveDown(true, AnimTime, Mapy, speed);
				
			/*	Mapy += speed;*/
				break;
			case SDLK_d:
				PlayerEntity->callMoveRight(true, AnimTime, Mapx, speed);
			/*	Mapx += speed;*/
				break;
			case SDLK_a:
				PlayerEntity->callMoveLeft(true, AnimTime, Mapx, speed);
			/*	Mapx -= speed;*/getcollision(getposition() - 1);
				break;
			case SDLK_k:
				/*printf("%f \n", deltatime);*/
				getposition();
				break;
			}
		case SDL_KEYUP:
			switch (eve.key.keysym.sym)
			{
			}
		}
	}
	return true;
}

void GameplayState::update(float dt)
{
		deltatime = dt;
		AnimTime->updateTimer(dt);
		test = PlayerEntity->getDescRect();
		Vec2 XY = PlayerEntity->XYpos();
		collision();
	
}

void GameplayState::draw()
{

	int y = 0;
	int x = 0;
	for (int i = 0; i < Route1.size(); i++)
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
			if (Route1OB[i].gettype() == 171 || Route1OB[i].gettype() == 169 || Route1OB[i].gettype() == 120 || Route1OB[i].gettype() == 129 || Route1OB[i].gettype() == 122 || Route1OB[i].gettype() == 128 || Route1OB[i].gettype() == 127 || Route1OB[i].gettype() == 130)
			{
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderDrawRect(renderer, &descRect);
				SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0);
			}
		}
		x++;
	}
	PlayerEntity->callDraw(renderer);
}

void GameplayState::onInit()
{
	//PlayerEntity = new Player(Rect(100, 100, 44, 44), Rect(0, 0, 50, 50), "Asset/Entity/Player/player.png", renderer);
	//Backgrounds = new Background("Asset/map.png", renderer);
	//speed = 70.0f;
	//fLoader->LoadMoeMonFile(MoeMonList, renderer);
	//fLoader->LoadSkillFile(SkillList);
	//fLoader->LoadTileFile(TileList);
	//fLoader->LoadMapFile(TestMap);
	//AnimTime = new Timer(0.8);
}

void GameplayState::getcollision(int pos)
{
	float initialspeed = speed; 
	int debugi = Route1OB[pos].gettype();
	std::cout << debugi << std::endl;
	if (Route1OB[pos].gettype() == 171 || Route1OB[pos].gettype() == 169 || Route1OB[pos].gettype() == 120 || Route1OB[pos].gettype() == 129 || Route1OB[pos].gettype() == 122 || Route1OB[pos].gettype() == 128 || Route1OB[pos].gettype() == 127 || Route1OB[pos].gettype() == 130)
		{	
			SDL_Rect debug = Route1OB[pos].getrect();
			if (SDL_HasIntersection(&test, &Route1OB[pos].getrect()) == SDL_TRUE)
			{
				speed = 0;
			}
	/*		if (Route1OB[i].gettype() == 171 || Route1OB[i].gettype() == 169 || Route1OB[i].gettype() == 120 || Route1OB[i].gettype() == 129 || Route1OB[i].gettype() == 122 || Route1OB[i].gettype() == 128 || Route1OB[i].gettype() == 127 || Route1OB[i].gettype() == 130)
			{
				if (SDL_HasIntersection(&test, &Route1OB[i].getrect()) == SDL_FALSE)
				{
					speed = initialspeed;
				}*/
			/*}*/
		}

	}




void GameplayState::collision()
{
	
}

int GameplayState::getposition()
{
	test = PlayerEntity->getDescRect();
	int x = (test.x + Mapx) / 32;
	int y = (test.y + Mapy) / 32;

	int pos = (y * 39) + x;

	std::cout << pos << std::endl;
	return pos;
}



