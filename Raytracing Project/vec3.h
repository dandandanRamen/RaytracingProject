#ifndef VEC3_H
#define VEC3_H

#include <iostream>

/// Vec3 class to deal with representing 3D positions, directions, offsets, RGB Color, etc. 

template <typename T>
class Vec3
{
protected:
	T m_x;
	T m_y;
	T m_z;

public:
	//constructors
	Vec3(T x, T y, T z) : m_x{ x }, m_y{ y }, m_z{ z } {}

	Vec3() : m_x{ 0 }, m_y{ 0 }, m_z{ 0 } {}

	Vec3(T x) : m_x{ x }, m_y{ x }, m_z{ x } {}


	//member functions
	T getLengthSquared() { return (m_x * m_x) + (m_y * m_y) + (m_z * m_z); }
	T getLength() { return sqrt(getLengthSquared()) }

	Vec3& normalize()
	{
		T length = getLength();
		if (length > 0.0) { m_x /= length; m_y /= length; m_z /= length; }
		return *this;
	};

	float getDotProduct(const Vec3& v)
	{
		return (m_x * v.m_x) + (m_y * v.m_y) + (m_z * v.m_z);
	};

	Vec3& getCrossProduct(const Vec3& v)
	{
		return Vec3<T>(m_y * v.m_z - m_z * v.m_y,
					   m_z * v.m_x - m_x * v.m_z,
					   m_x * v.m_y - m_y * v.m_x)
	};

	//operator overloads
	Vec3 operator + (const Vec3& v) { return Vec3<T>{m_x + v.m_x, m_y + v.m_y, m_z + v.m_z}; }

	Vec3 operator - (const Vec3& v) { return Vec3<T>{m_x - v.m_x, m_y - v.m_y, m_z - v.m_z}; }

	Vec3 operator * (const Vec3& v) { return Vec3<T>{m_x* v.m_x, m_y* v.m_y, m_z* v.m_z}; }

	Vec3 operator - () { return Vec3<T>{-m_x, -m_y, -m_z}; }

	Vec3& operator += (const Vec3& v) { return *this = Vec3<T>(m_x += v.m_x, m_y += v.m_y, m_z += v.m_z); }

	Vec3& operator -= (const Vec3& v) { return *this = Vec3<T>(m_x -= v.m_x, m_y -= v.m_y, m_z -= v.m_z); }

	friend std::ostream& operator << (std::ostream& out, Vec3& v)
	{
		out << "(" << v.m_x << ", " << v.m_y << ", " << v.m_z << ") ";
		return out;
	}
};

typedef Vec3<float> Vec3f;	//old way of type defs
using point = Vec3f;		//newer, cleaner way
using color = Vec3f;

#endif