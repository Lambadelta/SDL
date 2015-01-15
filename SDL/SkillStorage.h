#ifndef SKILLSTORAGE_H
#define SKILLSTORAGE_H
#include <vector>
#include "Skill.h"
class SkillStorage
{
public:
	SkillStorage();
	~SkillStorage();
	void add(Skill*);
	void remove(int);
	void useSkill(int);
	Skill* getSkill(int i)
	{
		if (Storage[i] == NULL)
		{
			return NULL;
		}
		return Storage[i];
	};
private:
	std::vector<Skill*> Storage;
	
};
#endif