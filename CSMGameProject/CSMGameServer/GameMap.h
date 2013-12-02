#pragma once

#include "NNResourceManager.h"

#define ATTRIBUTE_MOVE 0x01
#define TILESIZE 64
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
class Tile
{
public:
	Tile();
	virtual ~Tile();

	void Render();
	void Update( float dTime );


	int m_attribute;
	int m_height;
	bool m_isFull;
};
class GameMap
{
public:
	GameMap(std::wstring path);
	virtual ~GameMap(void);
	
	int GetAttribute(int i, int j) { return m_Tile[i][j]->m_attribute; }
	int SetAttribute(int i, int j, int value) { m_Tile[i][j]->m_attribute = value; }
	bool isValidTile(Point p);

	void Render();
	void Update( float dTime );

	//void CreateMap(NNXML* xml, );
	void convertFileToMap(std::wstring path);

	static GameMap* Create(std::wstring path)
	{
		GameMap* pInstance = new GameMap(path);
		return pInstance;
	}
	//NNCREATE_FUNC(GameMap);
	

private:
	NNXML* m_MapXMLData;
	Tile ***m_Tile;
	int m_Width, m_Height;

protected:
	Point positionToArrayIndex( Point p );
};

extern GameMap* GGameMap;