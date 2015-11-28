#pragma once
#include "GameObject.h"
class Object_Pattern1 :
	public GameObject
{
	std::vector<Vector> spawnPos;
public:
	Object_Pattern1();
	~Object_Pattern1();
	virtual void step();
};

