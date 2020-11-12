#include "Sensor.hpp"
#include "World.hpp"
#include "Ball.hpp"
#include "Robot.hpp"

#include <cmath>
#include <iostream>

constexpr const float PI = 3.1415;

Sensor::Sensor(const Robot& robot):
	robot(robot)
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
	reading = fmod(gamma - z + PI, 2*PI) - PI;
	std::cout << rad2deg(gamma) << " " << rad2deg(z) << " " << rad2deg(reading) << std::endl;
}

const float SimpleBallDirectionSensor::getReading() const
{
	return reading;
}

