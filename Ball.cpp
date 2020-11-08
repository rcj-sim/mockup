#include "Ball.hpp"

#include <osg/Geode>
#include <osg/ShapeDrawable>

Ball::Ball():
	Thing()
{
	createOSGGeode();
	createBulletBody();
}

void Ball::createOSGGeode()
{
	auto *geode = new osg::Geode();
	auto *sphere = new osg::Sphere(osg::Vec3(0, 0, 0), diameter / 2);
	auto *sd = new osg::ShapeDrawable(sphere);
	geode->addDrawable(sd);
	osgNode->addChild(geode);
}

void Ball::createBulletBody()
{
	auto *state = new btDefaultMotionState(
			btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0.2)));
	auto *shape = new btSphereShape(diameter / 2);
	btVector3 li;
	shape->calculateLocalInertia(1.2, li);
	btRigidBody::btRigidBodyConstructionInfo info(0.1, state, shape, li);
	info.m_restitution = 0.7;

	btBody = new btRigidBody(info);
}

