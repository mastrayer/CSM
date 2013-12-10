
#pragma once

#include "NNObject.h"
#include "NNSprite.h"
#include "NNResourceManager.h"
#include "NNSpriteAtlas.h"

#define ATTRIBUTE_MOVE 0x01
#define TILESIZE 64

class CTile : public NNObject
{
public:
	CTile();
	virtual ~CTile();

	void Init(){}
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CTile);

private:
	NNSpriteAtlas *mimage;
	int mattribute;
	int mheight;
	bool misFull;

	friend class CGameMap;
};
class CGameMap : public NNObject
{
public:
	CGameMap(std::wstring path);
	virtual ~CGameMap(void);
	
	int GetAttribute(int i, int j) { return mTile[i][j]->mattribute; }
	int SetAttribute(int i, int j, int value) { mTile[i][j]->mattribute = value; }
	bool isValidTile(NNPoint p);

	void Init(){}
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
	NNSprite* mMapSprite;
	NNXML* mMapXMLData;
	CTile ***mTile;
	int mWidth, mHeight;

protected:
	NNPoint positionToArrayIndex( NNPoint p );
};