#include "Viewer.hpp"
#include <osgGA/TrackballManipulator>

Viewer::Viewer(World& world):
	world(world)
{
	viewer.setSceneData(world.getOSGScene());
	viewer.setCameraManipulator(new osgGA::TrackballManipulator());
	viewer.setReleaseContextAtEndOfFrameHint(false);
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

