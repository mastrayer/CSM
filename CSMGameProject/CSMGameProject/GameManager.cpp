
#include "GameManager.h"

GameManager* GameManager::mInstance = nullptr;
GameManager* GameManager::GetInstance()
{
	if ( mInstance == nullptr ) 
		mInstance = new GameManager();

	return mInstance;
}
void GameManager::ReleaseInstance()
{
	if ( mInstance != nullptr )
		delete mInstance;
}

GameManager::GameManager()
	: mGameState(GameState::READY), mKillLimit(0)
{
	mKillScore[0] = 0;
	mKillScore[1] = 0;
}
GameManager::~GameManager()
{
}