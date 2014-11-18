#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SDL.h>
#include <vector>
#include <iostream>

class Background
{
public:
	Background();
	~Background();
	
	void callChangeBackground();
	SDL_Surface* getSurface();
	void setSurface(SDL_Surface* sSurface);
	SDL_Texture* getTexture(int i);
	void setTexture(SDL_Texture* sTexture);

	SDL_Rect getRect();

private:
	std::vector<SDL_Texture*>BackgroundTexture;
	SDL_Surface* BackgroundSurface;
	SDL_Rect BackRect;
};


#endif