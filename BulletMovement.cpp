#include "BulletMovement.h"
#include "GameObject.h"

BulletMovement::BulletMovement()
{
}


BulletMovement::~BulletMovement()
{
}

float BulletMovement::getDirection()
{
	return atan2(yVelocity, xVelocity);
}

float BulletMovement::getSpeed()
{
	return sqrt(xVelocity*xVelocity + yVelocity*yVelocity);
}

void BulletMovement::setMotion(float d, float s)
{
	xVelocity = s*sin(d);
	yVelocity = s*cos(d);
}

void BulletMovement::update(GameObject* parent)
{
	xVelocity += xAcceleration;
	yVelocity += yAcceleration;
	parent->x += xVelocity;
	parent->y += yVelocity;
}