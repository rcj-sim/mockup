#include "Robot.hpp"

#include <osg/Geode>
#include <osg/ShapeDrawable>

Robot::Robot():
	Thing()
{
	createOSGGeode();
	createBulletBody();
}

void Robot::createOSGGeode()
{
	auto *geode = new osg::Geode();
	auto *shape = new osg::Box(osg::Vec3(0, 0, 0), 0.14, 0.14, 0.14);
	auto *sd = new osg::ShapeDrawable(shape);
	geode->addDrawable(sd);
	osgNode->addChild(geode);
}

void Robot::createBulletBody()
{
	auto *state = new btDefaultMotionState(
			btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 1, 1)));
	auto *shape = new btBoxShape(btVector3(0.14, 0.14, 0.14) / 2);
	btVector3 li;
	shape->calculateLocalInertia(1.2, li);
	btRigidBody::btRigidBodyConstructionInfo info(1.2, state, shape, li);
	info.m_restitution = 0.2;

	btBody = new btRigidBody(info);
}

void Robot::update()
{
	Thing::update();
	btBody->applyCentralForce(btVector3(0, -4, 0));
}

