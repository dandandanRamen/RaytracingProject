
/* Raytracing Project, by daniel simpson
Adapted from Scratchapixel's Programming Blog.
a Vector3 class (this is probably to simulate objects in 3d space)
a Sphere class to draw these spheres.
a trace function
an overall render function that coalesces everything together */

#include <iostream>

///
/// Vector3 class to help place objects in 3D space.
///

template <typename T>
class Vec3
{
private:
	T m_x;
	T m_y;
	T m_z;

public:
	//constructors below.
	Vec3(T x, T y, T z)
		: m_x{ x }, m_y{ y }, m_z{ z } {}

	Vec3()
		: m_x{0}, m_y{0}, m_z{0} {}

	Vec3(T x)
		: m_x{x}, m_y{x}, m_z{x} {}

	//normalize function

	//operator overloads below.

	//

};

int main()
{

}