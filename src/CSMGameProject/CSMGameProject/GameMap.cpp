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

	// 	mMapSprite = NNSprite::Create( L"Resource/Sprite/map.png" );
	// 	mMapSprite->SetPosition( 0.f, 0.f );
	//  AddChild( mMapSprite );
}

CGameMap::~CGameMap(void)
{
	for (int i=0; i<mHeight; i++ )
		delete[] mTile[i];
	delete[] mTile;
}

void CGameMap::Update( float dTime )
{
	NNObject::Update( dTime );
}

void CGameMap::Render()
{
	NNObject::Render();
}
NNAnimation *CGameMap::CreateBarrackGate(TileType type)
{
	NNAnimation *Gate = NNAnimation::Create();
	std::wstring path = L"Resource/Sprite/Barrack/";

	switch (type)
	{
	case BARRACK_A:
		path += L"FireBarrack/";
		break;
	case BARRACK_B:
		path += L"WaterBarrack/";
		break;
	case BARRACK_C:
		path += L"WindBarrack/";
		break;
	case BARRACK_D:
		path += L"SandBarrack/";
		break;
	default:
		delete Gate;
		return nullptr;
	}
	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 20; i++)
	{
		wsprintf(temp, L"%s%d.png", path.c_str(), i);

		Gate->AddFrameNode(temp);
	}
	Gate->SetFrameTimeInSection(0.03f, 0, 19);
	
	return Gate;
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
			x = atoi(tileImageInfo->Attribute("Y")); 
			y = atoi(tileImageInfo->Attribute("X"));
			tileSetIndex = atoi(tileImageInfo->Attribute("Index"));
			mTile[i][j]->misFull = strcmp(child->Attribute("isFull"), "true") == 0 ? true : false;
			TiXmlElement* tileAttribute = child->FirstChild("Attribute")->ToElement();
			mTile[i][j]->mattribute = strcmp(tileAttribute->Attribute("move") , "true") == 0 ? 1 : 0;
			mTile[i][j]->mheight = atoi(tileAttribute->Attribute("height"));
			printf("%d / %d\n",i,j);

			TiXmlElement* tileObject = child->FirstChild("Object")->ToElement();

			mTile[i][j]->mimage = NNSpriteAtlas::Create(tileSetLoad[tileSetIndex]);
			mTile[i][j]->AddChild(mTile[i][j]->mimage);
			AddChild(mTile[i][j]);

			mTile[i][j]->mimage->SetCutSize((float)y, (float)x, y + 64.f, x + 64.f);

			mTile[i][j]->mimage->SetPosition(j*64.f, i*64.f);

			std::string temp = tileObject->Attribute("Type");


			if ( temp == "Tile" )
				mTile[i][j]->mType = TILE;
			else if (temp == "Barrack A In")
				mTile[i][j]->mType = BARRACK_A;
			else if ( temp == "Barrack B In" )
				mTile[i][j]->mType = BARRACK_B;
			else if ( temp == "Barrack C In" )
				mTile[i][j]->mType = BARRACK_C;
			else if ( temp == "Barrack D In" )
				mTile[i][j]->mType = BARRACK_D;
			else if ( temp == "Barrack Out" )
				mTile[i][j]->mType = BARRACK_OUT;
			else if ( temp == "A Team Starting Point" )
				mTile[i][j]->mType = STARTING_POINT_A;
			else if ( temp == "B Team Starting Point" )
				mTile[i][j]->mType = STARTING_POINT_B;

			NNAnimation *Gate = CreateBarrackGate(mTile[i][j]->mType);
			if (Gate != nullptr)
			{
				Gate->SetPosition(j*64.f, i*64.f);
				AddChild(Gate);
			}
		}
	}

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
