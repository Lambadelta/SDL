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
private:
	std::vector<Skill*> Storage;
	
};
#endif