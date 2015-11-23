#pragma once
#include "Component.h"
class ShipBulletMovement :
	public Component
{
	float speed = 3;
public:
	ShipBulletMovement();
	~ShipBulletMovement();
	void update(GameObject* parent);
};

