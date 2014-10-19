#include "Entity.h"

Entity::Entity(Vec2 v1, SourceRect sr1,float s)
{
	EntitySurface = NULL;
	EntityTexture = NULL;
	DescRect.x = v1.f_x;
	DescRect.y = v1.f_y;
	SrcRect.x = sr1.f_x;
	SrcRect.y = sr1.f_y;
	SrcRect.w = sr1.f_w;
	SrcRect.h = sr1.f_h;
	fSpeed = s;
}
Entity::~Entity()
{
	SDL_DestroyTexture(EntityTexture);
	SDL_FreeSurface(EntitySurface);
}

void Entity::callMoveUp()
{
	DescRect.y -= fSpeed;
}

void Entity::callMoveDown()
{
	DescRect.y += fSpeed;
}

void Entity::callMoveLeft()
{
	DescRect.x -= fSpeed;
}

void Entity::callMoveRight()
{
	DescRect.x += fSpeed;
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
