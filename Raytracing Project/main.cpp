/* Raytracing Project, by Daniel Simpson 
Adapted from Peter Shirley's "Raytracing in One Weekend" */

#include <iostream>
#include "color.h"

int main()
{

	//Set image Resolution
	const int width = 256;
	const int height = 256;

	//Render
	std::cout << "P3\n" << width << ' ' << height << "\n255\n";

	for (int j = height; j > 0 - 1; --j) {
		std::cerr << "\nScanlines remaining: " << j << ' ' << std::endl;	//writes progress to error output stream
		for (int i = 0; i < width; ++i) {

			color3f rgb = calculate_color(j, i, width, height);
			output_Color(std::cout, rgb);
		}

	}

	std::cerr << '\n' << "Image render done. " << '\n';
}