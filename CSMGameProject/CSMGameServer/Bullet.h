#pragma once
#include "Player.h"
enum SHAPE
{
	CIRCLE = 0,
	ELLIPSE = 1,
	RECTANGLE = 2,
	POLY = 3,
};
class Bullet
{
public:
	Bullet(Player* ownerPlayer);
	~Bullet(void);

	void SetPosition(Point point){ mPosition = point; }
	void SetVelocity(float velo){ mVelocity = velo; }
	void SetAcceleration(float acc){ mAcceleraction = acc; }
	void SetAngle(float angle){ mAngle = angle; }
	void SetLifeTime(float time){ mLifeTime = time; }

	void SetShape(SHAPE shape){ mShape = shape; }
	void SetRadius(float radius){ mRadius = radius; }
	void SetEllipseRadius(float xR, float yR){ mXRadius = xR, mYRadius = yR; }
	void SetRect(float width, float height, Point center){ mWidth = width, mHeight = height, mCenter = center; }
	void SetBulletNumber(int number){ mNumber = number; } 
	void SetPoly(Point* points, int counts){ memcpy(mPoints, points,counts), mPointCount = counts; }

	void Update(float dTime);
	void JudgeCollision(Player* player);
	bool isLive();

	SHAPE GetShape(){ return mShape; }
	Point GetPosition(){ return mPosition; }
	Point GetCenter(){ return mCenter; }
	float GetRadius(){ return mRadius; }
	float GetRotation(){ return mRotation; }
	float GetXRadius(){ return mXRadius; }
	float GetYRadius(){ return mYRadius; }
	float GetWidth(){ return mWidth; }
	float GetHeight(){ return mHeight; }
	int GetBulletNumber(){ return mNumber; }

	
	bool PolyCollisionTest(Point* APoints, int ACounts, Point* BPoints, int BCounts);

private:
	Point mPoints[64];
	int mPointCount;
	SHAPE mShape;
	int mNumber;

	float mVelocity;
	float mAcceleraction;
	float mAngle;
	float mLifeTime;
	float mRotation;

	Point mPosition;
	Point mCenter;

	Player* mOnwerPlayer;

	int mDamage;

	// CIRCLE
	float mRadius;

	// ELLIPSE
	float mXRadius;
	float mYRadius;

	// RECT
	float mWidth;
	float mHeight;
};

