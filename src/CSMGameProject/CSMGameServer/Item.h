#pragma once
#include "PacketType.h"

#define DAMAGEBUFF 0
#define HPBUFF 1
#define FLAG 2

class Item
{
public:
	Item(int id, Point position);
	Item();
	virtual ~Item(void);

	int GetItemType(){ return mItemType; }

	void SetItemId(int id){ mItemId = id; }
	int GetItemId() { return mItemId; }

	void SetOwnerId(int id){ mOwnerId = id; }
	int GetOwnerId(int id){ return mOwnerId; }

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
	int mOwnerId;

	float mLifeTime; // must init this.
	bool mIsPermanent; // and this too

	bool mIsConsumed;
	Point mPosition;

	float mRadius;
};
