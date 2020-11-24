#include "Sensor.h"
#include "Ball.h"
#include "Robot.h"
#include "World.h"

#include <cmath>
#include <iostream>

constexpr const float PI = 3.1415;

Sensor::Sensor(const Robot& robot): robot(robot)
{}

Sensor::~Sensor()
{}

constexpr float rad2deg(const float rad)
{
	return 180 * rad / PI;
}

void SimpleBallDirectionSensor::update(const World& state)
{
	const Transform& ballTransform = state.getBall()->getTransform();
	const Transform& robotTransform = robot.getTransform();
	Vec3 deltaVec = ballTransform.getVector() - robotTransform.getVector();
	deltaVec = deltaVec.normalized();
	Quat robotQuat = robotTransform.getQuat();
	btScalar x, y, z;
	robotQuat.getEulerZYX(z, y, x);
	float gamma = atan2(deltaVec.y(), deltaVec.x());
	reading = fmod(gamma - z + PI, 2 * PI) - PI;
}

const float SimpleBallDirectionSensor::getReading() const
{
	return reading;
}
