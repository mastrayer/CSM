#pragma once
#include "PacketType.h"

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

public:
	Player(void);
	Player(int id);
	virtual ~Player(void);
	void TransState(short state);
	void SetGameKeyStates(GameKeyStates _gameKeySates) { mGameKeyStates = _gameKeySates; }
	void SetPosition(Point position) { mPosition = position; }
	void SetRotation(float angle) { mRotation = angle; }
	Point GetPosition() { return mPosition; }
	PlayerInfo GetPlayerInfo();
	void Update( float dTime );
};

