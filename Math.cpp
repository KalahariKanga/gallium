#include "Math.h"


Math::Math()
{
}


Math::~Math()
{
}

float Math::clamp(float value, float min, float max)
{
	if (value < min)
		value = min;
	if (value > max)
		value = max;
	return value;
}