#pragma once
class GameManager
{
public:
	GameManager( int killLimit );
	~GameManager(void);
	void DiePlayer(int team);
	int GiveTeamNumber();
	void EndOfGame(int winnerTeam);
	void LogOutPlayer(int team);
	int GetKillLimit() { return mKillLimit; }
	int* GetKillScore() { return mKillScore; }

private:
	int mPlayerCount[2];
	int mKillScore[2];
	int mKillLimit;
};



extern GameManager* GGameManager;