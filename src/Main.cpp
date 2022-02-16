#include "Platform/Platform.hpp"

#include "../include/controller.h"
#include "../include/eclairement.h"
#include "../include/lumiere.h"
#include "../include/plan.h"
#include "../include/rayon.h"
#include "../include/sphere.h"
#include "../include/window.h"

int main()
{
	unsigned int resolEcran[2] = { 600, 400 };
	float bornes[4] = { -3., 3., -2., 2. };
	camera my_camera(vector3(0., 0., 5.), vector3(0., 0., -1.), 5., resolEcran, bornes);

	sphere s1(vector3(1.0f, -1.0f, -1.0f), 1.0f, vector3(0.8f, 0.8f, 0.3f), 1.0f, 1.0f, 1.0f);
	sphere s2(vector3(-3.0f, -1.0f, -3.0f), 1.0f, vector3(0.8f, 0.3f, 0.3f), 1.0f, 1.0f, 1.0f);
	sphere s3(vector3(0.0f, 0.0f, -5.0f), 2.0f, vector3(0.8f, 0.8f, 0.8f), 1.0f, 1.0f, 1.0f);
	plan p(vector3(0.0f, -2.0f, 0.0f), vector3(0.0f, 1.0f, 0.0f), vector3(0.9f, 0.6f, 0.6f), 1.0f, 0.5f, 0.6f);
	lumiere l1(vector3(60.0f, 50.0f, 100.0f), vector3(1.0f, 1.0f, 1.0f), vector3(0.5f, 0.5f, 0.5f));
	scene my_scene;
	my_scene.add_object(&s1);
	my_scene.add_object(&s2);
	my_scene.add_object(&s3);
	my_scene.add_object(&p);
	my_scene.add_lumiere(&l1);

	diffuse my_diffuse(NULL);
	phong my_phong(NULL);
	ambiant my_ambiant(NULL);
	std::vector<eclairement*> types_of_eclairement = { &my_diffuse };

	sf::RenderWindow rwindow;
	render my_render(my_camera, my_scene, types_of_eclairement);
	controller my_controller(&my_camera, NULL);
	window my_window(rwindow, my_render, my_controller);
	my_controller.change_window(&my_window);

	my_window.create(sf::VideoMode(resolEcran[0], resolEcran[1]), "SFML works!");

	sf::Event event;

	while (my_window.isOpen())
	{
		while (my_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				my_window.close();
		}
		my_window.check_events(event);
		my_window.update();
	}
	return 0;
}
