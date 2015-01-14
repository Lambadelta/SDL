#ifndef MOEMONSTORAGE_H
#define MOEMONSTORAGE_H

#include <vector>
#include "Moemon.h"

class MoeMonStorage
{
public:
	MoeMonStorage();
	~MoeMonStorage();

	void add(Moemon*, int);
	void remove(int);
	Moemon* get(int);


private:
	std::vector<Moemon*> Storage;
};

#endif