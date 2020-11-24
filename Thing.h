#ifndef RCJSIM_MOCKUP_THING_H
#define RCJSIM_MOCKUP_THING_H

#include "Math.h"
#include <btBulletDynamicsCommon.h>
#include <osg/PositionAttitudeTransform>
#include <vector>

class World;

class OSGBulletPair {
protected:
	osg::ref_ptr<osg::PositionAttitudeTransform> osgNode;
	btRigidBody* btBody;

public:
	OSGBulletPair(osg::ref_ptr<osg::PositionAttitudeTransform> osgNode,
		btRigidBody* btBody);
	OSGBulletPair(osg::Geode* osgNode, btRigidBody* btBody);
	OSGBulletPair(OSGBulletPair&&);
	virtual ~OSGBulletPair();
	void update();
	osg::ref_ptr<osg::PositionAttitudeTransform> getOSGNode();
	btRigidBody* getBulletBody();
};

class Thing {
protected:
	std::vector<OSGBulletPair> shapes;

public:
	Thing() = default;
	virtual ~Thing() = default;

	std::vector<OSGBulletPair>& getShapes();

	virtual void update(const World& state);
};

class LocateableThing: public Thing {
protected:
	Transform transform;

public:
	const Transform& getTransform() const;
	virtual void update(const World& state);
};

#endif // RCJSIM_MOCKUP_THING_H
