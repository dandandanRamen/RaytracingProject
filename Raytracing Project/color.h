#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include "vec3.h"

///calculate each normalized color channel, return channels in a Vec3f (R, G, B)
color3d calculate_color(int itr, int itr2, int width, int height)
{
	return color3d(float(itr) / (width - 1), float(itr2) / (height - 1), 0.25);
}

///output the translated value of each color component in text (R, G, B) [0, 256]
void output_Color(std::ostream& out, color3d pixelColor)
{
	out << static_cast<int>(255.99 * pixelColor.x()) << ' '
		<< static_cast<int>(255.99 * pixelColor.y()) << ' '
		<< static_cast<int>(255.99 * pixelColor.z()) << '\n';
}

#endif


//todo:
//change from two isolated functions to class Render
