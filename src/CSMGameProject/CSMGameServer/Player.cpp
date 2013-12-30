#include "stdafx.h"
#include "Player.h"
#include "Math.h"
#include "PlayerManager.h"
#include "GameManager.h"
#include "Skills.h"

#include "GameMap.h"

Player::Player(void):mPosition(0,0),mPlayerState(PLAYER_STATE_IDLE)
{
}

Player::Player(int id, ClientSession* client)
	: mHP(), mPlayerState(PLAYER_STATE_IDLE), mMoveDirection(Point(0.f,0.f)),
	mAttackRange(64), mRadius(24), mRotation(0), mAttackDelay(0), mUserSkillDelay(0),
	mTypeSkillDelay(0), mSpeed(0), mKillScore(0)
{
	mType = 0;
	InitWithType();
	mPlayerId = id;
	mClient = client;

	mTeam = GGameManager->GiveTeamNumber();

	int cnt = 0;
	while(1)
	{
		float x, y;
		if ( mTeam == 0 )
		{
			x = GGameMap->GetStartingPointAX() + 32.f;
			y = GGameMap->GetStartingPointAY() + 32.f;
		}
		else
		{
			x = GGameMap->GetStartingPointBX() + 32.f;
			y = GGameMap->GetStartingPointBY() + 32.f;
		}

		if ( cnt != 0 )
		{
			switch ( cnt%4 ) 
			{
			case 0:
				y -= int(cnt/4+1) * 64.f;
				break;
			case 1:
				x += int(cnt/4+1) * 64.f;
				break;
			case 2:
				y += int(cnt/4+1) * 64.f;
				break;
			case 3:
				x -= int(cnt/4+1) * 64.f;
				break;
			default:
				break;
			}
		}

		if(CouldGoPosition(Point(x,y)) == true)
		{
			mPosition = Point(x,y);
			break;
		}

		++cnt;
	}
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
			if ( mGameKeyStates.leftDirectKey ==  KEYSTATE_PRESSED )willGoPosition = willGoPosition + Point( -1.f, 0.f ) * mDTime * (float)mSpeed;
			if ( mGameKeyStates.rightDirectKey == KEYSTATE_PRESSED )willGoPosition = willGoPosition + Point( +1.f, 0.f ) * mDTime * (float)mSpeed;
			if ( mGameKeyStates.upDirectKey == KEYSTATE_PRESSED )	willGoPosition = willGoPosition + Point( 0.f, -1.f ) * mDTime * (float)mSpeed;
			if ( mGameKeyStates.downDirectKey == KEYSTATE_PRESSED )	willGoPosition = willGoPosition + Point( 0.f, +1.f ) * mDTime * (float)mSpeed;

			if ( GGameMap->isValidTile(willGoPosition) == false )
			{
				//못가니까 walk로 변환하지 않음.
				break;
			}
			if(mPlayerState == PLAYER_STATE_IDLE)
			{	
				mMoveDirection = Point(0.f,0.f);
				mPlayerState = state;
				GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
				outPacket.mMyPlayerInfo = this->GetPlayerInfo();
				mClient->Broadcast(&outPacket);
			}
		}
		break;
	case PLAYER_STATE_ATTACK:
		{
			if(mType == TYPE_ZERO) break;
			if(mAttackDelay <= 0 && (mPlayerState == PLAYER_STATE_IDLE || mPlayerState == PLAYER_STATE_WALK))
			{	
				mPreDelay = 0.1f;

				mMoveDirection = Point(0,0);
				GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
				outPacket.mMyPlayerInfo = this->GetPlayerInfo();
				mClient->Broadcast(&outPacket);

				mPlayerState = state;
			}
			mGameKeyStates.attackKey = KEYSTATE_NOTPRESSED;
		}
		break;
	case PLAYER_STATE_DIE:
		{
			if(mType == TYPE_ZERO) break;
			mResponTime = 5.f;
			mPlayerState = state;

			mMoveDirection = Point(0,0);
			GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
			outPacket.mMyPlayerInfo = this->GetPlayerInfo();
			mClient->Broadcast(&outPacket);
		}
		break;
	case PLAYER_STATE_TYPESKILL:
		{
			if(mType == TYPE_ZERO) break;
			if(mTypeSkillDelay <= 0 && (mPlayerState == PLAYER_STATE_IDLE || mPlayerState == PLAYER_STATE_WALK))
			{	
				//mPreDelay = 0.1f;
				mMoveDirection = Point(0,0);
				GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
				outPacket.mMyPlayerInfo = this->GetPlayerInfo();
				mClient->Broadcast(&outPacket);
				mPlayerState = state;
				if(mType == TYPE_D)
				{
					mDSkillPostDelay = 0.3f;
					new DTypeSkill(mRotation,this);
				}
			}
			else 
			{	
				mGameKeyStates.typeActiveSkillKey = KEYSTATE_NOTPRESSED;
			}
		}
		break;
	case PLAYER_STATE_USERSKILL:
		{
			if(mType == TYPE_ZERO) break;
			if(mUserSkillDelay <= 0 && (mPlayerState == PLAYER_STATE_IDLE || mPlayerState == PLAYER_STATE_WALK))
			{	
				//mPreDelay = 0.1f;
				mMoveDirection = Point(0,0);
				GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
				outPacket.mMyPlayerInfo = this->GetPlayerInfo();
				mClient->Broadcast(&outPacket);
				mPlayerState = state;
			}
			else 
			{	
				mGameKeyStates.userActiveSkillKey = KEYSTATE_NOTPRESSED;
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
	if(mPreDelay > 0)
		mPreDelay -= dTime;
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
			Point willGoDirection = Point(0,0);
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
			//Check Moving Input, and set Position to d
			if(mGameKeyStates.leftDirectKey == KEYSTATE_PRESSED && mGameKeyStates.rightDirectKey == KEYSTATE_PRESSED)
			{
				printf("ok");
			}	

			if ( mGameKeyStates.leftDirectKey ==  KEYSTATE_PRESSED )willGoDirection = willGoDirection + Point( -1.f, 0.f );
			if ( mGameKeyStates.rightDirectKey == KEYSTATE_PRESSED )willGoDirection = willGoDirection + Point( +1.f, 0.f );
			if ( mGameKeyStates.upDirectKey == KEYSTATE_PRESSED )	willGoDirection = willGoDirection + Point( 0.f, -1.f );
			if ( mGameKeyStates.downDirectKey == KEYSTATE_PRESSED )	willGoDirection = willGoDirection + Point( 0.f, +1.f );

			float d = pow( pow(willGoDirection.x , 2) + pow( willGoDirection.y, 2) , 0.5f);
			if(d != 0.f)
			{
				willGoDirection.x = willGoDirection.x / d;
				willGoDirection.y = willGoDirection.y / d;
			}
			willGoDirection = willGoDirection * (float)mSpeed;

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
			if(  mType == TYPE_ZERO && (GGameMap->GetTileType(GetPosition()) == BARRACK_A
				||GGameMap->GetTileType(GetPosition()) == BARRACK_B
				||GGameMap->GetTileType(GetPosition()) == BARRACK_C
				||GGameMap->GetTileType(GetPosition()) == BARRACK_D)
				&& GGameMap->GetTileType(willGoPosition) == BARRACK_OUT)
			{
				TileType tileType = GGameMap->GetTileType(GetPosition());
				int changeType = 0;
				switch (tileType)
				{
				case BARRACK_A:
					changeType = TYPE_A;
					break;
				case BARRACK_B:
					changeType = TYPE_B;
					break;
				case BARRACK_C:
					changeType = TYPE_C;
					break;
				case BARRACK_D:
					changeType = TYPE_D;
					break;
				default:
					break;
				}
				ChangeType(changeType);
			}
			SetPosition(willGoPosition);


			//이전과 다른 방향으로 이동했니?
			// -10, -10 이거 그냥 bool함수로 빼내서 초기화 다시 해줄것.
			if( mMoveDirection != willGoDirection)
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
			//if(mPreDelay > 0) break;
			switch (mType)
			{
			case TYPE_A:
				{
					mAttackDelay = 1.f;
					new ATypeAttack(mRotation,mPosition,this);
					TransState(PLAYER_STATE_IDLE);
				}break;
			case TYPE_B:
				{
					mAttackDelay = 0.6f;
					new BTypeAttack(mRotation,mPosition,this);
					TransState(PLAYER_STATE_IDLE);
				}break;
			case TYPE_C:
				{	
					mAttackDelay = 0.4f;
					new CTypeAttack(mRotation,mPosition,this);
					TransState(PLAYER_STATE_IDLE);
				}break;
			case TYPE_D:
				{	
					mAttackDelay = 0.7f;
					new DTypeAttack(mRotation,mPosition,this);
					TransState(PLAYER_STATE_IDLE);
				}break;
			default:
				break;
			}
		}
		break;

	case PLAYER_STATE_DIE:
		{
			mResponTime -= dTime;
			if(mResponTime < 0)
			{
				//살려내야합니다.
				int cnt = 0;
				while(1)
				{
					float x, y;
					if ( mTeam == 0 )
					{
						x = GGameMap->GetStartingPointAX() + 32.f;
						y = GGameMap->GetStartingPointAY() + 32.f;
					}
					else
					{
						x = GGameMap->GetStartingPointBX() + 32.f;
						y = GGameMap->GetStartingPointBY() + 32.f;
					}

					if ( cnt != 0 )
					{
						switch ( cnt%4 ) 
						{
						case 0:
							y -= int(cnt/4+1) * 64.f;
							break;
						case 1:
							x += int(cnt/4+1) * 64.f;
							break;
						case 2:
							y += int(cnt/4+1) * 64.f;
							break;
						case 3:
							x -= int(cnt/4+1) * 64.f;
							break;
						default:
							break;
						}
					}

					if(CouldGoPosition(Point(x,y)) == true)
					{
						mPosition = Point(x,y);
						break;
					}

					++cnt;
				}
				mType = 0;
				InitWithType();
				TransState(PLAYER_STATE_IDLE);
				break;
			}
		}
		break;
	case PLAYER_STATE_TYPESKILL:
		{
			//if(mPreDelay > 0) break;
			switch (mType)
			{
			case TYPE_A:
				{
					mTypeSkillDelay = 7.f;
					new ATypeSkill(mRotation,mPosition,this);
					TransState(PLAYER_STATE_IDLE);
				}break;
			case TYPE_B:
				{
					mTypeSkillDelay = 15.f;
					new BTypeSkill(this);
					TransState(PLAYER_STATE_IDLE);
				}break;
			case TYPE_C:
				{	
					mTypeSkillDelay = 3.f;
					new CTypeSkill(mRotation,mPosition,this);
					TransState(PLAYER_STATE_IDLE);
				}break;
			case TYPE_D:
				{
					if(mDSkillPostDelay <= 0)
					{
						mTypeSkillDelay = 3.f;
						TransState(PLAYER_STATE_IDLE);
					}
					mDSkillPostDelay -=dTime;
				}break;
			default:
				break;
			}
			break;
		}
		break;
	case PLAYER_STATE_USERSKILL:
		{
			//if(mPreDelay > 0) break;
			switch (mType)
			{
			case TYPE_A:
				{
					mUserSkillDelay = 5.f;
				}break;
			case TYPE_B:
				{
					mUserSkillDelay = 10.f;
				}break;
			case TYPE_C:
				{
					mUserSkillDelay = 5.f;
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
bool Player::Damaged(int damage, Player* player)
{
	if(mType == TYPE_ZERO) return false;
	//ChangeType(GetTypeChangeResult(mType, enemy->mType));
	if(mPlayerState != PLAYER_STATE_DIE && mHP  <= damage)
	{
		HPUpdateResult outPacket = HPUpdateResult();
		outPacket.mPlayerId = mPlayerId;
		outPacket.mHP = 0;
		mClient->Broadcast(&outPacket);
		//죽었슴다
		GGameManager->DiePlayer(mTeam);
		TransState(PLAYER_STATE_DIE);

		++player->mKillScore;

		PlayerKillScoreUpdateResult outPlayerKillScoreUpdatePacket;
		outPlayerKillScoreUpdatePacket.mPlayerId = player->mPlayerId;
		outPlayerKillScoreUpdatePacket.mKillScore = player->mKillScore;
		printf("asdfdasf %d\n",player->mKillScore);
		mClient->Broadcast(&outPlayerKillScoreUpdatePacket);

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
void Player::Heal(int dHP)
{
	if(mType == TYPE_ZERO) return;
	if(mPlayerState == PLAYER_STATE_DIE) return;

	if(mHP + dHP > mMaxHP)
		mHP = mMaxHP;
	else
		mHP += dHP;

	HPUpdateResult outPacket = HPUpdateResult();
	outPacket.mPlayerId = mPlayerId;
	outPacket.mHP = mHP;
	mClient->Broadcast(&outPacket);
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
	mPlayerInfo.mKillScore = mKillScore;
	return mPlayerInfo;
}

bool Player::CouldGoPosition(Point position)
{
	for( int x = int(position.x - mRadius)/64; x <= int(position.x + mRadius)/64; x += 1 )//64 = tilesize
	{
		for( int y = int(position.y - mRadius)/64; y <= int(position.y + mRadius)/64; y += 1 )//64 = tilesize
		{
			if ( GGameMap->isValidTile(Point(x*64.f,y*64.f)) == false)
				return false;
		}
	}

	if(mType != TYPE_ZERO && (GGameMap->GetTileType(position) == BARRACK_A
		||GGameMap->GetTileType(position) == BARRACK_B
		||GGameMap->GetTileType(position) == BARRACK_C
		||GGameMap->GetTileType(position) == BARRACK_D))
		return false;

	std::map<int,Player*> players = GPlayerManager->GetPlayers();
	for( std::map<int,Player*>::iterator it = players.begin(); it != players.end(); ++it ) 
	{
		Player* enemy = it->second;
		if(enemy == this)continue;

		if( Point().Distance( enemy->GetPosition(), position ) < mRadius*2 )
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
void Player::InitWithType()
{
	switch (mType)
	{
	case TYPE_ZERO:
		{

			mSpeed = 150;
		}
	case TYPE_A:
		{
			mMaxHP = TYPE_A_MAXHP;
			SetHP(mMaxHP);
			mSpeed = 150;
		}break;
	case TYPE_B:
		{
			mMaxHP = TYPE_B_MAXHP;
			SetHP(mMaxHP);
			mSpeed = 150;
		}break;
	case TYPE_C:
		{
			mMaxHP = TYPE_C_MAXHP;
			SetHP(mMaxHP);
			mSpeed = 150;
		}break;
	case TYPE_D:
		{
			mMaxHP = TYPE_D_MAXHP;
			SetHP(mMaxHP);
			mSpeed = 150;
		}break;
	default:
		break;
	}
}