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
	PlayerEntity = new Player(Rect(/*100, 100*/SCREEN_WIDTH /2, SCREEN_HEIGHT /2, 44, 44), Rect(0, 0, 50, 50), 15.0f, "Asset/Entity/Player/player.png", renderer);
	Backgrounds = new Background("Asset/map.png", renderer);
	speed = 6.0f;
	fLoader->LoadMoeMonFile(MoeMonList, renderer);
	fLoader->LoadSkillFile(SkillList);
	fLoader->LoadTileFile(TileList);
	fLoader->LoadMapFile(Route1, "Asset/Route 1.txt");
	fLoader->LoadMapFile(Route1OB, "Asset/Route 1 OBJ.txt");
	AnimTime = new Timer(1.5);
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
				PlayerEntity->callMoveUp(true, AnimTime, deltatime);
				Mapy -= speed;
				break;
			case SDLK_s:
				PlayerEntity->callMoveDown(true, AnimTime, deltatime);
				Mapy += speed;
				break;
			case SDLK_d:
				PlayerEntity->callMoveRight(true, AnimTime, deltatime);
				Mapx += speed;
				break;
			case SDLK_a:
				PlayerEntity->callMoveLeft(true, AnimTime, deltatime);
				Mapx -= speed;
				break;
			case SDLK_k:
				printf("%f \n", deltatime);
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

		Vec2 XY = PlayerEntity->XYpos();
	/*	Camera.x = (XY.f_x + PlayerEntity->rtnWidth() / 2) - SCREEN_WIDTH / 2;
		Camera.y = (XY.f_y + PlayerEntity->rtnHeight() / 2) - SCREEN_HEIGHT / 2;*/
	
}

void GameplayState::draw()
{

	int y = 0;
	int x = 0;
	for (int i = 0; i < Route1.size(); i++)
	{

		if (Route1[i] == 0)
		{
			y += 1;
			x = -1;
		}
		SDL_Rect descRect;
		descRect.x = (x * 32) - Mapx;
		descRect.y = (y * 32) - Mapy;
		descRect.w = 32;
		descRect.h = 32;

		if (SDL_HasIntersection(&Camera, &descRect) == SDL_TRUE)
		{
		/*	descRect.x - Camera.x;
			descRect.y - Camera.y;*/
			Backgrounds->callDraw(renderer, Backgrounds->getTexture(), descRect, TileList[Route1[i]].getBox());
			Backgrounds->callDraw(renderer, Backgrounds->getTexture(), descRect, TileList[Route1OB[i]].getBox());
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

