#include "Platform/Platform.hpp"

#include "../include/lumiere.h"
#include "../include/plan.h"
#include "../include/rayon.h"
#include "../include/sphere.h"
#include "../include/window.h"

int main()
{
	unsigned int resolEcran[2] = { 300, 200 };
	float bornes[4] = { -3., 3., -2., 2. };
	camera my_camera(vector3(0., 0., 5.), vector3(0., 0., -1.), 5., resolEcran, bornes);

	sphere s1(vector3(2., 0., -5.), 1., vector3(0.8, 0.8, 0.8), 0.1, 1.0, 1.0);
	sphere s2(vector3(-1., -1., -3.), 1., vector3(0.8, 0.3, 0.3), 0.1, 1.0, 0.0);
	sphere s3(vector3(0., 1., -12.), 3., vector3(1.0, 0.8, 0.4), 0.1, 1.0, 1.0);
	plan p(vector3(0., -2., 0.), vector3(0., 1., 0.), vector3(0.9, 0.6, 0.6), 0.1, 1.0, 0.0);
	lumiere l1(vector3(60.0, 50.0, 100.0), vector3(1.0, 1.0, 1.0), vector3(1.0, 1.0, 1.0));
	scene my_scene;
	my_scene.add_object(&s1);
	my_scene.add_object(&s2);
	my_scene.add_object(&s3);
	my_scene.add_object(&p);
	my_scene.add_lumiere(&l1);

	sf::RenderWindow rwindow;
	render my_render(my_camera, my_scene);
	window my_window(rwindow, my_render);

	my_window.create(sf::VideoMode(300, 200), "SFML works!");

	sf::Event event;

	while (my_window.isOpen())
	{
		while (my_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				my_window.close();
		}

		my_window.update();
	}
	return 0;
}
