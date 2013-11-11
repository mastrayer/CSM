#include "GameScene.h"
#include "NNApplication.h"
#include "Packet.h"
#include "PacketFunction.h"
#include "NNNetworkSystem.h"

CGameScene::CGameScene(void)
{
	m_GameMap = CGameMap::Create();
	AddChild(m_GameMap);

	m_Character = CCharacter::Create();
	AddChild(m_Character);

	m_FPSLbael = NNLabel::Create( L"Normal Label", L"¸¼Àº °íµñ", 35.f );
	AddChild(m_FPSLbael);
	
	NNNetworkSystem::GetInstance()->Init();

	NNNetworkSystem::GetInstance()->SetPacketFunction(PKT_SC_CHAT,ChatResultPacketFunction);
	NNNetworkSystem::GetInstance()->SetPacketFunction(PKT_SC_KEYSTATE,KeyStateUpdateResultPacketFunction);
	NNNetworkSystem::GetInstance()->Connect("127.0.0.1",9001);
		
	KeyStateUpdateRequset KSURequest = KeyStateUpdateRequset();
	NNNetworkSystem::GetInstance()->Send(&KSURequest);

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

	NNPoint endPoint = NNPoint(m_Character->GetPositionX()
		,m_Character->GetPositionY());
	
	GetCamera().SetPosition(NNPoint().Lerp(GetCamera().GetPosition(),endPoint,0.99f));
	
}