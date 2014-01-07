#pragma once
#include "PacketType.h"

#define DAMAGEBUFF 0
#define HPBUFF 1
#define FLAG 2

class Item
{
public:
	Item(int itemType, int itemId,int gameId, Point position);
	Item();
	virtual ~Item(void);

	int GetItemType(){ return mItemType; }

	int GetItemId() { return mItemId; }
	int GetGameId() { return mGameId; }

	void SetOwnerId(int playerId){ mOwnerId = playerId; }
	int GetOwnerId(){ return mOwnerId; }

	Point GetPosition(){ return mPosition; }
	float GetRadius(){ return mRadius; }

	virtual void Update(float dTime) { if(mIsPermanent == false) mLifeTime -= dTime; }
	virtual bool IsLive() { if(mIsPermanent == true || mLifeTime >= 0) return true; else return false; }
	virtual bool IsConsumed(){ return mIsConsumed; }
	
	virtual void ConsumeBy(int playerId);
	virtual void RemoveEffect();

public:
	int mItemType;

	int mItemId;
	int mGameId;
	int mOwnerId;

	float mLifeTime; // must init this.
	bool mIsPermanent; // and this too

	bool mIsConsumed;
	Point mPosition;

	float mRadius;
};
