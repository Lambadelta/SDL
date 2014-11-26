#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
public:
	Player(SourceRect v1, SourceRect sr1, float s);
	~Player();
	
	void callMoveUp(bool canMove, Timer* PlayerAnim, Time dt);
	void callMoveLeft(bool canMove, Timer* PlayerAnim, Time dt);
	void callMoveRight(bool canMove, Timer* PlayerAnim, Time dt);
	void callMoveDown(bool canMove, Timer* PlayerAnim, Time dt);
private:

	float fSpeed;
	bool bMoveUp = false;
	bool bMoveDown = false;
	bool bMoveLeft = false;
	bool bMoveRight = false;
	int iLives;

};

#endif