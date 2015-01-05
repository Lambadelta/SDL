#ifndef TRAINER_H
#define TRAINER_H

#include "Entity.h"
#include "MoemonStorage.h"

class Trainer : public Entity
{
public:
	Trainer(int,int,int, std::string,SDL_Renderer* renderer, MoeMonStorage*);
	~Trainer();

	void Move();
	void setDefeated(bool);
	bool isDefeated();
private:

	MoeMonStorage* MoeMon;

	int x;
	int y;
	int index;
	bool defeated;
};

#endif