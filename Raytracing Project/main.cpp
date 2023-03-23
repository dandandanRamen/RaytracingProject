
/* Raytracing Project, by Daniel Simpson
Adapted from Scratchapixel's Programming Blog. */

#include <iostream>

///
/// Vector3 class to deal with specific points in 3D space. 
///

template <typename T>
class Vec3
{
protected:
	///member variables
	T m_x;
	T m_y;
	T m_z;

public:
	///constructors
	Vec3(T x, T y, T z) : m_x{ x }, m_y{ y }, m_z{ z } {}
	Vec3() : m_x{ 0 }, m_y{ 0 }, m_z{ 0 } {}						
	Vec3(T x) : m_x{x}, m_y{x}, m_z{x} {}

	
	///member functions
	T getLengthSquared() { return (m_x * m_x) + (m_y * m_y) + (m_z * m_z); } 
	T getLength() { return sqrt(getLengthSquared()); }

	Vec3& normalize()
	{
		T lengthSquared = getLengthSquared();	//1. get the length squared
		T length = sqrt(getLengthSquared());	//2. 
	};

	///operator overloads (sorry for the dense text!)
	Vec3 operator+(const Vec3 &v) { return Vec3<T>{m_x + v.m_x, m_y + v.m_y, m_z + v.m_z}; }
	Vec3 operator-(const Vec3 &v) { return Vec3<T>{m_x - v.m_x, m_y - v.m_y, m_z - v.m_z}; }
	Vec3 operator*(const Vec3 &v) { return Vec3<T>{m_x * v.m_x, m_y * v.m_y, m_z * v.m_z}; }
	Vec3 operator-() { return Vec3<T>{-m_x, -m_y, -m_z}; }
	Vec3& operator+=(const Vec3 &v) { m_x += v.m_x; m_y += v.m_y; m_z += v.m_z; return *this; }
	Vec3& operator-=(const Vec3& v) { m_x -= v.m_x; m_y -= v.m_y; m_z -= v.m_z; return *this; }
	friend std::ostream& operator<<(std::ostream& out, Vec3& v) 
	{ 
		out << "(" << v.m_x << ", " << v.m_y << ", " << v.m_z << ") "; 
		return out; 
	}

};

typedef Vec3<float> Vec3f;

int main()
{
	Vec3f point{ 2, 5, 2 };
	Vec3f point2{ point + point };
	point2 += point;
	std::cout << point2 << point << '\n';
}


//a Vector3 class (this is probably to simulate objects in 3d space)
//a Sphere class to draw these spheres.
//a trace function
//an overall render function that coalesces everything together