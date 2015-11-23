#include "SFML/graphics.hpp"
#include "Game.h"
#include "Object_Ship.h"
#include <iostream>

int main(int argc, char* argv[])
{
	#ifndef NDEBUG
		srand(time(0));
	#endif
	Game game;
	ObjectPtr i = new Object_Ship();
	game.objectstore->createInstance(i);
	while (1)
		game.update();

	return 0;
}