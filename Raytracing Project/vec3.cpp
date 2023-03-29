
#include <iostream>

//Vec3 class to deal with representing 3D positions & RGB Color. 

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
	Vec3(T x) : m_x{ x }, m_y{ x }, m_z{ x } {}


	///member functions
	T getLengthSquared() { return (m_x * m_x) + (m_y * m_y) + (m_z * m_z); }

	int getDotProduct(const Vec3& v)
	{
		return (m_x * v.m_x) + (m_y * v.m_y) + (m_z * v.m_z);
	};

	Vec3& normalize()
	{
		T length = sqrt(getLengthSquared());
		if (length > 0.0) { m_x /= length; m_y /= length; m_z /= length; }
		return *this;
	};

	///operator overloads
	Vec3 operator + (const Vec3& v) { return Vec3<T>{m_x + v.m_x, m_y + v.m_y, m_z + v.m_z}; }
	Vec3 operator - (const Vec3& v) { return Vec3<T>{m_x - v.m_x, m_y - v.m_y, m_z - v.m_z}; }
	Vec3 operator * (const Vec3& v) { return Vec3<T>{m_x* v.m_x, m_y* v.m_y, m_z* v.m_z}; }
	Vec3 operator - () { return Vec3<T>{-m_x, -m_y, -m_z}; }
	Vec3& operator += (const Vec3& v) { m_x += v.m_x; m_y += v.m_y; m_z += v.m_z; return *this; }
	Vec3& operator -= (const Vec3& v) { m_x -= v.m_x; m_y -= v.m_y; m_z -= v.m_z; return *this; }
	friend std::ostream& operator << (std::ostream& out, Vec3& v)
	{
		out << "(" << v.m_x << ", " << v.m_y << ", " << v.m_z << ") ";
		return out;
	}
};

typedef Vec3<float> Vec3f;