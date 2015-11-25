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
		float state = 0;
		void setState(float s)
		{
			state = s;
			if (s < 0)
				state = 0;
			if (s > 1)
				state = 1;
		}
	};
	std::vector<std::vector<BigPixel>> pixels;
	void drawPixel(BigPixel* px, int root_x, int root_y, int x, int y);
	void updateState(BigPixel* px, int x, int y, int t);
	int pixelSize = 4;
	int transitionTime = 500;
	int width, height;
public:
	BigPixelArray(int pixelSize);
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

