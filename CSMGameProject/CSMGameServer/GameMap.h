#pragma once

#include "NNResourceManager.h"
#include "PacketType.h"
#define ATTRIBUTE_MOVE 0x01
#define TILESIZE 64

enum TileType
{
	TILE,
	BARRACK,
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

private:
	NNXML* m_MapXMLData;
	Tile ***m_Tile;
	int m_Width, m_Height;

protected:
	Point positionToArrayIndex( Point p );
};

extern GameMap* GGameMap;