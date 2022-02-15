#include "../../include/render.h"

render::render(camera& _camera, scene& _scene)
{
	p_camera = &_camera;
	p_scene = &_scene;
	p_ecran = new ecran(_camera.nb_pixel_y, _camera.nb_pixel_x);
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

void render::lancer0()
{
	for (unsigned int i = 0; i < p_camera->nb_pixel_x; i++)
	{
		for (unsigned int j = 0; j < p_camera->nb_pixel_y; j++)
		{
			std::vector<data_intersection> s;
			vector3 M(p_camera->point(i, j));
			rayon r(p_camera->position, vector3(p_camera->position, M));
			for (unsigned int index = 0; index < p_scene->get_nb_objects(); index++)
			{
				object* current_object = p_scene->get_object_from_index(index);
				std::vector<data_intersection> ss = current_object->intersection(r);
				s.insert(s.end(), ss.begin(), ss.end());
			}
			if (s.size())
				p_ecran->change(p_camera->nb_pixel_y - 1 - j, i, vector3(50., 50., 50.));
		}
	}
}

data_intersection render::plusProche(const vector3& B, const std::vector<data_intersection>& s)
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

void render::lancer1()
{
	for (unsigned int i = 0; i < p_camera->nb_pixel_x; i++)
	{
		for (unsigned int j = 0; j < p_camera->nb_pixel_y; j++)
		{
			std::vector<data_intersection> s;
			vector3 M(p_camera->point(i, j));
			rayon r(p_camera->position, vector3(p_camera->position, M));
			for (unsigned int index = 0; index < p_scene->get_nb_objects(); index++)
			{
				object* current_object = p_scene->get_object_from_index(index);
				std::vector<data_intersection> ss = current_object->intersection(r);
				s.insert(s.end(), ss.begin(), ss.end());
			}
			if (s.size())
			{
				data_intersection data = plusProche(p_camera->position, s);
				vector3 I = data.ptr->diffuse(data.point, *p_scene);
				p_ecran->change(p_camera->nb_pixel_y - 1 - j, i, 200.0f * vector3(std::min(I.x, 1.0f), std::min(I.y, 1.0f), std::min(I.z, 1.0f)));
			}
		}
	}
}