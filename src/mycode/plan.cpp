#include "../../include/plan.h"

plan::plan(const vector3& _org, const vector3& _normal) :
	org(_org),
	normal(_normal)
{}

std::vector<data_intersection> plan::intersection(const rayon& _rayon)
{
	std::vector<data_intersection> result;
	vector3 ray_org(_rayon.org), ray_dir(_rayon.dir);
	vector3 v(org, ray_org);
	float a = dot(ray_dir, normal);
	float b = dot(v, normal);
	if (a == 0)
		return result;
	else
	{
		float mu = -b / a;
		if (mu > 1e-5)
			result.push_back(data_intersection(this, ray_org + mu * ray_dir));
		return result;
	}
}

vector3 plan::vector_normal(const vector3& v)
{
	(void)v;
	return normal;
}