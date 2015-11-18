#pragma once
#include "Canvas.h"
class CanvasStore
{
	CanvasStore();
	static CanvasStore* instance;
	std::map < std::string, Canvas* > map;
public:

	~CanvasStore();

	static CanvasStore* get();

	
	Canvas* addCanvas(std::string name, int width, int height);
	Canvas* addCanvas(std::string name, std::string fname);
	Canvas* getCanvas(std::string name);
	Canvas* screen = 0;
	sf::Color clearColour;
	void clearScreen();
};

