#pragma once
#include <memory>
class GameObject
{
public:
	GameObject();
	~GameObject();
	void update();
};

typedef std::shared_ptr<GameObject> ObjectPtr;
