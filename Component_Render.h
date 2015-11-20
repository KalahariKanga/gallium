#pragma once
#include "Component.h"
#include "CanvasStore.h"
class Component_Render :
	public Component
{
protected:
	Canvas* const screen = CanvasStore::get()->screen;
	Canvas* _Canvas = nullptr;
public:
	Component_Render();
	~Component_Render();
	virtual void update(GameObject* parent);
};

