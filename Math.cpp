#include "Math.h"

std::default_random_engine Math::engine;
const float Math::pi = 3.14159265;

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

float Math::random(float a, float b)
{
	std::uniform_real_distribution<float> dist(a, b);
	return dist(engine);
}