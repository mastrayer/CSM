#include "PacketHandler.h"
#include <stdio.h>
#include "EffectManager.h"
#include "TypeB.h"

ATypeAttackEndHandler::ATypeAttackEndHandler()
{

}
ATypeAttackEndHandler::~ATypeAttackEndHandler()
{

}
void ATypeAttackEndHandler::HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header)
{
	switch (packetType)
	{
	case PKT_SC_A_TYPEATTACK_END:
		{
			if (circularBuffer->Read((char*)&mATypeAttackEndResult, header->mSize))
			{
				EffectManager::GetInstance()->GetATypeAttackEffect(mATypeAttackEndResult.mIndex)->Explose();
			}
			else
			{

			}
		}
		break;
	}
}
