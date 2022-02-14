#pragma once

#include <iostream>
#include <vector>

#include "rayon.h"
#include "vector3.h"

class object
{
public:
	object& operator=(const object&) = default;

	virtual std::vector<vector3> intersection(const rayon&);
	virtual vector3 vector_normal(const vector3&);
};