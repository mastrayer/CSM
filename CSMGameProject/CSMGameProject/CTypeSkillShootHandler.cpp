#include "PacketHandler.h"
#include <stdio.h>
#include <assert.h>
#include "EffectManager.h"
#include "TypeC.h"

CTypeSkillShootHandler::CTypeSkillShootHandler()
{

}
CTypeSkillShootHandler::~CTypeSkillShootHandler()
{

}
void CTypeSkillShootHandler::HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header)
{
	switch (packetType)
	{
	case PKT_SC_C_TYPESKILL_SHOOT:
		{
			if (circularBuffer->Read((char*)&mCTypeSkillShootResult, header->mSize))
			{

				//로그인이 잘못되어 캐릭터가 없을 수 있으므로
				EffectManager::GetInstance()->AddEffect(new CTypeSkillEffect(mCTypeSkillShootResult.mStartPosition, mCTypeSkillShootResult.mAngle));
			}
			else
			{
				assert(false);
			}
		}
		break;
	}
}
