#include "ObjectStore.h"


ObjectStore::ObjectStore()
{
}


ObjectStore::~ObjectStore()
{
}

void ObjectStore::update()
{
	for (auto o : objects)
	{
		o->update();
	}
	for (auto c : toCreate)
	{
		objects.push_back(c);
	}
	toCreate.clear();
	for (auto d : toDestroy)
	{
		auto o = std::find_if(objects.begin(), objects.end(), [d](ObjectPtr obj){return obj.get() == d.get(); });
		if (o != objects.end())
			objects.erase(o);
	}
	toDestroy.clear();
}

ObjectPtr ObjectStore::createInstance(GameObject* object)
{
	toCreate.push_back(std::make_shared<GameObject>(*object));
	return toCreate.back();
}

ObjectPtr ObjectStore::createInstance(ObjectPtr object)
{
	toCreate.push_back(object);
	return toCreate.back();
}

void ObjectStore::destroyInstance(ObjectPtr object)
{
	toDestroy.push_back(object);
}