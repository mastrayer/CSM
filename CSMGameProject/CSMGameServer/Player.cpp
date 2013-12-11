#include "stdafx.h"
#include "Player.h"
#include "Math.h"
#include "PlayerManager.h"
#include "GameManager.h"
#include "Skills.h"

Player::Player(void):mPosition(0,0),mPlayerState(PLAYER_STATE_IDLE)
{
}

Player::Player(int id, ClientSession* client):mHP(),mDamage(),mPlayerState(PLAYER_STATE_IDLE),mMoveDirection(Point(-10.f,-10.f))
	,mAttackRange(40),mRadius(24),mRotation(0),mAttackDelay(0),mUserSkillDelay(0),mTypeSkillDelay(0),mSpeed(0)
{
	mType = rand()%2;
	InitWithType();
	mPlayerId = id;
	mClient = client;

	while(1)
	{
		float x = rand() % (GGameMap->GetWidth() * 64);
		float y = rand() % (GGameMap->GetHeight() * 64);

		if(CouldGoPosition(Point(x,y)) == true)
		{
			mPosition = Point(x,y);
			break;
		}
	}
	mTeam = GGameManager->GiveTeamNumber();
}

Player::~Player(void)
{
	//소멸자가 제대로 호출 안될 수도 있을거같은데..
	GGameManager->LogOutPlayer(mTeam);
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
			Point willGoPosition = GetPosition();
			if ( mGameKeyStates.leftDirectKey ==  KEYSTATE_PRESSED )willGoPosition = willGoPosition + Point( -1.f, 0.f ) * mDTime * mSpeed;
			if ( mGameKeyStates.rightDirectKey == KEYSTATE_PRESSED )willGoPosition = willGoPosition + Point( +1.f, 0.f ) * mDTime * mSpeed;
			if ( mGameKeyStates.upDirectKey == KEYSTATE_PRESSED )	willGoPosition = willGoPosition + Point( 0.f, -1.f ) * mDTime * mSpeed;
			if ( mGameKeyStates.downDirectKey == KEYSTATE_PRESSED )	willGoPosition = willGoPosition + Point( 0.f, +1.f ) * mDTime * mSpeed;

			if ( GGameMap->isValidTile(willGoPosition) == false )
			{
				//못가니까 walk로 변환하지 않음.
				break;
			}
			if(mPlayerState == PLAYER_STATE_IDLE)
			{	
				mMoveDirection = Point(-10.f,-10.f);
				mPlayerState = state;
				GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
				outPacket.mMyPlayerInfo = this->GetPlayerInfo();
				mClient->Broadcast(&outPacket);
			}
		}
		break;
	case PLAYER_STATE_ATTACK:
		{
			if(mAttackDelay > 0) break;
			if(mPlayerState == PLAYER_STATE_IDLE ||
				mPlayerState == PLAYER_STATE_WALK)
			{	
				mPlayerState = state;
				mAttackDelay = 1;
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
	case PLAYER_STATE_TYPESKILL:
		{
			if(mTypeSkillDelay > 0 )break;
			if(mPlayerState == PLAYER_STATE_IDLE ||
				mPlayerState == PLAYER_STATE_WALK)
			{	
				mPlayerState = state;
			}
		}
		break;
	case PLAYER_STATE_USERSKILL:
		{
			if(mUserSkillDelay > 0) break;
			if(mPlayerState == PLAYER_STATE_IDLE ||
				mPlayerState == PLAYER_STATE_WALK)
			{	
				mPlayerState = state;
			}
		}
		break;
	default:
		break;
	}
}


