#include "stdafx.h"
#include "SkillManager.h"


SkillManager::SkillManager(void)
{
}


SkillManager::~SkillManager(void)
{
}

void SkillManager::AddSkill(Skill* skill)
{
	mSkills.push_back(skill);
}
void SkillManager::Update(float dTime)
{
	for (auto& iter=mSkills.begin(); iter!=mSkills.end(); iter++ )
	{
		if ( (*iter)->IsLive() == false )
		{
			delete( *iter );
			iter = mSkills.erase( iter );
			if ( iter == mSkills.end() )
			{
				break;   
			}
		}
		else
		{
			(*iter)->Update(dTime);
		}
	}
}
 SkillManager *GSkillManager = nullptr;