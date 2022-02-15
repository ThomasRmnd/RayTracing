#pragma once

#include <algorithm>
#include <vector>

#include "rayon.h"
#include "scene.h"
#include "vector3.h"

class scene;

class object;

struct data_intersection
{
	object* ptr;
	vector3 point;

	data_intersection(object*, const vector3&);

	data_intersection& operator=(const data_intersection&) = default;
};

class object
{
public:
	object& operator=(const object&) = default;

	virtual std::vector<data_intersection> intersection(const rayon&) = 0;
	virtual vector3 vector_normal(const vector3&) = 0;
	vector3 diffuse(const vector3&, const scene&);
};