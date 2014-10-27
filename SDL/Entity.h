#ifndef ENTITY_H
#define ENTITY_H
#include <SDL.h>
#include <iostream>
#include "Vec2.h"
#include "SourceRect.h"
#include "Time.h"

/*Entity Superclass

		This will be inherited by any entity object in the game*/

class Entity
{
public:
	/*Constructor*/
	Entity();
	~Entity();

	/*Surface/Texture methods to set, and retrieve the data in Entity*/
	void setSurface(SDL_Surface*);
	void setTexture(SDL_Texture*);
	SDL_Surface* getSurface();
	SDL_Texture* getTexture();

	/*Get the Rect data from the Entity*/
	SDL_Rect getDescRect();
	SDL_Rect getSrcRect();

protected:

	float fSpeed;
	SDL_Surface* EntitySurface;
	SDL_Texture* EntityTexture;
	SDL_Rect DescRect;
	SDL_Rect SrcRect;
};

#endif