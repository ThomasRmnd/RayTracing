#pragma once

#include "object.h"

class plan : public object
{
public:
	vector3 org;

	vector3 normal;

	plan(const vector3&, const vector3&);

	virtual std::vector<vector3> intersection(const rayon&);
	virtual vector3 vector_normal(const vector3&);
};