#ifndef LOADTEXTURE_H
#define LOADTEXTURE_H

#include <SDL.h>
#include <string>
#include "Vec2.h"
#include "SourceRect.h"


class LoadTexture 
{
public:
	LoadTexture();
	~LoadTexture();
	SDL_Surface* onTextureLoad(std::string path/*, SDL_Window* window*/);
	bool OnDraw(SDL_Renderer* Renderer, SDL_Surface* Source, SDL_Rect descRect);
	bool OnDraw(SDL_Renderer* Renderer, SDL_Surface* Source, SDL_Rect descRect, SDL_Rect srcRect);.
};

#endif