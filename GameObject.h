#pragma once
#include <memory>
#include <vector>
#include "Component.h"
class GameObject
{

protected:
	std::vector<Component*> components;
public:
	GameObject();
	~GameObject();
	float x, y;
	void update();
	template<class T> Component* getComponent();
};

template<class T>
Component* getComponent()
{
	for (auto a& : components)
	{
		if (typeid(T) == typeid(a))
			return a;
	}
	return nullptr;
}

typedef std::shared_ptr<GameObject> ObjectPtr;
