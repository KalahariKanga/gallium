#include "ShipController.h"
#include "GameObject.h"
#include "ObjectStore.h"
#include "Object_ShipBullet.h"

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
		parent->y -= speed;
	}
	if (sf::Keyboard::isKeyPressed(downKey))
	{
		parent->y += speed;
	}
	if (sf::Keyboard::isKeyPressed(leftKey))
	{
		parent->x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(rightKey))
	{
		parent->x += speed;
	}
	if (sf::Keyboard::isKeyPressed(fireKey))
	{
		GameObject* bullet = new Object_ShipBullet();
		bullet->x = parent->x;
		bullet->y = parent->y;
		ObjectStore::get()->createInstance(bullet);
	}
}