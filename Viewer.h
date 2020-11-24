#ifndef RCJSIM_MOCKUP_VIEWER_H
#define RCJSIM_MOCKUP_VIEWER_H

#include "World.h"
#include <osgViewer/Viewer>

class Viewer {
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
