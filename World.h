#ifndef RCJSIM_MOCKUP_WORLD_H
#define RCJSIM_MOCKUP_WORLD_H

#include <vector>
#include <memory>
#include <chrono>
#include <btBulletDynamicsCommon.h>
#include <osg/Group>

#include "Thing.h"

class Ball;

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
	Ball* ball;

	std::chrono::milliseconds simulationTime;

public:
	World();
	~World();

	const osg::ref_ptr<osg::Group>& getOSGScene() const;

	const std::unique_ptr<Thing>& addThing(std::unique_ptr<Thing> thing);
	void addBall(std::unique_ptr<Ball> ball);

	const std::vector<std::unique_ptr<Thing>>& getThings() const;
	const Ball* getBall() const;

	const std::chrono::milliseconds getSimulationTime() const;

	void step();
	void updateThings();
};

#endif // RCJSIM_MOCKUP_WORLD_H
