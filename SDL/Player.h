#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
public:
	Player(Vec2 v1, SourceRect sr1, float s);
	~Player();

	void callMove(char* input, Timer time);

private:

	bool bMoveUp = false;
	bool bMoveDown = false;
	bool bMoveLeft = false;
	bool bMoveRight = false;


};

#endif