/* Raytracing Project, by Daniel Simpson 
Adapted from Peter Shirley's "Raytracing in One Weekend" */

#include <iostream>

int main()
{

	//Image Resolution

	const int width = 256;
	const int height = 256;

	//Render

	std::cout << "P3\n" << width << ' ' << height << "\n255\n";

	for (int j = 0; j < height - 1; ++j) {
		std::cerr << "\nScanlines remaining: " << j << ' ' << std::endl;	//writes progress to error output stream
		for (int i = 0; i < width; ++i) {

			double r = double(i) / (width - 1);
			double g = double(j) / (width - 1);
			double b = 0.25;

			int i_r = static_cast<int>(255.999 * r);
			int i_g = static_cast<int>(255.999 * g);
			int i_b = static_cast<int>(255.999 * b);

			std::cout << i_r << ' ' << i_g << ' ' << i_b << '\n';
		}

	}
}