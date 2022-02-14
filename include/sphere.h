#pragma once

#include "object.h"

class sphere : public object
{
public:
	vector3 position;

	float radius;

	sphere(const vector3&, float);

	virtual std::vector<vector3> intersection();
};