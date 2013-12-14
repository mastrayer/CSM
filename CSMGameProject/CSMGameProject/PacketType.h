
#pragma once

#include "NNPacketHeader.h"
#include "NNPoint.h"
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
#define PKT_SC_B_TYPESKILL_SHOOT 13
#define PKT_SC_C_TYPESKILL_SHOOT 14
#define PKT_SC_USERSKILL_FLASH 15
#define PKT_SC_USERSKILL_DASH 16

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
	NNPoint mMoveVelocity;
	int mTeam;
	int mType;
};
#pragma pack(push,1)

struct LoginRequest : public NNPacketHeader
{
	LoginRequest()
	{
		mSize = sizeof(LoginRequest);
		mType = PKT_CS_LOGIN;
	}
};
struct LoginResult : public NNPacketHeader
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
struct LoginBroadcastResult : public NNPacketHeader
{
	LoginBroadcastResult()
	{
		mSize = sizeof(LoginBroadcastResult);
		mType = PKT_SC_LOGIN_BROADCAST;
	}
	PlayerInfo mMyPlayerInfo;
};
struct GameKeyStatesUpdateRequest : public NNPacketHeader
{
	GameKeyStatesUpdateRequest()
	{
		mSize = sizeof(GameKeyStatesUpdateRequest) ;
		mType = PKT_CS_KEYSTATE ;
		mMyPlayerInfo.mPlayerId = -1 ;
	}

	PlayerInfo mMyPlayerInfo;
} ;

struct GameKeyStatesUpdateResult : public NNPacketHeader
{
	GameKeyStatesUpdateResult()
	{
		mSize = sizeof(GameKeyStatesUpdateResult) ;
		mType = PKT_SC_KEYSTATE ;
		mMyPlayerInfo.mPlayerId = -1 ;
	}
	PlayerInfo mMyPlayerInfo;
} ;

struct LogoutResult : public NNPacketHeader
{
	LogoutResult()
	{
		mSize = sizeof(LogoutResult);
		mType = PKT_SC_LOGOUT;
	}
	int mPlayerId;
};

struct MouseAngleUpdateRequest : public NNPacketHeader
{
	MouseAngleUpdateRequest()
	{
		mSize = sizeof(MouseAngleUpdateRequest);
		mType = PKT_CS_MOUSEANGLE;
	}
	int mPlayerId;
	float mAngle;
};

struct MouseAngleUpdateResult : public NNPacketHeader
{
	MouseAngleUpdateResult()
	{
		mSize = sizeof(MouseAngleUpdateResult);
		mType = PKT_SC_MOUSEANGLE;
	}
	int mPlayerId;
	float mAngle;
};
struct HPUpdateResult : public NNPacketHeader
{
	HPUpdateResult()
	{
		mSize = sizeof(HPUpdateResult);
		mType = PKT_SC_HP;
	}
	int mPlayerId;
	int mHP;
};
struct KillScoreResult : public NNPacketHeader
{
	KillScoreResult()
	{
		mSize = sizeof(KillScoreResult);
		mType = PKT_SC_KILLSCORE;
	}
	int mKillScore[2];
	int mKillLimit;
};

struct EndOfGameResult : public NNPacketHeader
{
	EndOfGameResult()
	{
		mSize = sizeof(EndOfGameResult);
		mType = PKT_SC_ENDOFGAME;
	}
	int mWinnerTeam;
};
struct ATypeSkillShootResult : public NNPacketHeader
{
	ATypeSkillShootResult()
	{
		mSize = sizeof(ATypeSkillShootResult);
		mType = PKT_SC_A_TYPESKILL_SHOOT;
	}
	NNPoint mStartPosition;
	float mAngle;
};
struct BTypeSkillShootResult : public NNPacketHeader
{
	BTypeSkillShootResult()
	{
		mSize = sizeof(BTypeSkillShootResult);
		mType = PKT_SC_B_TYPESKILL_SHOOT;
	}
	NNPoint mStartPosition;
	NNPoint mTargetPosition;
};
struct CTypeSkillShootResult : public NNPacketHeader
{
	CTypeSkillShootResult()
	{
		mSize = sizeof(CTypeSkillShootResult);
		mType = PKT_SC_C_TYPESKILL_SHOOT;
	}
	NNPoint mStartPosition;
	float mAngle;
};
#pragma pack(pop)