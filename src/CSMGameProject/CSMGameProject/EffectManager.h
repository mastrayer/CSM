
#pragma once

#include "Effect.h"
#include <list>
#include "TypeA.h"
#include "TypeB.h"
#include "TypeC.h"
#include "TypeD.h"
#include "ItemEffect.h"

class EffectManager : public NNObject
{
public:
	void Render();
	void Update( float dTime );

	void AddEffect( IEffect* effect , int zIndex=0);

	static EffectManager* GetInstance()
	{
		static EffectManager* pInstance = new EffectManager();
		return pInstance;
	}
	ATypeAttackEffect* GetATypeAttackEffect(int index);
	BTypeAttackEffect* GetBTypeAttackEffect(int index);
	CTypeAttackEffect* GetCTypeAttackEffect(int index);
	DTypeSkillEffect* GetDTypeSkillEffect(int index);
	ITEM_EFFECT::Item* GetItemEffect(int itemId);
private:
	std::list<IEffect*> mEffectList;

private:
	EffectManager();
	virtual ~EffectManager();
	void Init() {};
};