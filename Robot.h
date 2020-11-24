#pragma once

#include "Thing.hpp"
#include "Sensor.hpp"

class Robot:
	public LocateableThing
{
private:
	btRigidBody* mainBody;
	SimpleBallDirectionSensor sns;

public:
	Robot();

	virtual void update(const class World& state) override;
};


