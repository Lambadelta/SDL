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
protected:
	static SDL_Surface* onTextureLoad(std::string path);
	static bool OnDraw(SDL_Surface* Dest, SDL_Surface* Source, Vec2 vecV);
	static bool OnDraw(SDL_Surface* Dest, SDL_Surface* Source, Vec2 vecV, SourceRect sr1);
};

#endif