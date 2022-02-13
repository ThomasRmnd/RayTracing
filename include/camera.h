#pragma once

#include "vector3.h"

class camera
{

public:
	unsigned int nb_pixel_x, nb_pixel_y;

	float xmin, xmax, ymin, ymax;

	vector3 position, directionVue;

	float d;

	float x, y, z;

	vector3 u, v, w;

	camera(const vector3&, const vector3&, float, unsigned int[2], float[4]);

	vector3 point(unsigned int, unsigned int);
};