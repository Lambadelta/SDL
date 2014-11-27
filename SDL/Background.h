#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL.h>
#include <vector>
#include <iostream>
/**
@brief A class that represents a background

This class is used to create a background object
*/
class Background
{
public:
	Background();
	~Background();
	/**
	@brief A method to get the background surface

	Returns a SDL_Surface* when called.
	*/
	SDL_Surface* getSurface();
	/**
	@brief A method to set the background surface

	Takes a SDL_Surface* parameter, and sets the background Surface to it.

	@param SDL_Surface* - A SDL_Surface* that contains the background image.
	@returns SDL_Surface*
	*/
	void setSurface(SDL_Surface* sSurface);
	/**
	@brief A method to get the background texture

	Returns a SDL_Texture* when called.
	*/
	SDL_Texture* getTexture();
	/**
	@brief A method to set the background texture

	Takes a SDL_Texture* parameter, and sets the background texture to it.

	@param SDL_Texture* - A SDL_Texture* that contains a texture created from the surface
	@returns SDL_Texture* 
	*/
	void setTexture(SDL_Texture* sTexture);
	/**
	@brief A method to get the background Rect

	Returns a SDL_Rect when called.
	*/
	SDL_Rect getRect();

private:
	///A SDL_Surface* containing the background surface
	SDL_Surface* BackgroundSurface;
	///A SDL_Texture* containing the background texture
	SDL_Texture* BackgroundTexture;
	///A SDL_Rect containing the background Rect
	SDL_Rect BackRect;
};


#endif