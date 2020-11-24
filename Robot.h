#ifndef RCJSIM_MOCKUP_ROBOT_H
#define RCJSIM_MOCKUP_ROBOT_H

#include "Thing.h"
#include "Sensor.h"

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


#endif // RCJSIM_MOCKUP_ROBOT_H
