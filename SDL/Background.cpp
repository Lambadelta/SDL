#include "Background.h"


Background::Background()
{
	BackgroundSurface = NULL;
}

Background::~Background()
{
	for (int iClear = 0; iClear > sizeof(BackgroundTexture); iClear++)
	{
		SDL_DestroyTexture(BackgroundTexture[iClear]);
	}
}

void Background::callChangeBackground()
{

}

SDL_Surface* Background::getSurface()
{
	return BackgroundSurface;
}

void Background::setSurface(SDL_Surface* sSurface)
{
	BackgroundSurface = sSurface;
}

SDL_Texture* Background::getTexture(int i)
{
	return BackgroundTexture[i];
}

void Background::setTexture(SDL_Texture* sTexture)
{
	/* add a loop to prevent multiple same textures being pushed.*/
	BackgroundTexture.push_back(sTexture);
	
}

SDL_Rect Background::getRect()
{
	return BackRect;
}

