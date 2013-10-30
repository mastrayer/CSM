#include "Character.h"


CCharacter::CCharacter(void):m_CharacterSprite(NULL)
{
	TransState(IDLE);

	AnimationImageInfo idleAnimationImageInfo = {2, L"idle",{0.1f,0.1f}};
	m_AnimationImageInfo.insert( std::map< CharacterState, AnimationImageInfo >::value_type(IDLE,idleAnimationImageInfo));
	
	AnimationImageInfo walkAnimationImageInfo = {2, L"walk",{0.2f,0.1f}};
	m_AnimationImageInfo.insert( std::map< CharacterState, AnimationImageInfo >::value_type(WALK,walkAnimationImageInfo));
	
	AnimationImageInfo attackAnimationImageInfo = {2, L"attack",{0.1f,0.1f}};
	m_AnimationImageInfo.insert( std::map< CharacterState, AnimationImageInfo >::value_type(ATTACK,attackAnimationImageInfo));
	
	AnimationImageInfo dieAnimationImageInfo = {2, L"die",{0.1f,0.1f}};
	m_AnimationImageInfo.insert( std::map< CharacterState, AnimationImageInfo >::value_type(DIE,dieAnimationImageInfo));

	m_AnimationFrameTime = 0.f;
}

CCharacter::~CCharacter(void)
{
}

void CCharacter::TransState(CharacterState state)
{
	m_CharacterState = state;
	m_AnimationFrameTime = 0;
	AnimationImageInfo nowAnimationImageInfo = m_AnimationImageInfo.find(m_CharacterState)->second;
	if( m_CharacterSprite != NULL)
	{
		RemoveChild(m_CharacterSprite);
		delete m_CharacterSprite;
	}
	WCHAR buff[1024];
	swprintf_s(buff,L"Sprite/%s_%d.png",nowAnimationImageInfo.imagePrefix,m_NowFrame);
	std::wstring framePath = buff;
	m_CharacterSprite = NNSprite::Create(framePath);
	AddChild(m_CharacterSprite);
}


void CCharacter::Update( float dTime)
{
	//Animation With m_State
	AnimationImageInfo nowAnimationImageInfo = m_AnimationImageInfo.find(m_CharacterState)->second;
	
	//Calculate 'Now Frame' With integration dtime
	m_AnimationFrameTime += dTime;
	bool isFrameChange = false;
	while(nowAnimationImageInfo.frameDelay[m_NowFrame] < m_AnimationFrameTime)
	{
		m_AnimationFrameTime -= nowAnimationImageInfo.frameDelay[m_NowFrame];
		m_NowFrame = (m_NowFrame+1)%nowAnimationImageInfo.totalFrameCount;
		isFrameChange = true;
	}
	if(isFrameChange == true)
	{
		RemoveChild(m_CharacterSprite);
		delete m_CharacterSprite;
		WCHAR buff[1024];
		swprintf_s(buff,L"Sprite/%s_%d.png",nowAnimationImageInfo.imagePrefix,m_NowFrame);
		std::wstring framePath = buff;
		m_CharacterSprite = NNSprite::Create(framePath);
		AddChild(m_CharacterSprite);
	}


	//Check Moving Input, and set Position to move
	if ( NNInputSystem::GetInstance()->GetKeyState( 'A' ) == KEY_DOWN  || 
		NNInputSystem::GetInstance()->GetKeyState( 'A' ) == KEY_PRESSED)
	{
		//Left
		SetPosition( GetPosition() + NNPoint(-100.f,0.f) * dTime );
	}
	if ( NNInputSystem::GetInstance()->GetKeyState( 'D' ) == KEY_DOWN  || 
		NNInputSystem::GetInstance()->GetKeyState( 'D' ) == KEY_PRESSED)
	{
		//Right
		SetPosition( GetPosition() + NNPoint(100.f,0.f) * dTime );
	}
	if ( NNInputSystem::GetInstance()->GetKeyState( 'W' ) == KEY_DOWN  || 
		NNInputSystem::GetInstance()->GetKeyState( 'W' ) == KEY_PRESSED)
	{
		//UP
		SetPosition( GetPosition() + NNPoint(0.f,-100.f) * dTime );
	}
	if ( NNInputSystem::GetInstance()->GetKeyState( 'S' ) == KEY_DOWN  || 
		NNInputSystem::GetInstance()->GetKeyState( 'S' ) == KEY_PRESSED)
	{
		//Down
		SetPosition( GetPosition() + NNPoint(0.f,100.f) * dTime );
	}


	//Change Image By now Frame.
}
void CCharacter::Render()
{
	NNObject::Render();
}