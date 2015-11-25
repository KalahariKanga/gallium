#include "Object_Bullet.h"
#include "BigPixelArray.h"
#include "BulletMovement.h"

Object_Bullet::Object_Bullet()
{
	components.push_back(new BigPixelArray(4));
	components.push_back(new BulletMovement());
	getComponent<BulletMovement>()->setMotion(Math::random(0, 2 * Math::pi), 2);
	getComponent<BigPixelArray>()->loadFromFile("res\\shipbullet.png");
	x = y = 200;
}


Object_Bullet::~Object_Bullet()
{
}
