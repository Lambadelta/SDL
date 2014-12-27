#ifndef TILE_H
#define TILE_H

#include <SDL.h>
#include <vector>
#include <fstream>
/**
@brief A class that represents a Tile

This class is used to create tile objects
*/
class Tile
{
public:
	/**
	@brief The default constructor for the Tile object
	*/
	Tile();
	/**
	@brief The constructor for the Tile object

	@param int - An int containing the x axises
	@param int - An int containing the y axises
	@param int - An int containing the type of tile
	*/
	Tile(int x, int y, int id);
	/**
	@brief The deconstructor for the Tile object
	*/
	~Tile();
	/**
	@brief A method to get the type of tile.

	Returns an int that relates to what type the tile is.
	@returns int - Containing type
	*/
	int getType();
	/**
	@brief A method to get the SDL_Rect of the tile

	Returns a SDL_Rect.
	@returns SDL_Rect
	*/
	SDL_Rect getBox();
	
private:
	///A SDL_Rect containing the tiles Rect
	SDL_Rect BoxRect;
	///An int containing the tile type
	int iID;

	///An constant int containing the tile Width
	const int WH = 16;






};

#endif