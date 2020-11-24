#include "World.h"
#include "Ball.h"

World::World(): simulationTime(0)
{
	broadphase = new btDbvtBroadphase();
	collisionConfig = new btDefaultCollisionConfiguration();
	dispatch = new btCollisionDispatcher(collisionConfig);
	solver = new btSequentialImpulseConstraintSolver();
	dynamics = new btDiscreteDynamicsWorld(
		dispatch, broadphase, solver, collisionConfig);

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
	for (auto& s: thing->getShapes()) {
		auto* b = s.getBulletBody();
		dynamics->addRigidBody(b);
		scene->addChild(s.getOSGNode());
	}
	auto it = things.insert(things.end(), std::move(thing));
	return *it;
}

void World::addBall(std::unique_ptr<Ball> newBall)
{
	ball = newBall.get();
	addThing(std::move(newBall));
}

const Ball* World::getBall() const
{
	return ball;
}

const std::vector<std::unique_ptr<Thing>>& World::getThings() const
{
	return things;
}

void World::step()
{
	dynamics->stepSimulation(0.01, 30);
	simulationTime += std::chrono::milliseconds(10);
	updateThings();
}

void World::updateThings()
{
	for (auto& t: things) {
		t->update(*this);
	}
}

const std::chrono::milliseconds World::getSimulationTime() const
{
	return simulationTime;
}
