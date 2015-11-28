#include "GameObject.h"
#include "ObjectStore.h"

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::step()
{

}

void GameObject::update()
{
	step();
	for (auto& a : components)
		a->update(this);
}

void GameObject::createInstance(GameObject* obj)
{
	ObjectStore::get()->createInstance(obj);
}

void GameObject::destroyInstance()
{
	ObjectStore::get()->destroyInstance(this);
}