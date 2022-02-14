#pragma once

#include <cmath>

#include "object.h"

class sphere : public object
{
public:
	vector3 position;

	float radius;

	sphere(const vector3&, float);

	virtual std::vector<vector3> intersection(const rayon&);
	virtual vector3 vector_normal(const vector3&);
};