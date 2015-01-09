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
	/*Checks to see if the application is running*/
	if (callInit() == false)
	{
		return -1;
	}
	///*Creates an SDL Event called sdlEvent*/
	//SDL_Event sdlEvent;
	GSManager->Add(new GameplayState(GSManager, Renderer, WINDOW_WIDTH, WINDOW_HEIGHT));
	/*While GameLoop is running, and the event can be called the loop is called along with the renderer*/
	while (GameLoop)
	{
	//	/*Grabs the events queued in sdlEvent, while there can be many in the queue the process is looped to go through them all*/
	//	//callEvent(&sdlEvent);
	//	//callLoop();
	//	//SDL_RenderPresent(Renderer);
	//	/*callRenderer();*/
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
void Application::callEvent(SDL_Event* sdlEvent)
{

}
void Application::callLoop()
{
	/*Method that calls other methods that regularly need to loop*/

	/*Updates the time, and timer for animation*/
	callRenderer();
}
void Application::callRenderer()
{
	///*Clears the render then draws to the screen*/
	//SDL_RenderClear(Renderer);
	//int y = 0;
	//int x = 0;
	//for (int i = 0; i < TestMap.size(); i++)
	//{
	//	
	//	if (TestMap[i] == 0)
	//	{
	//		y += 1;
	//		x = -1;
	//	}
	//	SDL_Rect descRect;
	//	descRect.x = x * 32;
	//	descRect.y = y * 32;
	//	descRect.w = 32;
	//	descRect.h = 32;

	//	if (SDL_HasIntersection(&Camera,&descRect) == SDL_TRUE)
	//	{
	//		descRect.x - Camera.x;
	//		descRect.y - Camera.y;
	//	Backgrounds->Draw(Renderer, Backgrounds->getTexture(),descRect, TileList[TestMap[i]].getBox());
	//	}
	//	x++;
	//}
	//PlayerEntity->Draw(Renderer);
	
}
void Application::callCleanup()
{
	/*MoeMonList.clear();*/
	SDL_Quit();
}

