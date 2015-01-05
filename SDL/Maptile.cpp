#include "Maptile.h"

Maptile::Maptile(int ind, int xpos, int ypos,int type)
{
	index = ind;
	x = xpos;
	y = ypos;
	tile = type;
	rect.x = x;
	rect.y = y;
	rect.w = 32;
	rect.h = 32;
}

Maptile::~Maptile()
{

}

int Maptile::getx()
{
	return x;
}

int Maptile::gety()
{
	return y;
}

int Maptile::getindex()
{
	return index;
}

int Maptile::gettype()
{
	return tile;
}

SDL_Rect Maptile::getrect()
{
	return rect;
}
