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

	// 	mMapSprite = NNSprite::Create( L"Sprite/map.png" );
	// 	mMapSprite->SetPosition( 0.f, 0.f );
	//  AddChild( mMapSprite );
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
	mMapXMLData= NNResourceManager::GetInstance()->LoadXMLFromMemory(xmlLoad);

	std::string tile;
	int usedTileSet = 0;

	printf("################# MapInfo \n");
	// MapInfo
	{
		// Map Size
		{
			mWidth = atoi(mMapXMLData->XPathToString("/map/mapInfo/size/@width").c_str());
			mHeight = atoi(mMapXMLData->XPathToString("/map/mapInfo/size/@height").c_str());

			mTile = new CTile**[mHeight];
			for(int i=0;i<mHeight; ++i)
			{
				mTile[i] = new CTile *[mWidth];
				for( int j=0; j< mWidth; ++j)
					mTile[i][j] = CTile::Create();
			}
		}
		// Used Tile Set
		{
			usedTileSet = atoi(mMapXMLData->XPathToString("/map/mapInfo/usedTileSet/@count").c_str());
			tileSetLoad = new NNZip*[usedTileSet];

			for(int i=0; i<usedTileSet; ++i)
				tileSetLoad[i] = NNResourceManager::GetInstance()->UnzipFileToMemory(path, FILENAME[1] + std::to_wstring(i));
		}
	}
	printf("################# /MapInfo \n");

	// TILE Initialize //////////////////////////////////////////////////////////////////////////

	// 	mMapInfo.tile = new TILE *[mMapInfo.mapHeight];
	// 	for(int i=0;i<mMapInfo.mapHeight; ++i)
	// 		mMapInfo.tile[i] = new TILE[mMapInfo.mapWidth];

	/////////////////////////////////////////////////////////////////////////////////////////////

	printf("################# TileInfo \n");
	// Tile Info
	{
		TiXmlHandle docHandle( mMapXMLData->GetDoc() );
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
			mTile[i][j]->misFull = strcmp(child->Attribute("isFull"), "true") == 0 ? true : false;
			TiXmlElement* tileAttribute = child->FirstChild("Attribute")->ToElement();
			mTile[i][j]->mattribute = strcmp(tileAttribute->Attribute("move") , "true") == 0 ? 1 : 0;
			mTile[i][j]->mheight = atoi(tileAttribute->Attribute("height"));
			printf("%d / %d\n",i,j);

			mTile[i][j]->mimage = NNSpriteAtlas::Create(tileSetLoad[tileSetIndex]);
			AddChild(mTile[i][j]->mimage);

			assert(y+64<=256);
			assert(x+64<=128);


			mTile[i][j]->mimage->SetCutSize((float)y, (float)x, y + 64.f, x + 64.f);

			mTile[i][j]->mimage->SetPosition(i*64.f, j*64.f);
		}
		/*
		for(int i=0; i<mHeight; ++i)
		//for(int i=0; i<2; ++i)
		{
		for(int j=0; j<mWidth; ++j)
		//for(int j=0; j<2; ++j)
		{
		//printf("[%d/%d] ",i,j);
		int tileSetIndex, x, y;

		tile = "t" + std::to_string(i) + "-" + std::to_string(j);

		a = GetTickCount();
		mTile[i][j]->misFull = strcmp(mMapXMLData->XPathToString("/map/tileInfo/tile[@Y=\"" + std::to_string(i) +"\" and @X=\"" + std::to_string(j) + "\"]/@isFull").c_str(), "true") == 0 ? true : false;
		en(a);

		a = GetTickCount();
		tileSetIndex = atoi(mMapXMLData->XPathToString("/map/tileInfo/tile[@Y=\"" + std::to_string(i) + "\" and @X=\"" + std::to_string(j) + "\"]/TileImageInfo/@Index").c_str());
		en(a);

		a = GetTickCount();
		x = atoi(mMapXMLData->XPathToString("/map/tileInfo/tile[@Y=\"" + std::to_string(i) + "\" and @X=\"" + std::to_string(j) + "\"]/TileImageInfo/@X").c_str());
		en(a);

		a = GetTickCount();
		y = atoi(mMapXMLData->XPathToString("/map/tileInfo/tile[@Y=\"" + std::to_string(i) + "\" and @X=\"" + std::to_string(j) + "\"]/TileImageInfo/@Y").c_str());
		en(a);

		a = GetTickCount();
		mTile[i][j]->mattribute = strcmp(mMapXMLData->XPathToString("/map/tileInfo/tile[@Y=\"" + std::to_string(i) + "\" and @X=\"" + std::to_string(j) + "\"]/Attribute/@move").c_str() , "true") == 0 ? 1 : 0;
		en(a);

		a = GetTickCount();
		mTile[i][j]->mheight = atoi(mMapXMLData->XPathToString("/map/tileInfo/tile[@Y=\"" + std::to_string(i) + "\" and @X=\"" + std::to_string(j) + "\"]/Attribute/@height").c_str());
		en(a);


		printf("[%d/%d] (%0.f-%0.f)(%0.f-%0.f) \n",i,j,y + 0.f,y+64.f,x + 0.f,x+64.f);
		mTile[i][j]->mimage = NNSpriteAtlas::Create(tileSetLoad[tileSetIndex]);
		AddChild(mTile[i][j]->mimage);

		assert(y+64<=256);
		assert(x+64<=128);

		mTile[i][j]->mimage->SetCutSize(y, x, y + 64, x + 64);
		//mTile[i][j]->mimage->SetCutSize(192, 64, 192 + 64.f, 64+64.f);

		mTile[i][j]->mimage->SetPosition(i*64, j*64);
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

	CTile *tile = mTile[i][j];

	// 이 타일이 빈 타일이거나
	// 움직일 수 없는 타일이거나
	if(tile->misFull == false ||
		tile->mattribute & ATTRIBUTE_MOVE )
		return false;

	return true;
}

//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////                            /////////////////////////////
/////////////////////////////           CTile            /////////////////////////////
/////////////////////////////                            /////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

CTile::CTile()
	: mattribute(0), mheight(0), mimage(nullptr), misFull(false)
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
