#include "Manager.h"
Manager::~Manager()
{
	for (int i = 0; i < sizeof(vGS); i++)
	{
		delete vGS.at(i);
	}
}

void Manager::Add(Gamestate* GS)
{
	vGS.push_back(GS);
	std::cout << "Added " << GS->getname() << " State to stack" << std::endl;
}

void Manager::Change(Gamestate* GS)
{
	for (unsigned int i = 0; i < vGS.size();)
	{
		delete vGS.at(i);
		i++;
	}
	vGS.clear();
	Add(GS);
}

void Manager::RemoveLast()
{
	std::cout << "Removed from stack" << std::endl;
	delete vGS.back();
	vGS.pop_back();
	
}

bool Manager::EventHandle()
{
	return vGS.back()->EventHandle();
}

void Manager::update(float dt)
{
	vGS.back()->update(dt);
}

void Manager::draw()
{
	/*vGS.at(0)->draw();*/
	for (unsigned int i = 0; i < vGS.size(); i++)
	{
	vGS.at(i)->draw();

	}
/*	vGS.back()->draw();*/
}

