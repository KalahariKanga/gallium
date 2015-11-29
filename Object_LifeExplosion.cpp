#include "Object_LifeExplosion.h"
#include "BigPixelArray.h"
#include "Game.h"

Object_LifeExplosion::Object_LifeExplosion()
{
	components.push_back(new BigPixelArray(6));
	BigPixelArray* bpa = getComponent<BigPixelArray>();
	bpa->setSize(Game::window_width / 6, Game::window_height / 6);
	auto col = sf::Color(250, 10, 0);
	bpa->addPixel(20, 20, col, 20);
	bpa->addPixel(21, 20, col, 20);
	bpa->addPixel(21, 21, col, 20);
	bpa->addPixel(22, 21, col, 20);
	bpa->addPixel(21, 22, col, 20);
}


Object_LifeExplosion::~Object_LifeExplosion()
{
}

int Object_LifeExplosion::countNeighbours(int cx, int cy)
{
	BigPixelArray* bpa = getComponent<BigPixelArray>();
	int count = 0;
	for (int ox = -1; ox <= 1; ox++)
		for (int oy = -1; oy <= 1; oy++)
		{
			if (ox == 0 && oy == 0)
				continue;
			if (cx+ox >= 0 && cx+ox < bpa->getWidth())
				if (cy+oy >= 0 && cy+oy < bpa->getHeight())
				{
					if (bpa->getAlive(cx + ox, cy + oy))
						++count;
				}
		}
	return count;
}

void Object_LifeExplosion::step()
{
	BigPixelArray* bpa = getComponent<BigPixelArray>();
	std::vector<std::pair<int, int>> toAdd;
	std::vector<std::pair<int, int>> toRemove;
	for (int cx = 0; cx < bpa->getWidth(); cx++)
		for (int cy = 0; cy < bpa->getHeight(); cy++)
		{
			int neighbours = countNeighbours(cx, cy);
			if (bpa->getAlive(cx, cy))
			{
				if (neighbours != 2 && neighbours != 3)
					toRemove.push_back(std::make_pair(cx, cy));
			}
			else
			{
				if (neighbours == 3)
					toAdd.push_back(std::make_pair(cx, cy));
			}
		}
	for (auto add : toAdd)
	{
		bpa->addPixel(add.first, add.second, sf::Color(250, 10, 0), 20);
	}
	for (auto rm : toRemove)
	{
		bpa->removePixel(rm.first, rm.second);
	}
}
