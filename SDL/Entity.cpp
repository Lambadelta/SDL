#include "Entity.h"

Entity::Entity(Vec2 v1, SourceRect sr1,float s)
{
}
Entity::~Entity()
{
	SDL_DestroyTexture(EntityTexture);
	SDL_FreeSurface(EntitySurface);
}

void Entity::setSurface(SDL_Surface* sSurface)
{
	EntitySurface = sSurface;
}

void Entity::setTexture(SDL_Texture* sTexture)
{
	EntityTexture = sTexture;
}

SDL_Surface* Entity::getSurface()
{
	return EntitySurface;
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

