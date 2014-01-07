#include "PacketHandler.h"
#include <stdio.h>
#include "EffectManager.h"
#include "UserSkillEffect.h"

UserSkillFlashHandler::UserSkillFlashHandler()
{

}
UserSkillFlashHandler::~UserSkillFlashHandler()
{

}
void UserSkillFlashHandler::HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header)
{
	switch (packetType)
	{
	case PKT_SC_USERSKILL_FLASH:
		{
			if (circularBuffer->Read((char*)&mUserSkillFlashResult, header->mSize))
			{
				
				EffectManager::GetInstance()->AddEffect( new USER_SKILL_EFFECT::Flash(mUserSkillFlashResult.mBeforePosition, mUserSkillFlashResult.mAfterPosition) );
			}
		}
		break;
	}
}
