#include "SFML/graphics.hpp"
#include "Game.h"
#include "Object_Ship.h"
#include "Object_Pattern1.h"
#include <iostream>

int main(int argc, char* argv[])
{
	#ifndef NDEBUG
		srand(time(0));
	#endif
	Game game;
	ObjectPtr i = new Object_Ship();
	ObjectPtr j = new Object_Pattern1();
	game.objectstore->createInstance(i);
	game.objectstore->createInstance(j);
	while (1)
		game.update();

	return 0;
}