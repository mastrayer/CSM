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

#define PKT_SC_A_TYPEATTACK_SHOOT 13
#define PKT_SC_A_TYPEATTACK_END 14

#define PKT_SC_B_TYPESKILL_SHOOT 15

#define PKT_SC_B_TYPEATTACK_SHOOT 16
#define PKT_SC_B_TYPEATTACK_END 17

#define PKT_SC_C_TYPESKILL_SHOOT 18

#define PKT_SC_C_TYPEATTACK_SHOOT 19
#define PKT_SC_C_TYPEATTACK_END 20

#define PKT_SC_D_TYPESKILL_SHOOT 21
#define PKT_SC_D_TYPESKILL_END 22

#define PKT_SC_D_TYPEATTACK_SHOOT 23

#define PKT_SC_USERSKILL_FLASH 24
#define PKT_SC_USERSKILL_DASH 25

#define PKT_SC_PLAYER_KILLSCORE_UPDATE 26

#define PKT_SC_ITEM_WILLCOME 27
#define PKT_SC_ITEM_COME 28
#define PKT_SC_ITEM_PLAYER_CONSUME 29
#define PKT_SC_ITEM_PLAYER_DROP 30

#define PKT_CS_EMOTICON 31

#define PKT_SC_EMOTICON 32

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
	float Distance(const Point& aPoint, const Point& bPoint) const {
		return (float)pow(pow(aPoint.x-bPoint.x,2) + pow(aPoint.y-bPoint.y,2),0.5);
	}
	Point Rotate(Point point, float angle) const {
		return Point(point.x * cos(angle) - point.y * sin(angle),
			point.x * sin(angle) + point.y * cos(angle));
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
	int mKillScore;
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
	int mGameId;
	int mPlayerId;
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

struct PlayerKillScoreUpdateResult : public PacketHeader
{
	PlayerKillScoreUpdateResult()
	{
		mSize = sizeof(PlayerKillScoreUpdateResult);
		mType = PKT_SC_PLAYER_KILLSCORE_UPDATE;
	}
	int mPlayerId;
	int mKillScore;
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
struct ATypeAttackShootResult : public PacketHeader
{
	ATypeAttackShootResult()
	{
		mSize = sizeof(ATypeAttackShootResult);
		mType = PKT_SC_A_TYPEATTACK_SHOOT;
	}
	Point mStartPosition;
	float mAngle;
	int mIndex;
};
struct ATypeAttackEndResult : public PacketHeader
{
	ATypeAttackEndResult()
	{
		mSize = sizeof(ATypeAttackEndResult);
		mType = PKT_SC_A_TYPEATTACK_END;
	}
	int mIndex;
};
struct BTypeSkillShootResult : public PacketHeader
{
	BTypeSkillShootResult()
	{
		mSize = sizeof(BTypeSkillShootResult);
		mType = PKT_SC_B_TYPESKILL_SHOOT;
	}
	Point mStartPosition;
};
struct BTypeAttackShootResult : public PacketHeader
{
	BTypeAttackShootResult()
	{
		mSize = sizeof(BTypeAttackShootResult);
		mType = PKT_SC_B_TYPEATTACK_SHOOT;
	}
	Point mStartPosition;
	float mAngle;
	int mIndex;
};
struct BTypeAttackEndResult : public PacketHeader
{
	BTypeAttackEndResult()
	{
		mSize = sizeof(BTypeAttackEndResult);
		mType = PKT_SC_B_TYPEATTACK_END;
	}
	int mIndex;
};

struct CTypeAttackShootResult : public PacketHeader
{
	CTypeAttackShootResult()
	{
		mSize = sizeof(CTypeAttackShootResult);
		mType = PKT_SC_C_TYPEATTACK_SHOOT;
	}
	Point mStartPosition;
	float mAngle;
	int mIndex;
};
struct CTypeAttackEndResult : public PacketHeader
{
	CTypeAttackEndResult()
	{
		mSize = sizeof(CTypeAttackEndResult);
		mType = PKT_SC_C_TYPEATTACK_END;
	}
	int mIndex;
};
struct CTypeSkillShootResult : public PacketHeader
{
	CTypeSkillShootResult()
	{
		mSize = sizeof(CTypeSkillShootResult);
		mType = PKT_SC_C_TYPESKILL_SHOOT;
	}
	Point mStartPosition;
	float mAngle;
};

struct DTypeAttackShootResult : public PacketHeader
{
	DTypeAttackShootResult()
	{
		mSize = sizeof(DTypeAttackShootResult);
		mType = PKT_SC_D_TYPEATTACK_SHOOT;
	}
	int mPlayerId;
};
struct DTypeSkillShootResult : public PacketHeader
{
	DTypeSkillShootResult()
	{
		mSize = sizeof(DTypeSkillShootResult);
		mType = PKT_SC_D_TYPESKILL_SHOOT;
	}
	Point mStartPosition;
	float mAngle;
	int mPlayerId;
};
struct DTypeSkillEndResult : public PacketHeader
{
	DTypeSkillEndResult()
	{
		mSize = sizeof(DTypeSkillEndResult);
		mType = PKT_SC_D_TYPESKILL_END;
	}
	int mPlayerId;
};

struct ItemWillComeResult : public PacketHeader
{
	ItemWillComeResult()
	{
		mSize = sizeof(ItemWillComeResult);
		mType = PKT_SC_ITEM_WILLCOME;
	}
	int mItemType;
	int mLeftTime;
};
struct ItemComeResult : public PacketHeader
{
	ItemComeResult()
	{
		mSize = sizeof(ItemComeResult);
		mType = PKT_SC_ITEM_COME;
	}
	int mItemType;
	Point mPosition;
};
struct ItemPlayerConsumeResult : public PacketHeader
{
	ItemPlayerConsumeResult()
	{
		mSize = sizeof(ItemPlayerConsumeResult);
		mType = PKT_SC_ITEM_PLAYER_CONSUME;
	}
	int mItemType;
	int mPlayerId;
};
struct ItemPlayerDropResult : public PacketHeader
{
	ItemPlayerDropResult()
	{
		mSize = sizeof(ItemPlayerDropResult);
		mType = PKT_SC_ITEM_PLAYER_DROP;
	}
	int mItemType;
	int mPlayerId;
};

struct EmoticonRequest : public PacketHeader
{
	EmoticonRequest()
	{
		mSize = sizeof(EmoticonRequest);
		mType = PKT_CS_EMOTICON;
	}
	int mPlayerId;
	int mEmoticonNumber;
};

struct EmoticonResult : public PacketHeader
{
	EmoticonResult()
	{
		mSize = sizeof(EmoticonResult);
		mType = PKT_SC_EMOTICON;
	}
	int mPlayerId;
	int mEmoticonNumber;
};
struct UserSkillFlashResult : public PacketHeader
{
	UserSkillFlashResult()
	{
		mSize = sizeof(UserSkillFlashResult);
		mType = PKT_SC_USERSKILL_FLASH;
	}
	Point mBeforePosition;
	Point mAfterPosition;
};
#pragma pack(pop)