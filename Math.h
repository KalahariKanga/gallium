#pragma once
#include <random>
class Math
{
	static std::default_random_engine engine;
public:
	Math();
	~Math();
	static float const pi;
	static float clamp(float value, float min, float max);
	static float random(float a, float b);
};

