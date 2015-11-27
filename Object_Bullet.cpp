#include "Object_Bullet.h"
#include "BigPixelArray.h"
#include "Motion.h"

Object_Bullet::Object_Bullet()
{
	components.push_back(new BigPixelArray(4));
	components.push_back(new Motion());
	Vector velocity;
	velocity.setPolar(2, Math::random(0, 2 * Math::pi));
	getComponent<Motion>()->setVelocity(velocity);
	getComponent<BigPixelArray>()->loadFromFile("res\\shipbullet.png");
	position.setXY(200,200);
}


Object_Bullet::~Object_Bullet()
{
}
