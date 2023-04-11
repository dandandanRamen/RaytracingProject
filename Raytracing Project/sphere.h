#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
public:
	vec3d center;
	double radius;

public:
	sphere() {}
	sphere() { vec3d c, double r } : center{ c }, radius{ r } {};

	virtual bool hit(const ray& r, double tmax, double tmin, hit_record& rec) const override;

};

bool sphere::hit(const ray& r, double tmax, double tmin, hit_record& rec) const
{

}

#endif 