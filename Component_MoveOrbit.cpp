#include "Component_MoveOrbit.h"
#include "GameObject.h"

Component_MoveOrbit::Component_MoveOrbit()
{
}


Component_MoveOrbit::~Component_MoveOrbit()
{
}

void Component_MoveOrbit::update(GameObject* parent)
{
	static int t = 0;
	t++;
	parent->x += sin((float)t / 100);
	parent->y += cos((float)t / 100);
}