#pragma once

#include <vector>

#include "vector3.h"

class object
{
public:
	virtual std::vector<vector3> intersection();
};