#include "Application.h"
Application::Application()
{
	GameLoop = true;
	Display = NULL;
	PlayerEntity = new Player(SourceRect(100, 100, 44, 44), SourceRect(0, 0, 22, 22), 60.0f);
	TextureLoader = new LoadTexture;
	Backgrounds = new Background;
	TileLoader = NULL;
	Renderer = NULL;
	Anim = new Timer(0.49f);
	SurfaceCall = 0;
	ftimer = 0;

}
Application::~Application()
{

}
int Application::callExecution()
{
	/*Checks to see if the application is running*/
	if (callInit() == false)
	{
		return -1;
	}
	/*Creates an SDL Event called sdlEvent*/
	SDL_Event sdlEvent;

	/*While GameLoop is running, and the event can be called the loop is called along with the renderer*/
	while (GameLoop)
	{
		/*Grabs the events queued in sdlEvent, while there can be many in the queue the process is looped to go through them all*/
		callEvent(&sdlEvent);
		callLoop();
		SDL_RenderPresent(Renderer);
		/*callRenderer();*/
	}
	return 0;

}
bool Application::callInit()
{
	/*If called initialise the program*/


	/*Assigns the Display window the screen size, and properties*/
	Display = SDL_CreateWindow("SDL Main", WINDOW_X, WINDOW_Y,WINDOW_WIDTH, WINDOW_HEIGHT,SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	/*Checks if the display has been initialised correctly*/
	if (Display == NULL)
	{
		return false;
	}
	Renderer = SDL_CreateRenderer(Display, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(Renderer, 0xFF, 0x0, 0x0, 0xFF);
	/*TileLoader->loadmap("TestMap.map");*/
	time.callStart();


	/*Initialise the surfaces and textures currently
	
	Will be changed*/
	callSurface();
	callTexture();



	return true;
}
void Application::callEvent(SDL_Event* sdlEvent)
{

	/*Event Handler*/

	while (SDL_PollEvent(sdlEvent))
	{
		switch (sdlEvent->type)
		{
		case SDL_QUIT:
			GameLoop = false;
			break;
			/* Checks if the key has been pressed down*/
		case SDL_KEYDOWN:
			PlayerEntity->callMove(sdlEvent->key.keysym.sym, time, Anim);
			break;
			/*Checks if the key has been released*/
		case SDL_KEYUP:
			PlayerEntity->callMove(sdlEvent->key.keysym.sym, time, Anim);
			break;
		}
	}
}
void Application::callLoop()
{
	/*Method that calls other methods that regularly need to loop*/

	/*Updates the time, and timer for animation*/
	time.updateTime();
	Anim->updateTimer(time.getDelta());
	/*Calls the rendering method*/
	callRenderer();
}
void Application::callRenderer()
{
	/*Clears the render then draws to the screen*/
	SDL_RenderClear(Renderer);
	TextureLoader->OnDraw(Renderer, Backgrounds->getTexture(0), Backgrounds->getRect());
	TextureLoader->OnDraw(Renderer, PlayerEntity->getTexture(), PlayerEntity->getDescRect(),PlayerEntity->getSrcRect());
	
}
void Application::callCleanup()
{
	SDL_Quit();
}

void Application::callSurface()
{	
	/*Idea for loading different levels/backgrounds by  calling them
	
	will most likely not use, and will just load all the tiles+sprites at the game start
	
	Look at ways to Improve This*/
	switch (SurfaceCall)
	{
	case 0:
		PlayerEntity->setSurface(TextureLoader->onTextureLoad("Asset/Entity/Player/Player.png"));
		Backgrounds->setSurface(TextureLoader->onTextureLoad("background.bmp"));
		SurfaceCall = 1;
		break;
	case 1:
		break;
	default:
		break;

	}

}

void Application::callTexture()
{

	/*sets the texture to the entities/background*/
	PlayerEntity->setTexture(TextureLoader->callTexture(Renderer, PlayerEntity->getSurface()));
	Backgrounds->setTexture(TextureLoader->callTexture(Renderer, Backgrounds->getSurface()));

}
