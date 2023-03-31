#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include "vec3.h"

///calculate each normalized color channel, return channels in a Vec3f (R, G, B) [-1, 1]
color3f calculate_color(int itr, int itr2, int width, int height)
{
	return color3f(float(itr) / (width - 1), float(itr2) / (height - 1), 0.25);
}

///output the translated value of each color component in text (R, G, B) [0, 256]
void output_Color(std::ostream& out, color3f pixelColor)
{
	out << static_cast<int>(255.99 * pixelColor.m_x) << ' '
		<< static_cast<int>(255.99 * pixelColor.m_y) << ' '
		<< static_cast<int>(255.99 * pixelColor.m_z) << '\n';
}

#endif


//todo:
//change from two isolated functions to class Render
