#pragma once

#include <vector>

#include "vector3.h"

class object
{
public:
	object& operator=(const object&) = default;

	virtual std::vector<vector3> intersection();
};