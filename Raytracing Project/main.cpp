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
	double t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t) * color3d(1.0, 1.0, 1.0) + t*color3d(0.5, 0.7, 1.0);
}

int main()
{

	//set image Resolution
	const auto aspect_ratio = 16.0 / 9.0;
	const int image_width = 400;
	const int image_height = static_cast<int>(image_width / aspect_ratio);

	//set viewport (or camera) where we'll pass our rays through
	auto viewport_height = 2.0;
	auto viewport_width = aspect_ratio * viewport_height;
	auto focal_length = 1.0;

	auto origin = vec3d(0, 0, 0);
	auto horizontal = vec3d(viewport_width, 0, 0);
	auto vertical = vec3d(0, viewport_height, 0);
	auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3d(0, 0, focal_length);

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = image_height - 1; j >= 0 ; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;  //shows progress
		for (int i = 0; i < image_width; ++i) {

			auto u = double(i) / (image_width - 1);
			auto v = double(j) / (image_height - 1);

			ray r(origin, (lower_left_corner + (u * horizontal) + (v * vertical) - origin)); //(origin, direction.)
			color3d pixel_color = ray_color(r);
			//color3d rgb = calculate_color(j, i, image_width, image_height);
			output_Color(std::cout, pixel_color);
		}

	}

	std::cerr << '\n' << "Image render done. " << '\n';
}