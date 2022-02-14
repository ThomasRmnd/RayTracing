#pragma once

#include "vector3.h"

class rayon
{

public:
	vector3 org;

	vector3 dir;

	rayon::rayon(const vector3&, const vector3&);
};