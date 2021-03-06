#pragma once

#include "object.h"

class plan : public object
{
public:
	vector3 org;

	vector3 normal;

	plan(const vector3&, const vector3&, const vector3&, float, float, float);

	virtual std::vector<data_intersection> intersection(const rayon&);
	virtual vector3 vector_normal(const vector3&);
};