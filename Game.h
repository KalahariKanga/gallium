#pragma once
#include "sfml/graphics.hpp"
#include "ObjectStore.h"
#include "CanvasStore.h"
class Game
{
	sf::RenderWindow window;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Image image;
	const int window_width = 800;
	const int window_height = 600;
public:
	Game();
	~Game();

	CanvasStore* const canvasstore = CanvasStore::get();
	ObjectStore objectstore;

	void update();
};

