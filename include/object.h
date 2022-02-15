#pragma once

#include <iostream>
#include <vector>

#include "rayon.h"
#include "vector3.h"

class object;

struct data_intersection
{
	object* ptr;
	vector3 point;

	data_intersection(object*, const vector3&);
};

class object
{
public:
	object& operator=(const object&) = default;

	virtual std::vector<data_intersection> intersection(const rayon&) = 0;
	virtual vector3 vector_normal(const vector3&) = 0;
};