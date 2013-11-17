#pragma once
#include "PacketType.h"
enum PlayerState
{
	IDLE,
	WALK,
	ATTACK,
	DIE,
};

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
	PlayerState mPlayerState;
	GameKeyStates mGameKeyStates;
	Point mPosition;
	int mPlayerId;

public:
	Player(void);
	Player(int id);
	virtual ~Player(void);
	void TransState(PlayerState state);
	void SetGameKeyStates(GameKeyStates _gameKeySates) { mGameKeyStates = _gameKeySates; };
	void SetPosition(Point position) { mPosition = position; };
	Point GetPosition() { return mPosition; };
	PlayerInfo GetPlayerInfo();
	void Update( float dTime );
};

