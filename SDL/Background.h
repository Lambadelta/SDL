#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <string>
#include <iostream>
/**
@brief A class that represents a background

This class is used to create a background object
*/
class Background
{
public:
	Background(std::string path, SDL_Renderer* renderer);
	~Background();
	/**
	@brief A method to get the background surface

	Returns a SDL_Surface* when called.
	*/
	SDL_Surface* getSurface();
	bool loadIMG(std::string, SDL_Renderer*);
	/**
	@brief A method to get the background texture

	Returns a SDL_Texture* when called.
	*/
	SDL_Texture* getTexture();

	bool callDraw(SDL_Renderer* Renderer, SDL_Texture* cTexture,SDL_Rect descRect, SDL_Rect srcRect);

	/**
	@brief A method to get the background Rect

	Returns a SDL_Rect when called.
	*/
	SDL_Rect getRect();

private:
	///A SDL_Texture* containing the background texture
	SDL_Texture* BackgroundTexture;
	///A SDL_Rect containing the background Rect
	SDL_Rect BackRect;
};


#endif