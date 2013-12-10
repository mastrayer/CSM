#include "stdafx.h"
#include "BulletManager.h"


BulletManager::BulletManager(void):mBullets(),mDetectPlate()
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
void BulletManager::DeleteBullet(Bullet* bullet)
{
	std::map<int,Bullet*>::iterator itor = mBullets.find(bullet->GetBulletNumber());

	if( itor != mBullets.end() ) 
	{
		mBullets.erase(itor);
		bullet->SetLifeTime(-1);
	}
	delete bullet;
}
void BulletManager::Update(float dTime)
{
	mDetectPlate.clear();
	
	for( std::map<int,Player*>::iterator it = GPlayerManager->GetPlayers().begin(); it != GPlayerManager->GetPlayers().end(); ++it ) 
	{
		for(int x = it->second->GetPosition().x; x <= it->second->GetPosition().x + pow(DETECT_POINT, 0.5); x++)
		{
			for(int y = it->second->GetPosition().y; y <= it->second->GetPosition().y + pow(DETECT_POINT, 0.5); y++)
			{
				if( pow( pow(it->second->GetPosition().x - x, 2) + pow(it->second->GetPosition().y - y, 2) , 0.5) < it->second->GetRadius() )
				{
		
					DetectPlatePoint dpp;
					dpp.x = x, dpp.y = y;				
					Player* player = it->second;
								
	
					//std::map<DetectPlatePoint,Player*>::iterator itor = mDetectPlate.find(dpp);
/*
					if( itor == mDetectPlate.end() ) 
					{
						mDetectPlate.insert(std::map<DetectPlatePoint,Player*>::value_type(dpp,player));;	
					}
					else
					{
						itor->second = player;
					}
	*/
				}
			}
		}
	}

	/*
	for( std::map<int,Bullet*>::iterator it = mBullets.begin(); it != mBullets.end(); ++it ) 
	{
		bool loopBreaker = false;
		it->second->Update(dTime);
		switch (it->second->GetShape())
		{
		case CIRCLE :
			{
				int startX = it->second->GetPosition().x - it->second->GetCenter().x;
				int endX = startX + 2 * it->second->GetRadius();
				float dX = 2 * it->second->GetRadius() / pow(DETECT_POINT, 0.5);

				int startY = it->second->GetPosition().y - it->second->GetCenter().y;
				int endY = startY + 2 * it->second->GetRadius();
				float dY = 2 * it->second->GetRadius() / pow(DETECT_POINT, 0.5);

				float rotation = it->second->GetRotation();

				for(int bx = startX; bx <= endX; bx += dX)
				{
					for(int by = startY; by <= endY; by += dY)
					{
						int x = cos(rotation) * bx - sin(rotation) * by;
						int y = sin(rotation) * bx + cos(rotation) * by;
						if( pow( pow(it->second->GetPosition().x - x, 2) + pow(it->second->GetPosition().y - y, 2) , 0.5) < it->second->GetRadius() )
						{
							DetectPlatePoint dpp;
							dpp.x = x, dpp.y = y;				
							
							std::map<DetectPlatePoint,Player*>::iterator itor = mDetectPlate.find(dpp);

							if( itor != mDetectPlate.end() ) 
							{
								it->second->JudgeCollision(itor->second);
								if( it->second->isLive() == false)
								{
									loopBreaker = true;
									break;
								}
							}
						}
					}
					if( loopBreaker == true) break;
				}
			}break;

		case ELLIPSE :
			{
				int startX = it->second->GetPosition().x - it->second->GetCenter().x;
				int endX = startX + 2 * it->second->GetXRadius();
				float dX = 2 * it->second->GetXRadius() / pow(DETECT_POINT, 0.5);

				int startY = it->second->GetPosition().y - it->second->GetCenter().y;
				int endY = startY + 2 * it->second->GetYRadius();
				float dY = 2 * it->second->GetYRadius() / pow(DETECT_POINT, 0.5);

				float rotation = it->second->GetRotation();

				for(int bx = startX; bx <= endX; bx += dX)
				{
					for(int by = startY; by <= endY; by += dY)
					{
						int x = cos(rotation) * bx - sin(rotation) * by;
						int y = sin(rotation) * bx + cos(rotation) * by;
						if( pow((it->second->GetPosition().x - x) * cos(it->second->GetRotation()) + 
							(it->second->GetPosition().y - y) * sin(it->second->GetRotation()), 2) 
							/ pow(it->second->GetXRadius(),2) + 
							 pow((it->second->GetPosition().x - x) * sin(it->second->GetRotation()) + 
							(it->second->GetPosition().y - y) * cos(it->second->GetRotation()) , 2)
							/ pow(it->second->GetXRadius(),2) < 1 )
						{
							DetectPlatePoint dpp;
							dpp.x = x, dpp.y = y;				
							
							std::map<DetectPlatePoint,Player*>::iterator itor = mDetectPlate.find(dpp);

							if( itor != mDetectPlate.end() ) 
							{
								it->second->JudgeCollision(itor->second);
								if( it->second->isLive() == false)
								{
									loopBreaker = true;
									break;
								}
							}
						}
					}
					if( loopBreaker == true) break;
				}
			}break;

		case RECTANGLE :
			{
				int startX = it->second->GetPosition().x - it->second->GetCenter().x;
				int endX = startX + it->second->GetWidth();
				float dX = it->second->GetWidth() / pow(DETECT_POINT, 0.5);

				int startY = it->second->GetPosition().y - it->second->GetCenter().y;
				int endY = startY + it->second->GetHeight();
				float dY = it->second->GetHeight() / pow(DETECT_POINT, 0.5);

				float rotation = it->second->GetRotation();

				for(int bx = startX; bx <= endX; bx += dX)
				{
					for(int by = startY; by <= endY; by += dY)
					{
						int x = cos(rotation) * bx - sin(rotation) * by;
						int y = sin(rotation) * bx + cos(rotation) * by;

							DetectPlatePoint dpp;
							dpp.x = x, dpp.y = y;				
							
							std::map<DetectPlatePoint,Player*>::iterator itor = mDetectPlate.find(dpp);

							if( itor != mDetectPlate.end() ) 
							{
								it->second->JudgeCollision(itor->second);
								if( it->second->isLive() == false)
								{
									loopBreaker = true;
									break;
								}
							}
						
					}
					if( loopBreaker == true) break;
				}
			}break;
		default:
			break;
		}
		
		if ( it->second->isLive() == false )
		{
			DeleteBullet( it->second );
			if ( it == mBullets.end() )
			{
				break;   
			}
		}
	}
	*/
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