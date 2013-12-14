
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
}
