#include "PacketHandler.h"
#include <stdio.h>
#include <assert.h>
#include "EffectManager.h"
#include "TypeA.h"

ATypeAttackShootHandler::ATypeAttackShootHandler()
{

}
ATypeAttackShootHandler::~ATypeAttackShootHandler()
{

}
void ATypeAttackShootHandler::HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header )
{
	switch ( packetType )
	{
	case PKT_SC_A_TYPEATTACK_SHOOT:
		{
			if ( circularBuffer->Read((char*)&mATypeAttackShootResult, header->mSize) )
			{

				//로그인이 잘못되어 캐릭터가 없을 수 있으므로
				EffectManager::GetInstance()->AddEffect( new ATypeAttackEffect(mATypeAttackShootResult.mAngle,mATypeAttackShootResult.mStartPosition,mATypeAttackShootResult.mIndex));
			}
			else
			{

			}
		}
		break;
	}
}
