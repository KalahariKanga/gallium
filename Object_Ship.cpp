#include "Object_Ship.h"
#include "Component_MoveOrbit.h"
#include "Component_Render.h"

Object_Ship::Object_Ship()
{
	components.push_back(new Component_MoveOrbit());
	components.push_back(new Component_Render());
	x = y = 200;
}


Object_Ship::~Object_Ship()
{
}