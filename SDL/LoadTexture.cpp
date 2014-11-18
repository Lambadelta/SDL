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
	SDL_Surface* Temp = NULL;

	Temp = IMG_Load(path.c_str());
	if (Temp == NULL)
	{
		// We'll do a quick check here because it's easy to get filenames or directories wrong
		std::cout << "Image -> " << path << "Could not be loaded. Returning NULL" << std::endl;
		SDL_Delay(100);
		SDL_Quit();
		/*Returns the value NULL to the pointer incase of an error with the image*/
		return NULL;
	}

	return Temp;
}
/*OnDraw method for drawing the texture singler*/
bool LoadTexture::OnDraw(SDL_Renderer* Renderer, SDL_Texture* cTexture, SDL_Rect descRect)
{
	SDL_QueryTexture(cTexture, NULL, NULL, &descRect.w, &descRect.h);
	SDL_RenderCopy(Renderer, cTexture, NULL, &descRect);
	return true;
}
/*OnDraw method for using a sprite map source image*/
bool LoadTexture::OnDraw(SDL_Renderer* Renderer, SDL_Texture* cTexture, SDL_Rect descRect, SDL_Rect srcRect)
{
	/*Coping the destination surface with the texture from the Source surface using the Rect data*/
	SDL_RenderCopy(Renderer, cTexture,&srcRect, &descRect);

	return true;
}

SDL_Texture* LoadTexture::callTexture(SDL_Renderer* sRenderer,SDL_Surface* sSurface)
{

	SDL_Texture* cTexture = SDL_CreateTextureFromSurface(sRenderer, sSurface);
	return cTexture;
}	
