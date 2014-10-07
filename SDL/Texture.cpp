#include "Texture.h"
/*Constructor*/
Texture::Texture()
{
	cTexture = NULL;
	cImage = NULL;
	cRenderer = NULL;
	cDestRect = NULL;
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
void Texture::createRenderer(SDL_Window * window)
{
	cRenderer = SDL_CreateRenderer(window, -1, 0);
}

void Texture::Render()
{
	SDL_Texture * cTexture = SDL_CreateTextureFromSurface(cRenderer, cImage);
}

/*Deallocate the texture data*/
void Texture::Deallocate()
{
	SDL_FreeSurface(cImage);
	SDL_DestroyTexture(cTexture);
}
/*Sets colour*/
void Texture::setColour()
{
	// Set the colour for drawing, set to red here
	SDL_SetRenderDrawColor(cRenderer, 0xFF, 0x0, 0x0, 0xFF);
}
/*Clears the colour*/
void Texture::clearColour()
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

SDL_Renderer* Texture::getRenderer()
{
	return &cRenderer;
}
void Texture::CopyToScreen()
{
	SDL_RenderCopy(cRenderer, cTexture, NULL, &cDestRect);
}
void Texture::ShowScreen()
{
	SDL_RenderPresent(cRenderer);
}
void Texture::QureyTexture()
{
	// Query the texture to get its original width and height
	SDL_QueryTexture(cTexture, NULL, NULL, &cDestRect.w, &cDestRect.h);
}
void Texture::ProcessTexture(SDL_Window* window, std::string path)
{
	loadFromFile(path);
	createRenderer(SDL_Window * window);
	Render();
	CopyToScreen();
	ShowScreen();

}