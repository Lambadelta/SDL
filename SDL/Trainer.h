#ifndef TRAINER_H
#define TRAINER_H

#include "Entity.h"
#include "MoemonStorage.h"

class Trainer : public Entity
{
public:
	Trainer(int, int, int, std::string, SDL_Renderer*, MoeMonStorage*);
	Trainer(MoeMonStorage*,std::string, SDL_Renderer*);
	virtual Trainer* clone(){ return new Trainer(*this); };
	~Trainer();

	void Move();
	void setDefeated(bool);
	void callDraw(SDL_Renderer*);
	void BattleAnimation(SDL_Renderer*);
	int getStorageSize(){  return MoeMon->getStorage().size(); };

	MoeMonStorage* getBag() {	return MoeMon;};
	const bool isDefeated() const{ return defeated; };
private:

	MoeMonStorage* MoeMon;

	int x;
	int y;
	int index;
	bool defeated;
};

#endif