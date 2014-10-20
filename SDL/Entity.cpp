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

void Entity::callMoveUp(bool move, float time)
{
	if (move == true)
	{
		/*DescRect.y -= fSpeed;*/
		DescRect.y = DescRect.y - (fSpeed * time);
	}
	else
	{
		std::cout << "Stop Moving Up\n";
	}
}

void Entity::callMoveDown(bool move, float time)
{
	if (move == true)
	{
		/*DescRect.y += fSpeed;*/
		DescRect.y = DescRect.y + (fSpeed * time);
	}
	else
	{
		std::cout << "Stop Moving Down\n";
	}
}

void Entity::callMoveLeft(bool move, float time)
{
	if (move == true)
	{
		/*DescRect.x -= fSpeed;*/
		DescRect.x = DescRect.x - (fSpeed * time);
	}
	else
	{
		std::cout << "Stop Moving Left\n";
	}
}

void Entity::callMoveRight(bool move, float time)
{
	if (move == true)
	{
		/*DescRect.x += fSpeed;*/
		DescRect.x = DescRect.x + (fSpeed * time);
	}
	else
	{
		std::cout << "Stop Moving Right\n";
	}
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
