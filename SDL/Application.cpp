#include "Application.h"
Application::Application()
{
	GameLoop = true;
	Display = NULL;
	PlayerEntity = new Entity(Vec2(100, 100), SourceRect(28, 46, 28, 46), 5.0f);
	TextureLoader = new LoadTexture;
	Backgrounds = new Background;
	TileLoader = new Tile;
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
	Renderer = SDL_CreateRenderer(Display, -1, 0);
	SDL_SetRenderDrawColor(Renderer, 0xFF, 0x0, 0x0, 0xFF);
	TileLoader->loadmap("TestMap.map");
	callSurface();
	callTexture();

	return true;
}
void Application::callEvent(SDL_Event* sdlEvent)
{

	/*Event Handler*/

	while (SDL_PollEvent(sdlEvent))
	{
		/*Checks to see if the event quit has been called*/
		if (sdlEvent->type == SDL_QUIT)
		{
			GameLoop = false;
		}
		else if (sdlEvent->type == SDL_KEYDOWN)
		{
			/*Switch statement that checks the key events*/
			switch (sdlEvent->key.keysym.sym)
			{
				/*Escape Key*/
			case SDLK_ESCAPE:
				GameLoop = false;
				break;
				/*W key*/
			case SDLK_w:
				PlayerEntity->callMoveUp();
				std::cout << "W is pressed\n";
				break;
			case SDLK_a:
				/*A Key*/
				PlayerEntity->callMoveLeft();
				std::cout << "A is pressed\n";
				break;
				/*S Key*/
			case SDLK_s:
				PlayerEntity->callMoveDown();
				std::cout << "S is pressed\n";
				break;
				/*D Key*/
			case SDLK_d :
				PlayerEntity->callMoveRight();
				std::cout << "D is pressed\n";
				break;
				/*E Key*/
			case SDLK_e: 
				break;
				/*T Key*/
			case SDLK_t:
				std::cout << "called texture\n";
				callTexture();
				break;
				/*Debug keys to control surface loading*/
			case SDLK_1:
				std::cout << "called Surface 1\n";
				SurfaceCall = 1;
				callSurface();
				break;
			case SDLK_2:
				std::cout << "called Surface 2\n";
				SurfaceCall = 2;
				callSurface();
				break;
				/*End of Debug Keys*/
			default:
				break;
			}
		}
	}
}
void Application::callLoop()
{
	/*Method that calls other methods that regularly need to loop*/
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
		PlayerEntity->setSurface(TextureLoader->onTextureLoad("image.bmp"));
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
