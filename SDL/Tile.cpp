#include "Tile.h"
Tile::Tile()
{
}
Tile::Tile(int x, int y, int id, bool collision)
{
	BoxRect.x = (x - 1 ) * WH ;
	BoxRect.y = (y - 1 ) * WH;

	BoxRect.w = WH;
	BoxRect.h = WH;

	iID = id;
	isWall = collision;
}

Tile::~Tile()
{

}

int Tile::getType()
{
	return iID;
}

SDL_Rect Tile::getBox()
{
	return BoxRect;
}

bool Tile::getisWall()
{
	if (isWall == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
