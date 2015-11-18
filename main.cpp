#include "SFML/graphics.hpp"
#include "Game.h"
#include <iostream>

int main(int argc, char* argv[])
{
	Game game;
	ObjectPtr i = std::make_shared<GameObject>();
	game.objectstore.createInstance(i);
	game.objectstore.update();
	game.objectstore.destroyInstance(i);
	game.objectstore.update();


	return 0;
}