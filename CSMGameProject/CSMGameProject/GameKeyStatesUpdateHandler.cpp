
#include "PacketHandler.h"
#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include "PlayerManager.h"

//여기 왜 에러뜨나요?//
GameKeyStatesUpdateHandler::GameKeyStatesUpdateHandler()
{

}
GameKeyStatesUpdateHandler::~GameKeyStatesUpdateHandler()
{

}
void GameKeyStatesUpdateHandler::HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header )
{
	switch ( packetType )
	{
	case PKT_SC_KEYSTATE:
		{
			if ( circularBuffer->Read((char*)&m_GameKeyStatesUpdateResult, header->m_Size) )
			{
				// 패킷처리
				if ( m_GameKeyStatesUpdateResult.m_MyPlayerInfo.m_PlayerId == -1  )
				{
					/// 잘못된 데이터
					/// 무시한다
					return;
				}
				//로그인이 잘못되어 캐릭터가 없을 수 있으므로
				CPlayerManager::GetInstance()->NewPlayer( m_GameKeyStatesUpdateResult.m_MyPlayerInfo.m_PlayerId );
				
				CPlayerManager::GetInstance()->UpdatePlayerInfo( m_GameKeyStatesUpdateResult.m_MyPlayerInfo );
				printf("Key State Changed[%d] Pos : %4d, %4d \n", m_GameKeyStatesUpdateResult.m_MyPlayerInfo.m_PlayerId,
					m_GameKeyStatesUpdateResult.m_MyPlayerInfo.m_X, m_GameKeyStatesUpdateResult.m_MyPlayerInfo.m_Y) ;
			}
			else
			{
				assert(false) ;
			}
		}
		break;
	}
}
