#pragma once
#include "GameObject.h"
class Object_Ship :
	public GameObject
{
public:
	Object_Ship();
	~Object_Ship();
	virtual void update();
};

