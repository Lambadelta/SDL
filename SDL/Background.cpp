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

SDL_Texture* Background::GetTexture(int i)
{
	return BackgroundTexture[1];
}

void Background::setTexture(SDL_Texture* sTexture)
{
	for (int iCheck = 0; iCheck > sizeof(BackgroundTexture); iCheck++)
	{
		if (BackgroundTexture[iCheck] == sTexture)
		{
			std::cout << sTexture << " is already loaded\n";
		}
		else 
		{
			BackgroundTexture.push_back(sTexture);
		}
	}
	
}

SDL_Rect Background::getRect()
{
	return BackRect;
}

