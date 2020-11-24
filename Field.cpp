#include "Field.h"

#include <osg/Geode>
#include <osg/ShapeDrawable>

static auto* createFloorGeode()
{
	auto* geode = new osg::Geode();
	auto* box = new osg::Box(osg::Vec3(0, 0, -0.01), 1., 2., 0.02);
	auto* sd = new osg::ShapeDrawable(box);
	sd->setColor(osg::Vec4(0, 0.7, 0, 1));
	geode->addDrawable(sd);
	return geode;
}

static auto* createFloorBody()
{
	auto* state = new btDefaultMotionState(
			btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, -0.5)));
	auto* shape = new btBoxShape(btVector3(10, 20, 1) / 2);
	btRigidBody::btRigidBodyConstructionInfo info(0., state, shape);
	info.m_restitution = 0.95;

	return new btRigidBody(info);
}

static auto* createXWallGeode(double factor)
{
	auto* geode = new osg::Geode();
	auto* box = new osg::Box(osg::Vec3(factor * (0.5 - 0.01), 0, 0.1), 0.02, 2, 0.2);
	auto* sd = new osg::ShapeDrawable(box);
	sd->setColor(osg::Vec4(0.1, 0.1, 0.1, 1));
	geode->addDrawable(sd);
	return geode;
}

static auto* createXWallBody(double factor)
{
	auto* state = new btDefaultMotionState(
			btTransform(btQuaternion(0, 0, 0, 1),
			btVector3(factor * (0.5 - 0.01), 0, 0.1)));
	auto* shape = new btBoxShape(btVector3(0.02, 3, 2) / 2);
	btRigidBody::btRigidBodyConstructionInfo info(0., state, shape);
	info.m_restitution = 0.95;

	return new btRigidBody(info);
}

static auto* createYWallGeode(double factor)
{
	auto* geode = new osg::Geode();
	auto* box = new osg::Box(osg::Vec3(0, factor * (1 - 0.01), 0.1), 1, 0.02, 0.2);
	auto* sd = new osg::ShapeDrawable(box);
	sd->setColor(osg::Vec4(0.1, 0.1, 0.1, 1));
	geode->addDrawable(sd);
	return geode;
}

static auto* createYWallBody(double factor)
{
	auto* state = new btDefaultMotionState(
			btTransform(btQuaternion(0, 0, 0, 1),
			btVector3(0, factor * (1 - 0.01), 0.1)));
	auto* shape = new btBoxShape(btVector3(2, 0.02, 2) / 2);
	btRigidBody::btRigidBodyConstructionInfo info(0., state, shape);
	info.m_restitution = 0.95;

	return new btRigidBody(info);
}

Field::Field():
	Thing()
{
	shapes.emplace_back(createFloorGeode(), createFloorBody());
	shapes.emplace_back(createXWallGeode(+1), createXWallBody(+1));
	shapes.emplace_back(createXWallGeode(-1), createXWallBody(-1));
	shapes.emplace_back(createYWallGeode(+1), createYWallBody(+1));
	shapes.emplace_back(createYWallGeode(-1), createYWallBody(-1));
}

void Field::update(const World&)
{}
