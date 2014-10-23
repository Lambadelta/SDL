#ifndef ENTITY_H
#define ENTITY_H
#include <SDL.h>
#include <iostream>
#include "Vec2.h"
#include "SourceRect.h"
#include "Timer.h"

class Entity
{
public:
	Entity(Vec2 v1, SourceRect sr1,float s);
	~Entity();


	void setSurface(SDL_Surface*);
	void setTexture(SDL_Texture*);
	SDL_Surface* getSurface();
	SDL_Texture* getTexture();

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