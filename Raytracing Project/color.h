#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include "vec3.h"

///
///calculate each color channel and output in a Vec3f (R, G, B)
/// 
 
Vec3f calculate_color(int i, int j, int width, int height)
{
	return Vec3f(float(i) / (width - 1), float(j) / (height - 1), 0.25);
}

///
///write the translated value of each color component (R, G, B) [0, 255]
/// 

void output_Color(std::ostream& out, Vec3f pixelColor)
{
	out << static_cast<int>(255.99 * pixelColor.m_x) << ' '
		<< static_cast<int>(255.99 * pixelColor.m_y) << ' '
		<< static_cast<int>(255.99 * pixelColor.m_z) << '\n';
}

#endif
