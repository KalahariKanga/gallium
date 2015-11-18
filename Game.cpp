#include "Game.h"


Game::Game()
{
	CanvasStore::get()->screen = CanvasStore::get()->addCanvas("screen", window_width, window_height);
	window.create(sf::VideoMode(window_width, window_height), "gallium");
}


Game::~Game()
{
}

void Game::update()
{
	objectstore.update();

	image.create(window_width, window_height, CanvasStore::get()->screen->getData());
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	window.draw(sprite);
	window.display();
}