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
				EffectManager::GetInstance()->AddEffect(new BTypeSkillEffect(mBTypeSkillShootResult.mStartPosition));
			}
			else
			{

			}
		}
		break;
	}
}
