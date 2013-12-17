#include "PacketHandler.h"
#include <stdio.h>
#include <assert.h>
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
				//로그인이 잘못되어 캐릭터가 없을 수 있으므로
				EffectManager::GetInstance()->GetATypeAttackEffect(mATypeAttackEndResult.mIndex)->Explose();
			}
			else
			{
				assert(false);
			}
		}
		break;
	}
}
