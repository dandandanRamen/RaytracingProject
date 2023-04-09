#ifndef RAY_H
#define RAY_H

#include "vec3.h"

/// ray class to represent the points along in 3D space

class ray {
	public:
		vec3d m_org;
		vec3d m_dir;

	public:
		ray() {}
		ray(const vec3d& origin, const vec3d& direction) : m_org{ origin }, m_dir{ direction } {}

		vec3d getOrigin() const { return m_org; }
		vec3d getDirection() const { return m_dir; }

		vec3d at(double t) const 
		{ 
			return m_org + t*m_dir; //P(t) = A + tB
		}
};

#endif