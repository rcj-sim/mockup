#include "Field.hpp"

#include <osg/Geode>
#include <osg/ShapeDrawable>

Field::Field():
	Thing()
{
	createOSGGeode();
	createBulletBody();
}

void Field::createOSGGeode()
{
	osg::Geode *geode = new osg::Geode();
	osg::Box *box = new osg::Box(osg::Vec3(0, 0, 0), 1., 2., 0.02);
	osg::ShapeDrawable *sd = new osg::ShapeDrawable(box);
	geode->addDrawable(sd);
	osgNode->addChild(geode);
}

void Field::createBulletBody()
{
	btDefaultMotionState *state = new btDefaultMotionState(
			btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)));
	btBoxShape *shape = new btBoxShape(btVector3(1, 2, 0.02) / 2);
	btRigidBody::btRigidBodyConstructionInfo info(0., state, shape);
	info.m_restitution = 0.95;

	btBody = new btRigidBody(info);
}

