#include "LoadTexture.h"
#include <iostream>
LoadTexture::LoadTexture()
{

}

LoadTexture::~LoadTexture()
{

}
SDL_Surface* LoadTexture::onTextureLoad(std::string path/*,SDL_Window* window*/)
{
	/*Two Surfaces to load the texture, and then return it to the LoadTexture to be used */
	/*This uses two local instances of surface to ensure the main one doesn't have an issue*/
	SDL_Surface* Temp = NULL;
	//SDL_Surface* ReturnSurface = NULL;

	Temp = SDL_LoadBMP(path.c_str());
	if (Temp == NULL)
	{
		// We'll do a quick check here because it's easy to get filenames or directories wrong
		std::cout << "Image -> " << path << "Could not be loaded. Returning NULL" << std::endl;
		SDL_Delay(100);
		SDL_Quit();
		/*Returns the value NULL to the pointer incase of an error with the image*/
		return NULL;
	}

	///*Copies the surface with the image to a new surface*/
	//ReturnSurface = SDL_ConvertSurface(Temp,window->format,NULL);

	/*Clears Temp*/
	//SDL_FreeSurface(Temp);
	/*Returns the copied surface as the value for onTextureLoad*/
	return Temp;
}
/*OnDraw method for drawing the texture singler*/
bool LoadTexture::OnDraw(SDL_Renderer* Renderer, SDL_Texture* cTexture, SDL_Rect descRect)
{
	/*Copy the destination surface with the texture from the Source surface using the Rect data*/
	SDL_RenderCopy(Renderer, cTexture, NULL, &descRect);
	SDL_RenderPresent(Renderer);

	return true;
}
/*OnDraw method for using a sprite map source image*/
bool LoadTexture::OnDraw(SDL_Renderer* Renderer, SDL_Texture* cTexture, SDL_Rect descRect, SDL_Rect srcRect)
{

	/*Coping the destination surface with the texture from the Source surface using the Rect data*/
	SDL_RenderCopy(Renderer, cTexture, &descRect,&srcRect);
	SDL_RenderPresent(Renderer);

	return true;
}

SDL_Texture* LoadTexture::callTexture(SDL_Renderer* Renderer, SDL_Surface* Source)
{
	if (Source == NULL)
	{
		return false;
	}

	SDL_Texture* Dest = SDL_CreateTextureFromSurface(Renderer, Source);
	if (Dest == NULL)
	{
		std::cout << "Unable to create texture from \n";
		return NULL;
	}

	return Dest;
}
