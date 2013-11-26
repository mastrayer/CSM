#pragma once
#include "PacketType.h"
#include "ClientSession.h"

#define PLAYER_STATE_IDLE 0
#define PLAYER_STATE_WALK 1
#define PLAYER_STATE_ATTACK 2
#define PLAYER_STATE_DIE 3


struct Point
{
	Point()
	{

	}
	Point(float _x, float _y)
	{
		x = _x , y = _y;
	}
	Point operator+( const Point& point ) const{
		return Point(x+point.x,y+point.y);
	}
	Point operator-( const Point& point ) const{
		return Point(x+point.x,y+point.y);
	}
	Point operator*( float n ) const{
		return Point(x*n,y*n);
	}
	float GetDistance(const Point& aPoint, const Point& bPoint) const{
		return (float)pow(pow(aPoint.x-bPoint.x,2) + pow(aPoint.y-bPoint.y,2),0.5);
	}
	float x,y;
};
class Player
{
private:
	short mPlayerState;
	GameKeyStates mGameKeyStates;
	Point mPosition;
	int mPlayerId;
	float mRotation;
	ClientSession* mClient;
	float mAttackRange;
	int mHP;
	int mDamage;
	float mResponTime;

public:
	Player(void);
	Player(int id, ClientSession* client);
	virtual ~Player(void);
	void TransState(short state);
	void SetGameKeyStates(GameKeyStates _gameKeySates) { mGameKeyStates = _gameKeySates; }
	void SetPosition(Point position) { mPosition = position; }
	void SetRotation(float angle) { mRotation = angle; }
	Point GetPosition() { return mPosition; }
	void Damaged(int damage);
	void SetHP(int hp) {mHP = hp;}
	PlayerInfo GetPlayerInfo();
	void Update( float dTime );
};

