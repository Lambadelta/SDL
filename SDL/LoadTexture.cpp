#include "LoadTexture.h"
#include <iostream>
LoadTexture::LoadTexture()
{

}

LoadTexture::~LoadTexture()
{

}
SDL_Surface* LoadTexture::onTextureLoad(std::string path)
{
	/*Two Surfaces to load the texture, and then return it to the LoadTexture to be used */
	/*This uses two local instances of surface to ensure the main one doesn't have an issue*/
	SDL_Surface* Temp = NULL;
	SDL_Surface* ReturnSurface = NULL;

	Temp = SDL_LoadBMP(path.c_str());
	if (!Temp)
	{
		// We'll do a quick check here because it's easy to get filenames or directories wrong
		std::cout << "Oh dear, sorry but I can't find your image file. This brings me great sadness :(" << std::endl;
		SDL_Delay(100);
		SDL_Quit();
		/*Returns the value NULL to the pointer incase of an error with the image*/
		return NULL;
	}

	/*Copies the surface with the image to a new surface*/
	ReturnSurface = SDL_ConvertSurfaceFormat(Temp, SDL_PIXELFORMAT_UNKNOWN, 0);

	/*Clears Temp*/
	SDL_FreeSurface(Temp);
	/*Returns the copied surface as the value for onTextureLoad*/
	return ReturnSurface;
}
/*OnDraw method for drawing the texture singler*/
bool LoadTexture::OnDraw(SDL_Surface* Dest, SDL_Surface* Source, Vec2 vecV)
{
	/*Checks to see if the Destination surface, and the source surface are valid locations before continuing*/
	if (Dest == NULL || Source == NULL)
	{
		return false;
	}

	/*defines a rectangle that is used for positioning the texture*/
	SDL_Rect DestXY;
	/*Assigning the Rect values from the Vec2 structure*/
	DestXY.x = vecV.f_x;
	DestXY.y = vecV.f_y;


	/*Bliting the destination surface with the texture from the Source surface using the Rect data*/
	SDL_BlitSurface(Source, NULL, Dest, &DestXY);
	
	return true;
}
/*OnDraw method for using a sprite map source image*/
bool LoadTexture::OnDraw(SDL_Surface* Dest, SDL_Surface* Source, Vec2 vecV, SourceRect sr1)
{
	/*Checks to see if the Destination surface, and the source surface are valid locations before continuing*/
	if (Dest == NULL || Source == NULL)
	{
		return false;
	}

	/*defines a rectangle that is used for positioning the texture*/
	SDL_Rect DestXY;
	/*Assigning the Rect values from the Vec2 structure*/
	DestXY.x = vecV.f_x;
	DestXY.y = vecV.f_y;

	SDL_Rect SrcRect;
	SrcRect.x = sr1.f_x;
	SrcRect.y = sr1.f_y;
	SrcRect.w = sr1.f_w;
	SrcRect.h = sr1.f_h;

	/*Bliting the destination surface with the texture from the Source surface using the Rect data*/
	SDL_BlitSurface(Source, &SrcRect, Dest, &DestXY);

	return true;
}