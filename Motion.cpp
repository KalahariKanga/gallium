#include "Motion.h"
#include "GameObject.h"

Motion::Motion()
{
}


Motion::~Motion()
{
}

float Motion::getDirection()
{
	return atan2(yVelocity, xVelocity);
}

float Motion::getSpeed()
{
	return sqrt(xVelocity*xVelocity + yVelocity*yVelocity);
}

void Motion::setMotion(float d, float s)
{
	xVelocity = s*sin(d);
	yVelocity = s*cos(d);
}

void Motion::update(GameObject* parent)
{
	xVelocity += xAcceleration;
	yVelocity += yAcceleration;
	parent->x += xVelocity;
	parent->y += yVelocity;
}