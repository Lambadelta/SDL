#ifndef ENTITY_H
#define ENTITY_H
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
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
	Entity(std::string path, SDL_Renderer* renderer);
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
	bool loadIMG(std::string, SDL_Renderer*);

	bool Entity::loadIMGA(std::string path, SDL_Renderer* renderer);
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

	///The objects Texture created from the surface, and used to render to screen
	SDL_Texture* EntityTexture;
	SDL_Texture* AnimaText;
	///The objects location to be drawn to the screen
	SDL_Rect DescRect;
	///The objects location on the texture to be drawn
	SDL_Rect SrcRect;
	SDL_Rect SrcAnimRect;
};

#endif