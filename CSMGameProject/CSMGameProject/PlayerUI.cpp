
#include "PlayerUI.h"
#include "Player.h"
#include "NNApplication.h"

PlayerUI::PlayerUI()
{
	//mHp = (dynamic_cast<CPlayer*>(GetParent()))->GetPlayerHP();
	//mHp = 1;

	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();
	
	mHpBar = NNSprite::Create( L"Sprite/hpbar.png" );
	//mHpBarFrame = NNSprite::Create( L"Sprite/hpbar_frame.png" );
	//mHpBar->SetCenter( mHpBar->GetImageWidth()/2.f, mHpBar->GetImageHeight()/2.f );
	mHpBar->SetPosition( -30.f, -50.f );
	AddChild( mHpBar );
}

PlayerUI::~PlayerUI()
{
}

void PlayerUI::Render()
{
	NNObject::Render();
}

void PlayerUI::Update( float dTime )
{
	NNObject::Update( dTime );
	
	mHpBar->SetScale( mHp / 50.f, 1.f);
}