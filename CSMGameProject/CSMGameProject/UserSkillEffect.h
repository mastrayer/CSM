
#pragma once

#include "Effect.h"
#include "NNAnimation.h"
#include "Player.h"

namespace USER_SKILL
{
	class Flash : public IEffect
	{
	public:
		Flash(CPlayer* follower);
		virtual ~Flash();

		void Render();
		void Update(float dTime);

	private:
		NNAnimation *mSrcAnimation;
		NNAnimation *mDstAnimation;
		bool mDstAnimationStart;
		float mDirection;
		float mDistance;
		NNPoint mDstPoint;
		CPlayer* mFollower;
	};

	class Dash : public IEffect
	{
	public:
		Dash(CPlayer* follower);
		virtual ~Dash();

		void Render();
		void Update(float dTime);

	private:
		float mDirection;
		float mDistance;
		NNPoint mDstPoint;
		CPlayer* mFollower;
	};

	class Heal : public IEffect
	{
	public :
		Heal(CPlayer *follower);
		virtual ~Heal();

		void Render();
		void Update(float dTime);

	private:
		NNAnimation *mAnimation;
		CPlayer* mFollower;
	};

	class Immolation : public IEffect
	{
	public:
		Immolation(CPlayer* follower);
		virtual ~Immolation();

		void Render();
		void Update(float dTime);

	private:
		NNParticleSystem *mPaticleEffect;
		CPlayer* mFollower;
	};
}
