#include "../../include/sphere.h"

sphere::sphere(const vector3& _position, float _radius, const vector3& _color, float _ka, float _kd, float _ks) :
	object(_color, _ka, _kd, _ks),
	position(_position),
	radius(_radius)
{}

std::vector<data_intersection> sphere::intersection(const rayon& _rayon)
{
	std::vector<data_intersection> result;
	vector3 ray_org(_rayon.org), ray_dir(_rayon.dir);
	vector3 v(position, ray_org);
	float a = ray_dir.norm() * ray_dir.norm();
	float b = 2. * dot(ray_dir, v);
	float c = v.norm() * v.norm() - radius * radius;
	float Delta = b * b - 4 * a * c;
	if (Delta < 0)
		return result;
	else if (Delta == 0)
	{
		float mu = -b / (2 * a);
		if (mu > 1e-5)
			result.push_back(data_intersection(this, ray_org + mu * ray_dir));
		return result;
	}
	else
	{
		float delta = std::sqrt(Delta);
		float mu1 = (-b - delta) / (2 * a);
		if (mu1 > 1e-5)
			result.push_back(data_intersection(this, ray_org + mu1 * ray_dir));
		float mu2 = (-b + delta) / (2 * a);
		if (mu2 > 1e-5)
			result.push_back(data_intersection(this, ray_org + mu2 * ray_dir));
		return result;
	}
}

vector3 sphere::vector_normal(const vector3& v)
{
	return vector3(position, v);
}