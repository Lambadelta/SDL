#include "Tile.h"
Tile::Tile()
{
}
Tile::Tile(int x, int y, int type)
{
	BoxRect.x = x;
	BoxRect.y = y;

	BoxRect.w = csTile_Width;
	BoxRect.h = csTile_Height;

	iType = type;
}

Tile::~Tile()
{

}

int Tile::getType()
{
	return iType;
}

SDL_Rect Tile::getBox()
{
	return BoxRect;
}
