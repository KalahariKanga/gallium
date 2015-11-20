#pragma once
#include <vector>
#include "Component_Render.h"
class BigPixelArray : public Component_Render
{
	Canvas* const screen = CanvasStore::get()->screen;
	struct BigPixel
	{
		bool on = 0;
		sf::Color col;
		float state;
	};
	std::vector<std::vector<BigPixel>> pixels;
	void drawPixel(BigPixel* px, int root_x, int root_y, int x, int y);
	int pixelSize = 4;
	int width, height;
public:
	BigPixelArray();
	~BigPixelArray();
	virtual void update(GameObject* parent);
	void addPixel(int x, int y, sf::Color col, int variance);
	void clearPixels();
	void setSize(unsigned width, unsigned height)
	{
		this->width = width;
		this->height = height;
		pixels = std::vector<std::vector<BigPixel>>(width, std::vector<BigPixel>(height));
	}
	void loadFromFile(std::string fname);
};

