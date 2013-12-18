#include "stdafx.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "EllipseCollisionTest.h"
Bullet::Bullet(Player* ownerPlayer):mShape(CIRCLE),mVelocity(0),mAcceleraction(0),mAngle(0),mLifeTime(-1),mRotation(0),mPosition(Point()),mOnwerPlayer(ownerPlayer),mDamage(0),mRadius(0),mXRadius(0),mYRadius(0),mWidth(0),mHeight(0),mCenter(Point(0,0)),mNumber(-1)
{
	GBulletManager->AddBullet(this);
	printf("oh\n");
}


Bullet::~Bullet(void)
{
}

void Bullet::Update(float dTime)
{
	mLifeTime -= dTime;

	mPosition = mPosition + Point( cos(mAngle) * mVelocity , sin(mAngle) * mVelocity ) * dTime;

	mVelocity = mVelocity + mAcceleraction * dTime;
	printf("%.f %.f\n",mPosition.x,mPosition.y);
}

void Bullet::JudgeCollision(Player* player)
{
	if( isLive() == true )
	{
		if(player->GetTeam() != mOnwerPlayer->GetTeam())
		{
			switch (mShape)
			{
			case CIRCLE:
				{
					if( Point().Distance(mPosition,player->GetPosition()) < mRadius + player->GetRadius() )
					{
						Hit(player, mOnwerPlayer);
					}
				}
				break;
			case ELLIPSE:
				{
					EllipseCollisionTest ellipseCollisionTest(10);
					if(ellipseCollisionTest.collide(mPosition.x, mPosition.y, cos(mRotation) * mXRadius, sin(mRotation) * mXRadius, mYRadius,
						player->GetPosition().x, player->GetPosition().y,player->GetRadius(),0,player->GetRadius() ) == true)
					{
						Hit(player, mOnwerPlayer);
					}
				}
				break;
			case RECTANGLE:
				{
					Point circlePoints[32];
					for( int i=0; i<32; i++)
					{
						circlePoints[i] = Point(cos(i*3.14f/32*2) * player->GetRadius(),sin(i*3.14f/32*2) * player->GetRadius());
					}
					Point rectanglePoints[4];
					rectanglePoints[0] = Point( mPosition.x - mCenter.x, mPosition.y - mCenter.y );
					rectanglePoints[1] = Point( mPosition.x - mCenter.x, mPosition.y - mCenter.y + mHeight );
					rectanglePoints[2] = Point( mPosition.x - mCenter.x + mWidth, mPosition.y - mCenter.y + mHeight );
					rectanglePoints[3] = Point( mPosition.x - mCenter.x + mWidth, mPosition.y + mCenter.y );
					if(PolyCollisionTest(circlePoints,32,rectanglePoints,4) == true)
					{
					}
				}
				break;
			case POLY:
				{
					Point circlePoints[32];
					for( int i=0; i<32; i++)
					{
						circlePoints[i] = Point(cos(i*3.14f/32*2) * player->GetRadius(),sin(i*3.14f/32*2) * player->GetRadius());
					}
					if(PolyCollisionTest(circlePoints,32,mPoints,mPointCount) == true)
					{
						Hit(player, mOnwerPlayer);
					}
				}
				break;
			default:
				break;
			}
		}
	}
}
bool Bullet::isLive()
{
	if(mLifeTime >= 0) return true;
	return false;
}


bool Bullet::PolyCollisionTest(Point* APoints, int ACounts, Point* BPoints, int BCounts)
{
	bool isCollide = true;
	for( int i = 0; i<ACounts; i++)
	{
		Point axis = APoints[i] - APoints[(i+1)%ACounts];
		Point normalAxis = Point().Rotate(axis,3.14/2);
		float theta = atan2(normalAxis.y,normalAxis.x);
		float AMaxX = 0;
		float AMinX = 0;
		float BMaxX = 0;
		float BMinX = 0;
		for( int q = 0; q < ACounts; q++)
		{
			float x_ = cos(theta) * APoints[q].x + sin(theta) * APoints[q].y;
			AMaxX = AMaxX < x_ ? x_ : AMaxX;
			AMinX = AMinX < x_ ? x_ : AMinX;
		}
		for( int q = 0; q < BCounts; q++)
		{
			float x_ = cos(theta) * BPoints[q].x + sin(theta) * BPoints[q].y;
			BMaxX = BMaxX < x_ ? x_ : BMaxX;
			BMinX = BMinX < x_ ? x_ : BMinX;
		}
		if( (AMaxX - AMinX) * (AMaxX - BMinX) * (BMaxX - AMinX) * (BMaxX - BMinX) < 0)
		{
			isCollide = false;
			break;
		}
	}
	return isCollide;
}

void Bullet::Hit(Player* victimPlayer, Player* attackerPlayer)
{
	victimPlayer->Damaged(mDamage, attackerPlayer);
	mLifeTime = -1;
}