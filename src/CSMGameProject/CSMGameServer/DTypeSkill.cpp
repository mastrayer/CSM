#include "stdafx.h"
#include "DTypeSkill.h"
#include "Bullet.h"
#include "SkillManager.h"
#include "ClientManager.h"
#include "PlayerManager.h"

DTypeSkill::DTypeSkill(float angle, Player* ownerPlayer):mOwnerPlayer(ownerPlayer),mLifeTime(0.3f),mAngle(angle),mDamage(17),mVelocity(700)
{
	GSkillManager->AddSkill(this);
	DTypeSkillShootResult outPacket = DTypeSkillShootResult();
	outPacket.mAngle = mAngle;
	outPacket.mStartPosition =  ownerPlayer->GetPosition();
	outPacket.mPlayerId = ownerPlayer->GetPlayerInfo().mPlayerId;
	GClientManager->BroadcastPacket(nullptr,&outPacket);
}


DTypeSkill::~DTypeSkill(void)
{

}

void DTypeSkill::Update(float dTime)
{
	mLifeTime -= dTime;

	std::map<int,Player*> players = GPlayerManager->GetPlayers();
	for( std::map<int,Player*>::iterator playerIt = players.begin(); playerIt != players.end(); ++playerIt ) 
	{
		Player* enemyPlayer = playerIt->second;
		if( enemyPlayer -> GetTeam() == mOwnerPlayer->GetTeam() ) continue;
		if( Point().Distance( enemyPlayer->GetPosition() , mOwnerPlayer->GetPosition() ) < enemyPlayer->GetRadius() + mOwnerPlayer->GetRadius() + mVelocity * dTime )
		{
			//멈추고
			mLifeTime = -1;
			//데미지 주고
			enemyPlayer->Damaged(17,mOwnerPlayer);
			//끝났다고 패킷 주고.
			DTypeSkillEndResult outPacket = DTypeSkillEndResult();
			outPacket.mPlayerId = mOwnerPlayer->GetPlayerInfo().mPlayerId;
			GClientManager->BroadcastPacket(nullptr,&outPacket);
			// 업데이트문 강제 종료.
			return;
		}
	}
	
	//이동
	if( IsLive() == true)
	{
		if( mOwnerPlayer->CouldGoPosition(mOwnerPlayer->GetPosition() + Point(cos(mAngle),sin(mAngle)) * mVelocity * dTime) )
			mOwnerPlayer->SetPosition(mOwnerPlayer->GetPosition() + Point(cos(mAngle),sin(mAngle)) * mVelocity * dTime);
		else
		{
			//멈추고
			mLifeTime = -1;
			//끝났다고 패킷 주고.
			DTypeSkillEndResult outPacket = DTypeSkillEndResult();
			outPacket.mPlayerId = mOwnerPlayer->GetPlayerInfo().mPlayerId;
			GClientManager->BroadcastPacket(nullptr,&outPacket);
			// 업데이트문 강제 종료.
			return;
		}
	}
}
bool DTypeSkill::IsLive()
{
	if(mLifeTime < 0)
	{
		return false;
	}
	return true;
}