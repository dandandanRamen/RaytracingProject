/* Raytracing Project, by Dan Simpson 
Adapted from Peter Shirley's "Raytracing in One Weekend" */


#include <iostream>
#include "color.h"
#include "ray.h"
#include "vec3.h"

//use the quadratic forumla to determine if the ray hits sphere. 
double hit_sphere(const vec3d& sphereCenter, double radius, const ray& r)
{
	vec3d oc = r.getOrigin() - sphereCenter;								//get origin minus center. 
	double a = r.getDirection().getLengthSquared();							//calculate a
	double b = 2.0 * dotProduct(oc, r.getDirection());						//calculate b
	double c = oc.getLengthSquared() - (radius * radius);						//calculate c

	double discriminant = (b * b) - 4 * a * c;								//b^2 - 4ac

	if (discriminant < 0)
		return -1.0;														//sphere wasn't hit.
	else
		return (-b - sqrt(discriminant)) / (2.0 * a);						//sphere hit.
}

//returns a vec3 color per ray (based on ray direction, unit vectors, t, y axis, etc)
color3d ray_color(const ray& r)	
{
	//calculate if ray it sphere first, output color to reflect that.
	double t = hit_sphere(vec3d(0, 0, -1), 0.5, r);

	if (t > 0.0) {
		vec3d normal = unitVector(r.at(t) - vec3d(0, 0, -1));
		return 0.5 * color3d(normal.x() + 1, normal.y() + 1, normal.z() + 1);
	}

	//else calculate ray color depending on direction of ray.
	vec3d unit_direction = unitVector(r.getDirection());				//normalize direction vector
	t = 0.5 * (unit_direction.y() + 1.0);								//t will be scaled with height y
	vec3d blendedValue = (1.0 - t) * color3d(1.0, 1.0, 1.0) + t * color3d(0.5, 0.7, 1.0);
	return blendedValue; 
}

int main()
{

	//set image Resolution
	const double aspect_ratio = 16.0 / 9.0;
	const int image_width = 400;
	const int image_height = static_cast<int>(image_width / aspect_ratio);

	//set viewport (or camera) where we'll pass our rays through
	double viewport_height = 2.0;
	double viewport_width = aspect_ratio * viewport_height;
	double focal_length = 1.0;

	vec3d origin = vec3d(0, 0, 0);
	vec3d horizontal = vec3d(viewport_width, 0, 0);
	vec3d vertical = vec3d(0, viewport_height, 0);
	vec3d lower_left_corner = origin - horizontal/2 - vertical/2 - vec3d(0, 0, focal_length);

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = image_height - 1; j >= 0 ; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;  //shows progress
		for (int i = 0; i < image_width; ++i) {

			double v = double(j) / (image_height - 1);	//scales height with itr
			double u = double(i) / (image_width - 1);		//scales width with itr

			ray r(origin, (lower_left_corner + (u * horizontal) + (v * vertical) - origin)); //(origin, direction.)
			color3d pixel_color = ray_color(r);

			//color3d rgb = calculate_color(j, i, image_width, image_height);
			output_Color(std::cout, pixel_color);
		}

	}

	std::cerr << '\n' << "Image render done. " << '\n';
}