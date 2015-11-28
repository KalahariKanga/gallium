#include "Object_Ship.h"
#include "ShipController.h"
#include "BigPixelArray.h"
#include "BulletSpawn.h"

Object_Ship::Object_Ship()
{
	components.push_back(new ShipController());
	components.push_back(new BigPixelArray(2));
	//obviously very dumb
	//make loadFromCanvas
	getComponent<BigPixelArray>()->loadFromFile("res\\ship.png");
	position.setXY(200, 200);
}


Object_Ship::~Object_Ship()
{
}