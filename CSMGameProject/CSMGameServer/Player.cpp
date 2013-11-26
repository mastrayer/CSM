#include "stdafx.h"
#include "Player.h"
#include "Math.h"


Player::Player(void):mPosition(0,0)
{
	TransState(PLAYER_STATE_IDLE);
}

Player::Player(int id):mPosition(0,0)
{
	TransState(PLAYER_STATE_IDLE);
	mPlayerId = id;
}

Player::~Player(void)
{
}

void Player::TransState(short state)
{
	mPlayerState = state;
}


void Player::Update( float dTime)
{
	//Move myPlayer with Game Key States.
	//Check Moving Input, and set Position to d
	if ( mGameKeyStates.leftDirectKey ==  KEYSTATE_PRESSED )
	{
		//Left
		SetPosition( GetPosition() + Point( -1.f, 0.f ) * dTime * 100.f );
	}
	if ( mGameKeyStates.rightDirectKey == KEYSTATE_PRESSED )
	{
		//Right
		SetPosition( GetPosition() + Point( 1.f, 0.f ) * dTime * 100.f );
	}
	if (mGameKeyStates.upDirectKey == KEYSTATE_PRESSED )
	{
		//UP
		SetPosition( GetPosition() + Point( 0.f, -1.f ) * dTime * 100.f );
	}
	if ( mGameKeyStates.downDirectKey == KEYSTATE_PRESSED )
	{
		//Down
		SetPosition( GetPosition() + Point( 0.f, 1.f ) * dTime * 100.f );
	}
}
PlayerInfo Player::GetPlayerInfo()
{
	PlayerInfo mPlayerInfo;
	mPlayerInfo.mGameKeyStates = mGameKeyStates;
	mPlayerInfo.mX = mPosition.x;
	mPlayerInfo.mY = mPosition.y;
	mPlayerInfo.mPlayerId = mPlayerId;
	mPlayerInfo.mAngle = mRotation;
	return mPlayerInfo;
}