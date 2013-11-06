#include "Character.h"


CCharacter::CCharacter(void):m_CharacterSprite(NULL)
{
	AnimationImageInfo idleAnimationImageInfo = {2, L"idle",{10.f,10.f}};
	m_AnimationImageInfo.insert( std::map< CharacterState, AnimationImageInfo >::value_type(IDLE,idleAnimationImageInfo));
	
	AnimationImageInfo walkAnimationImageInfo = {2, L"walk",{20.f,10.f}};
	m_AnimationImageInfo.insert( std::map< CharacterState, AnimationImageInfo >::value_type(WALK,walkAnimationImageInfo));
	
	AnimationImageInfo attackAnimationImageInfo = {2, L"attack",{10.f,10.f}};
	m_AnimationImageInfo.insert( std::map< CharacterState, AnimationImageInfo >::value_type(ATTACK,attackAnimationImageInfo));
	
	AnimationImageInfo dieAnimationImageInfo = {2, L"die",{10.f,10.f}};
	m_AnimationImageInfo.insert( std::map< CharacterState, AnimationImageInfo >::value_type(DIE,dieAnimationImageInfo));

	m_AnimationFrameTime = 0.f;
	
	TransState(IDLE);
	m_LogLabel = NNLabel::Create( L"Normal Label", L"¸¼Àº °íµñ", 35.f );
	m_LogLabel->SetPosition(50.f,50.f);
	AddChild(m_LogLabel);

	NNAudioSystem::GetInstance()->AddEffectSound( "Effect", L"Sound/effect.wav" );
	NNAudioSystem::GetInstance()->AddEffectSound( "Effect1", L"Sound/effect1.mp3" );

}

CCharacter::~CCharacter(void)
{
}

void CCharacter::TransState(CharacterState state)
{
	m_CharacterState = state;
	m_AnimationFrameTime = 0;
	m_NowFrame = 0;
	AnimationImageInfo nowAnimationImageInfo = m_AnimationImageInfo.find(m_CharacterState)->second;
	if( m_CharacterSprite != NULL)
	{
		RemoveChild(m_CharacterSprite);
	}
	WCHAR buff[1024];
	swprintf_s(buff,L"Sprite/%s_%d.png",nowAnimationImageInfo.imagePrefix.c_str(),m_NowFrame);
	std::wstring framePath = buff;
	m_CharacterSprite = NNSprite::Create(framePath);
	m_CharacterSprite->SetCenter(m_CharacterSprite->GetImageWidth()/2.f, m_CharacterSprite->GetImageHeight()/2.f);
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
		WCHAR buff[1024];
		swprintf_s(buff,L"Sprite/%s_%d.png",nowAnimationImageInfo.imagePrefix.c_str(),m_NowFrame);
		std::wstring framePath = buff;
		m_CharacterSprite = NNSprite::Create(framePath);
		m_CharacterSprite->SetCenter(m_CharacterSprite->GetImageWidth()/2.f, m_CharacterSprite->GetImageHeight()/2.f);
		AddChild(m_CharacterSprite);
	}


	//Check Moving Input, and set Position to d
	if ( NNInputSystem::GetInstance()->GetKeyState( 'A' ) == KEY_DOWN  || 
		NNInputSystem::GetInstance()->GetKeyState( 'A' ) == KEY_PRESSED)
	{
		//Left
		SetPosition( GetPosition() + NNPoint(-10.f,0.f) * dTime );
	}
	if ( NNInputSystem::GetInstance()->GetKeyState( 'D' ) == KEY_DOWN  || 
		NNInputSystem::GetInstance()->GetKeyState( 'D' ) == KEY_PRESSED)
	{
		//Right
		SetPosition( GetPosition() + NNPoint(10.f,0.f) * dTime );
	}
	if ( NNInputSystem::GetInstance()->GetKeyState( 'W' ) == KEY_DOWN  || 
		NNInputSystem::GetInstance()->GetKeyState( 'W' ) == KEY_PRESSED)
	{
		//UP
		SetPosition( GetPosition() + NNPoint(0.f,-10.f) * dTime );
	}
	if ( NNInputSystem::GetInstance()->GetKeyState( 'S' ) == KEY_DOWN  || 
		NNInputSystem::GetInstance()->GetKeyState( 'S' ) == KEY_PRESSED)
	{
		//Down
		SetPosition( GetPosition() + NNPoint(0.f,10.f) * dTime );
	}

	if ( NNInputSystem::GetInstance()->GetKeyState( '1' ) == KEY_DOWN )
	{
		TransState(WALK);
	}
	if ( NNInputSystem::GetInstance()->GetKeyState( '2' ) == KEY_DOWN )
	{
		TransState(IDLE);
	}
	if ( NNInputSystem::GetInstance()->GetKeyState( '3' ) == KEY_DOWN )
	{
		TransState(ATTACK);
	}
	if ( NNInputSystem::GetInstance()->GetKeyState( '4' ) == KEY_DOWN )
	{
		TransState(DIE);
	}
	if ( NNInputSystem::GetInstance()->GetKeyState( '5' ) == KEY_DOWN )
	{
		NNAudioSystem::GetInstance()->PlayEffectSound( "Effect" );
	}
	if ( NNInputSystem::GetInstance()->GetKeyState( '6' ) == KEY_DOWN )
{
		NNAudioSystem::GetInstance()->PlayEffectSound( "Effect1" );
	}
	//Change Image By now Frame.
	NNPoint mousePoint = NNInputSystem::GetInstance()->GetMousePosition();
	WCHAR buff[1024];
	swprintf_s(buff,L"%f / %f",mousePoint.GetX(),mousePoint.GetY());
	m_LogLabel->SetString(buff);
	m_CharacterSprite->SetRotation(atan2f(mousePoint.GetY() - 300.f, mousePoint.GetX() - 400.f) * 180.0f / 3.14f);
}
void CCharacter::Render()
{
	NNObject::Render();
}