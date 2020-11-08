#pragma once

#include <osg/PositionAttitudeTransform>
#include <btBulletDynamicsCommon.h>
#include <chrono>

class Thing
{
protected:
	osg::ref_ptr<osg::PositionAttitudeTransform> osgNode;
	btRigidBody *btBody;

public:
	Thing();
	Thing(Thing &&) noexcept;
	virtual ~Thing();

	btRigidBody *getRigidBody();
	osg::ref_ptr<osg::PositionAttitudeTransform> getSceneNode();

	virtual void update();
};

