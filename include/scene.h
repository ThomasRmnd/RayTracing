#pragma once

#include "lumiere.h"
#include "object.h"

class scene
{
private:
	unsigned int nb_objects;
	unsigned int nb_lumieres;
	object* objects;
	lumiere* lumieres;

public:
	scene();
	scene(object*, lumiere*, unsigned int, unsigned int);
	scene(const scene&);
	~scene();

	scene& operator=(const scene&);

	scene& add_object(const object&);
	scene& add_lumiere(const lumiere&);
};