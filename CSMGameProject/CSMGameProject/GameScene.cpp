
#include "GameScene.h"
#include "NNApplication.h"
#include "PacketType.h"
#include "NNNetworkSystem.h"
#include "PacketHandler.h"

CGameScene::CGameScene(void) : 
	m_NowGameKeyStates(), m_Angle(0), m_LastAngleChangedTime(timeGetTime()),
	m_isInit(false)
{	
	// UI Setting
	

	// Camera Setting
	GetCamera().SetCameraAnchor(CameraAnchor::MIDDLE_CENTER);

	// GameMap Create
	m_GameMap = CGameMap::Create(L"map/gamemap.csm");

	AddChild( m_GameMap );

	// EffectManager
	AddChild( EffectManager::GetInstance() );

	InitNetworkSetting();
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

	if( CPlayerManager::GetInstance()->IsLogin() == true )
	{
	//	TODO :: CPlayerManager의 Score, Limit를 표현해주세요
		if(m_isInit == false)
		{
			m_isInit = true;
			SetUISet( GameUISet::Create() );
		}
		GetCamera().SetPosition(NNPoint().Lerp(GetCamera().GetPosition(),
			CPlayerManager::GetInstance()->GetMyPlayer()->GetPosition()
			,0.99f));

		if( isChangedGameKeyStates() == true )
		{
			m_LastAngleChangedTime = timeGetTime();
			m_Angle = GetNowAngle();
			m_NowGameKeyStates = GetNowGameKeyStates();
			
			//send packet
			m_GameKeyStatesUpdateHandler->m_GameKeyStatesUpdateRequest.m_MyPlayerInfo.m_GameKeyStates = GetNowGameKeyStates();
			m_GameKeyStatesUpdateHandler->m_GameKeyStatesUpdateRequest.m_MyPlayerInfo.m_PlayerId = CPlayerManager::GetInstance()->GetMyPlayerId();
			m_GameKeyStatesUpdateHandler->m_GameKeyStatesUpdateRequest.m_MyPlayerInfo.m_X = CPlayerManager::GetInstance()->GetMyPlayer()->GetPositionX();
			m_GameKeyStatesUpdateHandler->m_GameKeyStatesUpdateRequest.m_MyPlayerInfo.m_Y = CPlayerManager::GetInstance()->GetMyPlayer()->GetPositionY();
			m_GameKeyStatesUpdateHandler->m_GameKeyStatesUpdateRequest.m_MyPlayerInfo.m_Angle = m_Angle;
			NNNetworkSystem::GetInstance()->Write( (const char*)&m_GameKeyStatesUpdateHandler->m_GameKeyStatesUpdateRequest,
				m_GameKeyStatesUpdateHandler->m_GameKeyStatesUpdateRequest.m_Size );
		}
		if( isChangedAngle() == true )
		{
			m_LastAngleChangedTime = timeGetTime();
			m_Angle = GetNowAngle();
			m_MouseAngleUpdateHandler->m_MouseAngleUpdateRequest.m_PlayerId = CPlayerManager::GetInstance()->GetMyPlayerId();
			m_MouseAngleUpdateHandler->m_MouseAngleUpdateRequest.m_Angle = m_Angle;
			NNNetworkSystem::GetInstance()->Write( (const char*)&m_MouseAngleUpdateHandler->m_MouseAngleUpdateRequest,
				m_MouseAngleUpdateHandler->m_MouseAngleUpdateRequest.m_Size );
		}
	}
}

void CGameScene::InitNetworkSetting()
{
	m_LoginHandler = new LoginHandler();
	m_LoginBroadcastHandler = new LoginBroadcastHandler();
	m_GameKeyStatesUpdateHandler = new GameKeyStatesUpdateHandler();
	m_LogoutHandler = new LogoutHandler();
	m_MouseAngleUpdateHandler = new MouseAngleUpdateHandler();
	m_HPUpdateHandler = new HPUpdateHandler();
	NNNetworkSystem::GetInstance()->Init();

	NNNetworkSystem::GetInstance()->SetPacketHandler( PKT_SC_KEYSTATE, m_GameKeyStatesUpdateHandler );
	NNNetworkSystem::GetInstance()->SetPacketHandler( PKT_SC_LOGIN, m_LoginHandler );
	NNNetworkSystem::GetInstance()->SetPacketHandler( PKT_SC_LOGIN_BROADCAST, m_LoginBroadcastHandler );
	NNNetworkSystem::GetInstance()->SetPacketHandler( PKT_SC_LOGOUT, m_LogoutHandler );
	NNNetworkSystem::GetInstance()->SetPacketHandler( PKT_SC_MOUSEANGLE, m_MouseAngleUpdateHandler );
	NNNetworkSystem::GetInstance()->SetPacketHandler( PKT_SC_HP, m_HPUpdateHandler );

	NNNetworkSystem::GetInstance()->Connect( "10.73.44.30",9001);

	NNNetworkSystem::GetInstance()->Write( (const char*)&m_LoginHandler->m_LoginRequestPacket, m_LoginHandler->m_LoginRequestPacket.m_Size );
}

