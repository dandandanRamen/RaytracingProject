/* Raytracing Project, by Dan Simpson 
Adapted from Peter Shirley's "Raytracing in One Weekend" */


#include <iostream>
#include "color.h"
#include "ray.h"
#include "vec3.h"

//returns a vec3 color using math magic on a ray (based on ray direction, unit vectors, t, y axis, etc)
color3d ray_color(const ray& r)	
{
	vec3d unit_direction = unitVector(r.getDirection());
	float t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t) * color3d(1.0, 1.0, 1.0) + t * color3d(0.5, 0.7, 1.0);
}

int main()
{

	//Set image Resolution
	const auto aspect_ratio = 16.0 / 9.0;
	const int width = 400;
	const int height = static_cast<int>(width / aspect_ratio);

	//set viewport (or camera) where we'll pass our rays through
	auto viewport_height = 2.0;
	auto viewport_width = aspect_ratio * viewport_height;
	auto focal_length = 1.0;

	auto origin = vec3d(0, 0, 0);
	auto horizontal = vec3d(viewport_width, 0, 0);
	auto vertical = vec3d(0, viewport_height, 0);
	auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3d(0, 0, focal_length);

	//Render
	std::cout << "P3\n" << width << ' ' << height << "\n255\n";

	for (int j = height; j > 0 - 1; --j) {
		std::cerr << "\nScanlines remaining: " << j << ' ' << std::endl;  //
		for (int i = 0; i < width; ++i) {

			color3d rgb = calculate_color(j, i, width, height);
			output_Color(std::cout, rgb);
		}

	}

	std::cerr << '\n' << "Image render done. " << '\n';
}