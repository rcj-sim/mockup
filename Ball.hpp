#pragma once

#include "Thing.hpp"

class Ball:
	public LocateableThing
{
	const double diameter = 0.08;
public:
	Ball();
};


