#pragma once
class GameObject;

class Component
{
public:
	Component();
	~Component();
	virtual void update(GameObject* parent) = 0;
};

