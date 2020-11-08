#pragma once

#include <vector>
#include <memory>
#include <btBulletDynamicsCommon.h>
#include <osg/Group>

#include "Thing.hpp"

class World
{
private:
	btDbvtBroadphase* broadphase;
	btDefaultCollisionConfiguration* collisionConfig;
	btCollisionDispatcher* dispatch;
	btSequentialImpulseConstraintSolver* solver;
	btDynamicsWorld* dynamics;

	osg::ref_ptr<osg::Group> scene;

	std::vector<std::unique_ptr<Thing>> things;

public:
	World();
	~World();

	const osg::ref_ptr<osg::Group>& getOSGScene() const;

	const std::unique_ptr<Thing>& addThing(std::unique_ptr<Thing> thing);

	const std::vector<std::unique_ptr<Thing>>& getThings() const;

	void step();
	void update();
};

