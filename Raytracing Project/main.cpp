
/* Raytracing Project, by Daniel Simpson
Adapted from Scratchapixel's Programming Blog. */

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
	///constructors
	Vec3(T x, T y, T z) : m_x{ x }, m_y{ y }, m_z{ z } {}
	Vec3() : m_x{ 0 }, m_y{ 0 }, m_z{ 0 } {}						
	Vec3(T x) : m_x{x}, m_y{x}, m_z{x} {}

	
	///member functions
	T getLengthSquared() { return (m_x * m_x) + (m_y * m_y) + (m_z * m_z); }  //magnitude is length
	T getLength() { return m_x + m_y + m_z; }
	Vec3& normalize()
	{
		T lengthSquared = getLengthSquared();
	};

	///operator overloads
	friend Vec3 operator+(const Vec3& v, const Vec3& v2) { return v.m_x + v2.m_x, v.m_y + v2.m_y; }
	friend Vec3 operator-(const Vec3& v, const Vec3& v2) { return v.m_x - v2.m_x, v.m_y - v2.m_y; }
	friend std::ostream& operator<<(std::ostream& out, Vec3& v) { out << "(" << v.m_x << ", " << v.m_y << ") "; return out; }

};

typedef Vec3<float> Vec3f;

int main()
{
	Vec3f point{ 2, 5, 2 };

	std::cout << point.getLengthSquared() << '\n';
	std::cout << point.getLength() << '\n';
	
	Vec3f point2{ point + point };
	
	std::cout << point2 << point << '\n';
}


//a Vector3 class (this is probably to simulate objects in 3d space)
//a Sphere class to draw these spheres.
//a trace function
//an overall render function that coalesces everything together