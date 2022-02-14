#include "../../include/scene.h"

scene::scene() :
	nb_objects(0),
	nb_lumieres(0)
{
	objects = NULL;
	lumieres = NULL;
}

scene::scene(object* _objects, lumiere* _lumieres, unsigned int _nb_objects, unsigned int _nb_lumieres) :
	nb_objects(_nb_objects),
	nb_lumieres(_nb_lumieres)
{
	objects = new object[nb_objects];
	lumieres = new lumiere[nb_lumieres];
	for (unsigned int i = 0; i < nb_objects; i++)
	{
		objects[i] = _objects[i];
	}
	for (unsigned int i = 0; i < nb_lumieres; i++)
	{
		lumieres[i] = _lumieres[i];
	}
}

scene::scene(const scene& other) :
	nb_objects(other.nb_objects),
	nb_lumieres(other.nb_lumieres)
{
	objects = new object[nb_objects];
	lumieres = new lumiere[nb_lumieres];
	for (unsigned int i = 0; i < nb_objects; i++)
	{
		objects[i] = other.objects[i];
	}
	for (unsigned int i = 0; i < nb_lumieres; i++)
	{
		lumieres[i] = other.lumieres[i];
	}
}

scene::~scene()
{
	delete[] objects;
	delete[] lumieres;
}

scene& scene::operator=(const scene& other)
{
	if (this != &other)
	{
		delete[] objects;
		delete[] lumieres;
		nb_objects = other.nb_objects;
		nb_lumieres = other.nb_lumieres;
		objects = new object[nb_objects];
		lumieres = new lumiere[nb_lumieres];
		for (unsigned int i = 0; i < nb_objects; i++)
		{
			objects[i] = other.objects[i];
		}
		for (unsigned int i = 0; i < nb_lumieres; i++)
		{
			lumieres[i] = other.lumieres[i];
		}
	}
	return *this;
}

scene& scene::add_object(const object& _object)
{
	nb_objects++;
	object* new_objects = new object[nb_objects];
	for (unsigned int i = 0; i < nb_objects - 1; i++)
	{
		new_objects[i] = objects[i];
	}
	new_objects[nb_objects - 1] = _object;
	delete[] objects;
	objects = new_objects;
	return *this;
}

scene& scene::add_lumiere(const lumiere& _lumiere)
{
	nb_lumieres++;
	lumiere* new_lumieres = new lumiere[nb_lumieres];
	for (unsigned int i = 0; i < nb_lumieres - 1; i++)
	{
		new_lumieres[i] = lumieres[i];
	}
	new_lumieres[nb_lumieres - 1] = _lumiere;
	delete[] lumieres;
	lumieres = new_lumieres;
	return *this;
}