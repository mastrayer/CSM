#include "PacketHandler.h"
#include <stdio.h>
#include <assert.h>
#include "EffectManager.h"
#include "TypeB.h"

BTypeAttackEndHandler::BTypeAttackEndHandler()
{

}
BTypeAttackEndHandler::~BTypeAttackEndHandler()
{

}
void BTypeAttackEndHandler::HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header)
{
	switch (packetType)
	{
	case PKT_SC_B_TYPEATTACK_END:
		{
			if (circularBuffer->Read((char*)&mBTypeAttackEndResult, header->mSize))
			{
				EffectManager::GetInstance()->GetBTypeAttackEffect(mBTypeAttackEndResult.mIndex)->Explose();
			}
			else
			{
			}
		}
		break;
	}
}
