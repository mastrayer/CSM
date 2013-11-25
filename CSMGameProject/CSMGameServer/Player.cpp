#include "stdafx.h"
#include "Player.h"
#include "Math.h"


Player::Player(void):mPosition(0,0)
{
	TransState(IDLE);
}

Player::Player(int id):mPosition(0,0)
{
	TransState(IDLE);
	mPlayerId = id;
}

Player::~Player(void)
{
}

void Player::TransState(PlayerState state)
{
	mPlayerState = state;
}


void Player::Update( float dTime)
{
	//Move myPlayer with Game Key States.
	//Check Moving Input, and set Position to d
	if ( mGameKeyStates.leftDirectKey ==  KEY_DOWN  || 
		mGameKeyStates.leftDirectKey == KEY_PRESSED )
	{
		//Left
		SetPosition( GetPosition() + Point( 1.f, 0.f ) * dTime * 100.f );
	}
	if ( mGameKeyStates.rightDirectKey == KEY_DOWN  || 
		mGameKeyStates.rightDirectKey == KEY_PRESSED)
	{
		//Right
		SetPosition( GetPosition() + Point( -1.f, 0.f ) * dTime * 100.f );
	}
	if (mGameKeyStates.upDirectKey == KEY_DOWN  || 
		mGameKeyStates.upDirectKey == KEY_PRESSED)
	{
		//UP
		SetPosition( GetPosition() + Point( 0.f, -1.f ) * dTime * 100.f );
	}
	if ( mGameKeyStates.downDirectKey == KEY_DOWN  || 
		mGameKeyStates.downDirectKey == KEY_PRESSED)
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
	return mPlayerInfo;
}