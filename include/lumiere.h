#pragma once

#include "vector3.h"

class lumiere
{
public:
	vector3 org;
	vector3 I;
	vector3 Ia;

	lumiere(const vector3&, const vector3&, const vector3&);
};