#include "PacketHandler.h"
#include <stdio.h>
#include "EffectManager.h"
#include "TypeC.h"

CTypeAttackEndHandler::CTypeAttackEndHandler()
{

}
CTypeAttackEndHandler::~CTypeAttackEndHandler()
{

}
void CTypeAttackEndHandler::HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header)
{
	switch (packetType)
	{
	case PKT_SC_C_TYPEATTACK_END:
		{
			if (circularBuffer->Read((char*)&mCTypeAttackEndResult, header->mSize))
			{
				EffectManager::GetInstance()->GetCTypeAttackEffect(mCTypeAttackEndResult.mIndex)->Explose();
			}
			else
			{

			}
		}
		break;
	}
}
