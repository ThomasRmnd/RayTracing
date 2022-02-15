#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "camera.h"
#include "window.h"

class window;

class controller
{
private:
	bool moving;
	bool move_active;
	sf::Keyboard::Key forward;
	sf::Keyboard::Key backward;
	sf::Keyboard::Key right;
	sf::Keyboard::Key left;
	sf::Keyboard::Key up;
	sf::Keyboard::Key down;

	camera* p_camera;
	window* p_window;

	void move();

public:
	controller(camera*, window*);
	controller(const sf::Keyboard::Key&, const sf::Keyboard::Key&, const sf::Keyboard::Key&, const sf::Keyboard::Key&, const sf::Keyboard::Key&, const sf::Keyboard::Key&);

	controller& operator=(const controller&) = default;

	void check_event(const sf::Event&);
	void update();

	controller& change_camera(camera*);
	controller& change_window(window*);
};