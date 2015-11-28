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
	Vector position;
	void update();
	virtual void step();
	template<class T> T* getComponent();
	void createInstance(GameObject* obj);
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
