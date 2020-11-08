#pragma once

#include <LinearMath/btVector3.h>

class Vec3:
	public btVector3
{
public:
	using btVector3::btVector3;

	Vec3(const osg::Vec3f &v):
		btVector3(v.x(), v.y(), v.z())
	{}

	Vec3(const btVector3 &v):
		btVector3(v.x(), v.y(), v.z())
	{}

	operator osg::Vec3d() const
	{
		return osg::Vec3d(x(), y(), z());
	}
};

class Quat:
	public btQuaternion
{
public:
	using btQuaternion::btQuaternion;

	Quat(const btQuaternion& q):
		btQuaternion(q.x(), q.y(), q.z(), q.w())
	{}

	operator osg::Quat() const
	{
		return osg::Quat(x(), y(), z(), w());
	}
};

