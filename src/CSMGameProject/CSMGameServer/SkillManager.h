#pragma once
#include "Skill.h"
#include <list>
class SkillManager
{
public:
	SkillManager(void);
	~SkillManager(void);

	void Update(float dTime);
	
	void AddSkill(Skill* skill);
	void RemoveSkill(int gameId);
private:
	std::list<Skill*>mSkills;
};

extern SkillManager *GSkillManager;