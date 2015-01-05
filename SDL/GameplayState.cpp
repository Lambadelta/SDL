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
	PlayerEntity = new Player(Rect(/*100, 100*/256,224, 32, 32), Rect(0, 0, 50, 50), "Asset/Entity/Player/player.png", renderer);
	Backgrounds = new Background("Asset/map.png", renderer);
	speed = 32.0f;	
	initialspeed = speed;
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
				getcollision(getposition() - 39, "up");
				PlayerEntity->callMoveUp(true, AnimTime, Mapy, speed);
				
				/*Mapy -= speed;*/
				break;
			case SDLK_s:
				getcollision(getposition() + 39, "down");
				PlayerEntity->callMoveDown(true, AnimTime, Mapy, speed);
				
			/*	Mapy += speed;*/
				break;
			case SDLK_d:
				getcollision(getposition() + 1, "right");
				PlayerEntity->callMoveRight(true, AnimTime, Mapx, speed);
			/*	Mapx += speed;*/
				break;
			case SDLK_a:
				getcollision(getposition() - 1, "left");
				PlayerEntity->callMoveLeft(true, AnimTime, Mapx, speed);
			/*	Mapx -= speed;*/
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
		}
		x++;
	}
	PlayerEntity->callDraw(renderer);
}


bool GameplayState::getcollision(int pos, std::string direction)
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
	int debugi = Route1OB[pos].gettype();
	std::cout << debugi << std::endl;			SDL_Rect debug = Route1OB[pos].getrect();
	SDL_Rect collision;
	collision.w = 32;
	collision.h = 32;
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

	std::cout << pos << std::endl;
	return pos;
}