GameKeyStates CGameScene::GetNowGameKeyStates()
{
	GameKeyStates nowGameKeyState;
	if( NNInputSystem::GetInstance()->GetKeyState('W') == KEY_PRESSED ||
		NNInputSystem::GetInstance()->GetKeyState('W') == KEY_DOWN )
		nowGameKeyState.upDirectKey = KEYSTATE_PRESSED;
	if( NNInputSystem::GetInstance()->GetKeyState('S') == KEY_PRESSED ||
		NNInputSystem::GetInstance()->GetKeyState('S') == KEY_DOWN )
		nowGameKeyState.downDirectKey = KEYSTATE_PRESSED;
	if( NNInputSystem::GetInstance()->GetKeyState('A') == KEY_PRESSED ||
		NNInputSystem::GetInstance()->GetKeyState('A') == KEY_DOWN )
		nowGameKeyState.leftDirectKey = KEYSTATE_PRESSED;
	if( NNInputSystem::GetInstance()->GetKeyState('D') == KEY_PRESSED ||
		NNInputSystem::GetInstance()->GetKeyState('D') == KEY_DOWN )
		nowGameKeyState.rightDirectKey = KEYSTATE_PRESSED;
	if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) == KEY_PRESSED ||
		NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) == KEY_DOWN )
		nowGameKeyState.attackKey = KEYSTATE_PRESSED;
	if( NNInputSystem::GetInstance()->GetKeyState(VK_RBUTTON) == KEY_PRESSED ||
		NNInputSystem::GetInstance()->GetKeyState(VK_RBUTTON) == KEY_DOWN )
		nowGameKeyState.typeActiveSkillKey = KEYSTATE_PRESSED;
	if( NNInputSystem::GetInstance()->GetKeyState(VK_SPACE) == KEY_PRESSED ||
		NNInputSystem::GetInstance()->GetKeyState(VK_SPACE) == KEY_DOWN )
		nowGameKeyState.userActiveSkillKey = KEYSTATE_PRESSED;

	//printf(" @@@@@@@@@@@@@@ %d \n",nowGameKeyState.typeActiveSkillKey);
	return nowGameKeyState;
}
bool CGameScene::isChangedGameKeyStates()
{
	GameKeyStates nowGameKeyState = GetNowGameKeyStates();
	if( nowGameKeyState.attackKey != m_NowGameKeyStates.attackKey
		||nowGameKeyState.upDirectKey != m_NowGameKeyStates.upDirectKey
		||nowGameKeyState.downDirectKey != m_NowGameKeyStates.downDirectKey
		||nowGameKeyState.leftDirectKey != m_NowGameKeyStates.leftDirectKey
		||nowGameKeyState.rightDirectKey != m_NowGameKeyStates.rightDirectKey
		||nowGameKeyState.typeActiveSkillKey != m_NowGameKeyStates.typeActiveSkillKey
		||nowGameKeyState.userActiveSkillKey != m_NowGameKeyStates.userActiveSkillKey)
		return true;
	return false;
}

float CGameScene::GetNowAngle()
{
	NNPoint mousePoint = NNInputSystem::GetInstance()->GetMousePosition();
	// characterPositionByWC, WC -> window center. 화면 가운데를 0,0으로 했을때의 캐릭터 좌표
	//NNPoint characterPositionByWC = GetCamera().GetPosition() -	CPlayerManager::GetInstance()->GetMyPlayer()->GetPosition();
	NNPoint referencePointForMouse = NNPoint(GetCamera().GetScreenWidth()/2.f,GetCamera().GetScreenHeight()/2.f);// + characterPositionByWC;
	return atan2f( NNPoint(mousePoint-referencePointForMouse).GetY() , NNPoint(mousePoint-referencePointForMouse).GetX() )*180.0f/3.14f ;
}
bool CGameScene::isChangedAngle()
{
	DWORD time_A = timeGetTime();
	if( (timeGetTime() - m_LastAngleChangedTime ) > 20 )
	{
		//20 밀리세컨드마다 마우스 방향 변경.
		if( m_Angle != GetNowAngle() )
		{
			printf("Oh!!\n");
			return true;
		}
	}
	return false;
}