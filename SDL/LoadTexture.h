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
	static SDL_Surface* onTextureLoad(std::string path/*, SDL_Window* window*/);
	static bool OnDraw(SDL_Renderer* Renderer, SDL_Texture* cTexture, SDL_Rect descRect);
	static bool OnDraw(SDL_Renderer* Renderer, SDL_Texture* cTexture, SDL_Rect descRect, SDL_Rect srcRect);
	static SDL_Texture* callTexture(SDL_Renderer* Renderer, SDL_Surface* Source);
};

#endif