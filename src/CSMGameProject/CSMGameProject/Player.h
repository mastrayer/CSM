
#pragma once

#include "NNObject.h"
#include "NNSprite.h"
#include "NNLabel.h"
#include "NNAnimation.h"
#include "PacketType.h"
#include "NNParticleSystem.h"

#include "PlayerUI.h"
#include "config.h"

enum ITEMTYPE
{
	DAMAGEBUFF = 0,
	HPBUFF = 1,
	FLAG = 2,
};
class CPlayer : public NNObject
{
public:
	CPlayer(void);
	virtual ~CPlayer(void);
	void Init();
	void InitWithType();
	void TransState( PlayerState state );
	
	void SetPlayerPosition( NNPoint position ) { SetPosition(position); }
	void SetPlayerRotation( float angle ) { SetRotation(angle); /*mAngle = angle; mMove->SetRotation(angle); mStop->SetRotation(angle);*/ }
	void SetPlayerMoveDirection( NNPoint direction) { mMoveVelocity = direction; }
	void SetPlayerHP(int hp) { mHp = hp; }	void SetPlayerTeam(int team) { mTeam = team; }
	void SetPlayerType( PlayerType type ) { mPlayerType = type; InitWithType(); }
	void SetKillScore( int killScore ) { mKillScore = killScore; }
	void SetNickname(char value[20]) 
	{
		strcpy(mNickname, value);  
		mPlayerUI->SetNickname(value);

		//const char *temp = playerList[iter.first]->GetNickname();
		int nLen = strlen(value) + 1;

		//wchar_t* pwstr = (LPWSTR)malloc(sizeof(wchar_t)* nLen);
		//mbstowcs(pwstr, value, nLen);
		mbstowcs(mNicknameW, value, nLen);
	}

	NNPoint GetPlayerPosition() { return GetPosition(); }
	float GetPlayerRotation( ) { return mRotation; }
	int GetPlayerHP() { return mHp; }
	PlayerType GetPlayerType() { return mPlayerType; }
	int GetTeam() { return mTeam; }
	int GetKillScore() const { return mKillScore; }
	char *GetNickname() { return mNickname; }
	wchar_t *GetNicknameW() { return mNicknameW;  }
	
	bool IsEmoticonRunning() { return mIsEmoticonRunning; }
	void SetEmoticonRunning(bool value) { mIsEmoticonRunning = value; }

	bool HasItem(ITEMTYPE itemType){ return mHasItem[itemType]; }

	void ConsumeItem(ITEMTYPE itemType);

	NNCREATE_FUNC(CPlayer);

private:
	void Render();
	void Update( float dTime );

	void InitStopImage();
	void InitMoveImage();
	void InitAttackImage();
	void INitDieImage();

private:
	NNSprite* mDie;
	NNAnimation* mMoveNormal;
	NNAnimation* mMoveFire;
	NNAnimation* mMoveWind;
	NNAnimation* mMoveWater;
	NNAnimation* mMoveEarth;

	NNAnimation* mStopNormal;
	NNAnimation* mStopFire;
	NNAnimation* mStopWind;
	NNAnimation* mStopWater;
	NNAnimation* mStopEarth;

	NNAnimation* mAttackNormal;
	NNAnimation* mAttackFire;
	NNAnimation* mAttackWind;
	NNAnimation* mAttackWater;
	NNAnimation* mAttackEarth;

	NNAnimation* mDieNormal;
	NNAnimation* mDieFire;
	NNAnimation* mDieWind;
	NNAnimation* mDieWater;
	NNAnimation* mDieEarth;

private:
	std::list<NNParticleSystem*> mParticleSystemList;
	PlayerUI* mPlayerUI;
	PlayerState mPlayerState;
	
	NNParticleSystem *mUserEffect;
	NNPoint mMoveVelocity;
	NNLabel *mRebirthTimer;
	
	//std::string mNickname;
	char mNickname[20];
	wchar_t mNicknameW[12];

	float mRebirthDelayTime;
	int mHp;
	int mTeam;
	int mSpeed;
	
	int mKillScore;

	bool mIsEmoticonRunning;
	PlayerType mPlayerType;

	bool mHasItem[3];

	friend class PlayerManager;
};