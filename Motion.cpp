#include "Motion.h"
#include "GameObject.h"

Motion::Motion()
{
}


Motion::~Motion()
{
}

void Motion::setVelocity(Vector v)
{
	velocity = v;
}

void Motion::setAcceleration(Vector a)
{
	acceleration = a;
}

void Motion::update(GameObject* parent)
{
	velocity = velocity + acceleration;
	parent->position = parent->position + velocity;
}