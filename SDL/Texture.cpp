#pragma once
#include "Texture.h"

/*Constructor*/
Texture::Texture()
{
	cTexture = NULL;
	cImage = NULL;
	cDestRect.x = NULL;
	cDestRect.y = NULL;
}

/*Destructor*/
Texture::~Texture()
{
	Deallocate();
}

/*Function to load texture from file*/
bool Texture::loadFromFile(std::string path)
{	
	cImage = SDL_LoadBMP(path.c_str());
	if (!cImage)
	{
		// We'll do a quick check here because it's easy to get filenames or directories wrong
		std::cout << "Oh dear, sorry but I can't find your image file. This brings me great sadness :(" << std::endl;
		SDL_Delay(100);
		SDL_Quit();
		return -1;
	}
}

void Texture::Render(SDL_Renderer* cRenderer)
{
	cTexture = SDL_CreateTextureFromSurface(cRenderer, cImage);
	if (cTexture == NULL)
	{
		std::cout << "Unable to create texture from %s! SDL Error: %s\n", SDL_GetError();
	}

}

/*Deallocate the texture data*/
void Texture::Deallocate()
{
	SDL_FreeSurface(cImage);
	SDL_DestroyTexture(cTexture);
}
/*Sets colour*/
void Texture::setColour(SDL_Renderer* cRenderer)
{
	// Set the colour for drawing, set to red here
	SDL_SetRenderDrawColor(cRenderer, 0xFF, 0x0, 0x0, 0xFF);
}
/*Clears the colour*/
void Texture::clearColour(SDL_Renderer* cRenderer)
{
	SDL_RenderClear(cRenderer);
}
/*Sets Alpha*/
void Texture::setAlpha()
{
	
}
void Texture::setRect()
{
	// SDL has (0,0) at the top left corner - check this by playing about with the numbers!
	cDestRect.x = 100;
	cDestRect.y = 100;

}

void Texture::CopyToScreen(SDL_Renderer* cRenderer)
{
	SDL_RenderCopy(cRenderer, cTexture, NULL, &cDestRect);
}
void Texture::ShowScreen(SDL_Renderer* cRenderer)
{
	SDL_RenderPresent(cRenderer);
}
void Texture::QureyTexture()
{
	// Query the texture to get its original width and height
	SDL_QueryTexture(cTexture, NULL, NULL, &cDestRect.w, &cDestRect.h);
}
void Texture::ProcessTexture(SDL_Renderer* cRenderer)
{
	setRect();
	setColour(cRenderer);
	Render(cRenderer);
	QureyTexture();
	CopyToScreen(cRenderer);
	ShowScreen(cRenderer);

}