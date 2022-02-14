#pragma once

#include "vector3.h"

class ecran
{
private:
	vector3** matrix;
	unsigned int nb_row;
	unsigned int nb_col;

public:
	ecran(unsigned int, unsigned int);
	ecran(const ecran&);
	~ecran();

	ecran& operator=(const ecran&);

	unsigned int get_nb_row() const;
	unsigned int get_nb_col() const;
	vector3 at(unsigned int, unsigned int) const;
	ecran& change(unsigned int, unsigned int, const vector3&);
};