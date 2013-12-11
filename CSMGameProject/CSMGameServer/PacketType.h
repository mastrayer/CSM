#pragma once
#include <time.h>

#define MAX_CHAT_LEN	1024

#define MAX_NAME_LEN	30
#define MAX_COMMENT_LEN	40

#define MAX_PLAYER_LEN 20


#define KEYSTATE_NOTPRESSED 0
#define KEYSTATE_PRESSED 1


#define PKT_NONE 0
#define PKT_CS_LOGIN 1
#define PKT_SC_LOGIN 2
#define PKT_SC_LOGIN_BROADCAST 3
#define PKT_CS_KEYSTATE 4
#define PKT_SC_KEYSTATE 5
#define PKT_SC_LOGOUT 6
#define PKT_CS_MOUSEANGLE 7
#define PKT_SC_MOUSEANGLE 8
#define PKT_SC_HP 9
#define PKT_SC_KILLSCORE 10
#define PKT_SC_ENDOFGAME 11
#define PKT_SC_A_TYPESKILL_SHOOT 12
struct Point
{
	Point()
	{

	}
	Point(float _x, float _y)
	{
		x = _x , y = _y;
	}
	Point operator+( const Point& point ) const{
		return Point(x+point.x,y+point.y);
	}
	Point operator-( const Point& point ) const{
		return Point(x+point.x,y+point.y);
	}
	Point operator*( float n ) const{
		return Point(x*n,y*n);
	}
	bool operator!=( const Point& point ) const{
		if( x == point.x && y == point.y)
			return false;
		return true;
	}
	bool operator==( const Point& point ) const{
		if( x == point.x && y == point.y)
			return true;
		return false;
	}
	float GetDistance(const Point& aPoint, const Point& bPoint) const{
		return (float)pow(pow(aPoint.x-bPoint.x,2) + pow(aPoint.y-bPoint.y,2),0.5);
	}
	float x,y;
};
struct GameKeyStates
{
	GameKeyStates()
	{
		upDirectKey = KEYSTATE_NOTPRESSED;
		downDirectKey = KEYSTATE_NOTPRESSED;
		leftDirectKey = KEYSTATE_NOTPRESSED;
		rightDirectKey = KEYSTATE_NOTPRESSED;
		attackKey = KEYSTATE_NOTPRESSED;
		userActiveSkillKey = KEYSTATE_NOTPRESSED;
		typeActiveSkillKey = KEYSTATE_NOTPRESSED;
	}
	short upDirectKey;
	short downDirectKey;
	short leftDirectKey;
	short rightDirectKey;
	short attackKey;
	short userActiveSkillKey;
	short typeActiveSkillKey;
};

struct PlayerInfo
{
	float mX, mY, mAngle;
	int mPlayerId;
	GameKeyStates mGameKeyStates;
	short mPlayerState;
	int mHP;
	Point mMoveDirection;
	int mTeam;
	int mType;
};
#pragma pack(push, 1)

struct PacketHeader
{
	PacketHeader() : mSize(0), mType(PKT_NONE) 	{}
	short mSize ;
	short mType ;
} ;

struct LoginRequest : public PacketHeader
{
	LoginRequest()
	{
		mSize = sizeof(LoginRequest);
		mType = PKT_CS_LOGIN;
	}
};
struct LoginResult : public PacketHeader
{
	LoginResult()
	{
		mSize = sizeof(LoginResult);
		mType = PKT_SC_LOGIN;
	}
	PlayerInfo mMyPlayerInfo;
	int mNowPlayersLength;
	PlayerInfo mPlayerInfo[MAX_PLAYER_LEN];
	int mKillScore[2];
	int mKillLimit;
};
struct LoginBroadcastResult : public PacketHeader
{
	LoginBroadcastResult()
	{
		mSize = sizeof(LoginBroadcastResult);
		mType = PKT_SC_LOGIN_BROADCAST;
	}
	PlayerInfo mMyPlayerInfo;
};
struct GameKeyStatesUpdateRequest : public PacketHeader
{
	GameKeyStatesUpdateRequest()
	{
		mSize = sizeof(GameKeyStatesUpdateRequest) ;
		mType = PKT_CS_KEYSTATE ;
		mMyPlayerInfo.mPlayerId = -1 ;
	}

	PlayerInfo mMyPlayerInfo;
} ;

struct GameKeyStatesUpdateResult : public PacketHeader
{
	GameKeyStatesUpdateResult()
	{
		mSize = sizeof(GameKeyStatesUpdateResult) ;
		mType = PKT_SC_KEYSTATE ;
		mMyPlayerInfo.mPlayerId = -1 ;
	}
	PlayerInfo mMyPlayerInfo;
} ;
struct LogoutResult : public PacketHeader
{
	LogoutResult()
	{
		mSize = sizeof(LogoutResult);
		mType = PKT_SC_LOGOUT;
	}
	int mPlayerId;
};

struct MouseAngleUpdateRequest : public PacketHeader
{
	MouseAngleUpdateRequest()
	{
		mSize = sizeof(MouseAngleUpdateRequest);
		mType = PKT_CS_MOUSEANGLE;
	}
	int mPlayerId;
	float mAngle;
};

struct MouseAngleUpdateResult : public PacketHeader
{
	MouseAngleUpdateResult()
	{
		mSize = sizeof(MouseAngleUpdateResult);
		mType = PKT_SC_MOUSEANGLE;
	}
	int mPlayerId;
	float mAngle;
};

struct HPUpdateResult : public PacketHeader
{
	HPUpdateResult()
	{
		mSize = sizeof(HPUpdateResult);
		mType = PKT_SC_HP;
	}
	int mPlayerId;
	int mHP;
};

struct KillScoreResult : public PacketHeader
{
	KillScoreResult()
	{
		mSize = sizeof(KillScoreResult);
		mType = PKT_SC_KILLSCORE;
	}
	int mKillScore[2];
	int mKillLimit;
};

struct EndOfGameResult : public PacketHeader
{
	EndOfGameResult()
	{
		mSize = sizeof(EndOfGameResult);
		mType = PKT_SC_ENDOFGAME;
	}
	int mWinnerTeam;
};
struct ATypeSkillShootResult : public PacketHeader
{
	ATypeSkillShootResult()
	{
		mSize = sizeof(ATypeSkillShootResult);
		mType = PKT_SC_A_TYPESKILL_SHOOT;
	}
	Point mStartPosition;
	float mAngle;
};
#pragma pack(pop)