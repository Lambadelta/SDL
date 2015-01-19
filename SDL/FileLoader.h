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
	/**
	@brief A Method to load in the Skill List file.

	This method takes the SkillList.txt file, and fills the Vector referenced with new Skill objects.

	@param std::Vector<Skill>& - A reference to the Skill vector
	*/
	void LoadSkillFile(std::vector<Skill>&,SDL_Renderer*);
	/**
	@brief A Method to load in the Tile List file.

	This method takes the Tiles.txt file, and fills the Vector referenced with new Tile objects.

	@param std::Vector<Tile>& - A reference to the Tile vector
	*/
	void LoadTileFile(std::vector<Tile>&);
	/**
	@brief A Method to load in the MoeMon List file.

	This method takes the (MapName).txt file, and fills the Vector referenced with new Maptile objects.

	@param std::Vector<Maptile>& - A reference to the Maptile vector
	@param std::string - A path to read from. A file containing a map layout.
	*/
	void LoadMapFile(std::vector<Maptile>&, std::string);
	/**
	@brief A Method to load in the Trainer List file.

	This method takes the Trainer.txt file, and fills the Vector referenced with new Trainer objects.
	Creates trainers that hold copies of the Moemon, and Skill objects.

	@param std::Vector<Trainer>& - A reference to the Trainer vector
	@param std::Vector<Moemon>& - A reference to the populated Moemon vector
	@param std::Vector<Skill>& - A reference to the populated Skill vector
	@param SDL_Renderer* - A renderer for creating the textures
	*/
	void LoadTrainerFile(std::vector<Trainer>& , std::vector<Moemon>&, std::vector<Skill>&, SDL_Renderer*);
	
private:

};



#endif