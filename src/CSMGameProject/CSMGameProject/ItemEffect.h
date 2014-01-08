
#pragma once

#include "Effect.h"
#include "NNAnimation.h"
#include "Player.h"

namespace ITEM_EFFECT
{
	class Item : public IEffect
	{
	public:
		Item(NNPoint startPosition, int itemId);
		virtual ~Item();

		virtual void Render() = 0;
		virtual void Update(float dTime) = 0;

		virtual void Follow(int playerId);
		virtual void Remove();
		virtual void BackToStartPosition();
		void SetLifeTime(float time){ mLifeTime = time; }
		int GetId(){ return mItemId; }
	protected:
		NNPoint mStartPosition;
		CPlayer* mOwner;
		int mItemId;
	};
	class DamageBuff : public Item
	{
	public:
		DamageBuff(NNPoint startPosition, int itemId, float lifeTime);
		 ~DamageBuff();

		 void Render();
		void Update(float dTime);
		void Follow(int playerId);

	private:
		NNAnimation *mBeforeConsumeAnimation;
		NNAnimation *mAfterConsumeAnimation;
	};

	class HPBuff : public Item
	{
	public :
		HPBuff(NNPoint startPosition, int itemId, float lifeTime);
		 ~HPBuff();

		 void Render();
		 void Update(float dTime);
		 void Follow(int playerId);

	private:
		NNAnimation *mBeforeConsumeAnimation;
		NNAnimation *mAfterConsumeAnimation;
	};

	class Flag : public Item
	{
	public:
		Flag(NNPoint startPosition, int itemId);
		virtual ~Flag();

		virtual void Render();
		virtual void Update(float dTime);

	private:
		NNAnimation *mAnimation;
	};
}
