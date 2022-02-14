#include "Platform/Platform.hpp"

#include "../include/rayon.h"
#include "../include/sphere.h"
#include "../include/window.h"

int main()
{
	unsigned int resolEcran[2] = { 0, 0 };
	float bornes[4] = { 0, 0, 0, 0 };
	camera my_camera(vector3(), vector3(), 0., resolEcran, bornes);
	scene my_scene;
	sf::RenderWindow rwindow;
	render my_render(my_camera, my_scene);
	window my_window(rwindow, my_render);

	my_window.create(sf::VideoMode(200.0f, 200.0f), "SFML works!");

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
