#include "GameObject.h"
#include "ObjectStore.h"

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::update()
{
	for (auto& a : components)
		a->update(this);
}

void GameObject::destroyInstance()
{
	ObjectStore::get()->destroyInstance(this);
}