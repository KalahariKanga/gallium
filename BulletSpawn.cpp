#include "BulletSpawn.h"
#include "GameObject.h"
#include "Object_Bullet.h"
#include "Motion.h"

BulletSpawn::BulletSpawn()
{
}


BulletSpawn::~BulletSpawn()
{
}

void BulletSpawn::update(GameObject* parent)
{
	t++;
	/*GameObject* bullet = new Object_Bullet();
	bullet->x = bullet->y = 200;
	bullet->getComponent<Motion>()->setMotion(Math::pi * -tan((float)t / 10), 2);
	parent->createInstance(bullet);
	bullet = new Object_Bullet();
	bullet->x = bullet->y = 200;
	bullet->getComponent<Motion>()->setMotion(Math::pi * tan((float)t / 10), 2);
	parent->createInstance(bullet);*/
}

void BulletSpawn::spawn(Vector p, Vector v, Vector a)
{
	GameObject* bullet = new Object_Bullet();
	bullet->position = p;
	bullet->getComponent<Motion>()->setVelocity(v);
	bullet->getComponent<Motion>()->setAcceleration(a);
}
