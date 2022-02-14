#pragma once

#include <vector>

#include "lumiere.h"
#include "object.h"

class scene
{
private:
	std::vector<object*> objects;
	std::vector<lumiere*> lumieres;

public:
	scene();
	scene(object**, lumiere**, unsigned int, unsigned int);
	scene(const scene&) = default;
	~scene() = default;

	scene& operator=(const scene&) = default;

	unsigned int get_nb_objects() const;
	unsigned int get_nb_lumieres() const;

	object* get_object_from_index(unsigned int) const;
	lumiere* get_lumiere_from_index(unsigned int) const;

	scene& add_object(object*);
	scene& add_lumiere(lumiere*);
};