void Player::Update( float dTime)
{
	mDTime = dTime;
	if(mAttackDelay > 0)
		mAttackDelay -= dTime;
	if(mUserSkillDelay > 0)
		mUserSkillDelay -= dTime;
	if(mTypeSkillDelay > 0)
		mTypeSkillDelay -= dTime;
	switch (mPlayerState)
	{
	case PLAYER_STATE_IDLE:
		{
			if( mGameKeyStates.typeActiveSkillKey == KEYSTATE_PRESSED)
			{
				TransState(PLAYER_STATE_TYPESKILL);
				break;
			}
			if( mGameKeyStates.userActiveSkillKey == KEYSTATE_PRESSED)
			{
				TransState(PLAYER_STATE_USERSKILL);
				break;
			}
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
			}else if ( mGameKeyStates.typeActiveSkillKey == KEYSTATE_PRESSED)
				TransState(PLAYER_STATE_TYPESKILL);
		}
		break;
	case PLAYER_STATE_WALK:
		{
			if( mGameKeyStates.typeActiveSkillKey == KEYSTATE_PRESSED)
			{
				TransState(PLAYER_STATE_TYPESKILL);
				break;
			}
			if( mGameKeyStates.userActiveSkillKey == KEYSTATE_PRESSED)
			{
				TransState(PLAYER_STATE_USERSKILL);
				break;
			}
			if( mGameKeyStates.attackKey == KEYSTATE_PRESSED )
			{
				TransState(PLAYER_STATE_ATTACK);
				break;
			}
			//Move myPlayer with Game Key States.
			//Check Moving Input, and sㅇㅇㅇㅈㅈㅇet Position to d


			Point willGoDirection = Point(0,0);

			if ( mGameKeyStates.leftDirectKey ==  KEYSTATE_PRESSED )willGoDirection = willGoDirection + Point( -1.f, 0.f );
			if ( mGameKeyStates.rightDirectKey == KEYSTATE_PRESSED )willGoDirection = willGoDirection + Point( +1.f, 0.f );
			if ( mGameKeyStates.upDirectKey == KEYSTATE_PRESSED )	willGoDirection = willGoDirection + Point( 0.f, -1.f );
			if ( mGameKeyStates.downDirectKey == KEYSTATE_PRESSED )	willGoDirection = willGoDirection + Point( 0.f, +1.f );

			float d = pow( pow(willGoDirection.x , 2) + pow( willGoDirection.y, 2) , 0.5);
			if(d != 0.f)
			{
				willGoDirection.x = willGoDirection.x / d;
				willGoDirection.y = willGoDirection.y / d;
			}
			willGoDirection = willGoDirection * mSpeed;

			Point willGoPosition;

			//wasd 전부 다 땠는지 확인
			if ( mGameKeyStates.leftDirectKey ==  KEYSTATE_NOTPRESSED 
				&& mGameKeyStates.rightDirectKey == KEYSTATE_NOTPRESSED 
				&& mGameKeyStates.upDirectKey == KEYSTATE_NOTPRESSED 
				&& mGameKeyStates.downDirectKey == KEYSTATE_NOTPRESSED )
			{
				TransState(PLAYER_STATE_IDLE);
				break;
			}

			//지금 갈려고 하는 방향이 map에서 이동 불가능한 지역이니?
			if ( CouldGoPosition( GetPosition() + willGoDirection * dTime ) == false )
			{
				//X좌표라도 갈수있니?
				if ( CouldGoPosition( GetPosition() + Point(willGoDirection.x,0) * dTime ) == true )
				{
					willGoDirection = Point(willGoDirection.x,0);
				}
				//Y좌표라도 갈 수 있니?
				else if ( CouldGoPosition( GetPosition() +  Point(0,willGoDirection.y) * dTime ) == true )
				{
					willGoDirection = Point(0,willGoDirection.y);
				}
				else
				{
					willGoDirection = Point(0,0);
				}
			}
			willGoPosition = GetPosition() + willGoDirection * dTime;
			SetPosition(willGoPosition);


			//이전과 다른 방향으로 이동했니?
			// -10, -10 이거 그냥 bool함수로 빼내서 초기화 다시 해줄것.
			if( mMoveDirection == Point(-10.f,-10.f) || mMoveDirection != willGoDirection)
			{
				mMoveDirection = willGoDirection;
				//방향바뀐 key정보를 보내야함.
				GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
				outPacket.mMyPlayerInfo = this->GetPlayerInfo();
				mClient->Broadcast(&outPacket);
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

				if( Point().GetDistance( enemy->GetPosition(), AttackPoint ) < mRadius )
				{
					//피격데스네
					if ( enemy->Damaged(mDamage+rand()%10) == true);
					{
						//쟤를 죽인거니까	
						ChangeType(GetTypeChangeResult(mType, enemy->mType));
					}
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
				while(1)
				{
					float x = rand() % (GGameMap->GetWidth() * 64);
					float y = rand() % (GGameMap->GetHeight() * 64);
					if(CouldGoPosition(Point(x,y)) == true)
					{
						mPosition = Point(x,y);
						break;
					}
				}
				mType = rand()%2;
				InitWithType();
				TransState(PLAYER_STATE_IDLE);
				break;
			}
		}
		break;
	case PLAYER_STATE_TYPESKILL:
		{
			switch (mType)
			{
			case TYPE_A:
				{
					mTypeSkillDelay = 3.f;
					ATypeSkill(mRotation,mPosition);
					GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
					outPacket.mMyPlayerInfo = this->GetPlayerInfo();
					mClient->Broadcast(&outPacket);
					TransState(PLAYER_STATE_IDLE);
				}break;
			case TYPE_B:
				{
					
					mTypeSkillDelay = 3.f;
					GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
					outPacket.mMyPlayerInfo = this->GetPlayerInfo();
					mClient->Broadcast(&outPacket);
					TransState(PLAYER_STATE_IDLE);
				}break;
			case TYPE_C:
				{
					
					mTypeSkillDelay = 3.f;
					GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
					outPacket.mMyPlayerInfo = this->GetPlayerInfo();
					mClient->Broadcast(&outPacket);
					TransState(PLAYER_STATE_IDLE);
				}break;
			default:
				break;
			}
			break;
		}
		break;
	case PLAYER_STATE_USERSKILL:
		{
			switch (mType)
			{
			case TYPE_A:
				{
					
					mUserSkillDelay = 5.f;
					GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
					outPacket.mMyPlayerInfo = this->GetPlayerInfo();
					mClient->Broadcast(&outPacket);
				}break;
			case TYPE_B:
				{
					mUserSkillDelay = 10.f;
					GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
					outPacket.mMyPlayerInfo = this->GetPlayerInfo();
					mClient->Broadcast(&outPacket);
				}break;
			case TYPE_C:
				{
					mUserSkillDelay = 5.f;
					GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
					outPacket.mMyPlayerInfo = this->GetPlayerInfo();
					mClient->Broadcast(&outPacket);
				}break;
			default:
				break;
			}
			TransState(PLAYER_STATE_IDLE);
			break;
		}
		break;
	default:
		break;
	}
}
// return value : true - die, false - non-die
bool Player::Damaged(int damage)
{
	if(mHP < damage)
	{
		HPUpdateResult outPacket = HPUpdateResult();
		outPacket.mPlayerId = mPlayerId;
		outPacket.mHP = 0;
		mClient->Broadcast(&outPacket);
		//죽었슴다
		GGameManager->DiePlayer(mTeam);
		TransState(PLAYER_STATE_DIE);
		return true;
	}
	else
	{
		mHP-=damage;
		//현재 피 얼마라고 브로드캐스팅
		HPUpdateResult outPacket = HPUpdateResult();
		outPacket.mPlayerId = mPlayerId;
		outPacket.mHP = mHP;
		mClient->Broadcast(&outPacket);
		return false;
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
	mPlayerInfo.mMoveDirection = mMoveDirection;
	mPlayerInfo.mTeam = mTeam;
	mPlayerInfo.mType = mType;
	return mPlayerInfo;
}

bool Player::CouldGoPosition(Point position)
{
	for( int x = (position.x - mRadius)/64; x <= (position.x + mRadius)/64; x += 1 )//64 = tilesize
	{
		for( int y = (position.y - mRadius)/64; y <= (position.y + mRadius)/64; y += 1 )//64 = tilesize
		{
			if ( GGameMap->isValidTile(Point(x*64,y*64)) == false)
				return false;
		}
	}	
	std::map<int,Player*> players = GPlayerManager->GetPlayers();
	for( std::map<int,Player*>::iterator it = players.begin(); it != players.end(); ++it ) 
	{
		Player* enemy = it->second;
		if(enemy == this)continue;

		if( Point().GetDistance( enemy->GetPosition(), position ) < mRadius*2 )
		{
			return false;
		}
	}
	return true;
}

void Player::ChangeType(int type)
{
	mType = type;
	GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
	outPacket.mMyPlayerInfo = this->GetPlayerInfo();
	mClient->Broadcast(&outPacket);
}

int Player::GetTypeChangeResult(int killerType, int victimType)
{
	switch (killerType)
	{
	case TYPE_A:
		{
			switch (killerType)
			{
			case TYPE_A:
				{
					return TYPE_A;
				}break;
			case TYPE_B:
				{
					return TYPE_C;
				}break;
			case TYPE_C:
				{
					return TYPE_B;
				}break;
			default:
				break;
			}
		}break;
	case TYPE_B:
		{
			switch (killerType)
			{
			case TYPE_A:
				{
					TYPE_C;
				}break;
			case TYPE_B:
				{
					TYPE_B;
				}break;
			case TYPE_C:
				{
					TYPE_A;
				}break;
			default:
				break;
			}
		}break;
	case TYPE_C:
		{
			switch (killerType)
			{
			case TYPE_A:
				{
					TYPE_C;
				}break;
			case TYPE_B:
				{
					return TYPE_C;
				}break;
			case TYPE_C:
				{
					if(rand()%2 == 0)
					{
						return TYPE_A;
					}
					return TYPE_B;
				}break;
			default:
				break;
			}
		}break;
	default:
		break;
	}

	/*
	지우지마세요
	switch (killerType)
	{
	case TYPE_A:
	{

	}break;
	case TYPE_B:
	{

	}break;
	case TYPE_C:
	{

	}break;
	default:
	break;
	}*/
}
void Player::InitWithType()
{
	switch (mType)
	{
	case TYPE_A:
		{
			SetHP(50);
			mDamage = 15;
			mSpeed = 100;
		}break;
	case TYPE_B:
		{
			SetHP(55);
			mDamage = 11;
			mSpeed = 110;
		}break;
	case TYPE_C:
		{
			SetHP(35);
			mDamage = 19;
			mSpeed = 120;
		}break;
	default:
		break;
	}
}