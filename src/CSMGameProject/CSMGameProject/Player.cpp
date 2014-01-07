
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
	  mRebirthDelayTime(10), mTeam(0), mKillScore(0),
	  mIsEmoticonRunning(false)
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
	
	AddChild( mDie );

	InitStopImage();
	InitMoveImage();
	InitAttackImage();
	INitDieImage();
	

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

	// Die
	mDie->SetVisible( false );

	// Normal
	mStopNormal->SetVisible( true );
	mMoveNormal->SetVisible( false );
	mAttackNormal->SetVisible( false );
	mDieNormal->SetVisible( false );

	// Fire
	mStopFire->SetVisible( false );
	mMoveFire->SetVisible( false );
	mAttackFire->SetVisible( false );
	mDieFire->SetVisible( false );

	// Water
	mStopWater->SetVisible( false );
	mMoveWater->SetVisible( false );
	mAttackWater->SetVisible( false );
	mDieWater->SetVisible( false );

	// Wind
	mStopWind->SetVisible( false );
	mMoveWind->SetVisible( false );
	mAttackWind->SetVisible( false );
	mDieWind->SetVisible( false );

	// Earth
	mStopEarth->SetVisible( false );
	mMoveEarth->SetVisible( false );
	mAttackEarth->SetVisible( false );
	mDieEarth->SetVisible( false );

	switch (mPlayerState)
	{
	case IDLE:
		{
			switch (mPlayerType)
			{
			case TYPE_ZERO:
				{
					mStopNormal->SetVisible( true );
				}
				break;
			case TYPE_A:
				{
					mStopFire->SetVisible( true );
				}
				break;
			case TYPE_B:
				{
					mStopWater->SetVisible( true );
				}
				break;
			case TYPE_C:
				{
					mStopWind->SetVisible( true );
				}
				break;
			case TYPE_D:
				{
					mStopEarth->SetVisible( true );
				}
				break;
			}
		}
		break;
	case WALK:
		{
			switch (mPlayerType)
			{
			case TYPE_ZERO:
				{
					mMoveNormal->SetVisible( true );
				}
				break;
			case TYPE_A:
				{
					mMoveFire->SetVisible( true );
				}
				break;
			case TYPE_B:
				{
					mMoveWater->SetVisible( true );
				}
				break;
			case TYPE_C:
				{
					mMoveWind->SetVisible( true );
				}
				break;
			case TYPE_D:
				{
					mMoveEarth->SetVisible( true );
				}
				break;
			}
			SetPosition( GetPosition() + mMoveVelocity * dTime  );
		}break;
	case ATTAACK:
		{
			switch (mPlayerType)
			{
			case TYPE_ZERO:
				{
					mAttackNormal->SetVisible( true );
				}
				break;
			case TYPE_A:
				{
					mAttackFire->SetVisible( true );
				}
				break;
			case TYPE_B:
				{
					mAttackWater->SetVisible( true );
				}
				break;
			case TYPE_C:
				{
					mAttackWind->SetVisible( true );
				}
				break;
			case TYPE_D:
				{
					mAttackEarth->SetVisible( true );
				}
				break;
			}
			SetPosition( GetPosition() + mMoveVelocity * dTime  );
		}
		break;
	case DIE:
		{
			mDie->SetVisible( true );
			switch (mPlayerType)
			{
			case TYPE_ZERO:
				{
					mDieNormal->SetVisible( true );
				}
				break;
			case TYPE_A:
				{
					mDieFire->SetVisible( true );
				}
				break;
			case TYPE_B:
				{
					mDieWater->SetVisible( true );
				}
				break;
			case TYPE_C:
				{
					mDieWind->SetVisible( true );
				}
				break;
			case TYPE_D:
				{
					mDieEarth->SetVisible( true );
				}
				break;
			}
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

void CPlayer::InitStopImage()
{
	mStopNormal = NNAnimation::Create( 4, 0.1f, 
		L"Resource/Sprite/Player/Normal/normal_stop1.png",
		L"Resource/Sprite/Player/Normal/normal_stop2.png",
		L"Resource/Sprite/Player/Normal/normal_stop3.png",
		L"Resource/Sprite/Player/Normal/normal_stop4.png" );
	mStopFire = NNAnimation::Create( 4, 0.1f, 
		L"Resource/Sprite/Player/Fire/fire_stop1.png",
		L"Resource/Sprite/Player/Fire/fire_stop2.png",
		L"Resource/Sprite/Player/Fire/fire_stop3.png",
		L"Resource/Sprite/Player/Fire/fire_stop4.png" );
	mStopWater = NNAnimation::Create( 4, 0.1f, 
		L"Resource/Sprite/Player/Water/water_stop1.png",
		L"Resource/Sprite/Player/Water/water_stop2.png",
		L"Resource/Sprite/Player/Water/water_stop3.png",
		L"Resource/Sprite/Player/Water/water_stop4.png" );
	mStopWind = NNAnimation::Create( 4, 0.1f, 
		L"Resource/Sprite/Player/Wind/wind_stop1.png",
		L"Resource/Sprite/Player/Wind/wind_stop2.png",
		L"Resource/Sprite/Player/Wind/wind_stop3.png",
		L"Resource/Sprite/Player/Wind/wind_stop4.png" );
	mStopEarth = NNAnimation::Create( 4, 0.1f, 
		L"Resource/Sprite/Player/Earth/earth_stop1.png",
		L"Resource/Sprite/Player/Earth/earth_stop2.png",
		L"Resource/Sprite/Player/Earth/earth_stop3.png",
		L"Resource/Sprite/Player/Earth/earth_stop4.png" );

	AddChild( mStopNormal );
	AddChild( mStopFire );
	AddChild( mStopWater );
	AddChild( mStopWind );
	AddChild( mStopEarth );
}
void CPlayer::InitMoveImage()
{
	mMoveNormal = NNAnimation::Create( 5, 0.1f, 
		L"Resource/Sprite/Player/Normal/normal_walk1.png",
		L"Resource/Sprite/Player/Normal/normal_walk2.png",
		L"Resource/Sprite/Player/Normal/normal_walk3.png",
		L"Resource/Sprite/Player/Normal/normal_walk4.png",
		L"Resource/Sprite/Player/Normal/normal_walk5.png" );
	mMoveNormal->GetFrame(0)->SetFrameTime(0.15f);
	mMoveNormal->GetFrame(1)->SetFrameTime(0.13f);
	mMoveNormal->GetFrame(2)->SetFrameTime(0.11f);
	mMoveNormal->GetFrame(3)->SetFrameTime(0.09f);
	mMoveNormal->GetFrame(4)->SetFrameTime(0.07f);

	mMoveFire = NNAnimation::Create( 5, 0.1f, 
		L"Resource/Sprite/Player/Fire/fire_walk1.png",
		L"Resource/Sprite/Player/Fire/fire_walk2.png",
		L"Resource/Sprite/Player/Fire/fire_walk3.png",
		L"Resource/Sprite/Player/Fire/fire_walk4.png",
		L"Resource/Sprite/Player/Fire/fire_walk5.png" );
	mMoveFire->GetFrame(0)->SetFrameTime(0.15f);
	mMoveFire->GetFrame(1)->SetFrameTime(0.13f);
	mMoveFire->GetFrame(2)->SetFrameTime(0.11f);
	mMoveFire->GetFrame(3)->SetFrameTime(0.09f);
	mMoveFire->GetFrame(4)->SetFrameTime(0.07f);

	mMoveWater = NNAnimation::Create( 5, 0.1f, 
		L"Resource/Sprite/Player/Water/water_walk1.png",
		L"Resource/Sprite/Player/Water/water_walk2.png",
		L"Resource/Sprite/Player/Water/water_walk3.png",
		L"Resource/Sprite/Player/Water/water_walk4.png",
		L"Resource/Sprite/Player/Water/water_walk5.png" );
	mMoveWater->GetFrame(0)->SetFrameTime(0.15f);
	mMoveWater->GetFrame(1)->SetFrameTime(0.13f);
	mMoveWater->GetFrame(2)->SetFrameTime(0.11f);
	mMoveWater->GetFrame(3)->SetFrameTime(0.09f);
	mMoveWater->GetFrame(4)->SetFrameTime(0.07f);

	mMoveWind = NNAnimation::Create( 5, 0.1f, 
		L"Resource/Sprite/Player/Wind/wind_walk1.png",
		L"Resource/Sprite/Player/Wind/wind_walk2.png",
		L"Resource/Sprite/Player/Wind/wind_walk3.png",
		L"Resource/Sprite/Player/Wind/wind_walk4.png",
		L"Resource/Sprite/Player/Wind/wind_walk5.png" );
	mMoveWind->GetFrame(0)->SetFrameTime(0.15f);
	mMoveWind->GetFrame(1)->SetFrameTime(0.13f);
	mMoveWind->GetFrame(2)->SetFrameTime(0.11f);
	mMoveWind->GetFrame(3)->SetFrameTime(0.09f);
	mMoveWind->GetFrame(4)->SetFrameTime(0.07f);

	mMoveEarth = NNAnimation::Create( 5, 0.1f, 
		L"Resource/Sprite/Player/Earth/earth_walk1.png",
		L"Resource/Sprite/Player/Earth/earth_walk2.png",
		L"Resource/Sprite/Player/Earth/earth_walk3.png",
		L"Resource/Sprite/Player/Earth/earth_walk4.png",
		L"Resource/Sprite/Player/Earth/earth_walk5.png" );
	mMoveEarth->GetFrame(0)->SetFrameTime(0.15f);
	mMoveEarth->GetFrame(1)->SetFrameTime(0.13f);
	mMoveEarth->GetFrame(2)->SetFrameTime(0.11f);
	mMoveEarth->GetFrame(3)->SetFrameTime(0.09f);
	mMoveEarth->GetFrame(4)->SetFrameTime(0.07f);

	AddChild( mMoveNormal );
	AddChild( mMoveFire );
	AddChild( mMoveWater );
	AddChild( mMoveWind );
	AddChild( mMoveEarth );
}
void CPlayer::InitAttackImage()
{
	mAttackNormal = NNAnimation::Create( 4, 0.05f, 
		L"Resource/Sprite/Player/Normal/normal_attack1.png",
		L"Resource/Sprite/Player/Normal/normal_attack2.png",
		L"Resource/Sprite/Player/Normal/normal_attack3.png",
		L"Resource/Sprite/Player/Normal/normal_attack4.png" );
	mAttackFire = NNAnimation::Create( 4, 0.05f, 
		L"Resource/Sprite/Player/Fire/fire_attack1.png",
		L"Resource/Sprite/Player/Fire/fire_attack2.png",
		L"Resource/Sprite/Player/Fire/fire_attack3.png",
		L"Resource/Sprite/Player/Fire/fire_attack4.png" );
	mAttackWater = NNAnimation::Create( 4, 0.05f, 
		L"Resource/Sprite/Player/Water/water_attack1.png",
		L"Resource/Sprite/Player/Water/water_attack2.png",
		L"Resource/Sprite/Player/Water/water_attack3.png",
		L"Resource/Sprite/Player/Water/water_attack4.png" );
	mAttackWind = NNAnimation::Create( 4, 0.05f, 
		L"Resource/Sprite/Player/Wind/wind_attack1.png",
		L"Resource/Sprite/Player/Wind/wind_attack2.png",
		L"Resource/Sprite/Player/Wind/wind_attack3.png",
		L"Resource/Sprite/Player/Wind/wind_attack4.png" );
	mAttackEarth = NNAnimation::Create( 4, 0.05f, 
		L"Resource/Sprite/Player/Earth/earth_attack1.png",
		L"Resource/Sprite/Player/Earth/earth_attack2.png",
		L"Resource/Sprite/Player/Earth/earth_attack3.png",
		L"Resource/Sprite/Player/Earth/earth_attack4.png" );

	AddChild( mAttackNormal );
	AddChild( mAttackFire );
	AddChild( mAttackWater );
	AddChild( mAttackWind );
	AddChild( mAttackEarth );
}
void CPlayer::INitDieImage()
{
	mDieNormal = NNAnimation::Create( 4, 0.05f, 
		L"Resource/Sprite/Player/Normal/normal_dead1.png",
		L"Resource/Sprite/Player/Normal/normal_dead2.png",
		L"Resource/Sprite/Player/Normal/normal_dead3.png",
		L"Resource/Sprite/Player/Normal/normal_dead4.png" );
	mDieFire = NNAnimation::Create( 4, 0.05f, 
		L"Resource/Sprite/Player/Fire/fire_dead1.png",
		L"Resource/Sprite/Player/Fire/fire_dead2.png",
		L"Resource/Sprite/Player/Fire/fire_dead3.png",
		L"Resource/Sprite/Player/Fire/fire_dead4.png" );
	mDieWater = NNAnimation::Create( 4, 0.05f, 
		L"Resource/Sprite/Player/Water/water_dead1.png",
		L"Resource/Sprite/Player/Water/water_dead2.png",
		L"Resource/Sprite/Player/Water/water_dead3.png",
		L"Resource/Sprite/Player/Water/water_dead4.png" );
	mDieWind = NNAnimation::Create( 4, 0.05f, 
		L"Resource/Sprite/Player/Wind/wind_dead1.png",
		L"Resource/Sprite/Player/Wind/wind_dead2.png",
		L"Resource/Sprite/Player/Wind/wind_dead3.png",
		L"Resource/Sprite/Player/Wind/wind_dead4.png" );
	mDieEarth = NNAnimation::Create( 4, 0.05f, 
		L"Resource/Sprite/Player/Earth/earth_dead1.png",
		L"Resource/Sprite/Player/Earth/earth_dead2.png",
		L"Resource/Sprite/Player/Earth/earth_dead3.png",
		L"Resource/Sprite/Player/Earth/earth_dead4.png" );

	AddChild( mDieNormal );
	AddChild( mDieFire );
	AddChild( mDieWater );
	AddChild( mDieWind );
	AddChild( mDieEarth );
}