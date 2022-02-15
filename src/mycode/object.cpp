#include "../include/object.h"

data_intersection::data_intersection(object* _ptr, const vector3& _point) :
	point(_point)
{
	ptr = _ptr;
}

object::object(const vector3& _color, float _ka, float _kd, float _ks) :
	color(_color),
	ka(_ka),
	kd(_kd),
	ks(_ks)
{}

vector3 object::diffuse(const vector3& A, const scene& my_scene)
{
	vector3 I;
	for (unsigned int i = 0; i < my_scene.get_nb_lumieres(); i++)
	{
		lumiere* current_lumiere = my_scene.get_lumiere_from_index(i);
		vector3 v(A, current_lumiere->org);
		vector3 u = this->vector_normal(A);
		vector3 I1 = this->kd * current_lumiere->I;
		I += std::max(0.0f, angle(u, v)) * I1;
	}
	return I;
}

vector3 object::phong(const vector3& A, const vector3& obs, const scene& my_scene)
{
	vector3 I;
	for (unsigned int i = 0; i < my_scene.get_nb_lumieres(); i++)
	{
		lumiere* current_lumiere = my_scene.get_lumiere_from_index(i);
		vector3 v(A, current_lumiere->org);
		v.normalize();
		vector3 u = this->vector_normal(A);
		vector3 w(A, obs);
		w.normalize();
		vector3 h = v + w;
		vector3 I1 = this->ks * current_lumiere->I;
		I += std::pow(std::max(0.0f, angle(u, h)), 100.0f) * I1;
	}
	return I;
}

vector3 object::ambiant(const scene& my_scene)
{
	vector3 I;
	for (unsigned int i = 0; i < my_scene.get_nb_lumieres(); i++)
	{
		lumiere* current_lumiere = my_scene.get_lumiere_from_index(i);
		I += this->ka * current_lumiere->Ia;
	}
	return I;
}

vector3 object::illumination(const vector3& A, const vector3& obs, const scene& my_scene)
{
	vector3 I;
	I += ambiant(my_scene) + diffuse(A, my_scene) + phong(A, obs, my_scene);
	return vector3(I.x * color.x, I.y * color.y, I.z * color.z);
}