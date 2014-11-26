#ifndef FILELOADER_H
#define FILELOADER_H


#include <fstream>

#include <string>
#include <vector>
#include "Moemon.h"

class FileLoader
{
public:
	FileLoader();
	~FileLoader();

	void LoadMoeMonFile(std::vector<Moemon>& List);
	
private:

	const int MOEMONNUMBER = 36;
};



#endif