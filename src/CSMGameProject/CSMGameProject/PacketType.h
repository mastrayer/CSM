
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

#define PKT_CS_EMOTICON 27
#define PKT_SC_EMOTICON 28

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
	int mKillScore;
	wchar_t mName[256];
};
#pragma pack(push,1)

struct LoginRequest : public NNPacketHeader
{
	LoginRequest()
	{
		mSize = sizeof(LoginRequest);
		mType = PKT_CS_LOGIN;
	}
	int mGameId;
	int mPlayerId;
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
struct PlayerKillScoreUpdateResult : public NNPacketHeader
{
        PlayerKillScoreUpdateResult()
        {
                mSize = sizeof(PlayerKillScoreUpdateResult);
                mType = PKT_SC_PLAYER_KILLSCORE_UPDATE;
        }
        int mPlayerId;
        int mKillScore;
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
struct ATypeAttackShootResult : public NNPacketHeader
{
	ATypeAttackShootResult()
	{
		mSize = sizeof(ATypeAttackShootResult);
		mType = PKT_SC_A_TYPEATTACK_SHOOT;
	}
	NNPoint mStartPosition;
	float mAngle;
	int mIndex;
};
struct ATypeAttackEndResult : public NNPacketHeader
{
	ATypeAttackEndResult()
	{
		mSize = sizeof(ATypeAttackEndResult);
		mType = PKT_SC_A_TYPEATTACK_END;
	}
	int mIndex;
};
struct BTypeSkillShootResult : public NNPacketHeader
{
	BTypeSkillShootResult()
	{
		mSize = sizeof(BTypeSkillShootResult);
		mType = PKT_SC_B_TYPESKILL_SHOOT;
	}
	NNPoint mStartPosition;
};
struct BTypeAttackShootResult : public NNPacketHeader
{
	BTypeAttackShootResult()
	{
		mSize = sizeof(BTypeAttackShootResult);
		mType = PKT_SC_B_TYPEATTACK_SHOOT;
	}
	NNPoint mStartPosition;
	float mAngle;
	int mIndex;
};
struct BTypeAttackEndResult : public NNPacketHeader
{
	BTypeAttackEndResult()
	{
		mSize = sizeof(BTypeAttackEndResult);
		mType = PKT_SC_B_TYPEATTACK_END;
	}
	int mIndex;
};


struct CTypeAttackShootResult : public NNPacketHeader
{
	CTypeAttackShootResult()
	{
		mSize = sizeof(CTypeAttackShootResult);
		mType = PKT_SC_C_TYPEATTACK_SHOOT;
	}
	NNPoint mStartPosition;
	float mAngle;
	int mIndex;
};
struct CTypeAttackEndResult : public NNPacketHeader
{
	CTypeAttackEndResult()
	{
		mSize = sizeof(CTypeAttackEndResult);
		mType = PKT_SC_C_TYPEATTACK_END;
	}
	int mIndex;
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

struct DTypeAttackShootResult : public NNPacketHeader
{
	DTypeAttackShootResult()
	{
		mSize = sizeof(DTypeAttackShootResult);
		mType = PKT_SC_D_TYPEATTACK_SHOOT;
	}
	int mPlayerId;
};
struct DTypeSkillShootResult : public NNPacketHeader
{
	DTypeSkillShootResult()
	{
		mSize = sizeof(DTypeSkillShootResult);
		mType = PKT_SC_D_TYPESKILL_SHOOT;
	}
	NNPoint mStartPosition;
	float mAngle;
	int mPlayerId;
};
struct DTypeSkillEndResult : public NNPacketHeader
{
	DTypeSkillEndResult()
	{
		mSize = sizeof(DTypeSkillEndResult);
		mType = PKT_SC_D_TYPESKILL_END;
	}
	int mIndex;
};
struct EmoticonRequest : public NNPacketHeader
{
	EmoticonRequest()
	{
		mSize = sizeof(EmoticonRequest);
		mType = PKT_CS_EMOTICON;
	}
	int mPlayerId;
	int mEmoticonNumber;
};

struct EmoticonResult : public NNPacketHeader
{
	EmoticonResult()
	{
		mSize = sizeof(EmoticonResult);
		mType = PKT_SC_EMOTICON;
	}
	int mPlayerId;
	int mEmoticonNumber;
};
struct UserSkillFlashResult : public NNPacketHeader
{
	UserSkillFlashResult()
	{
		mSize = sizeof(UserSkillFlashResult);
		mType = PKT_SC_USERSKILL_FLASH;
	}
	NNPoint mBeforePosition;
	NNPoint mAfterPosition;
};
#pragma pack(pop)