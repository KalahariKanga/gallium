#pragma once
#include "Component.h"
class OffscreenDestroy :
	public Component
{
public:
	OffscreenDestroy();
	~OffscreenDestroy();
	void update(GameObject* parent);
};

