#include "ShipBulletMovement.h"
#include "GameObject.h"
#include "ObjectStore.h"

ShipBulletMovement::ShipBulletMovement()
{
}


ShipBulletMovement::~ShipBulletMovement()
{
}

void ShipBulletMovement::update(GameObject* parent)
{
	parent->position = parent->position - Vector(0,-speed);
	if (parent->position.getY() < 100)
		parent->destroyInstance();
}