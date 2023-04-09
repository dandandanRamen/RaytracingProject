#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

struct hit_record {
	vec3d point;
	color3d normal;
	double t;
};

class hittable {
public:

	//meant to be overridden, that's why it's virtual and = 0.
	virtual bool hit(const ray& r, double tmin, double tmax, hit_record& record) = 0;
};

#endif