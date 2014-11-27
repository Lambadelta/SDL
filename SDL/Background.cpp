#include "Background.h"


Background::Background()
{
	BackgroundSurface = NULL;
}

Background::~Background()
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

SDL_Texture* Background::getTexture()
{
	return BackgroundTexture;
}

void Background::setTexture(SDL_Texture* sTexture)
{
	BackgroundTexture = sTexture;
}

SDL_Rect Background::getRect()
{
	return BackRect;
}

