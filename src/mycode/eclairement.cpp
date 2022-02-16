#include "../../include/eclairement.h"

eclairement::eclairement(object* _my_obj)
{
	my_obj = _my_obj;
}

void eclairement::change_obj(object* _my_obj)
{
	my_obj = _my_obj;
}

diffuse::diffuse(object* _my_obj) :
	eclairement(_my_obj)
{}

vector3 diffuse::operator()(const vector3& A, const vector3& obs, const scene& my_scene)
{
	(void)obs;
	vector3 I;
	for (unsigned int i = 0; i < my_scene.get_nb_lumieres(); i++)
	{
		lumiere* current_lumiere = my_scene.get_lumiere_from_index(i);
		rayon r(A, current_lumiere->org);
		bool black = false;
		for (unsigned int j = 0; j < my_scene.get_nb_objects(); j++)
		{
			object* current_object = my_scene.get_object_from_index(j);
			if (current_object->intersection(r).size())
			{
				black = true;
				break;
			}
		}
		if (!black)
		{
			vector3 v(A, current_lumiere->org);
			vector3 u = my_obj->vector_normal(A);
			vector3 I1 = my_obj->kd * current_lumiere->I;
			I += std::max(0.0f, angle(u, v)) * I1;
		}
	}
	return I;
}

phong::phong(object* _my_obj) :
	eclairement(_my_obj)
{}

vector3 phong::operator()(const vector3& A, const vector3& obs, const scene& my_scene)
{
	vector3 I;
	for (unsigned int i = 0; i < my_scene.get_nb_lumieres(); i++)
	{
		lumiere* current_lumiere = my_scene.get_lumiere_from_index(i);
		rayon r(A, current_lumiere->org);
		bool black = false;
		for (unsigned int j = 0; j < my_scene.get_nb_objects(); j++)
		{
			object* current_object = my_scene.get_object_from_index(j);
			if (current_object->intersection(r).size())
			{
				black = true;
				break;
			}
		}
		if (!black)
		{
			vector3 v(A, current_lumiere->org);
			v.normalize();
			vector3 u = my_obj->vector_normal(A);
			vector3 w(A, obs);
			w.normalize();
			vector3 h = v + w;
			h.normalize();
			vector3 I1 = my_obj->ks * current_lumiere->I;
			I += std::pow(std::max(0.0f, angle(u, h)), 100.0f) * I1;
		}
	}
	return I;
}

ambiant::ambiant(object* _my_obj) :
	eclairement(_my_obj)
{}

vector3 ambiant::operator()(const vector3& A, const vector3& obs, const scene& my_scene)
{
	(void)obs;
	vector3 I;
	for (unsigned int i = 0; i < my_scene.get_nb_lumieres(); i++)
	{
		lumiere* current_lumiere = my_scene.get_lumiere_from_index(i);
		rayon r(A, current_lumiere->org);
		bool black = false;
		for (unsigned int j = 0; j < my_scene.get_nb_objects(); j++)
		{
			object* current_object = my_scene.get_object_from_index(j);
			if (current_object->intersection(r).size())
			{
				black = true;
				break;
			}
		}
		if (!black)
			I += my_obj->ka * current_lumiere->Ia;
	}
	return I;
}