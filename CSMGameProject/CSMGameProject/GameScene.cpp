#include "GameScene.h"
#include "NNApplication.h"
#include "PacketType.h"
#include "NNNetworkSystem.h"
#include "PacketHandler.h"

CGameScene::CGameScene(void):m_NowGameKeyStates()
{
	m_LoginHandler = new LoginHandler();
	m_LoginBroadcastHandler = new LoginBroadcastHandler();
	m_GameKeyStatesUpdateHandler = new GameKeyStatesUpdateHandler();
	m_GameMap = CGameMap::Create();
	AddChild(m_GameMap);

	m_FPSLbael = NNLabel::Create( L"Normal Label", L"¸¼Àº °íµñ", 35.f );
	AddChild(m_FPSLbael);

	NNNetworkSystem::GetInstance()->Init();

	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_KEYSTATE,m_GameKeyStatesUpdateHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_LOGIN,m_LoginHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_LOGIN_BROADCAST,m_LoginBroadcastHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_LOGOUT,m_LogoutHandler);


	NNNetworkSystem::GetInstance()->Connect("10.73.44.30",9001);

	NNNetworkSystem::GetInstance()->Write( (const char*)&m_LoginHandler->m_LoginRequestPacket, m_LoginHandler->m_LoginRequestPacket.m_Size );

	GetCamera().SetCameraAnchor(CameraAnchor::MIDDLE_CENTER);

}


CGameScene::~CGameScene(void)
{
}

void CGameScene::Render()
{
	NNScene::Render();
}
void CGameScene::Update( float dTime )
{
	NNScene::Update(dTime);

	swprintf_s(m_FPSLabelBuff,L"%d",(int)NNApplication::GetInstance()->GetFPS());
	m_FPSLbael->SetString(m_FPSLabelBuff);

	if(CPlayerManager::GetInstance()->IsLogin() == true)
	{
		GetCamera().SetPosition(NNPoint().Lerp(GetCamera().GetPosition(),
			CPlayerManager::GetInstance()->GetMyPlayer()->GetPosition()
			,0.99f));

		if( isChangedGameKeyStates() == true )
		{
			//send packet
			m_GameKeyStatesUpdateHandler->m_GameKeyStatesUpdateRequest.m_MyPlayerInfo.m_GameKeyStates = GetNowGameKeyStates();
			m_GameKeyStatesUpdateHandler->m_GameKeyStatesUpdateRequest.m_MyPlayerInfo.m_PlayerId = CPlayerManager::GetInstance()->GetMyPlayerId();
			m_GameKeyStatesUpdateHandler->m_GameKeyStatesUpdateRequest.m_MyPlayerInfo.m_X = CPlayerManager::GetInstance()->GetMyPlayer()->GetPositionX();
			m_GameKeyStatesUpdateHandler->m_GameKeyStatesUpdateRequest.m_MyPlayerInfo.m_Y = CPlayerManager::GetInstance()->GetMyPlayer()->GetPositionY();
			NNNetworkSystem::GetInstance()->Write( (const char*)&m_GameKeyStatesUpdateHandler->m_GameKeyStatesUpdateRequest,
				m_GameKeyStatesUpdateHandler->m_GameKeyStatesUpdateRequest.m_Size );
		}
		
		/// above is... before Update Game Key States
		
		m_NowGameKeyStates = GetNowGameKeyStates();

		/// under is... After Update Game Key States

		CPlayerManager::GetInstance()->UpdateMyPlayerGameKeyStates(m_NowGameKeyStates);
	}
}

GameKeyStates CGameScene::GetNowGameKeyStates()
{
	GameKeyStates nowGameKeyState;
	nowGameKeyState.upDirectKey = NNInputSystem::GetInstance()->GetKeyState('W');
	nowGameKeyState.downDirectKey = NNInputSystem::GetInstance()->GetKeyState('S');
	nowGameKeyState.leftDirectKey = NNInputSystem::GetInstance()->GetKeyState('D');
	nowGameKeyState.rightDirectKey = NNInputSystem::GetInstance()->GetKeyState('A');
	nowGameKeyState.attackKey = NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON);
	nowGameKeyState.typeActiveSkillKey = NNInputSystem::GetInstance()->GetKeyState(VK_RBUTTON);
	nowGameKeyState.userActiveSkillKey = NNInputSystem::GetInstance()->GetKeyState(VK_SPACE);
	return nowGameKeyState;
}
bool CGameScene::isChangedGameKeyStates()
{
	GameKeyStates nowGameKeyState = GetNowGameKeyStates();
	if( nowGameKeyState.attackKey != m_NowGameKeyStates.attackKey
		||nowGameKeyState.downDirectKey != m_NowGameKeyStates.downDirectKey
		||nowGameKeyState.leftDirectKey != m_NowGameKeyStates.leftDirectKey
		||nowGameKeyState.rightDirectKey != m_NowGameKeyStates.rightDirectKey
		||nowGameKeyState.typeActiveSkillKey != m_NowGameKeyStates.typeActiveSkillKey
		||nowGameKeyState.upDirectKey != m_NowGameKeyStates.upDirectKey
		||nowGameKeyState.userActiveSkillKey != m_NowGameKeyStates.userActiveSkillKey)
		return true;
	return false;
}
