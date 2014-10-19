#ifndef TILE_H
#define TILE_H

#include <SDL.h>
#include <vector>
#include <fstream>

class Tile
{
public:
	Tile();
	Tile(int x, int y, int type);
	~Tile();
	int getType();
	SDL_Rect getBox();

	bool loadmap(std::string map);
	
private:
	SDL_Rect BoxRect;
	int iType;
	/*Tile Constants*/
	const int csTile_Width = 32;
	const int csTile_Height = 32;
	const int csTotal_Tiles = 49;
	const int csTotal_Tile_Sprites = 6;

	const int csTile_Empty = 0;
	const int csTile_Grass = 1;
	const int csTile_Stone = 2;
	const int csTile_Rock = 3;
	const int csTile_Wall = 4;
	const int csTile_Door = 5;
	
	std::vector<Tile*> Map01;






};

#endif