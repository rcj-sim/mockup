#pragma once

#include <osgViewer/Viewer>
#include "World.hpp"

class Viewer
{
private:
	osgViewer::Viewer viewer;
	World& world;

public:
	Viewer(World& world);

	int run();
	bool done();
	void frame();
};

