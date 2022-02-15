#pragma once

#include <algorithm>
#include <vector>

#include "camera.h"
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

	data_intersection plusProche(const vector3&, const std::vector<data_intersection>&);

public:
	render(camera&, scene&);
	render(const render&) = default;
	~render();

	render& operator=(const render&) = default;

	render& change_camera(camera&);
	render& change_scene(scene&);
	render& change_ecran(ecran&);

	void lancer0();
	void lancer1();

	friend window;
};