#ifndef VEC3_H
#define VEC3_H

#include <iostream>


/// Vec3 class to deal with representing 3D positions, directions, offsets, RGB Color, etc. 
/// important typedefs (vec3f, color3f) at the bottom...

class Vec3
{
public:
	double m_x;
	double m_y;
	double m_z;

public:
	//constructors
	Vec3(double x, double y, double z) : m_x{ x }, m_y{ y }, m_z{ z } {}
	Vec3() : m_x{ 0 }, m_y{ 0 }, m_z{ 0 } {}
	Vec3(double x) : m_x{ x }, m_y{ x }, m_z{ x } {}

	//member functions
	double x() { return m_x; }
	double y() { return m_y; }
	double z() { return m_z; }

	double getLengthSquared() { return (m_x * m_x) + (m_y * m_y) + (m_z * m_z); }
	double getLength() { return sqrt(getLengthSquared()); }

	Vec3 unitVector(Vec3 v) { return v / v.getLength(); };

	Vec3& normalize()
	{
		double length = getLength();
		if (length > 0.0) { m_x /= length; m_y /= length; m_z /= length; }
		return *this;
	};

	double dotProduct(const Vec3& v)
	{
		return (m_x * v.m_x) + (m_y * v.m_y) + (m_z * v.m_z);
	};

	Vec3 crossProduct(const Vec3& v)
	{
		return Vec3(m_y * v.m_z - m_z * v.m_y,
					   m_z * v.m_x - m_x * v.m_z,
					   m_x * v.m_y - m_y * v.m_x);
	};

	//operator overloads
	Vec3 operator + (const Vec3& v) { return Vec3{m_x + v.m_x, m_y + v.m_y, m_z + v.m_z}; }
	Vec3 operator - (const Vec3& v) { return Vec3{m_x - v.m_x, m_y - v.m_y, m_z - v.m_z}; }
	Vec3 operator * (const Vec3& v) { return Vec3{m_x * v.m_x, m_y * v.m_y, m_z * v.m_z}; }
	Vec3 operator / (const Vec3& v) { return Vec3{m_x / v.m_x, m_y / v.m_y, m_z / v.m_z}; }

	Vec3 operator - () { return Vec3{-m_x, -m_y, -m_z}; }

	Vec3& operator += (const Vec3& v) { return *this = Vec3(m_x += v.m_x, m_y += v.m_y, m_z += v.m_z); }
	Vec3& operator -= (const Vec3& v) { return *this = Vec3(m_x -= v.m_x, m_y -= v.m_y, m_z -= v.m_z); }
	Vec3& operator *= (const Vec3& v) { return *this = Vec3(m_x *= v.m_x, m_y *= v.m_y, m_z *= v.m_z); }

	Vec3& operator /= (const double t) { return *this *= 1 / t; }

	friend std::ostream& operator << (std::ostream& out, Vec3& v)
	{
		out << "(" << v.m_x << ", " << v.m_y << ", " << v.m_z << ") ";
		return out;
	}
};

//external functions
inline Vec3 unitVector(Vec3 v)
{
	return v / v.getLength();
};

//external operator overloads
inline Vec3 operator + (const Vec3& v, const Vec3& v2) { return Vec3{ v.m_x + v2.m_x, v.m_y + v2.m_y, v.m_z + v2.m_z }; }
inline Vec3 operator - (const Vec3& v, const Vec3& v2) { return Vec3{ v.m_x - v2.m_x, v.m_y - v2.m_y, v.m_z - v2.m_z }; }
inline Vec3 operator * (const Vec3& v, const Vec3& v2) { return Vec3{ v.m_x * v2.m_x, v.m_y * v2.m_y, v.m_z * v2.m_z }; }

inline Vec3 operator * (double n, const Vec3 v) { return Vec3{ n * v.m_x, n * v.m_y, n * v.m_z }; }
inline Vec3 operator * (const Vec3 v, double n) { return n * v; }

inline Vec3 operator / (Vec3 v, double t) { return (1 / t) * v; }





//type aliases are questionable i know
using vec3d = Vec3;			//for all geometric usage
using color3d = Vec3;		//for all color based usage


#endif


//feedback from a coding friend:

//→ For a class that represents a tiny, basic type, I would make it a pure value.Thus, all its members would be const except for assignment operator. Operations that modify the vector would return a new one without touching this.
//
//→ Vec3(T) does not really make sense.Just imagine looking at Vec3(42), it's not clear what it means and I would not allow it. I would require an explicit Vec3(42, 42, 42) if that's what is meant.
//
//→ I would avoid having get... for anything that is not a trivial getter.The verb get usually implies that it is free to get, or at least very cheap.
//
//→ Passing const Vec3 & around does not really make sense, and can introduce subtle bugs and subtle performance issues.Use Vec3 instead.
//
//→ I prefer symmetric operators to be symmetric, as in operator+(X, Y) rather than X::operator+(Y).
//
//→ using point = Vec3f and using color = Vec3f is not a good idea, it means you can pass a point where a color is expected and vice versa.You would normally want those to be strong types to avoid this issue.