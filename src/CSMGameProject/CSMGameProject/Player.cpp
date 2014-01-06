
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
#include "GameUISet.h"

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
	mDie = NNSprite::Create( L"Resource/Sprite/Player/die.png" );
	//mStop = NNSpriteAtlas::Create( L"Resource/Sprite/Player/player.png" );
	//mStop->SetCutSize( NNSize(0,41,65,83) );
	//mMove = NNAnimationAtlas::Create( L"Resource/Sprite/Player/player.png", 3, 0.05f, NNSize(0,0,65,41), NNSize(0,41,65,83), NNSize(0,83,65,125) );
	mStopNormal = NNSprite::Create( L"Resource/Sprite/Player/Normal/normal1.png" );
	mStopFire = NNSprite::Create( L"Resource/Sprite/Player/Fire/fire1.png" );

	mMoveNormal = NNAnimation::Create( 5, 0.1f, 
		L"Resource/Sprite/Player/Normal/normal1.png",
		L"Resource/Sprite/Player/Normal/normal2.png",
		L"Resource/Sprite/Player/Normal/normal3.png",
		L"Resource/Sprite/Player/Normal/normal4.png",
		L"Resource/Sprite/Player/Normal/normal5.png" );
	
	mMoveNormal->GetFrame(0)->SetFrameTime(0.15f);
	mMoveNormal->GetFrame(1)->SetFrameTime(0.13f);
	mMoveNormal->GetFrame(2)->SetFrameTime(0.11f);
	mMoveNormal->GetFrame(3)->SetFrameTime(0.09f);
	mMoveNormal->GetFrame(4)->SetFrameTime(0.07f);

	mMoveFire = NNAnimation::Create( 5, 0.1f, 
		L"Resource/Sprite/Player/Fire/fire1.png",
		L"Resource/Sprite/Player/Fire/fire2.png",
		L"Resource/Sprite/Player/Fire/fire3.png",
		L"Resource/Sprite/Player/Fire/fire4.png",
		L"Resource/Sprite/Player/Fire/fire5.png" );

	mMoveFire->GetFrame(0)->SetFrameTime(0.15f);
	mMoveFire->GetFrame(1)->SetFrameTime(0.13f);
	mMoveFire->GetFrame(2)->SetFrameTime(0.11f);
	mMoveFire->GetFrame(3)->SetFrameTime(0.09f);
	mMoveFire->GetFrame(4)->SetFrameTime(0.07f);
	
	AddChild( mDie );
	AddChild( mStopNormal );
	AddChild( mStopFire );
	AddChild( mMoveNormal );
	AddChild( mMoveFire );

	mDie->SetVisible( false );
	mStopNormal->SetVisible( false );
	mMoveNormal->SetVisible( false );
	mStopFire->SetVisible( false );
	mMoveFire->SetVisible( false );

	TransState(PlayerState::IDLE);

	mPlayerUI = PlayerUI::Create();
	mPlayerUI->SetParent( this );
	mPlayerUI->SetPosition( 21.f, 24.f );
	AddChild( mPlayerUI );
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
		GameUISet::GetInstance()->SetSkillCooldown(TYPE_ACTIVE_SKILL);
		break;

	case USER_ACTIVE_SKILL:
		GameUISet::GetInstance()->SetSkillCooldown(USER_ACTIVE_SKILL);
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
			switch (mPlayerType)
			{
			case TYPE_ZERO:
				{
					mStopNormal->SetVisible( true );
					mMoveNormal->SetVisible( false );

					mStopFire->SetVisible( false );
					mMoveFire->SetVisible( false );
				}
				break;
			case TYPE_A:
				{
					mStopNormal->SetVisible( false );
					mMoveNormal->SetVisible( false );

					mStopFire->SetVisible( true );
					mMoveFire->SetVisible( false );
				}
				break;
			}
		}
		break;
	case WALK:
		{
			//Move myPlayer with Game Key States.
			//Check Moving Input, and set Position to d
			mDie->SetVisible( false );
			switch (mPlayerType)
			{
			case TYPE_ZERO:
				{
					mStopNormal->SetVisible( false );
					mMoveNormal->SetVisible( true );

					mStopFire->SetVisible( false );
					mMoveFire->SetVisible( false );
				}
				break;
			case TYPE_A:
				{
					mStopNormal->SetVisible( false );
					mMoveNormal->SetVisible( false );

					mStopFire->SetVisible( false );
					mMoveFire->SetVisible( true );
				}
				break;
			}
			SetPosition( GetPosition() + mMoveVelocity * dTime  );
		}break;
	case ATTAACK:
		{
			SetPosition( GetPosition() + mMoveVelocity * dTime  );
		}
		break;
	case DIE:
		{
			mDie->SetVisible( true );
			mStopNormal->SetVisible( false );
			mMoveNormal->SetVisible( false );

			mStopFire->SetVisible( false );
			mMoveFire->SetVisible( false );
			mPlayerUI->SetHP( 0 );
		}
		break;
	case USER_ACTIVE_SKILL:
		{
			
			SetPosition( GetPosition() + mMoveVelocity * dTime  );
		}
		break;
	case TYPE_ACTIVE_SKILL:
		{
			
			SetPosition( GetPosition() + mMoveVelocity * dTime  );
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