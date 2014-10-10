#include "Application.h"
Application::Application(Vec4 v4)
{
	GameLoop = true;
	Display = NULL;
	PlayerTexture = NULL;
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

	Vec4 window(100, 100, 640, 480);

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
	Player.iMaxFrames = 8;
	Player.bfluctuate = true;
	if ((PlayerTexture = LoadTexture::onTextureLoad("image.bmp")) == NULL)
	{
		return false;
	}

	return true;
}
void Application::callEvent(SDL_Event* Event)
{
	EventHandler::onEvent(Event);
}
void Application::callLoop()
{
	Animation::onAnimation();
}
void Application::callRenderer()
{
	SDL_Renderer * Renderer = SDL_CreateRenderer(Display, -1, 0);
	LoadTexture::OnDraw(Renderer, PlayerTexture, v2, sr1);
}
void Application::callCleanup()
{
	SDL_FreeSurface(PlayerTexture);
	SDL_Quit();
}
