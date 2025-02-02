#ifndef MOEMON_H
#define MOEMON_H

#include "Entity.h"
#include "SkillStorage.h"
#include <vector>
#include "Text.h"

/** 
@brief Class that represents an MoeMon

This class contains the data that makes up a MoeMon. It inherits from Entity, which assigns it a surface and texture.
The data will be inputed from a file.


*/
class Moemon : public Entity
{
public:
	/**
	@brief The constructor of the MoeMon object

	Constructs the MoeMon from data that is read in from a file.

	@param int - Contains the Moemon id
	@param int - Contains the Moemon base health
	@param int - Contains the Moemon base attack
	@param int - Contains the Moemon base defense
	@param int - Contains the Moemon base SpAtk
	@param int - Contains the Moemon base SpDef
	@param int - Contains the Moemon base Speed
	@param int - Contains the Moemon default level
	@param std::string - Contains the Moemon's name
	@param std::string - Contains the Moemon's type
	*/
	Moemon(int, int, int, int, int, int , int, int , std::string, std::string, std::string, SDL_Renderer*);
	/**
	@brief A method to create a clone of this MoeMon

	Used to create unique versions of all the Moemon to prevent them sharing health, or other values.

	@Returns Moemon* - A pointer to a new clone of this Moemon.

	*/
	virtual Moemon* clone(){ return new Moemon(*this); };
	/**
	@brief A method to set if the moemon is shiny
	
	*/
	void setShiny();
	/**
	@brief A method to set the level of the Moemon

	Will modify the stats based on the new level given.

	@param int - An int containing the new level

	*/
	void setLevel(int);
	/**
	@brief A method to change the health of the Moemon

	Used to apply damage from the Battlestate.

	@param int - An int containing the amount to remove from health.

	*/
	void setHealth(int i) { Health -= i; };
	/**
	@brief A method to set the Moemon to full health

	Used for healing Moemon, and for future expansion of the MoeCenter system.

	*/
	void fullHeal() { Health = maxHealth; };
	/**
	@brief A method to draw the sprite of the Moemon.

	@param SDL_Renderer* - A pointer to the renderer where the Moemon will be drawn to.

	*/
	void callDraw(SDL_Renderer*);
	/**
	@brief A method to set the Moemon a new Rect

	@param SDL_Rect
	*/
	void setDescRect(SDL_Rect);
	void setEnemy();
	void cleanup();
	int getHealth() { return Health; };
	int getLevel() { return Level; };
	float getAttack() { return (float)Attack; };
	float getDefense() { return (float)Defense; };
	std::string getType() { return Type; };
	std::string getName(){	return MoeMonName;	}
	Text* getTextName() { if (Name == NULL) { return NULL; }  return Name; };
	Text* getTextLevel() { if (Lvl == NULL) { return NULL; }  return Lvl; };
	void setLearnedSkills(SkillStorage* in){ LearnedMoves = in; };
	void createLevelText();
	float getHPPercentage();
	void addEXP(int xp){ EXP += xp; checkIfLeveled(); };
	void checkIfLeveled();
	SkillStorage* getLearnedSkills();
private:
	///An int containing the ID of the Moemon
	int ID;
	///An int containing the base Health of the Moemon
	int Health;
	///An int containing the default Level of the Moemon
	int Level;
	///An int containing the base Attack of the Moemon
	int Attack;
	//An int containing the base Defense of the Moemon
	int Defense;
	///An int containing the base Special Attack of the Moemon
	int SpAtk;
	///An int containing the base Special Defense of the Moemon
	int SpDef;
	///An int containing the base Speed of the Moemon
	int Speed;

	int EXP;
	int EXPtoLVL;

	int maxHealth;
	///A string containing the Moemon's name
	std::string MoeMonName;
	///A string containing the Moemon's type
	std::string Type;
	SkillStorage* LearnedMoves;
	SDL_Renderer* renderer;
	std::string path;
	Text* Name;
	Text* Lvl;
	bool isShiny;


};


#endif