#pragma once
#include "Component.h"
class BulletSpawn :
	public Component
{
	int t = 0;
public:
	BulletSpawn();
	~BulletSpawn();
	void update(GameObject* parent);
};

