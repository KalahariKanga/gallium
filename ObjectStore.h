#pragma once
#include <memory>
#include <vector>
#include <algorithm>
#include "GameObject.h"

class ObjectStore
{
	std::vector<ObjectPtr> objects;
	std::vector<ObjectPtr> toCreate;
	std::vector<ObjectPtr> toDestroy;
public:
	ObjectStore();
	~ObjectStore();

	ObjectPtr createInstance(GameObject* object);
	ObjectPtr createInstance(ObjectPtr object);
	void destroyInstance(ObjectPtr object);

	void update();

};

