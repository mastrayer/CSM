#include "GameMap.h"
#include"iostream"

CGameMap::CGameMap(std::wstring path)
{
	NNSpriteAtlas *temp;
	for(int i=0;i<12; ++i)
	{
		for(int j=0; j<12; ++j)
		{
			temp = NNSpriteAtlas::Create(L"C:/Users/kim jihwan/Desktop/temp-tile/ground.png");
			AddChild(temp);

			temp->SetCutSize(0,0,64.f,64.f);
			temp->SetPosition(i*64,j*64);
		}
	}
// 	convertFileToMap(path);
// 	m_MapSprite = NNSprite::Create( L"Sprite/map.png" );
// 	m_MapSprite->SetPosition( 0.f, 0.f );
// 	AddChild( m_MapSprite );
}

CGameMap::~CGameMap(void)
{
}

void CGameMap::Update( float dTime )
{
	NNObject::Update( dTime );
}

void CGameMap::Render()
{
	NNObject::Render();
}
 
void CGameMap::CreateMapInfo(NNXML* xml)
{
	/*
	std::string tile;
	int usedTileSet = 0;

	// MapInfo
	{
		// Map Size
		{
			m_MapInfo.mapWidth = atoi(xml->XPathToString("/map/mapInfo/size/@width").c_str());
			m_MapInfo.mapHeight = atoi(xml->XPathToString("/map/mapInfo/size/@height").c_str());
		}
		// Used Tile Set
		{
			usedTileSet = atoi(xml->XPathToString("/map/mapInfo/usedTileSet/@count").c_str());
		}
	}

	// TILE Initialize //////////////////////////////////////////////////////////////////////////

	m_MapInfo.tile = new TILE *[m_MapInfo.mapHeight];
	for(int i=0;i<m_MapInfo.mapHeight; ++i)
		m_MapInfo.tile[i] = new TILE[m_MapInfo.mapWidth];

	/////////////////////////////////////////////////////////////////////////////////////////////

	// Tile Info
	{
		for(int i=0; i<m_MapInfo.mapHeight; ++i)
		{
			for(int j=0; j<m_MapInfo.mapWidth; ++j)
			{
				tile = "t" + std::to_string(i) + "-" + std::to_string(j);

				m_MapInfo.tile[i][j].isFull = xml->XPathToString("/map/tileInfo/" + tile + "/isFull").c_str() == "true" ? true : false;
				{
					m_MapInfo.tile[i][j].isFull = xml->XPathToString("/map/tileInfo/" + tile + "/TileImageInfo/@Index").c_str();
				}
			}
		}
	}

	
	

	getchar();*/
}
void CGameMap::convertFileToMap( std::wstring path )
{
	std::wstring FILENAME[2] = { L"map.xml", L"TileSet" };
	NNZip *loadZip;

	// XML LOAD
	loadZip = NNResourceManager::GetInstance()->UnzipFileToMemory(path, FILENAME[0]);
	m_MapXMLData= NNResourceManager::GetInstance()->LoadXMLFromMemory(loadZip);

	CreateMapInfo(m_MapXMLData);
}

//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////                            /////////////////////////////
/////////////////////////////           CTile            /////////////////////////////
/////////////////////////////                            /////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

CTile::CTile()
	: m_attribute(0), m_height(0), m_image(nullptr), m_isFull(false)
{

}
CTile::~CTile()
{

}
void CTile::Update( float dTime )
{
	NNObject::Update( dTime );
}

void CTile::Render()
{
	NNObject::Render();
}
