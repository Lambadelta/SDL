#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Vec2.h"
#include "MoemonStorage.h"
/**
@brief A class that represents a Player

This class is a derived class of Entity, and is used to create the Player object.
*/
class Player : public Entity
{
public:
	/**
	@brief The player constructor

	@param Rect - A rect structure containing four floating point numbers for destination
	@param Rect - A rect structure containing four floating point numbers for source
	@param float - A float containing the speed

	*/
	Player(Rect, Rect, std::string, SDL_Renderer*);
	~Player();
	/**
	@brief A method for calling the player to move up

	@param bool - A bool containing a true/false if the player can move
	@param Timer* - A timer to control the player's animation
	@param Time - The time for accessing time method (e.g. Delta time)
	*/
	void callMoveUp(bool, Timer* , int&,int);
	/**
	@brief A method for calling the player to move left

	@param bool - A bool containing a true/false if the player can move
	@param Timer* - A timer to control the player's animation
	@param Time - The time for accessing time method (e.g. Delta time)
	*/
	void callMoveLeft(bool, Timer*, int&, int);
	/**
	@brief A method for calling the player to move right

	@param bool - A bool containing a true/false if the player can move
	@param Timer* - A timer to control the player's animation
	@param Time - The time for accessing time method (e.g. Delta time)
	*/
	void callMoveRight(bool, Timer*, int&, int);
	/**
	@brief A method for calling the player to move down

	@param bool - A bool containing a true/false if the player can move
	@param Timer* - A timer to control the player's animation
	@param Time - The time for accessing time method (e.g. Delta time)
	*/
	void callMoveDown(bool, Timer*, int&, int);
	void callDraw(SDL_Renderer*);
	void callDrawAnimation(SDL_Renderer*);

	void battleAnimation(Timer*, float, SDL_Renderer*, int&);

	int rtnWidth();
	int rtnHeight();
	MoeMonStorage* getBag();
	int getStorageSize() { return MoeBag->getStorage().size(); };
	Vec2 XYpos();
	
private:
	MoeMonStorage* MoeBag;
};

#endif