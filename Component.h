#pragma once
#include "sfml/graphics.hpp"
#include "Vector.h"
class GameObject;

class Component
{
public:
	Component();
	~Component();
	virtual void update(GameObject* parent) = 0;
};

