#ifndef TRAINER_H
#define TRAINER_H

#include "Entity.h"
#include "MoemonStorage.h"

class Trainer : public Entity
{
public:
	Trainer(int, std::string, MoeMonStorage*);
	~Trainer();

	void Move();
private:

	MoeMonStorage* MoeMon;
};

#endif