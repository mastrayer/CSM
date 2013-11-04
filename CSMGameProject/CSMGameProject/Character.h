#pragma once
#include "NNObject.h"
#include "NNSprite.h"
#include "NNInputSystem.h"
#include "NNLabel.h"
enum CharacterState
{
	IDLE,
	WALK,
	ATTACK,
	DIE,
};
struct AnimationImageInfo
{
	int totalFrameCount;
	std::wstring imagePrefix;
	float frameDelay[1024];
};
class CCharacter :
	public NNObject
{
private:
	NNSprite* m_CharacterSprite;
	CharacterState m_CharacterState;
	std::map<CharacterState,AnimationImageInfo> m_AnimationImageInfo; 
	float m_AnimationFrameTime; // init when Animation Type Change.
	int m_NowFrame;
	NNLabel* m_LogLabel;

public:
	CCharacter(void);
	virtual ~CCharacter(void);
	NNCREATE_FUNC(CCharacter);
	void TransState(CharacterState state);
	NNSprite* GetCharacterSprite() { return m_CharacterSprite; }
	
private:
	void Render();
	void Update( float dTime );
};

