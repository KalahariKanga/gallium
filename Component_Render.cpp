#include "Component_Render.h"
#include "GameObject.h"

Component_Render::Component_Render()
{
	CanvasStore* cs = CanvasStore::get();
	_Canvas = cs->addCanvas("circle", 32, 32);
	_Canvas->drawCircle(16, 16, 16, 0);
}


Component_Render::~Component_Render()
{
}

void Component_Render::update(GameObject* parent)
{
	screen->drawCanvas(_Canvas, parent->x, parent->y);
}