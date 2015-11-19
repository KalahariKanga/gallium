#include "Game.h"


Game::Game()
{
	canvasstore->screen = canvasstore->addCanvas("screen", window_width, window_height);
	canvasstore->clearScreen();
	window.create(sf::VideoMode(window_width, window_height), "gallium");
}


Game::~Game()
{
}

void Game::update()
{
	canvasstore->clearScreen();
	objectstore.update();

	image.create(window_width, window_height, CanvasStore::get()->screen->getData());
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	window.draw(sprite);
	window.display();
}