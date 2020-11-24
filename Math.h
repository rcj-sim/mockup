#ifndef RCJSIM_MOCKUP_MATH_H
#define RCJSIM_MOCKUP_MATH_H

#include <LinearMath/btQuaternion.h>
#include <LinearMath/btTransform.h>
#include <LinearMath/btVector3.h>
#include <osg/Quat>
#include <osg/Vec3d>

class Vec3: public btVector3 {
public:
	using btVector3::btVector3;

	Vec3(const osg::Vec3f& v): btVector3(v.x(), v.y(), v.z())
	{}

	Vec3(const btVector3& v): btVector3(v.x(), v.y(), v.z())
	{}

	operator osg::Vec3d() const
	{
		return osg::Vec3d(x(), y(), z());
	}
};

class Quat: public btQuaternion {
public:
	using btQuaternion::btQuaternion;

	Quat(const btQuaternion& q): btQuaternion(q.x(), q.y(), q.z(), q.w())
	{}

	operator osg::Quat() const
	{
		return osg::Quat(x(), y(), z(), w());
	}
};

class Transform: public btTransform {
public:
	using btTransform::btTransform;

	Vec3 getVector() const
	{
		return Vec3(getOrigin());
	}

	Quat getQuat() const
	{
		return Quat(getRotation());
	}
};

#endif // RCJSIM_MOCKUP_MATH_H
