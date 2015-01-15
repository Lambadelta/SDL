#ifndef MOEMON_H
#define MOEMON_H

#include "Entity.h"
#include "SkillStorage.h"
#include <vector>

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
	Moemon(int id, int health, int attack, int defense, int SpAtk, int SpDef, int Speed, int level, std::string name, std::string type, std::string path, SDL_Renderer* renderer);
	/**
	@brief A method to set if the moemon is shiny
	
	*/
	void setShiny();
	void setLevel(int);
	void callDraw(SDL_Renderer*);
	void setDescRect(SDL_Rect);
	void setEnemy();
	SkillStorage* getLearnedSkills();
private:
	///An int containing the ID of the Moemon
	int i_ID;
	///An int containing the base Health of the Moemon
	int i_Health;
	///An int containing the default Level of the Moemon
	int i_Level;
	///An int containing the base Attack of the Moemon
	int i_Attack;
	//An int containing the base Defense of the Moemon
	int i_Defense;
	///An int containing the base Special Attack of the Moemon
	int i_SpAtk;
	///An int containing the base Special Defense of the Moemon
	int i_SpDef;
	///An int containing the base Speed of the Moemon
	int i_Speed;
	///A string containing the Moemon's name
	std::string s_MoeMonName;
	///A string containing the Moemon's type
	std::string s_Type;
	SkillStorage* LearnedMoves;
	SDL_Texture* test;
	bool isShiny;


};


#endif