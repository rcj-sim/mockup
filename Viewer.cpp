#include "Viewer.h"
#include <osgGA/TrackballManipulator>

Viewer::Viewer(World& world):
	world(world)
{
	viewer.setSceneData(world.getOSGScene());
	viewer.setReleaseContextAtEndOfFrameHint(false);

	auto* manip = new osgGA::TrackballManipulator();
	viewer.setCameraManipulator(manip);
	manip->setAutoComputeHomePosition(false);
	manip->setHomePosition(osg::Vec3(0, 0, 3), osg::Vec3(0, 0, 0), osg::Vec3(-1, 0, 0));
	manip->home(0.);
}

int Viewer::run()
{
	return viewer.run();
}

bool Viewer::done()
{
	return viewer.done();
}

void Viewer::frame()
{
	viewer.frame();
}

