#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
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
	Player(Rect v1, Rect sr1, float s);
	~Player();
	/**
	@brief A method for calling the player to move up

	@param bool - A bool containing a true/false if the player can move
	@param Timer* - A timer to control the player's animation
	@param Time - The time for accessing time method (e.g. Delta time)
	*/
	void callMoveUp(bool canMove, Timer* PlayerAnim, Time dt);
	/**
	@brief A method for calling the player to move left

	@param bool - A bool containing a true/false if the player can move
	@param Timer* - A timer to control the player's animation
	@param Time - The time for accessing time method (e.g. Delta time)
	*/
	void callMoveLeft(bool canMove, Timer* PlayerAnim, Time dt);
	/**
	@brief A method for calling the player to move right

	@param bool - A bool containing a true/false if the player can move
	@param Timer* - A timer to control the player's animation
	@param Time - The time for accessing time method (e.g. Delta time)
	*/
	void callMoveRight(bool canMove, Timer* PlayerAnim, Time dt);
	/**
	@brief A method for calling the player to move down

	@param bool - A bool containing a true/false if the player can move
	@param Timer* - A timer to control the player's animation
	@param Time - The time for accessing time method (e.g. Delta time)
	*/
	void callMoveDown(bool canMove, Timer* PlayerAnim, Time dt);
private:
	///A float containing speed
	float fSpeed;

};

#endif