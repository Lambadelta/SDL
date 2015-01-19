#ifndef SKILLSTORAGE_H
#define SKILLSTORAGE_H
#include <vector>
#include "Skill.h"
class SkillStorage
{
public:
	virtual SkillStorage* clone() { return new SkillStorage(*this); };
	~SkillStorage();
	void add(Skill*);
	void remove(int);
	std::vector<Skill*> getStorage(){ return Storage; };
	Skill* getSkill(int i)
	{
		return Storage[i];
	};
private:
	std::vector<Skill*> Storage;
	
};
#endif