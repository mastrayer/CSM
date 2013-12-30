#include "PacketHandler.h"
#include <stdio.h>
#include "EffectManager.h"
#include "TypeD.h"

DTypeSkillShootHandler::DTypeSkillShootHandler()
{

}
DTypeSkillShootHandler::~DTypeSkillShootHandler()
{

}
void DTypeSkillShootHandler::HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header)
{
	switch (packetType)
	{
	case PKT_SC_D_TYPESKILL_SHOOT:
		{
			if (circularBuffer->Read((char*)&mDTypeSkillShootResult, header->mSize))
			{
				EffectManager::GetInstance()->AddEffect( new DTypeSkillEffect(mDTypeSkillShootResult.mAngle,mDTypeSkillShootResult.mStartPosition,mDTypeSkillShootResult.mPlayerId));
			}
			else
			{

			}
		}
		break;
	}
}
