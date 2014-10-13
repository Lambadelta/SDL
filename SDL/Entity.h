#ifndef ENTITY_H
#define ENTITY_H
#include <SDL.h>
#include <iostream>
#include "Vec2.h"
#include "SourceRect.h"

class Entity
{
public:
	Entity(Vec2 v1, SourceRect sr1);
	~Entity();
	SDL_Surface* Sprite;
	SDL_Texture* EntityTexture;
	SDL_Rect SpriteDescRect;
	SDL_Rect SpriteSrcRect;
	void callQueryTexture();
private:
	
};

#endif