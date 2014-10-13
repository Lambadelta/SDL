#include "Entity.h"

Entity::Entity(Vec2 v1, SourceRect sr1,float s)
{
	Sprite = NULL;
	EntityTexture = NULL;
	SpriteDescRect.x = v1.f_x;
	SpriteDescRect.y = v1.f_y;
	SpriteSrcRect.x = sr1.f_x;
	SpriteSrcRect.y = sr1.f_y;
	SpriteSrcRect.w = sr1.f_w;
	SpriteSrcRect.h = sr1.f_h;
	fSpeed = s;
}

void Entity::callQueryTexture()
{
	SDL_QueryTexture(EntityTexture, NULL, NULL, &SpriteDescRect.w, &SpriteDescRect.h);
}

void Entity::callMoveUp()
{
	SpriteDescRect.y += fSpeed;
}

void Entity::callMoveDown()
{
	SpriteDescRect.y -= fSpeed;
}

void Entity::callMoveLeft()
{
	SpriteDescRect.x -= fSpeed;
}

void Entity::callMoveRight()
{
	SpriteDescRect.x += fSpeed;
}
