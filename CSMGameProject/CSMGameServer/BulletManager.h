#pragma once
#include <map>
#include "Bullet.h"
#include "PlayerManager.h"
#define DETECT_POINT 100

struct DetectPlatePoint
{
	int x, y;
};
class BulletManager
{
public:
	BulletManager(void);
	~BulletManager(void);

	void AddBullet(Bullet* bullet);
	void DeleteBullet(Bullet* bullet);
	void Update(float dTime);

private:
	int GenerateBulletNumber();

private:
	int mTime;
	std::map<int, Bullet*>mBullets;
	std::map<DetectPlatePoint,Player*>mDetectPlate;
};

extern BulletManager* GBulletManager;