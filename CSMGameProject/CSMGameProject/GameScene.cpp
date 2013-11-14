#include "GameScene.h"
#include "NNApplication.h"
#include "Packet.h"
#include "PacketFunction.h"
#include "NNNetworkSystem.h"

CGameScene::CGameScene(void)
{
	m_GameMap = CGameMap::Create();
	AddChild(m_GameMap);

	m_FPSLbael = NNLabel::Create( L"Normal Label", L"¸¼Àº °íµñ", 35.f );
	AddChild(m_FPSLbael);

	NNNetworkSystem::GetInstance()->Init();

	//NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_CHAT,ChatResultPacketFunction);
	//NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_KEYSTATE,KeyStateUpdateResultPacketFunction);
	NNNetworkSystem::GetInstance()->Connect("127.0.0.1",9001);

//	KeyStateUpdateRequset KSURequest = KeyStateUpdateRequset();
	//NNNetworkSystem::GetInstance()->Send(&KSURequest);

	GetCamera().SetCameraAnchor(CameraAnchor::MIDDLE_CENTER);

	m_MyPlayerId = -1;
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

	if(m_MyPlayerId != -1)
	{
		NNPoint endPoint = NNPoint(m_MyCharacter->GetPositionX()
			,m_MyCharacter->GetPositionY());

		GetCamera().SetPosition(NNPoint().Lerp(GetCamera().GetPosition(),endPoint,0.99f));

		if( isChangedGameKeyStates() == true )
		{
			//send packet
		}
		
		/// above is... before Update Game Key States
		
		m_NowGameKeyStates = GetNowGameKeyStates();

		/// under is... After Update Game Key States

		//Move myCharacter with Game Key States.
		//Check Moving Input, and set Position to d
		if ( m_NowGameKeyStates.leftDirectKey ==  KEY_DOWN  || 
			m_NowGameKeyStates.leftDirectKey == KEY_PRESSED )
		{
			//Left
			m_MyCharacter->SetPosition( m_MyCharacter->GetPosition() + NNPoint( cos((m_MyCharacter->GetRotation() + -90.f)/180.f*3.14f), sin((m_MyCharacter->GetRotation() -90.f)/180.f*3.14f)) * dTime * 100.f );
		}
		if ( m_NowGameKeyStates.rightDirectKey == KEY_DOWN  || 
			m_NowGameKeyStates.rightDirectKey == KEY_PRESSED)
		{
			//Right
			m_MyCharacter->SetPosition( m_MyCharacter->GetPosition() + NNPoint( cos((m_MyCharacter->GetRotation() +90.f)/180.f*3.14f), sin((m_MyCharacter->GetRotation() +90.f)/180.f*3.14f)) * dTime * 100.f );
		}
		if (m_NowGameKeyStates.upDirectKey == KEY_DOWN  || 
			m_NowGameKeyStates.upDirectKey == KEY_PRESSED)
		{
			//UP
			m_MyCharacter->SetPosition( m_MyCharacter->GetPosition() + NNPoint( cos((m_MyCharacter->GetRotation())/180.f*3.14f), sin((m_MyCharacter->GetRotation())/180.f*3.14f)) * dTime * 100.f );
		}
		if ( m_NowGameKeyStates.downDirectKey == KEY_DOWN  || 
			m_NowGameKeyStates.downDirectKey == KEY_PRESSED)
		{
			//Down
			m_MyCharacter->SetPosition( m_MyCharacter->GetPosition() + NNPoint( cos((m_MyCharacter->GetRotation() + 180.f)/180.f*3.14f), sin((m_MyCharacter->GetRotation() + 180.f)/180.f*3.14f)) * dTime * 100.f );
		}

		if ( NNInputSystem::GetInstance()->GetKeyState( '1' ) == KEY_DOWN )
		{
			m_MyCharacter->TransState(WALK);
		}
		if ( NNInputSystem::GetInstance()->GetKeyState( '2' ) == KEY_DOWN )
		{
			m_MyCharacter->TransState(IDLE);
		}
		if ( NNInputSystem::GetInstance()->GetKeyState( '3' ) == KEY_DOWN )
		{
			m_MyCharacter->TransState(ATTACK);
		}
		if ( NNInputSystem::GetInstance()->GetKeyState( '4' ) == KEY_DOWN )
		{
			m_MyCharacter->TransState(DIE);
		}
		if ( NNInputSystem::GetInstance()->GetKeyState( '5' ) == KEY_DOWN )
		{
			//		NNAudioSystem::GetInstance()->PlayEffectSound( "Effect" );
		}
		if ( NNInputSystem::GetInstance()->GetKeyState( '6' ) == KEY_DOWN )
		{
			//	NNAudioSystem::GetInstance()->PlayEffectSound( "Effect1" );
		}
		if ( NNInputSystem::GetInstance()->GetKeyState( '7' ) == KEY_DOWN )
		{
			ChatBroadcastRequest CBR = ChatBroadcastRequest();
			strcpy_s(CBR.m_Chat,"hihi");
			//	NNNetworkSystem::GetInstance()->Send(&CBR);
		}

	}
}
void CGameScene::SetMyPlayerId(int id)
{
	m_MyPlayerId = id;
	m_MyCharacter = NewCharacter(id);	
}
CCharacter* CGameScene::NewCharacter(int id)
{
	CCharacter* newCharacter = NULL;
	if( m_Characters.find(id)->second == NULL )
	{
		newCharacter = new CCharacter();
		m_Characters.insert(std::map<int,CCharacter*>::value_type(id,newCharacter));
		AddChild(newCharacter);
	}
	else
		newCharacter = m_Characters.find(id)->second;
	return newCharacter;
}
void CGameScene::DeleteCharacter(int id)
{
	if( m_Characters.find(id)->second != NULL )
	{
		CCharacter* deleteTarget = m_Characters.find(id)->second;
		m_Characters.erase( m_Characters.find(id) );
		RemoveChild(deleteTarget);
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
	return memcmp(&m_NowGameKeyStates, &nowGameKeyState, sizeof(GameKeyStates)) == 0 ? true : false;
}
