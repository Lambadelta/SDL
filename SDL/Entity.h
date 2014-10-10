#ifndef ENTITY_H
#define ENTITY_H
#include <SDL.h>
#include <iostream>
#include "Vec2.h"
#include "SourceRect.h"

class Entity
{
public:
	Entity(Vec2, SourceRect);
	~Entity();
	SDL_Surface* Sprite;
	SDL_Rect* SpriteRect;
	Vec2 vXY;
	SourceRect vXYWH;

private:
};

#endif