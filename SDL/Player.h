#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
public:
	Player(Vec2 v1, SourceRect sr1, float s);
	~Player();

	void callMove(char* input, Timer time);
	void addLives(int life);
	void subLives(int damage);
	int getLives();
private:

	bool bMoveUp = false;
	bool bMoveDown = false;
	bool bMoveLeft = false;
	bool bMoveRight = false;

	int iLives;

};

#endif