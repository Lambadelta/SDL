#ifndef MAPTILE_H
#define MAPTILE_H

#include <vector>
#include <SDL.h>
/**
@brief A class to create a Maptile

A Maptile is created from a Tile object using a Map.txt.
These are used to create the maps inside the game.
*/
class Maptile
{
public:

	/**
	@brief The constructor for the Maptile Class

	Takes in four ints that make up Index, Xpos, Ypos, and Collision.
	This information is proivded by a Tile Object.
	@param Index - The tiles index.
	@param X Axis Position - Where on the Map is this specific tile in relation to the X axies.
	@param Y Axis Position - Where on the Map is this specific tile in relation to the Y axies.
	@param Collision - Can the player walk on this spot or not.
	*/
	Maptile(int, int, int,int);
	/**
	@brief A method to get the X position of the Maptile 

	@returns int - An int containing the current X position.
	*/
	int getx();
	/**
	@brief A method to get the Y position of the Maptile 

	@returns int - An int containing the current Y position.
	*/
	int gety();
	/**
	@brief A method to get the SDL_Rect of the Maptile 

	@returns SDL_Rect - A Rect that contains the current position
	*/
	SDL_Rect getrect();
	/**
	@brief A method to get the index position of the Maptile

	@returns int - An int containing the index position.
	*/
	int getindex();
	/**
	@brief A method to get the type of Maptile it is

	@returns int - An int containing the type of tile based off the Tile Object.
	*/
	int gettype();

private:

	///An int containing the Maptiles index.
	int index;
	///An int containing the Maptiles X Axies.
	int x;
	///An int containing the Maptiles Y Axies.
	int y;
	///An int containing the Maptiles Tile Type.
	int tile;
	///An SDL_Rect storing the Maptile's Rect position.
	SDL_Rect rect;


};

#endif