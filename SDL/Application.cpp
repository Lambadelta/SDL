#include "Application.h"
Application::Application()
{
	GameLoop = true;
	Display = NULL;
	int winPosX = 100;
	int winPosY = 100;
	int winWidth = 640;
	int winHeight = 480;
}
Application::Application()
{

}
int Application::CallExecution()
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
		while (SDL_PollEvent(&sdlEvent))
		{
			callEvent(&sdlEvent);
		}
		callLoop();
		callRenderer();
	}
	return 0;

}
int main(int argc, char* argv[])
{
	/*Defines the Application*/
	Application SDL;
	/*Returns the execution method*/
	return SDL.CallExecution;
}
bool Application::callInit()
{
	/*If called initlise the program*/


	/*Assigns the Display window the screen size, and properties*/
	Display = SDL_CreateWindow("SDL Main", 
		winPosX, winPosY,
		winWidth, winHeight,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	/*Checks if the display has been initilised correctly*/
	if (Display == NULL)
	{
		return false;
	}
	return true;
}
void Application::callEvent(SDL_Event* Event)
{

}
void Application::callLoop()
{

}
void Application::callRenderer()
{

}
void Application::callCleanup()
{
	SDL_Quit();
}
