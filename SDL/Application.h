#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL.h>
#include <sstream>
#include <SDL_image.h>
#include "Manager.h"
#include "GameplayState.h"


/**
@brief A class representing the Application

Contains the methods, and parameters that build up the application.
Contains the application and use of all class objects.
*/
class Application
{
public:
	/**
	@brief The default constructor
	*/
	Application();
	/**
	@brief The default deconstructor
	*/
	~Application();
	
	/**
	@brief A method to call Initialisation

	This method initialises all the classes, and objects that are needed before the application loop begins.
	This is the very first method called on the application starting.
	*/
	bool callInit();
	/**
	@brief A method to call execution

	This method executes the main game loop, and the event handler.
	@returns bool - If the application has successfully initialised 
	*/
	int callExecution();
	/**
	@brief A method that is called as part of the game loop

	This method takes in the event parameter, and manages the EventHandler object.

	@param SDL_Event* - A SDL_Event* that contains all the events that SDL catches
	@returns 0
	*/
	void callEvent(SDL_Event* sdlEvent);
	/**
	@brief A method that is called as part of the game loop

	This method is where the methods of other objects are called to update them. 
	Time is updated here.
	*/
	void callLoop();
	/**
	@brief A method to call the rendering function

	This method is where the texture of objects are sent to the renderer.
	*/
	void callRenderer();
	/**
	@brief This method is called when the program exits

	This method cleans up all the vectors, objects, and any other parts of the application before exiting.
	*/
	void callCleanup();
	/**
	@brief A method to set the surface of all visual objects

	This method is where all the different objects that need surfaces are processed.
	This is called in the callInit method.
	*/
	void callSurface();


protected:
	///A SDL_Window* for creating the screen
	SDL_Window* Display;
	///The SDL_Renderer used to render textures to the screen
	SDL_Renderer * Renderer;
	///A bool to start or end the game loop
	bool GameLoop;
	Time* time;
	Manager* GSManager;
	///A constant int for the window's x axises
	const int WINDOW_X = 100;		
	///A constant int for the window's y axises
	const int WINDOW_Y = 100;		
	///A constant int for the window's Width
	const int WINDOW_WIDTH = 640;	
	///A constant int for the window's Height
	const int WINDOW_HEIGHT = 480;
};

#endif