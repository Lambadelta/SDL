#ifndef FILELOADER_H
#define FILELOADER_H


#include <fstream>
#include <string>
#include "Moemon.h"
#include <vector>

class FileLoader
{
public:
	FileLoader();
	~FileLoader();

	bool LoadMoeMonFile(Moemon* MoeMonList[]);
	std::vector<Moemon> LoadMoeMonFile();
	
private:

	const int MOEMONNUMBER = 2;
};



#endif