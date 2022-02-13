#include "vector3.h"

vector3::vector3() :
	x(0),
	y(0),
	z(0)
{}

vector3::vector3(float _x, float _y, float _z) :
	x(_x),
	y(_y),
	z(_z)
{}

vector3::vector3(const vector3& v1, const vector3& v2)
{
	*this = v2;
	*this -= v1;
}

vector3 vector3::spherical(float _norm, float _theta, float _phi)
{ // Convention rayon-colatitude-longitude
	return vector3(_norm * std::sin(_theta) * std::cos(_phi), _norm * std::sin(_theta) * std::sin(_phi), _norm * std::cos(_theta));
}

vector3& vector3::operator+=(const vector3& other)
{
	this->x += other.x, this->y += other.y, this->z += other.z;
	return *this;
}

vector3& vector3::operator-=(const vector3& other)
{
	this->x -= other.x, this->y -= other.y, this->z -= other.z;
	return *this;
}

vector3& vector3::operator*=(float lambda)
{
	this->x *= lambda, this->y *= lambda, this->z *= lambda;
	return *this;
}

vector3& vector3::operator/=(float lambda)
{
	this->x /= lambda, this->y /= lambda, this->z /= lambda;
	return *this;
}

float vector3::norm() const
{
	return std::sqrt(dot(*this, *this));
}

float vector3::norm_2() const
{
	return dot(*this, *this);
}

float vector3::theta() const
{ // Convention rayon-colatitude-longitude
	return std::acos(this->z / this->norm());
}

float vector3::phi() const
{ // Convention rayon-colatitude-longitude
	return std::atan(this->y / this->x);
}

void vector3::normalize()
{
	*this /= this->norm();
}

vector3 operator+(const vector3& v1, const vector3& v2)
{
	return vector3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

vector3 operator+(const vector3& v)
{
	return v;
}

vector3 operator-(const vector3& v1, const vector3& v2)
{
	return vector3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

vector3 operator-(const vector3& v)
{
	return (vector3() - v);
}

vector3 operator*(const vector3& v, float lambda)
{
	return vector3(v.x * lambda, v.y * lambda, v.z * lambda);
}

vector3 operator*(float lambda, const vector3& v)
{
	return (v * lambda);
}

vector3 operator/(const vector3& v, float lambda)
{
	return vector3(v.x / lambda, v.y * lambda, v.z / lambda);
}

bool operator==(const vector3& v1, const vector3& v2)
{
	return ((v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z));
}

bool operator!=(const vector3& v1, const vector3& v2)
{
	return !(v1 == v2);
}

float dot(const vector3& v1, const vector3& v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

vector3 cross(const vector3& v1, const vector3& v2)
{
	return vector3(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

float angle(const vector3& v1, const vector3& v2)
{
	return (dot(v1, v2) / (v1.norm() * v2.norm()));
}

float distance(const vector3& v1, const vector3& v2)
{
	return vector3(v1, v2).norm();
}