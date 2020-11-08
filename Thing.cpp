#include "Thing.hpp"
#include "Math.hpp"

Thing::Thing()
{
	osgNode = new osg::PositionAttitudeTransform();
}

Thing::Thing(Thing &&src) noexcept:
	osgNode(src.osgNode),
	btBody(src.btBody)
{
	src.osgNode = nullptr;
	src.btBody = nullptr;
}


Thing::~Thing()
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

btRigidBody *Thing::getRigidBody()
{
	return btBody;
}

osg::ref_ptr<osg::PositionAttitudeTransform> Thing::getSceneNode()
{
	return osgNode;
}

void Thing::update()
{
	if (!btBody || !osgNode) {
		return;
	}
	btTransform trans;
	btBody->getMotionState()->getWorldTransform(trans);
	osgNode->setPosition(Vec3(trans.getOrigin()));
	osgNode->setAttitude(Quat(trans.getRotation()));
}

