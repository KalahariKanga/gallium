#pragma once
#include "sfml/graphics.hpp"
#include "ObjectStore.h"

class Game
{
	sf::RenderWindow window;
public:
	Game();
	~Game();

	ObjectStore objectstore;

	void update();
};

