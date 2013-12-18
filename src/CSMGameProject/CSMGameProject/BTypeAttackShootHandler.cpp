#include "PacketHandler.h"
#include <stdio.h>
#include <assert.h>
#include "EffectManager.h"
#include "TypeA.h"

BTypeAttackShootHandler::BTypeAttackShootHandler()
{

}
BTypeAttackShootHandler::~BTypeAttackShootHandler()
{

}
void BTypeAttackShootHandler::HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header )
{
	switch ( packetType )
	{
	case PKT_SC_B_TYPEATTACK_SHOOT:
		{
			if ( circularBuffer->Read((char*)&mBTypeAttackShootResult, header->mSize) )
			{

				//로그인이 잘못되어 캐릭터가 없을 수 있으므로
				EffectManager::GetInstance()->AddEffect( new BTypeAttackEffect(mBTypeAttackShootResult.mAngle,mBTypeAttackShootResult.mStartPosition,mBTypeAttackShootResult.mIndex));
			}
			else
			{
				assert(false) ;
			}
		}
		break;
	}
}
