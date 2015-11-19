#include "GameObject.h"


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