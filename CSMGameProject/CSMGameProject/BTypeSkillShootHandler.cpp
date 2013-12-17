#include "PacketHandler.h"
#include <stdio.h>
#include <assert.h>
#include "EffectManager.h"
#include "TypeB.h"

BTypeSkillShootHandler::BTypeSkillShootHandler()
{

}
BTypeSkillShootHandler::~BTypeSkillShootHandler()
{

}
void BTypeSkillShootHandler::HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header)
{
	switch (packetType)
	{
	case PKT_SC_B_TYPESKILL_SHOOT:
		{
			if (circularBuffer->Read((char*)&mBTypeSkillShootResult, header->mSize))
			{

				//로그인이 잘못되어 캐릭터가 없을 수 있으므로
				EffectManager::GetInstance()->AddEffect(new BTypeSkillEffect(mBTypeSkillShootResult.mStartPosition, mBTypeSkillShootResult.mTargetPosition,mBTypeSkillShootResult.mIndex));
			}
			else
			{
				assert(false);
			}
		}
		break;
	}
}
