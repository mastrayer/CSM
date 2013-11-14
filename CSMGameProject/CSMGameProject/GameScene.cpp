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
		
	KeyStateUpdateRequset KSURequest = KeyStateUpdateRequset();
	//NNNetworkSystem::GetInstance()->Send(&KSURequest);

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

	if(m_MyPlayerId != -1)
	{
		NNPoint endPoint = NNPoint(m_MyCharacter->GetPositionX()
			,m_MyCharacter->GetPositionY());
	
		GetCamera().SetPosition(NNPoint().Lerp(GetCamera().GetPosition(),endPoint,0.99f));

		if( isChangedGameKeyStates() == true )
		{
			//send packet
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
	CCharacter* newCharacter;
	if( m_Characters.find(id)->second == NULL )
	{
		newCharacter = new CCharacter();
		m_Characters.insert(std::map<int,CCharacter*>::value_type(id,newCharacter));
		AddChild(newCharacter);

	}
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
	return memcmp(&m_PreGameKeyStates, &nowGameKeyState, sizeof(GameKeyStates));
}
