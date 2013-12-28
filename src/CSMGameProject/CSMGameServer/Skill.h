#pragma once
class Skill
{
public:
	Skill(void) {};
	virtual ~Skill(void) = 0 {};
	
	virtual bool IsLive() = 0;
	virtual void Update(float dTime) = 0;
};

