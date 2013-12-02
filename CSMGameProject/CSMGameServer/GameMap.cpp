#include "stdafx.h"
#include "GameMap.h"
#include <iostream>

GameMap::GameMap(std::wstring path)
{
	if(INVALID_FILE_ATTRIBUTES == GetFileAttributes(path.c_str()) && GetLastError()==ERROR_FILE_NOT_FOUND)
	{
		printf("File Not Exist!\n");
		return;
	}

	convertFileToMap(path);

}

GameMap::~GameMap(void)
{
}
 
void en(int b)
{
	static int c = 0;
	printf("%d] %d\n",c++, GetTickCount()-b);
}
void GameMap::convertFileToMap( std::wstring path )
{
	std::wstring FILENAME[2] = { L"map.xml", L"TileSet" };
	NNZip *xmlLoad;
	NNZip **tileSetLoad;

	// XML LOAD
	xmlLoad = NNResourceManager::GetInstance()->UnzipFileToMemory(path, FILENAME[0]);
	m_MapXMLData= NNResourceManager::GetInstance()->LoadXMLFromMemory(xmlLoad);

	std::string tile;
	int usedTileSet = 0;

	printf("################# MapInfo \n");
	// MapInfo
	{
		// Map Size
		{
			m_Width = atoi(m_MapXMLData->XPathToString("/map/mapInfo/size/@width").c_str());
			m_Height = atoi(m_MapXMLData->XPathToString("/map/mapInfo/size/@height").c_str());

			m_Tile = new Tile**[m_Height];
			for(int i=0;i<m_Height; ++i)
			{
				m_Tile[i] = new Tile *[m_Width];
				for( int j=0; j< m_Width; ++j)
					m_Tile[i][j] = new Tile();
			}
		}
		// Used Tile Set
		{
			usedTileSet = atoi(m_MapXMLData->XPathToString("/map/mapInfo/usedTileSet/@count").c_str());
			tileSetLoad = new NNZip*[usedTileSet];

			for(int i=0; i<usedTileSet; ++i)
				tileSetLoad[i] = NNResourceManager::GetInstance()->UnzipFileToMemory(path, FILENAME[1] + std::to_wstring(i));
		}
	}
	printf("################# /MapInfo \n");

	// TILE Initialize //////////////////////////////////////////////////////////////////////////

	// 	m_MapInfo.tile = new TILE *[m_MapInfo.mapHeight];
	// 	for(int i=0;i<m_MapInfo.mapHeight; ++i)
	// 		m_MapInfo.tile[i] = new TILE[m_MapInfo.mapWidth];

	/////////////////////////////////////////////////////////////////////////////////////////////


	printf("################# TileInfo \n");
	// Tile Info
	{

		for(int i=0; i<m_Height; ++i)
		//for(int i=0; i<2; ++i)
		{
			for(int j=0; j<m_Width; ++j)
			//for(int j=0; j<2; ++j)
			{
				//printf("[%d/%d] ",i,j);
				int tileSetIndex, x, y;
				m_Tile[i][j]->m_isFull = m_MapXMLData->XPathToString("/map/tileInfo/tile[@Y=\"" + std::to_string(i) +"\" and @X=\"" + std::to_string(j) + "\"]/@isFull").c_str() == "true" ? true : false;
				tileSetIndex = atoi(m_MapXMLData->XPathToString("/map/tileInfo/tile[@Y=\"" + std::to_string(i) + "\" and @X=\"" + std::to_string(j) + "\"]/TileImageInfo/@Index").c_str());
				x = atoi(m_MapXMLData->XPathToString("/map/tileInfo/tile[@Y=\"" + std::to_string(i) + "\" and @X=\"" + std::to_string(j) + "\"]/TileImageInfo/@X").c_str());
				y = atoi(m_MapXMLData->XPathToString("/map/tileInfo/tile[@Y=\"" + std::to_string(i) + "\" and @X=\"" + std::to_string(j) + "\"]/TileImageInfo/@Y").c_str());
				m_Tile[i][j]->m_attribute = m_MapXMLData->XPathToString("/map/tileInfo/tile[@Y=\"" + std::to_string(i) + "\" and @X=\"" + std::to_string(j) + "\"]/Attribute/@move").c_str() == "true" ? 1 : 0;
				m_Tile[i][j]->m_height = atoi(m_MapXMLData->XPathToString("/map/tileInfo/tile[@Y=\"" + std::to_string(i) + "\" and @X=\"" + std::to_string(j) + "\"]/Attribute/@height").c_str());
				printf("[%d/%d] (%0.f-%0.f)(%0.f-%0.f) \n",i,j,y + 0.f,y+64.f,x + 0.f,x+64.f);
				
			}
		}
	}
	printf("################# / TileInfo \n");


	delete tileSetLoad;
}

Point GameMap::positionToArrayIndex( Point p )
{
	p.x = ( p.x / TILESIZE );
	p.y = ( p.y / TILESIZE );

	return p;
}
bool GameMap::isValidTile( Point p )
{
	Point temp = positionToArrayIndex(p);
	int i = (int)temp.x;
	int j = (int)temp.y;

	Tile *tile = m_Tile[i][j];

	// 이 타일이 빈 타일이거나
	// 움직일 수 없는 타일이거나
 	if(tile->m_isFull == false ||
		tile->m_attribute & ATTRIBUTE_MOVE )
		return false;

	return true;
}

//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////                            /////////////////////////////
/////////////////////////////           Tile            /////////////////////////////
/////////////////////////////                            /////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

Tile::Tile()
	: m_attribute(0), m_height(0), m_isFull(false)
{

}
Tile::~Tile()
{

}


GameMap* GGameMap = nullptr;