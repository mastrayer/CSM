
#include "PlayerUI.h"
#include "Player.h"
#include "NNApplication.h"

PlayerUI::PlayerUI()
{
	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();
		
	mHpBar[BLUE] = NNSprite::Create( L"Sprite/BlueHpBar.png" );
	mHpBar[RED] = NNSprite::Create(L"Sprite/RedHpBar.png");
		
	mHpBar[BLUE]->SetPosition( -30.f, -50.f );
	mHpBar[RED]->SetPosition(-30.f, -50.f);

	AddChild(mHpBar[BLUE]);
	AddChild(mHpBar[RED]);
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

	mHpBar[BLUE]->SetVisible(false);
	mHpBar[RED]->SetVisible(false);

	TeamColor result = (TeamColor)(dynamic_cast<CPlayer*>(GetParent())->GetTeam());
	
	mHpBar[result]->SetVisible(true);
	mHpBar[result]->SetScale(mHp / 50.f, 1.f);
}