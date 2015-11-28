#pragma once
#include "sfml/graphics.hpp"
#include "ObjectStore.h"
#include "CanvasStore.h"
#include "Math.h"
#include <chrono>
#include <thread>
class Game
{
	sf::RenderWindow window;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Image image;

	std::chrono::time_point<std::chrono::system_clock> start, end;
	int fps = 60;
public:
	Game();
	~Game();

	CanvasStore* const canvasstore = CanvasStore::get();
	ObjectStore* const objectstore = ObjectStore::get();
	static const int window_width = 800;
	static const int window_height = 600;
	void update();
};

