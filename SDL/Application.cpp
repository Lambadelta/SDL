#include "Application.h"
Application::Application()
{
	GameLoop = true;
	Display = NULL;
	PlayerEntity = new Player(Vec2(100, 100), SourceRect(28, 46, 28, 46), 20.0f);
	TextureLoader = new LoadTexture;
	Backgrounds = new Background;
	TileLoader = NULL;
	Renderer = NULL;
	/*Debug*/
	SurfaceCall = 0;

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
	Renderer = SDL_CreateRenderer(Display, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(Renderer, 0xFF, 0x0, 0x0, 0xFF);
	/*TileLoader->loadmap("TestMap.map");*/
	time.callStart();
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
		case SDL_KEYDOWN:
			switch (sdlEvent->key.keysym.sym)
			{
			case SDLK_w:
				PlayerEntity->callMove("UP", time);
				std::cout << "W is pressed\n";
				break;
			case SDLK_s:
				PlayerEntity->callMove("DOWN", time);
				std::cout << "S is pressed\n";
				break;
			case SDLK_d:
				PlayerEntity->callMove("RIGHT", time);
				std::cout << "D is pressed\n";
				break;
			case SDLK_a:
				PlayerEntity->callMove("LEFT", time);
				std::cout << "A is pressed\n";
				break;
			case SDLK_k:
				ftime = time.getDelta();
				std::cout << ftime << "\n";
				break;
			case SDLK_ESCAPE:
				GameLoop = false;
				callCleanup();
				break;
			}
			break;
		case SDL_KEYUP:
			switch (sdlEvent->key.keysym.sym)
			{
			case SDLK_w:
				PlayerEntity->callMove("", time);
				std::cout << "W is released\n";
				break;
			case SDLK_s:
				PlayerEntity->callMove("", time);
				std::cout << "S is released\n";
				break;
			case SDLK_d:
				PlayerEntity->callMove("", time);
				std::cout << "D is released\n";
				break;
			case SDLK_a:
				PlayerEntity->callMove("", time);
				std::cout << "A is released\n";
				break;
			}
			break;
		}
	}
}
void Application::callLoop()
{
	/*Method that calls other methods that regularly need to loop*/
	time.updateTime();
	/*Calls the rendering method*/
	callRenderer();
}
void Application::callRenderer()
{
	/**/
	SDL_RenderClear(Renderer);
	TextureLoader->OnDraw(Renderer, Backgrounds->getSurface(), Backgrounds->getRect());
	TextureLoader->OnDraw(Renderer, PlayerEntity->getSurface(), PlayerEntity->getDescRect());
	
}
void Application::callCleanup()
{
	SDL_Quit();
}

void Application::callSurface()
{	
	switch (SurfaceCall)
	{
	case 0:
		PlayerEntity->setSurface(TextureLoader->onTextureLoad("Asset/Entity/Player/image.bmp"));
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
	PlayerEntity->setTexture(TextureLoader->callTexture(Renderer, PlayerEntity->getSurface()));
	Backgrounds->setTexture(TextureLoader->callTexture(Renderer, Backgrounds->getSurface()));

}
