
#include "PlayerUI.h"
#include "Player.h"
#include "NNApplication.h"
#include "PlayerManager.h"
#include "NNInputSystem.h"
#include "EffectManager.h"

#include "EmoticonEffect.h"

PlayerUI::PlayerUI(NNObject *follower)
{
	mFollower = follower;
}

PlayerUI::~PlayerUI()
{
}

void PlayerUI::Init()
{
	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

	mHpBar[BLUE] = NNSprite::Create( L"Resource/Sprite/UI/GameUI/BlueHpBar.png" );
	mHpBar[RED] = NNSprite::Create(L"Resource/Sprite/UI/GameUI/RedHpBar.png");

	mHpBar[BLUE]->SetPosition( 0.f, -40.f );
	mHpBar[RED]->SetPosition(0.f, -40.f);

	mNickname = NNLabel::Create(L"", L"¸¼Àº °íµñ", 20.f);
	mNickname->SetPosition(0.f, -70.f);
	mNickname->SetBold(true);

	AddChild(mNickname);
	AddChild(mHpBar[BLUE]);
	AddChild(mHpBar[RED]);

	SetCenter( mHpBar[BLUE]->GetImageWidth()/2.f, mHpBar[BLUE]->GetImageHeight()/2.f );

	mTeam = -1;
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

	//TeamColor mTeam = (TeamColor)(dynamic_cast<CPlayer*>(GetParent())->GetTeam());
	if (mTeam == -1)
	{
		mTeam = (TeamColor)(dynamic_cast<CPlayer*>(mFollower)->GetTeam());

		return;
	}
	
	
	mHpBar[mTeam]->SetVisible(true);
	mHpBar[mTeam]->SetScale(mHp / 50.f, 1.f);

	

}

void PlayerUI::SetNickname()
{
	CPlayer *player = dynamic_cast<CPlayer*>(mFollower);
	mNickname->SetString(player->GetNickname());
}
