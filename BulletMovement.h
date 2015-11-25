#pragma once
#include "Component.h"
class BulletMovement :
	public Component
{
	float xVelocity = 0, yVelocity = 0;
	float xAcceleration = 0, yAcceleration = 0;
public:
	BulletMovement();
	~BulletMovement();
	void update(GameObject* parent);
	float getDirection();
	float getSpeed();
	void setMotion(float d, float s);
};

