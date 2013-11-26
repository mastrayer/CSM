#include "stdafx.h"
#include "Player.h"
#include "Math.h"
#include "PlayerManager.h"


Player::Player(void):mPosition(0,0),mPlayerState(PLAYER_STATE_IDLE)
{
}

Player::Player(int id, ClientSession* client):mPosition(0,0),mHP(100),mDamage(5),mPlayerState(PLAYER_STATE_IDLE),mMovedInfo(0)
{
	
	mPlayerId = id;
	mClient = client;
}

Player::~Player(void)
{
}

void Player::TransState(short state)
{
	switch (state)
	{
	case PLAYER_STATE_IDLE:
		{
			mPlayerState = state;

			GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
			outPacket.mMyPlayerInfo = this->GetPlayerInfo();
			mClient->Broadcast(&outPacket);
			
		}
		break;
	case PLAYER_STATE_WALK:
		{
			if(mPlayerState == PLAYER_STATE_IDLE)
			{	
				mPlayerState = state;
				mMovedInfo = -1;
				GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
				outPacket.mMyPlayerInfo = this->GetPlayerInfo();
				mClient->Broadcast(&outPacket);
			}
		}
		break;
	case PLAYER_STATE_ATTACK:
		{
			if(mPlayerState == PLAYER_STATE_IDLE ||
				mPlayerState == PLAYER_STATE_WALK)
			{	
				mPlayerState = state;

				GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
				outPacket.mMyPlayerInfo = this->GetPlayerInfo();
				mClient->Broadcast(&outPacket);
			}

		}
		break;
	case PLAYER_STATE_DIE:
		{
			mResponTime = 5.f;
			mPlayerState = state;

			GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
			outPacket.mMyPlayerInfo = this->GetPlayerInfo();
			mClient->Broadcast(&outPacket);
		}
		break;
	default:
		break;
	}
}


void Player::Update( float dTime)
{
	switch (mPlayerState)
	{
	case PLAYER_STATE_IDLE:
		{
			//우선순위대로
			if( mGameKeyStates.attackKey == KEYSTATE_PRESSED )
			{
				TransState(PLAYER_STATE_ATTACK);
				break;
			}
			else if ( mGameKeyStates.leftDirectKey ==  KEYSTATE_PRESSED 
				|| mGameKeyStates.rightDirectKey == KEYSTATE_PRESSED 
				|| mGameKeyStates.upDirectKey == KEYSTATE_PRESSED 
				|| mGameKeyStates.downDirectKey == KEYSTATE_PRESSED )
			{
				TransState(PLAYER_STATE_WALK);
			}
		}
		break;
	case PLAYER_STATE_WALK:
		{
			//우선순위대로
			if( mGameKeyStates.attackKey == KEYSTATE_PRESSED )
			{
				TransState(PLAYER_STATE_ATTACK);
				break;
			}
			//Move myPlayer with Game Key States.
			//Check Moving Input, and set Position to d

			//방향이 바뀌었는지 체크
			int moveInfo = 0;
			if ( mGameKeyStates.leftDirectKey ==  KEYSTATE_PRESSED ) moveInfo |= 4;
			if ( mGameKeyStates.rightDirectKey == KEYSTATE_PRESSED ) moveInfo |= 2;
			if (mGameKeyStates.upDirectKey == KEYSTATE_PRESSED ) moveInfo |= 1;
			if ( mGameKeyStates.downDirectKey == KEYSTATE_PRESSED )	moveInfo |= 8;

			//이전과 다른 방향으로 이동했니?
			if( mMovedInfo != -1 && moveInfo != mMovedInfo)
			{
				//방향바뀐 key정보를 보내야함.
				GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
				outPacket.mMyPlayerInfo = this->GetPlayerInfo();
				mClient->Broadcast(&outPacket);
			}

			//얘네를 위에꺼랑 같이하지 않는 이유는, 아래 SetPosition 이동하고 데이터를 보내게 되면 클라 입장에서는 끊기는 것처럼 보여서...
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
			mMovedInfo = moveInfo;

			if ( mGameKeyStates.leftDirectKey ==  KEYSTATE_NOTPRESSED 
				&& mGameKeyStates.rightDirectKey == KEYSTATE_NOTPRESSED 
				&& mGameKeyStates.upDirectKey == KEYSTATE_NOTPRESSED 
				&& mGameKeyStates.downDirectKey == KEYSTATE_NOTPRESSED )
			{
				TransState(PLAYER_STATE_IDLE);
			}
		}
		break;
	case PLAYER_STATE_ATTACK:
		{
			 Point AttackPoint = mPosition + Point(cos(mRotation) * mAttackRange,sin(mRotation) * mAttackRange);
			 std::map<int,Player*> players = GPlayerManager->GetPlayers();
			for( std::map<int,Player*>::iterator it = players.begin(); it != players.end(); ++it ) 
			{
				Player* enemy = it->second;
				if(enemy == this)continue;

				if( Point().GetDistance( enemy->GetPosition(), AttackPoint ) < mAttackRange )
				{
					//피격데스네
					enemy->Damaged(mHP);
				}
			}
			TransState(PLAYER_STATE_IDLE);
			break;
		}
		break;
		
	case PLAYER_STATE_DIE:
		{
			mResponTime -= dTime;
			if(mResponTime < 0)
			{
				//살려내야합니다.
				SetPosition(Point(0,0));
				SetHP(100);
				TransState(PLAYER_STATE_IDLE);
				break;
			}
		}
		break;
	default:
		break;
	}
}
void Player::Damaged(int damage)
{
	if(mHP < damage)
	{
		//죽었슴다
		TransState(PLAYER_STATE_DIE);
	}
	else
	{
		mHP-=damage;
		//현재 피 얼마라고 브로드캐스팅
		HPUpdateResult outPacket = HPUpdateResult();
		outPacket.mPlayerId = mPlayerId;
		outPacket.mHP = mHP;
		mClient->Broadcast(&outPacket);
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
	mPlayerInfo.mPlayerState = mPlayerState;
	mPlayerInfo.mHP = mHP;
	return mPlayerInfo;
}