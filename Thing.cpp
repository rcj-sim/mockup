#include "Thing.h"
#include "Math.h"

#include <osg/Geode>

OSGBulletPair::OSGBulletPair(
		osg::ref_ptr<osg::PositionAttitudeTransform> osgNode,
		btRigidBody* btBody):
	osgNode(osgNode),
	btBody(btBody)
{}

OSGBulletPair::OSGBulletPair(osg::Geode* osgGeode,
		btRigidBody* btBody):
	osgNode(new osg::PositionAttitudeTransform()),
	btBody(btBody)
{
	osgNode->addChild(osgGeode);
}

OSGBulletPair::OSGBulletPair(OSGBulletPair&& old):
	osgNode(old.osgNode),
	btBody(old.btBody)
{
	old.osgNode = nullptr;
	old.btBody = nullptr;
}

OSGBulletPair::~OSGBulletPair()
{
	if (btBody) {
		auto *cs = btBody->getCollisionShape();
		if (cs) {
			delete cs;
		}
		auto *ms = btBody->getMotionState();
		if (ms) {
			delete ms;
		}
		delete btBody;
	}
}

btRigidBody* OSGBulletPair::getBulletBody()
{
	return btBody;
}

osg::ref_ptr<osg::PositionAttitudeTransform> OSGBulletPair::getOSGNode()
{
	return osgNode;
}

void OSGBulletPair::update()
{
	if (!btBody || !osgNode) {
		return;
	}
	Transform transform;
	btBody->getMotionState()->getWorldTransform(transform);
	osgNode->setPosition(transform.getVector());
	osgNode->setAttitude(transform.getQuat());
}

void Thing::update(const World&)
{
	for (auto& s: shapes) {
		s.update();
	}
}

std::vector<OSGBulletPair>& Thing::getShapes()
{
	return shapes;
}

void LocateableThing::update(const World& w)
{
	Thing::update(w);
	auto& s = shapes[0];
	s.getBulletBody()->getMotionState()->getWorldTransform(transform);
}

const Transform& LocateableThing::getTransform() const
{
	return transform;
}

