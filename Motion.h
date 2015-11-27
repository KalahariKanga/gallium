#pragma once
#include "Component.h"
class Motion :
	public Component
{
	Vector velocity;
	Vector acceleration;
public:
	Motion();
	~Motion();
	void update(GameObject* parent);
	float getDirection();
	float getSpeed();
	void setVelocity(Vector v);
	void setAcceleration(Vector a);
};

