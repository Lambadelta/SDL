#include "Entity.h"

Entity::Entity(Vec2 v1, SourceRect src1)
{
	SDL_Surface* Sprite = NULL;
	SDL_Rect* SpriteRect = NULL;
	Vec2 vXY(v1.f_x, v1.f_y);
	SourceRect vXYWH(src1.f_x,src1.f_y,src1.f_w,src1.f_h);
}

