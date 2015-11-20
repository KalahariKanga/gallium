#include "BigPixelArray.h"
#include "GameObject.h"

BigPixelArray::BigPixelArray()
{
}


BigPixelArray::~BigPixelArray()
{
}

void BigPixelArray::drawPixel(BigPixel* px, int root_x, int root_y, int x, int y)
{
	if (px->on)
	{
		sf::Color col;
		screen->setDrawColour(px->col);
		screen->drawRectangle(root_x + pixelSize * x, root_y + pixelSize * y, root_x + pixelSize * (x + 1), root_y + pixelSize * (y + 1), 0);
	}
}


void BigPixelArray::update(GameObject* parent)
{
	for (int cx = 0; cx < width; cx++)
		for (int cy = 0; cy < height; cy++)
		{
			drawPixel(&pixels[cx][cy], parent->x, parent->y, cx, cy);
		}
}

void BigPixelArray::addPixel(int x, int y, sf::Color col, int variance = 0)
{
	pixels[x][y].on = 1;
	sf::Color newcol = col;
	if (variance)
	{
		newcol.r = col.r - variance / 2 + rand() % variance;
		newcol.g = col.g - variance / 2 + rand() % variance;
		newcol.b = col.b - variance / 2 + rand() % variance;
	}
	pixels[x][y].col = newcol;
	pixels[x][y].state = 0;
}

void BigPixelArray::clearPixels()
{
	for (int cx = 0; cx < width; cx++)
		for (int cy = 0; cy < height; cy++)
			pixels[cx][cy].on = 0;
}

void BigPixelArray::loadFromFile(std::string fname)
{
	clearPixels();
	sf::Image image;
	image.loadFromFile(fname);
	setSize(image.getSize().x, image.getSize().y);
	for (int cx = 0; cx < width; cx++)
		for (int cy = 0; cy < height; cy++)
			addPixel(cx, cy, image.getPixel(cx, cy),10);
}