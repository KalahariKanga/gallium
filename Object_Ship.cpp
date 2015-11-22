#include "Object_Ship.h"
#include "ShipController.h"
#include "BigPixelArray.h"

Object_Ship::Object_Ship()
{
	components.push_back(new ShipController());
	components.push_back(new BigPixelArray());
	getComponent<BigPixelArray>()->loadFromFile("C:\\Users\\David\\Pictures\\greencircle.png");
	x = y = 200;
}


Object_Ship::~Object_Ship()
{
}