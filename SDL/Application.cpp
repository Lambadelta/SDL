#include "Application.h"
Application::Application(Vec4 v4)
{
	GameLoop = true;
	Display = NULL;
	PlayerEntity = new Entity(Vec2(100, 100), SourceRect(28, 46, 28, 46), 5.0f);
	TextureLoader = new LoadTexture;
	Background = NULL;
	Renderer = NULL;
	winPosX = v4.f_x;
	winPosY = v4.f_y;
	winWidth = v4.f_w;
	winHeight = v4.f_h;
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
	Display = SDL_CreateWindow("SDL Main", 
		winPosX, winPosY,
		winWidth, winHeight,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	/*Checks if the display has been initialised correctly*/
	if (Display == NULL)
	{
		return false;
	}
	Renderer = SDL_CreateRenderer(Display, -1, 0);
	SDL_SetRenderDrawColor(Renderer, 0xFF, 0x0, 0x0, 0xFF);
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
				std::cout << "called time\n";
				break;
				/*R Key*/
			case SDLK_r:
				std::cout << "called renderer\n";
				callRenderer();
				break;
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
	TextureLoader->OnDraw(Renderer, Background, BackRect);
	TextureLoader->OnDraw(Renderer, PlayerEntity->Sprite, PlayerEntity->SpriteDescRect);
	
}
void Application::callCleanup()
{
	SDL_FreeSurface(PlayerEntity->Sprite);
	SDL_Quit();
}

void Application::callSurface()
{	
		std::string Player("image.bmp");
		PlayerEntity->Sprite = TextureLoader->onTextureLoad(Player);

		std::string sBackground("background.bmp");
		Background = TextureLoader->onTextureLoad(sBackground);


}

void Application::callTexture()
{
	PlayerEntity->EntityTexture = TextureLoader->callTexture(Renderer, PlayerEntity->Sprite);

}
