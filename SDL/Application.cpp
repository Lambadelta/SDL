#include "Application.h"
Application::Application(Vec4 v4)
{
	GameLoop = true;
	Display = NULL;
	int winPosX = v4.f_x;
	int winPosY = v4.f_y;
	int winWidth = v4.f_w;
	int winHeight = v4.f_w;
}
Application::~Application()
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
	/* Assigning the size of the window*/

	Vec4 window;
	window.f_x = 100;
	window.f_y = 100;
	window.f_h = 480;
	window.f_w = 640;

	/*Creates the Application*/
	Application SDL(window);
	/*Returns the execution method*/
	return SDL.CallExecution;
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
	return true;
}
void Application::callEvent(SDL_Event* Event)
{
	if (Event->type == SDL_QUIT)
	{
		GameLoop = false;
	}
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
