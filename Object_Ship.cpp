#include "Object_Ship.h"


Object_Ship::Object_Ship()
{
	CanvasStore* cs = CanvasStore::get();
	_Canvas = cs->addCanvas("circle", 32, 32);
	_Canvas->drawCircle(16, 16, 16, 0);
}


Object_Ship::~Object_Ship()
{
}

void Object_Ship::update()
{
	screen->drawCanvas(_Canvas, 100, 100);
}