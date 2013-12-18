
#include "Player.h"

#include "NNAudioSystem.h"
#include "NNNetworkSystem.h"
#include "NNParticleSystem.h"
#include "NNInputSystem.h"
#include "NNApplication.h"
#include "NNAnimation.h"

#include "EffectManager.h"
#include "TypeA.h"
#include "TypeB.h"
#include "TypeC.h"
#include "UserSkillEffect.h"

CPlayer::CPlayer( void )
	: mMoveVelocity(NNPoint(0,0)), mHp(100),
	  mRebirthDelayTime(10), mTeam(0), mKillScore(0)
{
}

CPlayer::~CPlayer( void )
{
}

void CPlayer::Init()
{
	/* Player Animation, Sprite Init */
	mDie = NNSprite::Create( L"Resource/Sprite/die.png" );
	mStop = NNSpriteAtlas::Create( L"Resource/Sprite/Player/player.png" );
	mStop->SetCutSize( NNSize(0,41,65,83) );
	mMove = NNAnimationAtlas::Create( L"Resource/Sprite/Player/player.png", 3, 0.05f, NNSize(0,0,65,41), NNSize(0,41,65,83), NNSize(0,83,65,125) );
	AddChild( mDie );
	AddChild( mStop );
	AddChild( mMove );

	mDie->SetVisible( false );
	mStop->SetVisible( false );
	mMove->SetVisible( false );

	TransState(PlayerState::IDLE);

	mPlayerUI = PlayerUI::Create();
	mPlayerUI->SetParent( this );
	mPlayerUI->SetPosition( 21.f, 24.f );
	AddChild( mPlayerUI );

	ZeroMemory( mSkillCount, sizeof(mSkillCount) );
	ZeroMemory( mSkillCooldown, sizeof(mSkillCooldown) );
}

void CPlayer::CreateSkillEffect(PlayerType type, PlayerState skillType)
{
	switch (skillType)
	{
	case TYPE_ACTIVE_SKILL:
		
		//if (type == TYPE_A) EffectManager::GetInstance()->AddEffect();
		//else if (type == TYPE_B) EffectManager::GetInstance()->AddEffect();
		//else if (type == TYPE_C) EffectManager::GetInstance()->AddEffect();

		break;
	case USER_ACTIVE_SKILL:

		break;
	}

// 	switch (type)
// 	{
// 	case TYPE_A :
// 		//if (skillType == USER_ACTIVE_SKILL) EffectManager::GetInstance()->AddEffect(new AUserEffect(this));
// 		break;
// 
// 	case TYPE_B :
// 		//if (skillType == TYPE_ACTIVE_SKILL) EffectManager::GetInstance()->AddEffect(new BTypeEffect(this));
// 		//if (skillType == USER_ACTIVE_SKILL) EffectManager::GetInstance()->AddEffect(new BUserEffect(this));
// 		if (skillType == TYPE_ACTIVE_SKILL) EffectManager::GetInstance()->AddEffect(new USER_SKILL::Dash(this));
// 		if (skillType == USER_ACTIVE_SKILL) EffectManager::GetInstance()->AddEffect(new USER_SKILL::Flash(this));
// 		break;
// 
// 	case TYPE_C :
// 
// 		if (skillType == TYPE_ACTIVE_SKILL) EffectManager::GetInstance()->AddEffect(new CTypeEffect(this));
// 		//if (skillType == USER_ACTIVE_SKILL) EffectManager::GetInstance()->AddEffect(new CUserEffect(this));
// 		break;
// 	}

}
void CPlayer::TransState( PlayerState state )
{
	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();
	float rotation = mRotation;

	mPlayerState = state;

	//mDie->SetCenter( mDie->GetImageWidth()/2.f, mDie->GetImageHeight()/2.f );
	//mMove->SetCenter( 21.f, 24.f );
	//mStop->SetCenter( 21.f, 24.f );

	SetCenter( 21.f, 24.f );

	switch (state)
	{
	case IDLE:
		break;

	case WALK:
		break;

	case ATTAACK:
		break;

	case DIE:
		
		SetCenter( mDie->GetImageWidth()/2.f, mDie->GetImageHeight()/2.f );
		//mRebirthTimer = NNLabel::Create(L"À¸¾Ó~ Áê±Ý~ XÃÊ ¿ì¸® Á» Àß ÇØº¾½Ã´Ù", L"¸¼Àº °íµñ", 40.f);
		//mRebirthTimer->SetCenter(width / 2, height / 2 - 200);
		break;

	case TYPE_ACTIVE_SKILL:
		if (GetSkillCooldown(TYPE_ACTIVE_SKILL) == false)
		{
			SetSkillCooldown(true, TYPE_ACTIVE_SKILL);
			CreateSkillEffect(mPlayerType, TYPE_ACTIVE_SKILL);
		}
		break;

	case USER_ACTIVE_SKILL:
		if (GetSkillCooldown(USER_ACTIVE_SKILL) == false)
		{
			SetSkillCooldown(true, USER_ACTIVE_SKILL);
			CreateSkillEffect(mPlayerType, USER_ACTIVE_SKILL);
		}
		break;

	default:
		break;
	}
}

void CPlayer::Update( float dTime )
{
	NNObject::Update( dTime );

	mPlayerUI->SetRotation( -this->GetRotation() );
	mPlayerUI->SetHP( mHp );

	switch (mPlayerState)
	{
	case IDLE:
		{
			mDie->SetVisible( false );
			mStop->SetVisible( true );
			mMove->SetVisible( false );
		}
		break;
	case WALK:
		{
			//Move myPlayer with Game Key States.
			//Check Moving Input, and set Position to d
			mDie->SetVisible( false );
			mStop->SetVisible( false );
			mMove->SetVisible( true );
			SetPosition( GetPosition() + mMoveVelocity * dTime  );
			break;
		}
	case ATTAACK:
		{
		}
		break;
	case DIE:
		{
			mDie->SetVisible( true );
			mStop->SetVisible( false );
			mMove->SetVisible( false );
			mPlayerUI->SetHP( 0 );
		}
		break;
	case USER_ACTIVE_SKILL:
		{

		}
		break;
	case TYPE_ACTIVE_SKILL:
		{

		}
		break;
	default:
		break;
	}
}

void CPlayer::Render()
{
	NNObject::Render();
}

void CPlayer::InitWithType()
{
	switch (mPlayerType)
	{
	case TYPE_A:
		{
		}
		break;
	case TYPE_B:
		{
		}
		break;
	case TYPE_C:
		{
		}
		break;
	default:
		break;
	}
}