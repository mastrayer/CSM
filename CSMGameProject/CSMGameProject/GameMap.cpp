#include "GameMap.h"
#include"iostream"

CGameMap::CGameMap(std::wstring path)
{
// 	NNSpriteAtlas *temp;
// 	for(int i=0;i<12; ++i)
// 	{
// 		for(int j=0; j<12; ++j)
// 		{
// 			temp = NNSpriteAtlas::Create(L"C:/Users/kim jihwan/Desktop/temp-tile/ground.png");
// 			AddChild(temp);
// 
// 			temp->SetCutSize(0,0,64.f,64.f);
// 			temp->SetPosition(i*64,j*64);
// 		}
// 	}
	convertFileToMap(path);
// 	m_MapSprite = NNSprite::Create( L"Sprite/map.png" );
// 	m_MapSprite->SetPosition( 0.f, 0.f );
//  AddChild( m_MapSprite );
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
 
// void CGameMap::CreateMap(NNXML* xml)
// {
// 	
// 
// 	
// 	
// 
// 	getchar();
// }
void CGameMap::convertFileToMap( std::wstring path )
{
	std::wstring FILENAME[2] = { L"map.xml", L"TileSet" };
	NNZip *xmlLoad;
	NNZip **tileSetLoad;

	// XML LOAD
	xmlLoad = NNResourceManager::GetInstance()->UnzipFileToMemory(path, FILENAME[0]);
	m_MapXMLData= NNResourceManager::GetInstance()->LoadXMLFromMemory(xmlLoad);

	std::string tile;
	int usedTileSet = 0;

	// MapInfo
	{
		// Map Size
		{
			m_MapInfo.mapWidth = atoi(m_MapXMLData->XPathToString("/map/mapInfo/size/@width").c_str());
			m_MapInfo.mapHeight = atoi(m_MapXMLData->XPathToString("/map/mapInfo/size/@height").c_str());

			m_Tile = new CTile**[m_MapInfo.mapHeight];
			for(int i=0;i<m_MapInfo.mapHeight; ++i)
			{
				m_Tile[i] = new CTile *[m_MapInfo.mapWidth];
				for( int j=0; j< m_MapInfo.mapWidth; ++j)
					m_Tile[i][j] = CTile::Create();
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

	// TILE Initialize //////////////////////////////////////////////////////////////////////////

	// 	m_MapInfo.tile = new TILE *[m_MapInfo.mapHeight];
	// 	for(int i=0;i<m_MapInfo.mapHeight; ++i)
	// 		m_MapInfo.tile[i] = new TILE[m_MapInfo.mapWidth];

	/////////////////////////////////////////////////////////////////////////////////////////////

	// Tile Info
	{
		for(int i=0; i<m_MapInfo.mapHeight; ++i)
		{
			for(int j=0; j<m_MapInfo.mapWidth; ++j)
			{
				int tileSetIndex, x, y;

				tile = "t" + std::to_string(i) + "-" + std::to_string(j);

				m_Tile[i][j]->m_isFull = m_MapXMLData->XPathToString("/map/tileInfo/" + tile + "/isFull").c_str() == "true" ? true : false;

				tileSetIndex = atoi(m_MapXMLData->XPathToString("/map/tileInfo/" + tile + "/TileImageInfo/@Index").c_str());
				x = atoi(m_MapXMLData->XPathToString("/map/tileInfo/" + tile + "/TileImageInfo/@X").c_str());
				y = atoi(m_MapXMLData->XPathToString("/map/tileInfo/" + tile + "/TileImageInfo/@Y").c_str());

				m_Tile[i][j]->m_attribute = m_MapXMLData->XPathToString("/map/tileInfo/" + tile + "/Attribute/@move").c_str() == "true" ? 1 : 0;
				m_Tile[i][j]->m_height = atoi(m_MapXMLData->XPathToString("/map/tileInfo/" + tile + "/Attribute/@height").c_str());


				m_Tile[i][j]->m_image = NNSpriteAtlas::Create(tileSetLoad[tileSetIndex]);
				m_Tile[i][j]->m_image->SetCutSize(x,y,64.f,64.f);
				m_Tile[i][j]->m_image->SetPosition(i * 64, j * 64);

				AddChild(m_Tile[i][j]->m_image);

				//m_Tile[i][j]->m_image = NNSpriteAtlas::Create();
				//m_Tile[i][j]->m_image = NNSpriteAtlas::Create()
				//temp.isFull = xml->XPathToString("/map/tileInfo/" + tile + "/isFull").c_str() == "true" ? true : false;
				{
					//m_MapInfo.tile[i][j].isFull = xml->XPathToString("/map/tileInfo/" + tile + "/TileImageInfo/@Index").c_str();
				}
			}
		}
	}


	delete tileSetLoad;
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
