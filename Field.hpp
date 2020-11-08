#pragma once

#include "Thing.hpp"

class Field:
	public Thing
{

	void createOSGGeode();
	void createBulletBody();
public:
	Field();
};

