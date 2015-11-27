#include "BigPixelArray.h"
#include "GameObject.h"

BigPixelArray::BigPixelArray(int pixelSize) : pixelSize(pixelSize)
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
		int centrex = root_x + pixelSize * (x + 0.5);
		int centrey = root_y + pixelSize * (y + 0.5);
		int r = px->state*(pixelSize / 2);
		screen->drawCentredRectangle(centrex, centrey, r, r, 0);
	}
}

void BigPixelArray::update(GameObject* parent)
{
	static int t = 0;
	for (int cx = 0; cx < width; cx++)
		for (int cy = 0; cy < height; cy++)
		{
			updateState(&pixels[cx][cy], cx, cy, t);
			drawPixel(&pixels[cx][cy], parent->position.getX(), parent->position.getY(), cx, cy);
		}
	++t;
}

void BigPixelArray::addPixel(int x, int y, sf::Color col, int variance = 0)
{
	pixels[x][y].on = 1;
	sf::Color newcol = col;
	if (variance)
	{
		newcol.r = Math::clamp(col.r - variance / 2 + rand() % variance, 0, 255);
		newcol.g = Math::clamp(col.g - variance / 2 + rand() % variance, 0, 255);
		newcol.b = Math::clamp(col.b - variance / 2 + rand() % variance, 0, 255);
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
			addPixel(cx, cy, image.getPixel(cx, cy),50);
}

void BigPixelArray::loadFromCanvas(std::string canvasName)
{
	clearPixels();
	Canvas* canvas;
	canvas = CanvasStore::get()->getCanvas(canvasName);
	setSize(canvas->getWidth(), canvas->getHeight());
	for (int cx = 0; cx < width; cx++)
		for (int cy = 0; cy < height; cy++)
			addPixel(cx, cy, canvas->getPoint(cx, cy), 50);
}

void BigPixelArray::updateState(BigPixel* px, int x, int y, int t)
{
	if (rand() % width == 0)
		px->setState(px->state + 0.1);
	if (t > transitionTime)
		px->setState(1);
}