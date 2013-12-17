
#include <stdio.h>
#include <assert.h>

#include "PacketHandler.h"
#include "PlayerManager.h"
#include "GameManager.h"

LoginHandler::LoginHandler()
{

}
LoginHandler::~LoginHandler()
{

}
void LoginHandler::HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header )
{
	switch ( packetType )
	{
	case PKT_SC_LOGIN:
		{
			if ( circularBuffer->Read((char*)&mLoginResultPacket, header->mSize) )
			{
				// 패킷처리
				if ( mLoginResultPacket.mMyPlayerInfo.mPlayerId == -1  )
				{
					/// 여기 걸리면 로그인 실패다.
					PostQuitMessage(-1) ;
				}
				CPlayerManager::GetInstance()->SetMyPlayerId( mLoginResultPacket.mMyPlayerInfo.mPlayerId );
				CPlayerManager::GetInstance()->UpdatePlayerInfo(mLoginResultPacket.mMyPlayerInfo);
				//먼저 들어와있던 플레이어의 객체 만들기
				for(int i=0; i<mLoginResultPacket.mNowPlayersLength; i++)
				{
					if( mLoginResultPacket.mMyPlayerInfo.mPlayerId != mLoginResultPacket.mPlayerInfo[i].mPlayerId )
					{
						CPlayerManager::GetInstance()->NewPlayer( mLoginResultPacket.mPlayerInfo[i].mPlayerId );
						CPlayerManager::GetInstance()->UpdatePlayerInfo( mLoginResultPacket.mPlayerInfo[i] );
					}
				}
				//CPlayerManager::GetInstance()->SetKillLimit(mLoginResultPacket.mKillLimit);
				//CPlayerManager::GetInstance()->SetKillScore(mLoginResultPacket.mKillScore);
				GameManager::GetInstance()->SetKillLimit( mLoginResultPacket.mKillLimit );
				GameManager::GetInstance()->SetKillScore( mLoginResultPacket.mKillScore );

				printf("LOGIN SUCCESS ClientId[%d] \n", mLoginResultPacket.mMyPlayerInfo.mPlayerId) ;
			}
			else
			{
				assert(false) ;
			}
		}
		break;
	}
}
