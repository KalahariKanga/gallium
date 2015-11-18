#include "SFML/graphics.hpp"
#include "Game.h"
#include "Object_Ship.h"
#include <iostream>

int main(int argc, char* argv[])
{
	Game game;
	ObjectPtr i = std::make_shared<Object_Ship>();
	game.objectstore.createInstance(i);
	while (1)
		game.update();

	return 0;
}