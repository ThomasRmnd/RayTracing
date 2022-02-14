#pragma once

#include "lumiere.h"
#include "object.h"

class scene
{
private:
	object* objects;
	unsigned int nb_objects;
	lumiere* lumieres;
	unsigned int nb_lumieres;

public:
	scene();
	scene(const object*, const lumiere*, unsigned int, unsigned int);
	scene(const scene&);
	~scene();

	scene& operator=(const scene&);

	scene& add_object(const object&);
	scene& add_lumiere(const lumiere&);
};