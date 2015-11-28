#include "OffscreenDestroy.h"
#include "GameObject.h"
#include "Game.h"
OffscreenDestroy::OffscreenDestroy()
{
}


OffscreenDestroy::~OffscreenDestroy()
{
}

void OffscreenDestroy::update(GameObject* parent)
{
	if (parent->position.getX() < 0)
		parent->destroyInstance();
	if (parent->position.getY() < 0)
		parent->destroyInstance();
	if (parent->position.getX() > Game::window_width)
		parent->destroyInstance();
	if (parent->position.getY() > Game::window_height)
		parent->destroyInstance();
}