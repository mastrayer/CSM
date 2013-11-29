
#pragma once

#include "NNObject.h"
#include "NNSprite.h"
#include "NNResourceManager.h"
#include "NNSpriteAtlas.h"

#define ATTRIBUTE_MOVE 0x01

class CTile : public NNObject
{
public:
	CTile();
	virtual ~CTile();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CTile);

//private:
	NNSpriteAtlas *m_image;
	int m_attribute;
	int m_height;
	bool m_isFull;
};
struct MapInfo
{
	int mapWidth, mapHeight;
	CTile **tile;
	NNSprite *image;
};

class CGameMap : public NNObject
{
public:
	CGameMap(std::wstring path);
	virtual ~CGameMap(void);
	
	void Render();
	void Update( float dTime );

	//void CreateMap(NNXML* xml, );
	void convertFileToMap(std::wstring path);

	static CGameMap* Create(std::wstring path)
	{
		CGameMap* pInstance = new CGameMap(path);
		return pInstance;
	}
	//NNCREATE_FUNC(CGameMap);


private:
	NNSprite* m_MapSprite;
	NNXML* m_MapXMLData;
	MapInfo m_MapInfo;
	CTile ***m_Tile;
};