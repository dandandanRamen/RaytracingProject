
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

	int getDot(const Vec3& v)
	{
		return (m_x * v.m_x) + (m_y * v.m_y) + (m_z * v.m_z);
	};

	Vec3& normalize()
	{
		T length = sqrt(getLengthSquared());	
		if (length > 0.0) {
			m_x /= length; m_y /= length; m_z /= length;
		}
		return *this;
	};

	///operator overloads
	Vec3 operator + (const Vec3 &v) { return Vec3<T>{m_x + v.m_x, m_y + v.m_y, m_z + v.m_z}; }
	Vec3 operator - (const Vec3 &v) { return Vec3<T>{m_x - v.m_x, m_y - v.m_y, m_z - v.m_z}; }
	Vec3 operator * (const Vec3 &v) { return Vec3<T>{m_x * v.m_x, m_y * v.m_y, m_z * v.m_z}; }
	Vec3 operator - () { return Vec3<T>{-m_x, -m_y, -m_z}; }
	Vec3& operator += (const Vec3 &v) { m_x += v.m_x; m_y += v.m_y; m_z += v.m_z; return *this; }
	Vec3& operator -= (const Vec3 &v) { m_x -= v.m_x; m_y -= v.m_y; m_z -= v.m_z; return *this; }
	friend std::ostream& operator << (std::ostream& out, Vec3& v) 
	{ 
		out << "(" << v.m_x << ", " << v.m_y << ", " << v.m_z << ") "; 
		return out; 
	}
};

typedef Vec3<float> Vec3f;

int main()
{
	Vec3f point{ 1.0, 2.0, 3.0};
	Vec3f point2{ 2.0, 4.0, 6.0 };
	std::cout << point.getDot(point2) << '\n';
	
}


//a Vector3 class (this is probably to simulate objects in 3d space)
//a Sphere class to draw these spheres.
//a trace function
//an overall render function that coalesces everything together