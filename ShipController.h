#pragma once
#include "Component.h"
class ShipController :
	public Component
{
	float speed = 4;
	sf::Keyboard::Key upKey, downKey, leftKey, rightKey, fireKey;
public:
	ShipController();
	~ShipController();
	void update(GameObject* parent);
};

