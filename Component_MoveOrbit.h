#pragma once
#include "Component.h"
class Component_MoveOrbit :
	public Component
{
public:
	Component_MoveOrbit();
	~Component_MoveOrbit();
	void update(GameObject* parent);
};

