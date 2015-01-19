#ifndef FILELOADER_H
#define FILELOADER_H


#include <fstream>

#include <string>
#include <vector>
#include "Moemon.h"
#include "Skill.h"
#include "Tile.h"
#include "Maptile.h"
#include "Trainer.h"

	/**
	@brief A class that represents the FileLoader

	This class contains the methods to read in, and read out files.
	There are specific methods for different files to load in.
	*/

class FileLoader
{
public:
	/**
	@brief The constructor called on creation of the FileLoader object
	*/
	FileLoader();
	/**
	@brief The deconstructor called on destruction of the FileLoader object
	*/
	~FileLoader();

	/**       
	@brief A Method to load in the MoeMon List file.

	This method takes the MoeMon.txt file, and fills the Vector referenced with new MoeMon objects.

	@param std::Vector<Moemon>& - A reference to the Moemon vector
	*/
	void LoadMoeMonFile(std::vector<Moemon>&, SDL_Renderer*);
	void LoadSkillFile(std::vector<Skill>&,SDL_Renderer*);
	void LoadTileFile(std::vector<Tile>&);
	void LoadMapFile(std::vector<Maptile>&, std::string);
	void LoadTrainerFile(std::vector<Trainer>& , std::vector<Moemon>&, std::vector<Skill>&, SDL_Renderer*);
	
private:
	///A constant int containing the number of MoeMon to be loaded in
};



#endif