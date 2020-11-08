#pragma once

#include "Thing.hpp"

class Robot:
	public Thing
{
	void createOSGGeode();
	void createBulletBody();

public:
	Robot();

	virtual void update() override;
};


