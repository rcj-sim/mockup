#include "Robot.hpp"
#include "World.hpp"

#include <osg/Geode>
#include <osg/ShapeDrawable>

#include <chrono>
#include <cmath>

static auto* createOSGGeode()
{
	auto *geode = new osg::Geode();
	auto *shape = new osg::Box(osg::Vec3(0, 0, 0), 0.14, 0.14, 0.14);
	auto *sd = new osg::ShapeDrawable(shape);
	geode->addDrawable(sd);
	return geode;
}

static auto* createBulletBody()
{
	auto *state = new btDefaultMotionState(
			btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0.2)));
	auto *shape = new btBoxShape(btVector3(0.14, 0.14, 0.14) / 2);
	btVector3 li;
	shape->calculateLocalInertia(1.2, li);
	btRigidBody::btRigidBodyConstructionInfo info(1.2, state, shape, li);
	info.m_restitution = 0;

	return new btRigidBody(info);
}

Robot::Robot():
	LocateableThing(),
	sns(*this)
{
	auto* geode = createOSGGeode();
	mainBody = createBulletBody();
	shapes.emplace_back(geode, mainBody);
}

void Robot::update(const World& state)
{
	LocateableThing::update(state);
	sns.update(state);
	auto now = static_cast<float>(state.getSimulationTime().count()) / 300;
	float reading = sns.getReading();
	if (isfinite(reading)) {
		if (abs(reading) > 0.1) {
			mainBody->applyTorque(btVector3(0, 0, copysign(0.1, reading) + 0.2*reading));
		} else {
			const auto& tf = getTransform();
			mainBody->applyCentralForce(tf(btVector3(10, 0, 0)) - tf.getOrigin());
		}
	}
}

