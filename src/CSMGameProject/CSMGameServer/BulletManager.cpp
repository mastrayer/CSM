#include "stdafx.h"
#include "BulletManager.h"


BulletManager::BulletManager(void):mBullets()
{
}


BulletManager::~BulletManager(void)
{
}

void BulletManager::AddBullet(Bullet* bullet)
{
	int number = GenerateBulletNumber();
	std::map<int,Bullet*>::iterator itor = mBullets.find(number);

	if( itor == mBullets.end() ) 
	{
		mBullets.insert(std::map<int,Bullet*>::value_type(number,bullet));;
		bullet->SetBulletNumber(number);
	}
}
void BulletManager::Update(float dTime)
{
	for( std::map<int,Bullet*>::iterator bulletIt = mBullets.begin(); bulletIt != mBullets.end();) 
	{
		std::map<int,Player*> players;
		GPlayerManager->GetPlayers(bulletIt->second->GetOwnerPlayer()->GetGameId(), &players);
		for( std::map<int,Player*>::iterator playerIt = players.begin(); playerIt != players.end(); ++playerIt ) 
		{
			bulletIt->second->JudgeCollision(playerIt->second);
		}
		bulletIt->second->Update(dTime);


		if(bulletIt->second->isLive() == false)
		{
			mBullets.erase(bulletIt++);
		}
		else
		{
			++bulletIt;
		}
	}
}

int BulletManager::GenerateBulletNumber()
{
	while(1)
	{
		int number = rand();
		std::map<int,Bullet*>::iterator itor = mBullets.find(number);
		if( itor == mBullets.end() ) 
		{
			return number;	
		}
	}
	return -1;
}

BulletManager* GBulletManager = nullptr;