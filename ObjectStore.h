#pragma once
#include <memory>
#include <vector>
#include <algorithm>
#include "GameObject.h"

class ObjectStore
{
	ObjectStore();
	std::vector<ObjectPtr> objects;
	std::vector<ObjectPtr> toCreate;
	std::vector<ObjectPtr> toDestroy;
	static ObjectStore* instance;
public:
	
	~ObjectStore();
	static ObjectStore* get();
	//ObjectPtr createInstance(GameObject* object);
	ObjectPtr createInstance(ObjectPtr object);
	void destroyInstance(ObjectPtr object);

	void update();

};

