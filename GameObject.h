#pragma once
#include <memory>
#include "CanvasStore.h"
class GameObject
{

protected:
	Canvas* const screen = CanvasStore::get()->screen;
	Canvas* _Canvas = nullptr;
	int x, y;
public:
	GameObject();
	~GameObject();
	virtual void update();
};

typedef std::shared_ptr<GameObject> ObjectPtr;
