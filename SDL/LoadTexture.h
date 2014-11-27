#ifndef LOADTEXTURE_H
#define LOADTEXTURE_H

#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include "Vec2.h"
#include "SourceRect.h"

	/**
	@brief A class that represents a Texture Loader

	This class contains the methods to take in parameters, and return a textures and copy them to the screen.
	This class only contains methods.
	*/

class LoadTexture 
{
public:
	/**
	@brief The constructor called on creation of the LoadTexture object
	*/
	LoadTexture();
	/**
	@brief The desconstructor called on destruction of the LoadTexture object
	*/
	~LoadTexture();
	/**
	@brief A Method to create a surface from an image

	@param std::string - A string to the location of the image being used.
	@returns SDL_Surface*
	*/
	SDL_Surface* onSurfaceLoad(std::string path);
	/**
	@brief A Method to render a texture to the screen.
	This method does not support sprite maps.

	@param SDL_Renderer* - The Renderer that outputs to the screen
	@param SDL_Texture* - The Texture to be used for rendering
	@param SDL_Rect - The location on the screen to be rendered
	@returns bool - if it succeed/failed.
	*/
	bool OnDraw(SDL_Renderer* Renderer, SDL_Texture* cTexture, SDL_Rect descRect);
	/**
	@brief A Method to render a texture to the screen. Overloaded
	This method does support sprite maps.

	@param SDL_Renderer* - The Renderer that outputs to the screen
	@param SDL_Texture* - The Texture to be used for rendering
	@param SDL_Rect - The location on the screen to be rendered
	@param SDL_Rect - The location on the texture to be rendered
	@returns bool - If it succeed/failed
	*/
	bool OnDraw(SDL_Renderer* Renderer, SDL_Texture* cTexture, SDL_Rect descRect, SDL_Rect srcRect);

	/**
	@brief A Method to create a texture from a surface

	@param SDL_Renderer* - The renderer to create the texture
	@param SDL_Surface* - The surface to use when creating the texture
	@returns SDL_Texture*
	*/
	SDL_Texture* callTexture(SDL_Renderer* sRenderer, SDL_Surface* sSurface);
};

#endif