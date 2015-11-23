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
	start = std::chrono::system_clock::now();
	canvasstore->clearScreen();
	objectstore->update();

	image.create(window_width, window_height, CanvasStore::get()->screen->getData());
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	window.draw(sprite);
	window.display();
	end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	int ms = 1000 * (((1 / (float)fps)) - elapsed_seconds.count());
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));

}