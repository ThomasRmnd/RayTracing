#include "../../include/ecran.h"

ecran::ecran(unsigned int i, unsigned int j) :
	nb_row(i),
	nb_col(j)
{
	matrix = new vector3*[nb_row];
	for (unsigned int i = 0; i < nb_row; i++)
	{
		matrix[i] = new vector3[nb_col];
	}
}

ecran::ecran(const ecran& other) :
	nb_row(other.nb_row),
	nb_col(other.nb_col)
{
	matrix = new vector3*[nb_row];
	for (unsigned int i = 0; i < nb_row; i++)
	{
		matrix[i] = new vector3[nb_col];
		for (unsigned int j = 0; j < nb_col; j++)
		{
			matrix[i][j] = other.matrix[i][j];
		}
	}
}

ecran::~ecran()
{
	for (unsigned int i = 0; i < nb_row; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

ecran& ecran::operator=(const ecran& other)
{
	for (unsigned int i = 0; i < nb_row; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	nb_row = other.nb_row;
	nb_col = other.nb_col;
	matrix = new vector3*[nb_row];
	for (unsigned int i = 0; i < nb_row; i++)
	{
		matrix[i] = new vector3[nb_col];
		for (unsigned int j = 0; j < nb_col; j++)
		{
			matrix[i][j] = other.matrix[i][j];
		}
	}
	return *this;
}

unsigned int ecran::get_nb_row() const
{
	return nb_row;
}

unsigned int ecran::get_nb_col() const
{
	return nb_col;
}

vector3 ecran::at(unsigned int i, unsigned int j) const
{
	return matrix[i][j];
}

ecran& ecran::change(unsigned int i, unsigned int j, const vector3& value)
{
	matrix[i][j] = value;
	return *this;
}