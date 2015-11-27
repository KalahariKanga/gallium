#include "ShipController.h"
#include "GameObject.h"
#include "ObjectStore.h"
#include "Object_ShipBullet.h"
#include "Object_Bullet.h"

ShipController::ShipController()
{
	upKey = sf::Keyboard::Up;
	downKey = sf::Keyboard::Down;
	leftKey = sf::Keyboard::Left;
	rightKey = sf::Keyboard::Right;
	fireKey = sf::Keyboard::Z;
}


ShipController::~ShipController()
{
}

void ShipController::update(GameObject* parent)
{	
	if (sf::Keyboard::isKeyPressed(upKey))
	{
		parent->position += Vector(0, -speed);
	}
	if (sf::Keyboard::isKeyPressed(downKey))
	{
		parent->position += Vector(0, speed);
	}
	if (sf::Keyboard::isKeyPressed(leftKey))
	{
		parent->position += Vector(-speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(rightKey))
	{
		parent->position += Vector(speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(fireKey))
	{
		GameObject* bullet = new Object_ShipBullet();
		bullet->position = parent->position;
		ObjectStore::get()->createInstance(bullet);
	}
}