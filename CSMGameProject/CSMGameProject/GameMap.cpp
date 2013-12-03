#include "GameMap.h"
#include"iostream"

CGameMap::CGameMap(std::wstring path)
{
	if(INVALID_FILE_ATTRIBUTES == GetFileAttributes(path.c_str()) && GetLastError()==ERROR_FILE_NOT_FOUND)
	{
		printf("File Not Exist!\n");
		return;
	}

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

void en(int b)
{
	static int c = 0;
	printf("%d] %d\n",c++, GetTickCount()-b);
}
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

	printf("################# MapInfo \n");
	// MapInfo
	{
		// Map Size
		{
			m_Width = atoi(m_MapXMLData->XPathToString("/map/mapInfo/size/@width").c_str());
			m_Height = atoi(m_MapXMLData->XPathToString("/map/mapInfo/size/@height").c_str());

			m_Tile = new CTile**[m_Height];
			for(int i=0;i<m_Height; ++i)
			{
				m_Tile[i] = new CTile *[m_Width];
				for( int j=0; j< m_Width; ++j)
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
	printf("################# /MapInfo \n");

	// TILE Initialize //////////////////////////////////////////////////////////////////////////

	// 	m_MapInfo.tile = new TILE *[m_MapInfo.mapHeight];
	// 	for(int i=0;i<m_MapInfo.mapHeight; ++i)
	// 		m_MapInfo.tile[i] = new TILE[m_MapInfo.mapWidth];

	/////////////////////////////////////////////////////////////////////////////////////////////

	printf("################# TileInfo \n");
	// Tile Info
	{
		TiXmlHandle docHandle( m_MapXMLData->GetDoc() );
		TiXmlElement* child = docHandle.FirstChild( "map" ).FirstChild( "tileInfo").FirstChild("tile").ToElement();

		for( child; child; child=child->NextSiblingElement() )
		{
			int i = atoi(child->Attribute("Y"));
			int j = atoi(child->Attribute("X"));
			int tileSetIndex, x, y;
			TiXmlElement* tileImageInfo = child->FirstChild("TileImageInfo")->ToElement();
			x = atoi(tileImageInfo->Attribute("X"));
			y = atoi(tileImageInfo->Attribute("Y"));
			tileSetIndex = atoi(tileImageInfo->Attribute("Index"));
			m_Tile[i][j]->m_isFull = strcmp(child->Attribute("isFull"), "true") == 0 ? true : false;
			TiXmlElement* tileAttribute = child->FirstChild("Attribute")->ToElement();
			m_Tile[i][j]->m_attribute = strcmp(tileAttribute->Attribute("move") , "true") == 0 ? 1 : 0;
			m_Tile[i][j]->m_height = atoi(tileAttribute->Attribute("height"));
			printf("%d / %d\n",i,j);

			m_Tile[i][j]->m_image = NNSpriteAtlas::Create(tileSetLoad[tileSetIndex]);
			AddChild(m_Tile[i][j]->m_image);

			assert(y+64<=256);
			assert(x+64<=128);


			m_Tile[i][j]->m_image->SetCutSize((float)y, (float)x, y + 64.f, x + 64.f);

			m_Tile[i][j]->m_image->SetPosition(i*64.f, j*64.f);
		}
		/*
		for(int i=0; i<m_Height; ++i)
		//for(int i=0; i<2; ++i)
		{
		for(int j=0; j<m_Width; ++j)
		//for(int j=0; j<2; ++j)
		{
		//printf("[%d/%d] ",i,j);
		int tileSetIndex, x, y;

		tile = "t" + std::to_string(i) + "-" + std::to_string(j);

		a = GetTickCount();
		m_Tile[i][j]->m_isFull = strcmp(m_MapXMLData->XPathToString("/map/tileInfo/tile[@Y=\"" + std::to_string(i) +"\" and @X=\"" + std::to_string(j) + "\"]/@isFull").c_str(), "true") == 0 ? true : false;
		en(a);

		a = GetTickCount();
		tileSetIndex = atoi(m_MapXMLData->XPathToString("/map/tileInfo/tile[@Y=\"" + std::to_string(i) + "\" and @X=\"" + std::to_string(j) + "\"]/TileImageInfo/@Index").c_str());
		en(a);

		a = GetTickCount();
		x = atoi(m_MapXMLData->XPathToString("/map/tileInfo/tile[@Y=\"" + std::to_string(i) + "\" and @X=\"" + std::to_string(j) + "\"]/TileImageInfo/@X").c_str());
		en(a);

		a = GetTickCount();
		y = atoi(m_MapXMLData->XPathToString("/map/tileInfo/tile[@Y=\"" + std::to_string(i) + "\" and @X=\"" + std::to_string(j) + "\"]/TileImageInfo/@Y").c_str());
		en(a);

		a = GetTickCount();
		m_Tile[i][j]->m_attribute = strcmp(m_MapXMLData->XPathToString("/map/tileInfo/tile[@Y=\"" + std::to_string(i) + "\" and @X=\"" + std::to_string(j) + "\"]/Attribute/@move").c_str() , "true") == 0 ? 1 : 0;
		en(a);

		a = GetTickCount();
		m_Tile[i][j]->m_height = atoi(m_MapXMLData->XPathToString("/map/tileInfo/tile[@Y=\"" + std::to_string(i) + "\" and @X=\"" + std::to_string(j) + "\"]/Attribute/@height").c_str());
		en(a);


		printf("[%d/%d] (%0.f-%0.f)(%0.f-%0.f) \n",i,j,y + 0.f,y+64.f,x + 0.f,x+64.f);
		m_Tile[i][j]->m_image = NNSpriteAtlas::Create(tileSetLoad[tileSetIndex]);
		AddChild(m_Tile[i][j]->m_image);

		assert(y+64<=256);
		assert(x+64<=128);

		m_Tile[i][j]->m_image->SetCutSize(y, x, y + 64, x + 64);
		//m_Tile[i][j]->m_image->SetCutSize(192, 64, 192 + 64.f, 64+64.f);

		m_Tile[i][j]->m_image->SetPosition(i*64, j*64);
		}
		}*/
	}
	printf("################# / TileInfo \n");


	delete tileSetLoad;
}

NNPoint CGameMap::positionToArrayIndex( NNPoint p )
{
	p.SetX( p.GetX() / TILESIZE );
	p.SetY( p.GetY() / TILESIZE );

	return p;
}
bool CGameMap::isValidTile( NNPoint p )
{
	NNPoint temp = positionToArrayIndex(p);
	int i = (int)temp.GetX();
	int j = (int)temp.GetY();

	CTile *tile = m_Tile[i][j];

	// 이 타일이 빈 타일이거나
	// 움직일 수 없는 타일이거나
	if(tile->m_isFull == false ||
		tile->m_attribute & ATTRIBUTE_MOVE )
		return false;

	return true;
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
