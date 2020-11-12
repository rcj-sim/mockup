#include "Ball.hpp"

#include <osg/Geode>
#include <osg/ShapeDrawable>

static auto* createOSGGeode(const double diameter)
{
	auto *geode = new osg::Geode();
	auto *sphere = new osg::Sphere(osg::Vec3(0, 0, 0), diameter / 2);
	auto *sd = new osg::ShapeDrawable(sphere);
	sd->setColor(osg::Vec4(1, 0.7, 0, 1));
	geode->addDrawable(sd);
	return geode;
}

static auto* createBulletBody(const double diameter)
{
	auto *state = new btDefaultMotionState(
			btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 1)));
	auto *shape = new btSphereShape(diameter / 2);
	btVector3 li;
	shape->calculateLocalInertia(1.2, li);
	btRigidBody::btRigidBodyConstructionInfo info(0.1, state, shape, li);
	info.m_restitution = 0.7;

	return new btRigidBody(info);
}

Ball::Ball():
	LocateableThing()
{
	auto* geode = createOSGGeode(diameter);
	auto* body = createBulletBody(diameter);
	shapes.emplace_back(geode, body);
}

