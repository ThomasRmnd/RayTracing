#include "../../include/render.h"

render::render(camera& _camera, scene& _scene, const std::vector<eclairement*>& _types_of_eclairement)
{
	p_camera = &_camera;
	p_scene = &_scene;
	p_ecran = new ecran(_camera.nb_pixel_y, _camera.nb_pixel_x);
	types_of_eclairement = _types_of_eclairement;
}

render::~render()
{
	delete p_ecran;
}

render& render::change_camera(camera& _camera)
{
	p_camera = &_camera;
	return *this;
}

render& render::change_scene(scene& _scene)
{
	p_scene = &_scene;
	return *this;
}

render& render::change_ecran(ecran& _ecran)
{
	p_ecran = &_ecran;
	return *this;
}

data_intersection render::plusProche(const vector3& B, const std::vector<data_intersection>& s) const
{
	data_intersection data0 = s[0];
	for (unsigned int i = 0; i < s.size(); i++)
	{
		data_intersection data = s[i];
		if (distance(B, data.point) < distance(B, data0.point))
		{
			data0 = data;
		}
	}
	return data0;
}

vector3 render::lancerRayon(const rayon& r, float att, unsigned int prof, unsigned int prof0)
{
	std::vector<data_intersection> s;
	for (unsigned int index = 0; index < p_scene->get_nb_objects(); index++)
	{
		object* current_object = p_scene->get_object_from_index(index);
		std::vector<data_intersection> ss = current_object->intersection(r);
		s.insert(s.end(), ss.begin(), ss.end());
	}
	if (s.size())
	{
		data_intersection data = plusProche(r.org, s);
		vector3 I = att * illumination(data.point, r.org, data.ptr, *p_scene);
		if (prof > 0)
		{
			vector3 u(r.dir);
			u.normalize();
			vector3 n(data.ptr->vector_normal(data.point));
			n.normalize();
			vector3 v = u - 2.0f * dot(u, n) * n;
			rayon r1(data.point, v);
			vector3 I1 = lancerRayon(r1, 0.5f * att, prof - 1, prof0);
			I += I1;
		}
		return I;
	}
	else if (prof == prof0)
		return vector3(0.5f, 0.5f, 1.0f);
	else
		return vector3();
}

void render::lancer(unsigned int prof, unsigned int prof0)
{
	for (unsigned int i = 0; i < p_camera->nb_pixel_x; i++)
	{
		for (unsigned int j = 0; j < p_camera->nb_pixel_y; j++)
		{
			vector3 M(p_camera->point(i, j));
			vector3 u(p_camera->position, M);
			rayon r(p_camera->position, u);
			vector3 I = lancerRayon(r, 1.0f, prof, prof0);
			p_ecran->change(p_camera->nb_pixel_y - 1 - j, i, 200.0f * vector3(std::min(I.x, 1.0f), std::min(I.y, 1.0f), std::min(I.z, 1.0f)));
		}
	}
}

vector3 render::illumination(const vector3& A, const vector3& obs, object* my_obj, const scene& my_scene)
{
	vector3 I;
	for (unsigned int i = 0; i < types_of_eclairement.size(); i++)
	{
		types_of_eclairement[i]->change_obj(my_obj);
		I += types_of_eclairement[i]->operator()(A, obs, my_scene);
	}
	return vector3(I.x * my_obj->color.x, I.y * my_obj->color.y, I.z * my_obj->color.z);
}