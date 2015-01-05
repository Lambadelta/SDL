#ifndef MAPTILE_H
#define MAPTILE_H

#include <vector>
#include <SDL.h>
class Maptile
{
public:
	Maptile(int, int, int,int);
	~Maptile();
	
	int getx();
	int gety();
	SDL_Rect getrect();
	int getindex();
	int gettype();

private:

	int index;
	int x;
	int y;
	int tile;
	SDL_Rect rect;


};

#endif