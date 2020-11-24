#ifndef RCJSIM_MOCKUP_VIEWER_H
#define RCJSIM_MOCKUP_VIEWER_H

#include <osgViewer/Viewer>
#include "World.h"

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

#endif // RCJSIM_MOCKUP_VIEWER_H
