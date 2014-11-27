#ifndef ENTITY_H
#define ENTITY_H
#include <SDL.h>
#include <iostream>
#include "Vec2.h"
#include "SourceRect.h"
#include "Time.h"
#include "Timer.h"

/**
@brief A class that represents an Entity

This class contains the basic methods, and variables that all Entities require.
It contains an SDL_Texture*, SDL_Surface*, SDL_Rect and SDL_Rect

*/

class Entity
{
public:
	/**
	@brief Constructs an Entity object

	Is called when a class inheriting Entity is created
	Only derived objects will call this.

	*/
	Entity();
	/**
	@brief Deconstructs an Entity object

	Called when a derived class object is destroyed.
	Only derived objects will call this.
	*/
	~Entity();

	/**
	@brief A method to set the surface of the object

	@param SDL_Surface* - A pointer to a SDL_Surface
	*/
	void setSurface(SDL_Surface*);
	/**
	@brief A method to set the texture of the object

	@param SDL_Texture* - A pointer to a SDL_Texture
	*/
	void setTexture(SDL_Texture*);
	/**
	@brief A method to get the surface from the object

	Returns a SDL_Surface* when called
	@returns SDL_Surface*
	*/
	SDL_Surface* getSurface();
	/**
	@brief A method to get the texture from the object

	Returns a SDL_Texture* when called
	@returns SDL_Texture*
	*/
	SDL_Texture* getTexture();

	/**
	@brief A method to get the Destination Rect

	Returns a SDL_Rect containing the Destination when called
	@returns SDL_Rect
	*/
	SDL_Rect getDescRect();
	/**
	@brief A method to get the Source Rect

	Returns a SDL_Rect containing the Source when called
	@returns SDL_Rect
	*/
	SDL_Rect getSrcRect();

protected:

	///The objects Surface used to create a texture
	SDL_Surface* EntitySurface;
	///The objects Texture created from the surface, and used to render to screen
	SDL_Texture* EntityTexture;
	///The objects location to be drawn to the screen
	SDL_Rect DescRect;
	///The objects location on the texture to be drawn
	SDL_Rect SrcRect;
};

#endif