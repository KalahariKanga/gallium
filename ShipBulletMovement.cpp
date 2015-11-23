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
	parent->y -= speed;
	if (parent->y < 100)
		parent->destroyInstance();
}