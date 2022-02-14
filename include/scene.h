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

	unsigned int get_nb_objects() const;
	unsigned int get_nb_lumieres() const;

	object* get_object_from_index(unsigned int) const;
	lumiere* get_lumiere_from_index(unsigned int) const;

	scene& add_object(const object&);
	scene& add_lumiere(const lumiere&);
};