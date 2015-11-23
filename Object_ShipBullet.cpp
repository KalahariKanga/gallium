#include "Object_ShipBullet.h"
#include "BigPixelArray.h"
#include "ShipBulletMovement.h"

Object_ShipBullet::Object_ShipBullet()
{
	components.push_back(new BigPixelArray());
	components.push_back(new ShipBulletMovement());
	getComponent<BigPixelArray>()->loadFromFile("res\\shipbullet.png");
}


Object_ShipBullet::~Object_ShipBullet()
{
}
