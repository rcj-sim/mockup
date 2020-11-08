#pragma once

#include "Thing.hpp"

class Ball:
	public Thing
{
	const double diameter = 0.08;

	void createOSGGeode();
	void createBulletBody();
public:
	Ball();
};


