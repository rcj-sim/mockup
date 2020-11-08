#include "World.hpp"
#include <iostream>

World::World()
{
	broadphase = new btDbvtBroadphase();
	collisionConfig = new btDefaultCollisionConfiguration();
	dispatch = new btCollisionDispatcher(collisionConfig);
	solver = new btSequentialImpulseConstraintSolver();
	dynamics = new btDiscreteDynamicsWorld(dispatch, broadphase, solver, collisionConfig);

	scene = new osg::Group();

	dynamics->setGravity(btVector3(0, 0, -9.81));
}

World::~World()
{
	delete dynamics;
	delete solver;
	delete dispatch;
	delete collisionConfig;
	delete broadphase;
}

const osg::ref_ptr<osg::Group>& World::getOSGScene() const
{
	return scene;
}

const std::unique_ptr<Thing>& World::addThing(std::unique_ptr<Thing> thing)
{
	dynamics->addRigidBody(thing->getRigidBody());
	scene->addChild(thing->getSceneNode());
	auto it = things.insert(things.end(), std::move(thing));
	return *it;
}

const std::vector<std::unique_ptr<Thing>>& World::getThings() const
{
	return things;
}

void World::step()
{
	dynamics->stepSimulation(0.01, 30);
	update();
}

void World::update()
{
	for (auto& t: things) {
		t->update();
	}
}

