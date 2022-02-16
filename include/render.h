#pragma once

#include <algorithm>
#include <vector>

#include "camera.h"
#include "eclairement.h"
#include "ecran.h"
#include "rayon.h"
#include "scene.h"
#include "window.h"

class window;

class render
{
private:
	camera* p_camera;
	scene* p_scene;
	ecran* p_ecran;
	std::vector<eclairement*> types_of_eclairement;

	data_intersection plusProche(const vector3&, const std::vector<data_intersection>&) const;
	vector3 lancerRayon(const rayon&, float, unsigned int, unsigned int);

public:
	render(camera&, scene&, const std::vector<eclairement*>&);
	render(const render&) = default;
	~render();

	render& operator=(const render&) = default;

	render& change_camera(camera&);
	render& change_scene(scene&);
	render& change_ecran(ecran&);

	void lancer(unsigned int, unsigned int);

	vector3 illumination(const vector3&, const vector3&, object*, const scene&);

	friend window;
};