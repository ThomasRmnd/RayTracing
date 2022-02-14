#include "Platform/Platform.hpp"

#include "../include/rayon.h"
#include "../include/sphere.h"

int main()
{
	sphere s(vector3(1., 0., -3.), -2.);
	rayon r(vector3(0., 0., 0.), vector3(0., 0., -1.));
	std::vector<vector3> result = s.intersection(r);

	std::cout << result.size() << std::endl;
	for (unsigned int i = 0; i < result.size(); i++)
	{
		vector3 element = result[i];
		std::cout << element.x << " " << element.y << " " << element.z << std::endl;
	}

	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(200.0f * screenScalingFactor, 200.0f * screenScalingFactor), "SFML works!");
	platform.setIcon(window.getSystemHandle());

	sf::CircleShape shape(window.getSize().x / 2);
	shape.setFillColor(sf::Color::White);

	sf::Texture shapeTexture;
	shapeTexture.loadFromFile("content/sfml.png");
	shape.setTexture(&shapeTexture);

	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
