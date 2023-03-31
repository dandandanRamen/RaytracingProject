#ifndef RAY_H
#define RAY_H

#include "vec3.h"

/// ray class to represent the points along in 3D space

class Ray {
	public:
		vec3f m_org;
		vec3f m_dir;

	public:
		Ray() {}
		Ray(const Vec3f origin, const vec3f direction, ) : m_org{ origin }, m_dir{ direction } {}

		vec3f getOrigin() const { return m_org; }
		vec3f getDirection() const { return m_dir; }

		vec3f positionAt(double t) const 
		{ 
			return m_org + (t * direction); //P(t) = A + tB
		}
};

#endif