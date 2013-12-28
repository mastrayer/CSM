#include "PacketHandler.h"
#include <stdio.h>
#include <assert.h>
#include "EffectManager.h"
#include "TypeD.h"

DTypeSkillEndHandler::DTypeSkillEndHandler()
{

}
DTypeSkillEndHandler::~DTypeSkillEndHandler()
{

}
void DTypeSkillEndHandler::HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header)
{
	switch (packetType)
	{
	case PKT_SC_D_TYPESKILL_END:
		{
			if (circularBuffer->Read((char*)&mDTypeSkillEndResult, header->mSize))
			{
				EffectManager::GetInstance()->GetDTypeSkillEffect(mDTypeSkillEndResult.mIndex)->Crash();
			}
			else
			{

			}
		}
		break;
	}
}
