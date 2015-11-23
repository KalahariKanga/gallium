#pragma once
#include <memory>
#include <vector>
#include "Component.h"
#include "Math.h"
class GameObject
{

protected:
	std::vector<Component*> components;
public:
	GameObject();
	~GameObject();
	float x, y;
	void update();
	template<class T> T* getComponent();
	void destroyInstance();
};

template<class T>
T* GameObject::getComponent()
{
	for (auto a : components)
	{
		T* ptr = dynamic_cast<T*>(a);
		if (ptr)
			return ptr;
	}
	throw new std::exception("getComponent error");
}

//typedef std::shared_ptr<GameObject> ObjectPtr;
typedef GameObject* ObjectPtr;
