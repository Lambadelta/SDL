#include "Entity.h"

Entity::Entity(std::string path, SDL_Renderer* renderer)
{
	loadIMG(path, renderer);
}
Entity::~Entity()
{
	/*SDL_DestroyTexture(EntityTexture);
	SDL_FreeSurface(EntitySurface);*/
}

bool Entity::loadIMG(std::string path, SDL_Renderer* renderer)
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
	EntityTexture = SDL_CreateTextureFromSurface(renderer, Temp);
	if (EntityTexture == NULL)
	{
		return NULL;
	}
	SDL_FreeSurface(Temp);
	return true;
}
SDL_Texture* Entity::getTexture()
{
	return EntityTexture;
}

SDL_Rect Entity::getDescRect()
{
	return DescRect;
}

SDL_Rect Entity::getSrcRect()
{
	return SrcRect;
}
