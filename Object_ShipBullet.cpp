#include "Object_ShipBullet.h"
#include "BigPixelArray.h"

Object_ShipBullet::Object_ShipBullet()
{
	components.push_back(new BigPixelArray());
	getComponent<BigPixelArray>()->loadFromFile("res\\shipbullet.png");
}


Object_ShipBullet::~Object_ShipBullet()
{
}
