#include "ShipController.h"
#include "GameObject.h"

ShipController::ShipController()
{
	upKey = sf::Keyboard::Up;
	downKey = sf::Keyboard::Down;
	leftKey = sf::Keyboard::Left;
	rightKey = sf::Keyboard::Right;
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
}