#include "Application.h"
Application::Application()
{
	Display = NULL;
	Renderer = NULL;
	GSManager = new Manager;
	time = new Time;
	
}
Application::~Application()
{

}
int Application::callExecution()
{
	if (callInit() == false)
	{
		return -1;
	}
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1048);
	TTF_Init();
	GSManager->Add(new GameplayState(GSManager, Renderer, WINDOW_WIDTH, WINDOW_HEIGHT));
	while (GameLoop)
	{
	GameLoop = GSManager->EventHandle();
	time->updateTime();
	float dt = time->getDelta();
	GSManager->update(dt);
	SDL_SetRenderDrawColor(Renderer, 0x0, 0x0, 0x0, 0x0);
	SDL_RenderClear(Renderer);
	GSManager->draw();

	SDL_RenderPresent(Renderer);
	}
	return 0;

}
bool Application::callInit()
{
	/*If called initialise the program*/


	/*Assigns the Display window the screen size, and properties*/
	Display = SDL_CreateWindow("SDL Main", WINDOW_X, WINDOW_Y, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	/*Checks if the display has been initialised correctly*/
	if (Display == NULL)
	{
		return false;
	}
	Renderer = SDL_CreateRenderer(Display, -1, SDL_RENDERER_PRESENTVSYNC);


	time->callStart();
	GameLoop = true;

	return true;
}

void Application::callCleanup()
{
	/*MoeMonList.clear();*/
	SDL_Quit();
}

