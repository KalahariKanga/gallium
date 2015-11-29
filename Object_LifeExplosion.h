#pragma once
#include "GameObject.h"
class Object_LifeExplosion :
	public GameObject
{
	int countNeighbours(int x, int y);
public:
	Object_LifeExplosion();
	~Object_LifeExplosion();
	virtual void step();
};

