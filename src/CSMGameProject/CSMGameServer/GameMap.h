#pragma once

#include "NNResourceManager.h"
#include "PacketType.h"
#define ATTRIBUTE_MOVE 0x01
#define TILESIZE 64

enum TileType
{
	TILE,
	BARRACK_A,
	BARRACK_B,
	BARRACK_C,
	BARRACK_D,
	BARRACK_OUT,
	STARTING_POINT_A,
	STARTING_POINT_B,
};

class Tile
{
public:
	Tile();
	virtual ~Tile();

	void Render();
	void Update( float dTime );

	TileType m_Type;
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
	TileType GetTileType(Point p);
	//void CreateMap(NNXML* xml, );
	void convertFileToMap(std::wstring path);

	static GameMap* Create(std::wstring path)
	{
		GameMap* pInstance = new GameMap(path);
		return pInstance;
	}
	//NNCREATE_FUNC(GameMap);
	int GetWidth(){ return m_Width; }
	int GetHeight(){ return m_Height; }

	float GetStartingPointAX() const { return m_StartingPointAX; }
	float GetStartingPointAY() const { return m_StartingPointAY; }
	float GetStartingPointBX() const { return m_StartingPointBX; }
	float GetStartingPointBY() const { return m_StartingPointBY; }

private:
	NNXML* m_MapXMLData;
	Tile ***m_Tile;
	int m_Width, m_Height;
	float m_StartingPointAX, m_StartingPointAY;
	float m_StartingPointBX, m_StartingPointBY;
protected:
	Point positionToArrayIndex( Point p );
};

extern GameMap* GGameMap;