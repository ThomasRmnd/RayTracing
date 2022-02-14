#include "../../include/scene.h"

scene::scene()
{}

scene::scene(object** _objects, lumiere** _lumieres, unsigned int _nb_objects, unsigned int _nb_lumieres)
{
	objects.resize(_nb_objects);
	lumieres.resize(_nb_lumieres);
	for (unsigned int i = 0; i < _nb_objects; i++)
	{
		objects[i] = _objects[i];
	}
	for (unsigned int i = 0; i < _nb_lumieres; i++)
	{
		lumieres[i] = _lumieres[i];
	}
}

unsigned int scene::get_nb_objects() const
{
	return objects.size();
}

unsigned int scene::get_nb_lumieres() const
{
	return lumieres.size();
}

object* scene::get_object_from_index(unsigned int i) const
{
	return objects[i];
}

lumiere* scene::get_lumiere_from_index(unsigned int i) const
{
	return lumieres[i];
}

scene& scene::add_object(object* _object)
{
	objects.push_back(_object);
	return *this;
}

scene& scene::add_lumiere(lumiere* _lumiere)
{
	lumieres.push_back(_lumiere);
	return *this;
}